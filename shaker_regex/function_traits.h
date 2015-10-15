#ifndef __FUNCTION_TRAITS__
#define __FUNCTION_TRAITS__
#include "shaker_define.h"
#include <vector>
#include "shaker_type.h"

SHAKER_NS_START;

#define S_Function_Traits(func) shaker::function_traits<decltype(&func)>

enum class CallType
	:unsigned int
{
	CT_CDECL = 0,
	CT_STDCALL,
	CT_FASTCALL,
	CT_VECTORCALL,
	CT_THISCALL,
};


template<typename _fnTy>
struct _function_traits{
	typedef _fnTy function_type;
};

template<typename _fnTy>
struct _calltype_traits{
	typedef _fnTy function_type;
};

template<typename _retTy, typename... _argsTy>
struct _dynamic_traits{

};

template<typename _argTy, uint pos = 0>
struct _param_traits_once{
};

/**
*	参数萃取器:
*	_argTy:参数类型
*	pos:表明是第几个参数
*	注意: 最大支持14个参数
*/
template<typename _argTy>
struct _param_traits_once<_argTy, 1>{
	typedef _argTy arg1_type;
};

template<typename _argTy>
struct _param_traits_once<_argTy, 2>{
	typedef _argTy arg2_type;
};

template<typename _argTy>
struct _param_traits_once<_argTy, 3>{
	typedef _argTy arg3_type;
};

template<typename _argTy>
struct _param_traits_once<_argTy, 4>{
	typedef _argTy arg4_type;
};

template<typename _argTy>
struct _param_traits_once<_argTy, 5>{
	typedef _argTy arg5_type;
};

template<typename _argTy>
struct _param_traits_once<_argTy, 6>{
	typedef _argTy arg6_type;
};

template<typename _argTy>
struct _param_traits_once<_argTy, 7>{
	typedef _argTy arg7_type;
};

template<typename _argTy>
struct _param_traits_once<_argTy, 8>{
	typedef _argTy arg8_type;
};

template<typename _argTy>
struct _param_traits_once<_argTy, 9>{
	typedef _argTy arg9_type;
};

template<typename _argTy>
struct _param_traits_once<_argTy, 10>{
	typedef _argTy arg10_type;
};

template<typename _argTy>
struct _param_traits_once<_argTy, 11>{
	typedef _argTy arg11_type;
};

template<typename _argTy>
struct _param_traits_once<_argTy, 12>{
	typedef _argTy arg12_type;
};

template<typename _argTy>
struct _param_traits_once<_argTy, 13>{
	typedef _argTy arg13_type;
};

template<typename _argTy>
struct _param_traits_once<_argTy, 14>
{
	typedef _argTy arg14_type;
};

template<typename _argTy,typename... _argsTy>
struct _param_traits_list
	:public _param_traits_once<_argTy, sizeof...(_argsTy) + 1>,
	public _param_traits_list<_argsTy...>
{

};

template<typename _argTy>
struct _param_traits_list<_argTy>
	:public _param_traits_once<_argTy, 1>
{

};



/**
*	函数特性萃取器:
*	function_type:	函数指针类型
*	param_size:		参数个数
*	return_type:	返回值类型
*	param_types[]:	参数类型列表
*	使用方法function_traits<decltype(函数指针)>::(得到参数个数，返回值类型，参数类型列表)
*/
template<typename _retTy, typename... _argsTy>
struct _function_traits<_retTy(*)(_argsTy...)>
{
	typedef _retTy			return_type;


	const static size_t		param_size = sizeof...(_argsTy);
	const static BaseType	return_type_val = _basetype_traits<_retTy>::value_enum;
	const static BaseType	param_types_val[param_size];
};

template<typename _retTy, typename... _argsTy>
const BaseType
_function_traits<_retTy(*)(_argsTy...)>::
param_types_val[_function_traits<_retTy(*)(_argsTy...)>::param_size] = {
	_basetype_traits<_argsTy>::value_enum...
};

template<typename _targetTy, typename _retTy, typename... _argsTy>
struct _function_traits<_retTy(_targetTy::* )(_argsTy...)>
{
	typedef _retTy			return_type;


	const static size_t		param_size = sizeof...(_argsTy);
	const static BaseType	return_type_val = _basetype_traits<_retTy>::value_enum;
	const static BaseType	param_types_val[param_size];
};

template<typename _targetTy, typename _retTy, typename... _argsTy>
const BaseType
_function_traits<_retTy(_targetTy::* )(_argsTy...)>::
param_types_val[_function_traits<_retTy(*)(_argsTy...)>::param_size] = {
	_basetype_traits<_argsTy>::value_enum...
};




/**
*	静态全局函数
*	
*/
template<typename _retTy, typename... _argsTy>
struct _calltype_traits<_retTy(__cdecl *)(_argsTy...)>
	:public _function_traits<_retTy(*)(_argsTy...)>
{
	const static CallType call_type = CallType::CT_CDECL;
};

template<typename _retTy, typename... _argsTy>
struct _calltype_traits<_retTy(__stdcall *)(_argsTy...)>
	:public _function_traits<_retTy(*)(_argsTy...)>
{
	const static CallType call_type = CallType::CT_STDCALL;
};

template<typename _retTy, typename... _argsTy>
struct _calltype_traits<_retTy(__fastcall *)(_argsTy...)>
	:public _function_traits<_retTy(*)(_argsTy...)>
{
	const static CallType call_type = CallType::CT_FASTCALL;
};

template<typename _retTy, typename... _argsTy>
struct _calltype_traits<_retTy(__vectorcall *)(_argsTy...)>
	:public _function_traits<_retTy(*)(_argsTy...)>
{
	const static CallType call_type = CallType::CT_VECTORCALL;
};


/**
*	动态成员函数特性萃取
*/
template<typename _retTy, typename... _argsTy>
struct _dynamic_traits<_retTy(*)(_argsTy...)>{
	const static bool is_member = false;
	const static bool is_constant = false;
};

template<typename _targetTy, typename _retTy, typename... _argsTy>
struct _dynamic_traits<_retTy(_targetTy::*)(_argsTy...)>
	:public _function_traits<_retTy(*)(_argsTy...)>
{
	typedef _targetTy	target_type;
	const static bool is_member = true;
	const static bool is_constant = false;
};

template<typename _targetTy, typename _retTy, typename... _argsTy>
struct _dynamic_traits<_retTy(_targetTy::*)(_argsTy...) const>
	:public _function_traits<_retTy(*)(_argsTy...)>
{
	typedef _targetTy	target_type;
	const static bool is_member = true;
	const static bool is_constant = true;
};

//函数参数萃取


//最终函数萃取
template<typename _fnTy>
struct function_traits
	:public _calltype_traits<_fnTy>, 
	public _dynamic_traits<_fnTy>
{
	typedef _fnTy	function_type;
};


SHAKER_NS_END;
#endif