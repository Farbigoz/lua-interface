/********************************************************************************
** Form generated from reading UI file 'windownquTTa.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef WINDOWNQUTTA_H
#define WINDOWNQUTTA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QSplitter *splitter;
    QFrame *workSpace;
    QGridLayout *gridLayout_4;
    QSplitter *splitter_2;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QTableWidget *inputs;
    QFrame *frame_3;
    QGridLayout *gridLayout;
    QTextEdit *codeEditor;
    QLabel *label_4;
    QFrame *frame_2;
    QGridLayout *gridLayout_3;
    QTreeWidget *state;
    QLabel *label_3;
    QPushButton *resetButton;
    QLabel *label;
    QSpinBox *cycleMs;
    QPushButton *runButton;
    QFrame *debug;
    QHBoxLayout *horizontalLayout_3;
    QTextEdit *output;
    QPushButton *clearOutput;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(971, 724);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setFrameShape(QFrame::NoFrame);
        splitter->setFrameShadow(QFrame::Plain);
        splitter->setLineWidth(2);
        splitter->setMidLineWidth(0);
        splitter->setOrientation(Qt::Vertical);
        splitter->setOpaqueResize(true);
        splitter->setHandleWidth(5);
        splitter->setChildrenCollapsible(true);
        workSpace = new QFrame(splitter);
        workSpace->setObjectName(QString::fromUtf8("workSpace"));
        workSpace->setFrameShape(QFrame::StyledPanel);
        workSpace->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(workSpace);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        splitter_2 = new QSplitter(workSpace);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        frame = new QFrame(splitter_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_2, 0, 0, 1, 2);

        inputs = new QTableWidget(frame);
        if (inputs->columnCount() < 2)
            inputs->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        inputs->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        inputs->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        inputs->setObjectName(QString::fromUtf8("inputs"));
        inputs->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        inputs->setAutoScroll(false);
        inputs->setEditTriggers(QAbstractItemView::NoEditTriggers);
        inputs->setTabKeyNavigation(false);
        inputs->setProperty("showDropIndicator", QVariant(true));
        inputs->setDragDropOverwriteMode(false);
        inputs->setWordWrap(false);
        inputs->setCornerButtonEnabled(false);
        inputs->horizontalHeader()->setCascadingSectionResizes(false);
        inputs->horizontalHeader()->setMinimumSectionSize(39);
        inputs->horizontalHeader()->setDefaultSectionSize(80);
        inputs->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        inputs->horizontalHeader()->setStretchLastSection(true);
        inputs->verticalHeader()->setCascadingSectionResizes(false);
        inputs->verticalHeader()->setMinimumSectionSize(23);
        inputs->verticalHeader()->setDefaultSectionSize(25);
        inputs->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        inputs->verticalHeader()->setStretchLastSection(false);

        gridLayout_2->addWidget(inputs, 1, 0, 1, 2);

        splitter_2->addWidget(frame);
        frame_3 = new QFrame(splitter_2);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        codeEditor = new QTextEdit(frame_3);
        codeEditor->setObjectName(QString::fromUtf8("codeEditor"));

        gridLayout->addWidget(codeEditor, 1, 0, 1, 1);

        label_4 = new QLabel(frame_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        splitter_2->addWidget(frame_3);
        frame_2 = new QFrame(splitter_2);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        state = new QTreeWidget(frame_2);
        state->setObjectName(QString::fromUtf8("state"));
        state->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
        state->setProperty("showDropIndicator", QVariant(true));
        state->setSelectionMode(QAbstractItemView::SingleSelection);
        state->header()->setCascadingSectionResizes(false);
        state->header()->setDefaultSectionSize(140);
        state->header()->setProperty("showSortIndicator", QVariant(false));

        gridLayout_3->addWidget(state, 1, 0, 1, 1);

        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_3, 0, 0, 1, 1);

        splitter_2->addWidget(frame_2);

        gridLayout_4->addWidget(splitter_2, 0, 0, 1, 4);

        resetButton = new QPushButton(workSpace);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));

        gridLayout_4->addWidget(resetButton, 1, 0, 1, 1);

        label = new QLabel(workSpace);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label, 1, 1, 1, 1);

        cycleMs = new QSpinBox(workSpace);
        cycleMs->setObjectName(QString::fromUtf8("cycleMs"));
        cycleMs->setMinimum(1);
        cycleMs->setMaximum(10000);
        cycleMs->setSingleStep(100);
        cycleMs->setValue(400);

        gridLayout_4->addWidget(cycleMs, 1, 2, 1, 1);

        runButton = new QPushButton(workSpace);
        runButton->setObjectName(QString::fromUtf8("runButton"));
        runButton->setCheckable(true);
        runButton->setAutoDefault(false);
        runButton->setFlat(false);

        gridLayout_4->addWidget(runButton, 1, 3, 1, 1);

        splitter->addWidget(workSpace);
        debug = new QFrame(splitter);
        debug->setObjectName(QString::fromUtf8("debug"));
        debug->setSizeIncrement(QSize(0, 0));
        debug->setBaseSize(QSize(0, 0));
        debug->setFrameShape(QFrame::StyledPanel);
        debug->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(debug);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        output = new QTextEdit(debug);
        output->setObjectName(QString::fromUtf8("output"));
        output->setUndoRedoEnabled(false);
        output->setReadOnly(true);

        horizontalLayout_3->addWidget(output);

        splitter->addWidget(debug);

        verticalLayout_3->addWidget(splitter);

        clearOutput = new QPushButton(centralwidget);
        clearOutput->setObjectName(QString::fromUtf8("clearOutput"));

        verticalLayout_3->addWidget(clearOutput);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 971, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        runButton->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\242\320\260\320\261\320\273\320\270\321\206\320\260 \320\262\321\205\320\276\320\264\320\275\321\213\321\205 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem = inputs->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = inputs->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\274\320\274\320\265\320\275\321\202\320\260\321\200\320\270\320\271", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Lua \321\201\320\272\321\200\320\270\320\277\321\202", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = state->headerItem();
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("MainWindow", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("MainWindow", "\320\237\320\276\320\273\320\265", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\224\320\265\321\200\320\265\320\262\320\276 \320\262\321\213\321\205\320\276\320\264\320\275\321\213\321\205 \320\267\320\260\321\207\320\265\320\275\320\270\320\271", nullptr));
        resetButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\267\320\260\320\277\321\203\321\201\320\272 \321\201\320\272\321\200\320\270\320\277\321\202\320\260 / \320\237\321\200\320\270\320\274\320\265\320\275\320\270\320\265 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320\271 \321\201\320\272\321\200\320\270\320\277\321\202\320\260", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\270\320\276\320\264 \321\200\320\260\320\261\320\276\321\207\320\265\320\263\320\276 \321\206\320\270\320\272\320\273\320\260 (\320\274\321\201):", nullptr));
        runButton->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\321\203\321\201\320\272", nullptr));
        clearOutput->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \320\262\321\213\320\262\320\276\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // WINDOWNQUTTA_H
