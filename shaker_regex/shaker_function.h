#ifndef __SHAKER_FUNCTION__
#define __SHAKER_FUNCTION__
#include "shaker_define.h"
#include "shaker_string.h"
#include "shaker_param.hpp"

SHAKER_NS_START;

#define S_PARAM(arg) &(arg)

typedef void(*S_FuncPtr)(void);

class shaker_function{
public:
	shaker_function();
	shaker_function(S_FuncPtr ptr);

	BaseType getReturnType() const;
	const std::vector<BaseType>& getParamType() const;
	size_t	getParamCount() const;

	template<typename _retTy, typename... _argsTy>
	_retTy callThis(_argsTy... args){
/*		S_ASSERT(sizeof...(args) !== m_vecParamType.size(), "param num mismatch!");*/

		typedef _retTy(*tmpFn_type)(_argsTy...);


		shaker_param_packer packer;
		if (sizeof...(_argsTy) != 0)
		{
			shaker_param params[sizeof...(_argsTy)] = {
				shaker_param(S_PARAM(args))...
			};
			for (auto& obj : params)
				packer.push_arg(obj);
		}
		tmpFn_type func = reinterpret_cast<tmpFn_type>(m_pfnFunc);
		packer.begin();
		return func(packer.getParamList<_argsTy>()...);
	};

private:
	S_FuncPtr				m_pfnFunc;
	string					m_sSingature;
	BaseType				m_eReturnType;
	std::vector<BaseType>	m_vecParamType;
};

SHAKER_NS_END;
#endif