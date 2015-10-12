#ifndef __SHAKER_STRING__
#define __SHAKER_STRING__
#include "shaker_define.h"
#include <string>

SHAKER_NS_START;

typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;
typedef unsigned long long ulonglong;
#if defined(_Double)
typedef double real;
#else
typedef float real;
#endif

class shaker_string
	: public std::string{
public:
	typedef std::string::_Myt			_Myt;
	typedef std::string					_Mybase;
	typedef std::string::value_type		_Elem;
//构造函数
public:
	shaker_string() _NOEXCEPT;
	shaker_string(const _Myt& _Right);
	shaker_string(const _Myt& _Right, const _Alloc& _Al);
	explicit shaker_string(const _Alloc& _Al) _NOEXCEPT;
	shaker_string(const _Myt& _Right, size_type _Roff,
		size_type _Count = npos);
	shaker_string(const _Myt& _Right, size_type _Roff, size_type _Count,
		const _Alloc& _Al);
	shaker_string(const _Elem *_Ptr, size_type _Count);
	shaker_string(const _Elem *_Ptr, size_type _Count, const _Alloc& _Al);
	shaker_string(const _Elem *_Ptr);
	shaker_string(const _Elem *_Ptr, const _Alloc& _Al);
	shaker_string(size_type _Count, _Elem _Ch);
	shaker_string(size_type _Count, _Elem _Ch, const _Alloc& _Al);
	template<class _Iter,
	class = typename enable_if<_Is_iterator<_Iter>::value,
		void>::type>
		shaker_string(_Iter _First, _Iter _Last, const _Alloc& _Al = _Alloc()) 
			:_Mybase(_First, _Last, _Al)
	{};

//新建的构造函数
public:
	shaker_string(bool b) _NOEXCEPT;
	shaker_string(char c) _NOEXCEPT;
	shaker_string(byte b) _NOEXCEPT;
	shaker_string(short sh) _NOEXCEPT;
	shaker_string(ushort ush) _NOEXCEPT;
	shaker_string(int i) _NOEXCEPT;
	shaker_string(uint ui) _NOEXCEPT;
	shaker_string(long l) _NOEXCEPT;
	shaker_string(ulong ul)_NOEXCEPT;
	shaker_string(long long ll) _NOEXCEPT;
	shaker_string(ulonglong ull) _NOEXCEPT;
	shaker_string(float f) _NOEXCEPT;
	shaker_string(double d) _NOEXCEPT;

	const _Myt& operator+=(const _Myt& str);
	const _Myt& operator+=(_Myt&& str);
	const _Myt& operator+=(bool b);
	const _Myt& operator+=(char c);
	const _Myt& operator+=(byte b);
	const _Myt& operator+=(short s);
	const _Myt& operator+=(ushort us);
	const _Myt& operator+=(int i);
	const _Myt& operator+=(uint ui);
	const _Myt& operator+=(long l);
	const _Myt& operator+=(ulong ul);
	const _Myt& operator+=(long long ll);
	const _Myt& operator+=(ulonglong ull);
	const _Myt& operator+=(float f);
	const _Myt& operator+=(double d);
};

SHAKER_NS_END;
#endif