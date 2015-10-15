#ifndef __VALUE_TRAITS__
#define __VALUE_TRAITS__
#include "shaker_define.h"
#include "shaker_type.h"

SHAKER_NS_START;

template<BaseType type = BaseType::BT_UNKNOWN>
struct value_traits {
	static_assert(type != BaseType::BT_UNKNOWN, "The type can not traits");
};

template<>
struct value_traits<BaseType::BT_VOID> {
	typedef void value_type;
};

template<>
struct value_traits<BaseType::BT_BOOL> {
	typedef bool value_type;
};

template<>
struct value_traits<BaseType::BT_CHAR> {
	typedef char value_type;
};
template<>
struct value_traits<BaseType::BT_BYTE> {
	typedef byte value_type;
};

template<>
struct value_traits<BaseType::BT_SHORT> {
	typedef short value_type;
};
template<>
struct value_traits<BaseType::BT_USHORT> {
	typedef ushort value_type;
};

template<>
struct value_traits<BaseType::BT_INT> {
	typedef int value_type;
};

template<>
struct value_traits<BaseType::BT_UINT> {
	typedef uint value_type;
};

template<>
struct value_traits<BaseType::BT_LONG> {
	typedef long value_type;
};

template<>
struct value_traits<BaseType::BT_ULONG> {
	typedef ulong value_type;
};

template<>
struct value_traits<BaseType::BT_LONGLONG> {
	typedef long long value_type;
};

template<>
struct value_traits<BaseType::BT_ULONGLONG> {
	typedef ulonglong value_type;
};

template<>
struct value_traits<BaseType::BT_FLOAT> {
	typedef float value_type;
};

template<>
struct value_traits<BaseType::BT_DOUBLE> {
	/*typedef double value_type;*/
};

template<>
struct value_traits<BaseType::BT_CLASS> {
	/*typedef class value_type;*/
};

template<>
struct value_traits<BaseType::BT_ENUM> {
	/*typedef enum value_type;*/
};

template<>
struct value_traits<BaseType::BT_UNION> {
	/*typedef union value_type;*/
};

template<>
struct value_traits<BaseType::BT_POINTER> {
	typedef void* value_type;
};





SHAKER_NS_END;
#endif