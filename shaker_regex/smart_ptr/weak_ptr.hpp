#ifndef __WEAK_PTR__
#define __WEAK_PTR__
#include "../shaker_define.h"
#include "shared_ptr.hpp"

SHAKER_NS_START;

/*
	weak_ptr: 
	���ڹ۲� shared_ptrָ������ü���,���ṩlock()����һ��shared_ptr
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


//�������
	size_t	use_count() const {
		if (!m_pSharedPtr)
			return 0;
		return m_pSharedPtr->getReferenceCount();
	};

//�Ƿ�Ϊ��
	bool expired() const {
		if (!m_pSharedPtr)
			return false;
		return m_pSharedPtr->getReferenceCount() == 0;
	};

//�����µ�����ָ��
	shared_ptr<_pTy> lock() const {
		if (expired())
			return shared_ptr<_pTy>();
		return *m_pSharedPtr;
	};

//�����۲������ָ��
	void observe(shared_ptr<_pTy>* s_ptr) {
		m_pSharedPtr = s_ptr;
	};

private:
	shared_ptr<_pTy>*		m_pSharedPtr;
};

SHAKER_NS_END;
#endif