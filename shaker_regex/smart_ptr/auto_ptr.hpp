#ifndef __AUTO_PTR__
#define __AUTO_PTR__
#include <type_traits>
#include "../shaker_define.h"
#include "../nocopy.h"

SHAKER_NS_START;

template<typename _pTy>
class auto_ptr
	: nocopy
{
	static_assert(std::is_pointer<_pTy>::value, "The type is not pointer!");
public:
	typedef typename std::remove_pointer<_pTy>::type	
												type;
	typedef _pTy								pointer;
public:
	auto_ptr(_pTy p)
		:m_pPointer(p)
	{};
	~auto_ptr() {
		SHAKER_SAFE_DELETE(m_pPointer);
	};

	_pTy			operator->() { return m_pPointer; }
	const _pTy		operator->() const { return m_pPointer; };
private:
	_pTy		m_pPointer;
};

SHAKER_NS_END;
#endif