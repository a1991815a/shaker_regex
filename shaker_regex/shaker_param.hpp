#ifndef __SHAKER_PARAM__
#define __SHAKER_PARAM__
#include "shaker_define.h"
#include <vector>
#include "shaker_type.h"

SHAKER_NS_START;

/**
*	参数对象
*	
*/
class shaker_param{
public:
	shaker_param()
		:m_arg(nullptr), m_size(0), m_type(BaseType::BT_UNKNOWN)
	{};
	template<typename _argTy>
	shaker_param(_argTy* arg)
		:m_arg(arg),
		m_size(sizeof(_argTy)),
		m_type(basetype_traits<_argTy>::value_enum)
	{

	};

	const shaker_param& operator=(const shaker_param& obj){
		m_arg = obj.m_arg;
		m_size = obj.m_size;
		m_type = obj.m_type;
	};

	template<typename _argTy>
	const shaker_param& operator=(const _argTy* arg){
		m_arg = arg;
		m_size = sizeof(_argTy);
		m_type = basetype_traits<_argTy>::value_enum;
	};

	template<_argTy>
	_argTy& castTo(){
		return *reinterpret_cast<_argTy*>(m_arg);
	};

	template<_argTy>
	const _argTy& castTo() const{
		return *reinterpret_cast<const _argTy*>(m_arg);
	};

	void check_type(BaseType type) const{
		S_ASSERT(type == m_type, "param type is error!");
	};

private:
	void*		m_arg;
	uint		m_size;
	BaseType	m_type;
};


/**
*参数打包器
*
*/
class shaker_param_packer{
public:
	void push_arg(shaker_param& param){
		m_vecParamList.push_back(param);
	};

	shaker_param pop_arg(){
		shaker_param param = m_vecParamList.back();
		m_vecParamList.pop_back();
		return param;
	};

	bool empty() const{
		return m_vecParamList.empty();
	};
	uint getParamCount() const{
		return m_vecParamList.size();
	};
private:
	std::vector<shaker_param> m_vecParamList;
};


SHAKER_NS_END;

#endif