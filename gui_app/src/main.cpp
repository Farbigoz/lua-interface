#include <QApplication>
#include <QFile>
#include <QTimer>
#include <QFileDialog>

#include <iostream>


#ifdef __cplusplus
extern "C" {
#endif

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

#ifdef __cplusplus
}
#endif



#include "lua_interface.h"
#include "lua_defs.h"

#include "ui_window.h"
#include "main.h"

#include <qsourcehighliter.h>


// print(collectgarbage("count")*1024) - Количество потребляемой памяти в байтах


char LUA_SCRIPT[] = "require \"defs\"																\n"
					"require \"interface\"															\n"
					"																				\n"
					"trc3 = interface.trc3Rec														\n"
					"ars = interface.arsGen															\n"
					"																				\n"
					"mapper = interface.can.mapper													\n"
					"inp = interface.can.input														\n"
					"																				\n"
					"function b2n(b) return b and 1 or 0 end										\n"
					"																				\n"
					"																				\n"
					"function setup()																\n"
					"	trc3[1].level = 99															\n"
					"	trc3[1].carrier = defs.F_720_HZ												\n"
					"	trc3[1].mod = defs.F_8_HZ													\n"
					"																				\n"
					"	mapper[0x12345678] = {pos = 32, len = 2, inp = 1, d = 0, timeout = 200}		\n"
					"	mapper[0x12345678] = {pos = 34, len = 2, inp = 2, d = 0, timeout = 200}		\n"
					"end																			\n"
					"																				\n"
					"																				\n"
					"function loop()																\n"
					"	print(inp[1])																\n"
					"	print(inp[2])																\n"
					"end																			\n";

void do_lua() {
	lua_State *L = luaL_newstate();
	luaL_openlibs(L);

	//LUA_INTERFACE.InitLib(L);
	//LUA_DEFS.InitLib(L);

	if (luaL_dostring(L, LUA_SCRIPT) != LUA_OK) {
		std::cout << lua_tostring(L, -1) << "\n";
		return;
	}


	lua_getglobal(L, "setup");  /* function to be called */
	if (lua_pcall(L, 0, 0, 0) != 0)
		std::cout << "Error: " << lua_tostring(L, -1) << "\n";


	lua_gc(L, LUA_GCCOLLECT);
	lua_gc(L, LUA_GCSTEP);


	lua_getglobal(L, "loop");  /* function to be called */
	if (lua_pcall(L, 0, 0, 0) != 0)
		std::cout << "Error: " << lua_tostring(L, -1) << "\n";


	lua_getglobal(L, "loop");  /* function to be called */
	if (lua_pcall(L, 0, 0, 0) != 0)
		std::cout << "Error: " << lua_tostring(L, -1) << "\n";

	for (int i = 0; i < 0; i++) {
		std::cout << "Heap usage: " << lua_gc(L, LUA_GCCOUNT) << "K " << lua_gc(L, LUA_GCCOUNTB) << "B" << "\n";

		lua_getglobal(L, "loop");  /* function to be called */
		if (lua_pcall(L, 0, 0, 0) != 0)
			std::cout << "Error: " << lua_tostring(L, -1) << "\n";
	}

}


LUA_LIB_TIME_T _time = 0;
LUA_LIB_TIME_T LuaLib_GetTime() {
	return _time;
}



Ui_MainWindow	WINDOW;
QTimer			LOOP_TIMER;

std::list<InputNode>	INPUT_LIST;
InputComments			INPUT_COMMENTS;



static lua_State	*LUA = nullptr;

LuaInterfaceLib			LUA_INTERFACE_LIB;

LuaInterface_Can		LUA_INTERFACE_CAN;

LuaInterface_Ktrc_Trc3	LUA_INTERFACE_KTRC_TRC3;
LuaInterface_Ktrc_Ars	LUA_INTERFACE_KTRC_ARS;

LuaInterface_Mu_Ktrc_Ars	LUA_INTERFACE_MU_KTRC_ARS;


//LuaLib_KtrcInterface	LUA_INTERFACE;
LuaLib_Defs			LUA_DEFS;


void lua_stdout_hook(const char *c, size_t size) {
	QString out = c;

	WINDOW.output->moveCursor(QTextCursor::End);
	WINDOW.output->insertPlainText(out);
	WINDOW.output->moveCursor(QTextCursor::End);

	std::cout << out.toStdString().c_str();
}


/**
 * @brief	Инициализация интерпретатора Lua
 */
void lua_init() {
	// Удаление экземпляра интерпретатора
	if (LUA != nullptr)
		lua_close(LUA);

	// Создание экземпляра интерпретатора
	LUA = luaL_newstate();

	// Подключение базовых библиотек Lua
	luaL_openlibs(LUA);

	LUA_INTERFACE_LIB.InitLib(LUA);
	LUA_INTERFACE_LIB.AddInterface(&LUA_INTERFACE_CAN);
	LUA_INTERFACE_LIB.AddInterface(&LUA_INTERFACE_KTRC_ARS);
	LUA_INTERFACE_LIB.AddInterface(&LUA_INTERFACE_KTRC_TRC3);

	LUA_INTERFACE_LIB.AddInterface(&LUA_INTERFACE_MU_KTRC_ARS);

	// Добавление в экземпляр интерпретатора библиотеки-интерфейса
	//LUA_INTERFACE.InitLib(LUA);
	// Добавление в экземпляр интерпретатора библиотеки-объявлений
	LUA_DEFS.InitLib(LUA);
}

/**
 * @brief	Загрузка кода в интерпретатор
 *
 * @param	code - загружаемый код
 */
void lua_loadcode(const char *code) {
	std::string err = "";

	if (luaL_dostring(LUA, code) != LUA_OK) {
		err = err + "Error: " + lua_tostring(LUA, -1) + "\n";
		lua_stdout_hook(err.c_str(), err.size());;

		return;
	}

	// Вызов сборщика мусора
	lua_gc(LUA, LUA_GCCOLLECT);
	lua_gc(LUA, LUA_GCSTEP);
}

/**
 * @brief	Вызов функции в Lua
 *
 * @note	Вызов только функций без параметров
 *
 * @param	func - вызываемая функция
 */
void lua_call_func(const char *func) {
	std::string err = "";

	lua_getglobal(LUA, func);

	if (lua_isnil(LUA, -1)) {
		err = err + "Error: not found \"" + func + "()\" function\n";
		lua_stdout_hook(err.c_str(), err.size());
		return;
	}

	if (lua_pcall(LUA, 0, 0, 0) != 0) {
		err = err + "Error in \"" + func + "()\": " + lua_tostring(LUA, -1) + "\n";
		lua_stdout_hook(err.c_str(), err.size());
	}
}

/**
 * @brief	Вызов функции "setup" в lua
 */
void lua_call_setup() {
	lua_call_func("setup");
}

/**
 * @brief	Вызов функции "loop" в lua
 */
void lua_call_loop() {
	lua_call_func("loop");
}



void init_codeEditor() {
	QFont f = QFontDatabase::systemFont(QFontDatabase::FixedFont);
	WINDOW.codeEditor->setFont(f);

	auto *highlighter = new QSourceHighlite::QSourceHighliter(WINDOW.codeEditor->document());
	highlighter->setCurrentLanguage(QSourceHighlite::QSourceHighliter::CodeLua);

	QFontMetricsF fontMetrics(WINDOW.codeEditor->fontMetrics());
	WINDOW.codeEditor->setTabStopDistance(fontMetrics.horizontalAdvance(' ') * 4);
}




void update_state_tree(const QList<StateTreeNode*> *children) {
	QTreeWidgetItem *item;

	auto it = children->begin();

	for ( ; it != children->end(); ++it ) {
		StateTreeNode* node = *it;

		item = node->treeItem;

		if (node->value != nullptr) {
			if (node->isSignedNum)
				switch (node->numSize) {
					case sizeof(int8_t):
						item->setText(1, QString::number(*(int8_t*)(node->value)));
						break;

					case sizeof(int16_t):
						item->setText(1, QString::number(*(int16_t*)(node->value)));
						break;

					case sizeof(int32_t):
						item->setText(1, QString::number(*(int32_t*)(node->value)));
						break;

					default:
						break;
				}

			else if (node->isUnsignedNum)
				switch (node->numSize) {
					case sizeof(uint8_t):
						item->setText(1, QString::number(*(uint8_t*)(node->value)));
						break;

					case sizeof(uint16_t):
						item->setText(1, QString::number(*(uint16_t*)(node->value)));
						break;

					case sizeof(uint32_t):
						item->setText(1, QString::number(*(uint32_t*)(node->value)));
						break;

					default:
						break;
				}
		}

		update_state_tree(&node->children);
	}
}

void update_state_tree() {
	update_state_tree(&STATE_TREE_DATA);
}

void init_state_tree(QTreeWidgetItem *_parent = nullptr, const QList<StateTreeNode*> *_children = nullptr) {
	QTreeWidgetItem *item;

	if (_children == nullptr)
		_children = &STATE_TREE_DATA;

	auto it = _children->begin();

	for ( ; it != _children->end(); ++it ) {
		StateTreeNode* node = *it;

		if (_parent == nullptr)
			item = new QTreeWidgetItem(WINDOW.state);
		else
			item = new QTreeWidgetItem(_parent);

		node->treeItem = item;

		item->setText(0, node->name);

		init_state_tree(item, &node->children);
	}
}



void _set_inputs_table_node(InputNode *inNode, int row) {
	InputCommentNode inCommentNode;

	QTableWidgetItem *inItem;
	QSpinBox *inField;
	QLineEdit *inComment;

	inItem = new QTableWidgetItem();
	inField = new QSpinBox();
	inComment = new QLineEdit();

	if (inNode->value != nullptr) {
		if (inNode->isSignedNum)
			switch (inNode->numSize) {
				case sizeof(int8_t):
					inField->setValue(*(int8_t*)(inNode->value));
					break;

				case sizeof(int16_t):
					inField->setValue(*(int16_t*)(inNode->value));
					break;

				case sizeof(int32_t):
					inField->setValue(*(int32_t*)(inNode->value));
					break;

				default:
					break;
			}

		else if (inNode->isUnsignedNum)
			switch (inNode->numSize) {
				case sizeof(uint8_t):
					inField->setValue(*(uint8_t*)(inNode->value));
					break;

				case sizeof(uint16_t):
					inField->setValue(*(uint16_t*)(inNode->value));
					break;

				case sizeof(uint32_t):
					inField->setValue(*(uint32_t*)(inNode->value));
					break;

				default:
					break;
			}
	}

	if (!INPUT_COMMENTS.contains(inNode->name))
		INPUT_COMMENTS[inNode->name] = {0};

	inCommentNode = INPUT_COMMENTS[inNode->name];

	inComment->setText(inCommentNode.comment);
	inCommentNode.field = inComment;

	inItem->setText(inNode->name);
	WINDOW.inputs->setVerticalHeaderItem(row, inItem);
	WINDOW.inputs->setCellWidget(row, 0, inField);
	WINDOW.inputs->setCellWidget(row, 1, inComment);

	inNode->field = inField;
	INPUT_LIST.push_back(*inNode);

	INPUT_COMMENTS[inNode->name] = inCommentNode;
}


void init_inputs_table() {
	InputNode	inNode;

	for (auto it = INPUT_COMMENTS.begin(); it != INPUT_COMMENTS.end(); it++) {
		if (it->field != nullptr) {
			it->comment = it->field->text();
		}

		it->field = nullptr;
	}

	WINDOW.inputs->setRowCount(0);
	WINDOW.inputs->setRowCount(LUA_INTERFACE_CAN.canInput.size() + 2);

	INPUT_LIST.clear();

	int row = 0;

	inNode.name = "trc3Rec[1].tc";
	inNode.value = &LUA_INTERFACE_KTRC_TRC3.trc3Rec.rec[0].tc;
	inNode.isUnsignedNum = true;
	inNode.numSize = sizeof(LUA_INTERFACE_KTRC_TRC3.trc3Rec.rec[0].tc);
	_set_inputs_table_node(&inNode, 0);
	row++;

	inNode.name = "trc3Rec[2].tc";
	inNode.value = &LUA_INTERFACE_KTRC_TRC3.trc3Rec.rec[1].tc;
	inNode.isUnsignedNum = true;
	inNode.numSize = sizeof(LUA_INTERFACE_KTRC_TRC3.trc3Rec.rec[1].tc);
	_set_inputs_table_node(&inNode, 1);
	row++;

	for (auto it = LUA_INTERFACE_CAN.canInput.begin(); it != LUA_INTERFACE_CAN.canInput.end(); it++) {

		inNode.name = "can.input[" + QString::number(it->first) + "]";
		inNode.value = &it->second;
		inNode.isUnsignedNum = true;
		inNode.numSize = sizeof(it->second);
		_set_inputs_table_node(&inNode, row);

		row++;
	}
}

void update_inputs_table() {
	for (auto it = INPUT_LIST.begin(); it != INPUT_LIST.end(); it++) {
		if (it->value != nullptr) {
			if (it->isSignedNum)
				switch (it->numSize) {
					case sizeof(int8_t):
						*(int8_t*)(it->value) = it->field->value();
						break;

					case sizeof(int16_t):
						*(int16_t*)(it->value) = it->field->value();
						break;

					case sizeof(int32_t):
						*(int32_t*)(it->value) = it->field->value();
						break;

					default:
						break;
				}

			else if (it->isUnsignedNum)
				switch (it->numSize) {
					case sizeof(uint8_t):
						*(uint8_t*)(it->value) = it->field->value();
						break;

					case sizeof(uint16_t):
						*(uint16_t*)(it->value) = it->field->value();
						break;

					case sizeof(uint32_t):
						*(uint32_t*)(it->value) = it->field->value();
						break;

					default:
						break;
				}
		}
	}
}



void button_run() {
	if (WINDOW.runButton->isChecked())
		LOOP_TIMER.start(WINDOW.cycleMs->value());
	else
		LOOP_TIMER.stop();
}

void button_reset() {
	WINDOW.runButton->setChecked(false);
	button_run();

	lua_init();
	lua_loadcode(WINDOW.codeEditor->toPlainText().toStdString().c_str());
	lua_call_setup();

	update_state_tree();
	init_inputs_table();

	_time = 0;
}

void button_clearOutput() {
	WINDOW.output->setText("");
}

void timer_loop() {
	_time += WINDOW.cycleMs->value();

	update_inputs_table();
	lua_call_loop();
	update_state_tree();
}


void save_script() {
	QString filename = QFileDialog::getSaveFileName(nullptr, "Сохранение скрипта",
													"/",
													"Script (*.lua)");
	if (filename == "")
		return;

	QFile file(filename);
	if (file.open(QFile::WriteOnly))
		file.write(WINDOW.codeEditor->toPlainText().toUtf8());
}

void load_script() {
	QString filename = QFileDialog::getOpenFileName(nullptr, "Загрузка скрипта",
													"/",
													"Script (*.lua)");
	if (filename == "")
		return;

	QFile file(filename);
	if (file.open(QFile::ReadOnly | QFile::Text))
		WINDOW.codeEditor->setPlainText(file.readAll());
}



int main(int argc, char *argv[]) {
	QApplication a(argc, argv);

	QMainWindow		mainWindow;
	WINDOW.setupUi(&mainWindow);
	mainWindow.setWindowTitle("Lua interface GUI");

	init_codeEditor();

	init_state_tree();
	update_state_tree();


	auto *saveScript = new QAction("Сохранить Lua скрипт");
	auto *saveComments = new QAction("Сохранить комментарии входных значений");
	auto *loadScript = new QAction("Загрузить Lua скрипт");
	auto *loadComments = new QAction("Загрузить комментарии входных значений");

	QMenu *menu = WINDOW.menubar->addMenu("Файл");
	menu->addAction(saveScript);
	//menu->addAction(saveComments);
	menu->addAction(loadScript);
	//menu->addAction(loadComments);

	QPushButton::connect(WINDOW.resetButton, &QPushButton::released, button_reset);
	QPushButton::connect(WINDOW.runButton, &QPushButton::released, button_run);
	QPushButton::connect(WINDOW.clearOutput, &QPushButton::released, button_clearOutput);

	QTimer::connect(&LOOP_TIMER, &QTimer::timeout, timer_loop);

	QAction::connect(saveScript, &QAction::triggered, save_script);
	QAction::connect(loadScript, &QAction::triggered, load_script);


	lua_init();


	mainWindow.show();

	return QApplication::exec();
}
