#ifndef __WEAK_PTR__
#define __WEAK_PTR__
#include "../shaker_define.h"
#include "shared_ptr.hpp"

SHAKER_NS_START;

/*
	weak_ptr: 
	用于观测 shared_ptr指针的引用计数,并提供lock()创建一个shared_ptr
*/
template<typename _pTy>
class weak_ptr{
	static_assert(std::is_pointer<_pTy>::value, "The type is not pointer!");
public:
	typedef typename shared_ptr<_pTy>			shared_type;
	typedef typename shared_ptr<_pTy>::type		type;
	typedef typename shared_ptr<_pTy>::pointer	pointer;
	
	weak_ptr() 
		:m_pSharedPtr(nullptr)
	{};
	weak_ptr(shared_ptr<_pTy>& s_ptr)
		:m_pSharedPtr(&s_ptr)
	{};
	~weak_ptr() {};


//获得引用
	size_t	use_count() const {
		if (!m_pSharedPtr)
			return 0;
		return m_pSharedPtr->getReferenceCount();
	};

//是否为空
	bool expired() const {
		if (!m_pSharedPtr)
			return false;
		return m_pSharedPtr->getReferenceCount() == 0;
	};

//创建新的智能指针
	shared_ptr<_pTy> lock() const {
		if (expired())
			return shared_ptr<_pTy>();
		return *m_pSharedPtr;
	};

//更换观测的智能指针
	void observe(shared_ptr<_pTy>* s_ptr) {
		m_pSharedPtr = s_ptr;
	};

private:
	shared_ptr<_pTy>*		m_pSharedPtr;
};

SHAKER_NS_END;
#endif