#ifndef __SHARED_PTR__
#define __SHARED_PTR__
#include "shaker_define.h"
#include <type_traits>

SHAKER_NS_START;

template<typename _pTy>
class shared_ptr{
	static_assert(std::is_pointer<_pTy>::value, "The type is not pointer!");
	
public:
	typedef typename std::remove_pointer<_pTy>::type		
												type;			//去指针类型
	typedef _pTy								pointer;		//指针类型

//构造函数
public:
	shared_ptr() 
		:m_pPointer(nullptr), m_uReferenceCount(nullptr)
	{};

	shared_ptr(const shared_ptr& ptr) 
		:m_pPointer(ptr.m_pPointer), m_uReferenceCount(ptr.m_uReferenceCount)
	{
		if (m_uReferenceCount)
			++*m_uReferenceCount;
	};

	shared_ptr(shared_ptr&& ptr) 
		:m_pPointer(ptr.m_pPointer), m_uReferenceCount(ptr.m_uReferenceCount)
	{
		ptr.m_pPointer = nullptr;
		ptr.m_uReferenceCount = nullptr;
	};

	shared_ptr(_pTy p) 
		:m_pPointer(p), m_uReferenceCount(nullptr)
	{
		if (m_pPointer)
			m_uReferenceCount = new size_t(1);
	};

	~shared_ptr() {
		clear();
	};

	bool operator==(const shared_ptr<_pTy>& ptr) const {
		return m_pPointer == ptr.m_pPointer;
	}
	bool operator!=(const shared_ptr<_pTy>& ptr) const {
		return m_pPointer != ptr.m_pPointer;
	};
//防止构造
	bool operator==(const _pTy ptr) const {
		return m_pPointer == ptr;
	}
	bool operator!=(const _pTy ptr) const {
		return m_pPointer != ptr;
	};

	const shared_ptr<_pTy>& operator=(const shared_ptr<_pTy>& ptr) {
		clear();
		m_pPointer = ptr.m_pPointer;
		m_uReferenceCount = ptr.m_uReferenceCount;
		if (m_uReferenceCount)
			++*m_uReferenceCount;

		return *this;
	};

//访问运算符重载
public:
	_pTy			
	operator->() { 
		return m_pPointer; 
	}
	const _pTy		
	operator->() const { 
		return m_pPointer; 
	};
	typename type&	
	operator*() {
		return *m_pPointer;
	};
	typename const type&
	operator*() const {
		return *m_pPointer;
	};

//API
public:
	bool is_nullptr() const {
		return m_pPointer == nullptr;
	};

	void clear() {
		if (m_uReferenceCount && --*m_uReferenceCount == 0)
		{
			SHAKER_SAFE_DELETE(m_pPointer);
			SHAKER_SAFE_DELETE(m_uReferenceCount);
		}
	};

	inline size_t getReferenceCount() const {
		if (m_uReferenceCount)
			return *m_uReferenceCount;
		return 0;
	};

private:
	_pTy	m_pPointer;
	size_t*	m_uReferenceCount;
};

SHAKER_NS_END;
#endif