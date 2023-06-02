#ifndef __VIRTUAL_MACHINE_HPP__
#define __VIRTUAL_MACHINE_HPP__


#include <list>
#include <string>


// Размер команды байткода (1 байт, 2 байта, ...)
#define VM_BYTECODE_COMMAND_SIZE	1

// Количество операторов
#define VM_OPERATOR_NUMBER			50		// С запасом, по факту операторов 37

// Количество переменных для взаимодействия (Входы/Выходы)
#define VM_IO_NUMBER				(((1 << (8 * VM_BYTECODE_COMMAND_SIZE)) - 1) \
									- VM_OPERATOR_NUMBER)


/*
 * Команды со значениями < VM_IO_NUMBER считаются номерами входов/выходов
 *
 * Команды со значениями >= VM_IO_NUMBER считаются операторами в соответствии с vm::TOperator
 */


namespace vm {


// Приоритеты определяются на этапе компиляции


// Операторы и их коды
typedef enum {
	// Служебные операторы
	OPERATOR_END			= 0x00,			//	';'		Переход к следующему выражению

	// Операторы с присваиванием

	OPERATOR_ASSIGN			= 0x05,			//	'='		Присваивание

	/// Побитовые операции
	OPERATOR_AND_ASSIGN		= 0x06,			//	'&='	Побитовое И с присваиванием
	OPERATOR_OR_ASSIGN		= 0x07,			//	'|='	Побитовое ИЛИ с присваиванием
	OPERATOR_XOR_ASSIGN		= 0x08,			//	'^='	Побитовое ИСКЛЮЧАЮЩЕЕ ИЛИ с присваиванием

	/// Операторы побитового сдвига
	OPERATOR_LSHIFT_ASSIGN	= 0x09,			//	'<<='	Сдвиг влево с присваиванием
	OPERATOR_RSHIFT_ASSIGN	= 0x0a,			//	'>>='	Сдвиг вправо с присваиванием

	/// Арифметические операторы
	OPERATOR_ADD_ASSIGN		= 0x0b,			//	'+='	_
	OPERATOR_SUB_ASSIGN		= 0x0c,			//	'-='	_
	OPERATOR_MULT_ASSIGN	= 0x0d,			//	'*='	_
	OPERATOR_DIV_ASSIGN		= 0x0e,			//	'/='	_
	OPERATOR_MOD_ASSIGN		= 0x0f,			//	'%='	_

	// Операторы

	/// Логические операторы
	OPERATOR_LOGIC_NOT		= 0x10,			//	'!'		_
	OPERATOR_LOGIC_AND		= 0x11,			//	'&&'	_
	OPERATOR_LOGIC_OR		= 0x12,			//	'||'	_

	/// Побитовые операторы
	OPERATOR_NOT			= 0x13,			//	'~'		_
	OPERATOR_AND			= 0x14,			//	'&'		_
	OPERATOR_OR				= 0x15,			//	'|'		_
	OPERATOR_XOR			= 0x16,			//	'^'		_

	/// Операторы побитового сдвига
	OPERATOR_LSHIFT			= 0x17,			//	'<<'	_
	OPERATOR_RSHIFT			= 0x18,			//	'>>'	_

	/// Операторы сравнения
	OPERATOR_EQUAL			= 0x19,			//	'=='	_
	OPERATOR_NOT_EQUAL		= 0x1a,			//	'!='	_
	OPERATOR_GREATER		= 0x1b,			//	'>'		_
	OPERATOR_LESS			= 0x1c,			//	'<'		_
	OPERATOR_GREATER_EQUAL	= 0x1d,			//	'>='	_
	OPERATOR_LESS_EQUAL		= 0x1e,			//	'<='	_

	/// Арифметические операторы
	OPERATOR_ADD			= 0x1f,			//	'+'		_
	OPERATOR_SUB			= 0x20,			//	'-'		_
	OPERATOR_MULT			= 0x21,			//	'*'		_
	OPERATOR_DIV			= 0x22,			//	'/'		_
	OPERATOR_MOD			= 0x23,			//	'%'		_
	OPERATOR_POW			= 0x24,			//	'**'	_

} TOperator;





}




#endif /* __VIRTUAL_MACHINE_HPP__ */