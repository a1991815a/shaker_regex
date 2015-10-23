#ifndef __BASETYPE_TRAITS__
#define __BASETYPE_TRAITS__
#include "../shaker_define.h"
#include "../shaker_type.h"
#include "../shaker_string.h"
#include <type_traits>
#include "../shaker_assert.h"
#include "../shaker_debug.h"

SHAKER_NS_START;

/**
*	类型萃取器:
*	使用方式:		shaker::value_traits<类型>::value_enum; 类型枚举
*	注意:			不支持引用
*/

template<typename _Ty, 
	bool isClass = __is_class(_Ty), 
	bool isEnum = __is_enum(_Ty),
	bool isUnion = __is_union(_Ty)
>
struct _basetype_traits
{
	typedef _Ty value_type;
	const static BaseType value_enum = BaseType::BT_UNKNOWN;
	const static bool is_constant = true;
};

template<typename _Ty>
struct _basetype_traits<_Ty, true, false, false>
{
	typedef _Ty value_type;
	const static BaseType value_enum = BaseType::BT_CLASS;
};

template<typename _Ty>
struct _basetype_traits<_Ty, false, true, false>
{
	typedef _Ty value_type;
	const static BaseType value_enum = BaseType::BT_ENUM;
};

template<typename _Ty>
struct _basetype_traits<_Ty, false, false, true>
{
	typedef _Ty value_type;
	const static BaseType value_enum = BaseType::BT_UNION;
};


template<typename _Ty>
struct _basetype_traits<_Ty*, false, false, false> {
	typedef _Ty nopointer_type;
	typedef _Ty* value_type;
	const static BaseType value_enum = BaseType::BT_POINTER;
};

template<>
struct _basetype_traits<void, false, false, false> {
	typedef bool value_type;
	const static BaseType value_enum = BaseType::BT_VOID;
};

template<>
struct _basetype_traits<bool, false, false, false> {
	typedef bool value_type;
	const static BaseType value_enum = BaseType::BT_BOOL;
};

template<>
struct _basetype_traits<char, false, false, false> {
	typedef char value_type;
	const static BaseType value_enum = BaseType::BT_BOOL;
};

template<>
struct _basetype_traits<byte, false, false, false> {
	typedef byte value_type;
	const static BaseType value_enum = BaseType::BT_BYTE;
};

template<>
struct _basetype_traits<short, false, false, false> {
	typedef short value_type;
	const static BaseType value_enum = BaseType::BT_SHORT;
};

template<>
struct _basetype_traits<ushort, false, false, false> {
	typedef ushort value_type;
	const static BaseType value_enum = BaseType::BT_USHORT;
};

template<>
struct _basetype_traits<int, false, false, false> {
	typedef int value_type;
	const static BaseType value_enum = BaseType::BT_INT;
};

template<>
struct _basetype_traits<uint, false, false, false> {
	typedef uint value_type;
	const static BaseType value_enum = BaseType::BT_UINT;
};

template<>
struct _basetype_traits<long, false, false, false> {
	typedef long value_type;
	const static BaseType value_enum = BaseType::BT_LONG;
};

template<>
struct _basetype_traits<ulong, false, false, false> {
	typedef ulong value_type;
	const static BaseType value_enum = BaseType::BT_ULONG;
};

template<>
struct _basetype_traits<long long, false, false, false> {
	typedef long long value_type;
	const static BaseType value_enum = BaseType::BT_LONGLONG;
};


template<>
struct _basetype_traits<ulonglong, false, false, false> {
	typedef ulonglong value_type;
	const static BaseType value_enum = BaseType::BT_ULONGLONG;
};

template<>
struct _basetype_traits<float, false, false, false> {
	typedef float value_type;
	const static BaseType value_enum = BaseType::BT_FLOAT;
};

template<>
struct _basetype_traits<double, false, false, false> {
	typedef double value_type;
	const static BaseType value_enum = BaseType::BT_DOUBLE;
};

template<typename _Ty>
struct basetype_traits
	:public _basetype_traits<_Ty>
{
	const static bool is_constant = false;
};


template<typename _Ty>
struct basetype_traits<const _Ty>
	:public _basetype_traits<_Ty>
{
	const static bool is_constant = true;
};

#if defined(_DEBUG)
#define DEBUG_BASETYPE(__basetype) shaker::debug_basetype(__basetype)
#define DEBUG_BASETYPE_ONCE(__basetype, __str) \
case __basetype:		\
__str = #__basetype;	\
break

void debug_basetype(BaseType type){
	std::string out_text;
	switch (type)
	{
		DEBUG_BASETYPE_ONCE(BaseType::BT_UNKNOWN, out_text);
		DEBUG_BASETYPE_ONCE(BaseType::BT_BOOL, out_text);
		DEBUG_BASETYPE_ONCE(BaseType::BT_CHAR, out_text);
		DEBUG_BASETYPE_ONCE(BaseType::BT_BYTE, out_text);
		DEBUG_BASETYPE_ONCE(BaseType::BT_SHORT, out_text);
		DEBUG_BASETYPE_ONCE(BaseType::BT_USHORT, out_text);
		DEBUG_BASETYPE_ONCE(BaseType::BT_INT, out_text);
		DEBUG_BASETYPE_ONCE(BaseType::BT_UINT, out_text);
		DEBUG_BASETYPE_ONCE(BaseType::BT_LONG, out_text);
		DEBUG_BASETYPE_ONCE(BaseType::BT_ULONG, out_text);
		DEBUG_BASETYPE_ONCE(BaseType::BT_LONGLONG, out_text);
		DEBUG_BASETYPE_ONCE(BaseType::BT_ULONGLONG, out_text);
		DEBUG_BASETYPE_ONCE(BaseType::BT_FLOAT, out_text);
		DEBUG_BASETYPE_ONCE(BaseType::BT_DOUBLE, out_text);
		DEBUG_BASETYPE_ONCE(BaseType::BT_POINTER, out_text);
		DEBUG_BASETYPE_ONCE(BaseType::BT_VOID, out_text);
		DEBUG_BASETYPE_ONCE(BaseType::BT_CLASS, out_text);
		DEBUG_BASETYPE_ONCE(BaseType::BT_ENUM, out_text);
		DEBUG_BASETYPE_ONCE(BaseType::BT_UNION, out_text);
	default:
		S_ASSERT(false, "Type is error!");
	}
	SHAKER_DEBUG(out_text.c_str());
};

#else
#define DEBUG_BASETYPE(__basetype) 
#endif

SHAKER_NS_END;
#endif