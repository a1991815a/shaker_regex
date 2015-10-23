#ifndef __SHAKER_STRING__
#define __SHAKER_STRING__
#include "shaker_define.h"
#include <string>
#include <vector>

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

class string
	: public std::string{
public:
	typedef std::string::_Myt			_Myt;
	typedef std::string					_Mybase;
	typedef std::string::value_type		_Elem;
//构造函数
public:
	string() _NOEXCEPT;
	string(const _Myt& _Right);
	string(const _Myt& _Right, const _Alloc& _Al);
	explicit string(const _Alloc& _Al) _NOEXCEPT;
	string(const _Myt& _Right, size_type _Roff,
		size_type _Count = npos);
	string(const _Myt& _Right, size_type _Roff, size_type _Count,
		const _Alloc& _Al);
	string(const _Elem *_Ptr, size_type _Count);
	string(const _Elem *_Ptr, size_type _Count, const _Alloc& _Al);
	string(const _Elem *_Ptr);
	string(const _Elem *_Ptr, const _Alloc& _Al);
	string(size_type _Count, _Elem _Ch);
	string(size_type _Count, _Elem _Ch, const _Alloc& _Al);
// 	template<class _Iter,
// 	class = typename std::enable_if<_Is_iterator<_Iter>::value,
// 		void>::type>
// 		string(_Iter _First, _Iter _Last, const _Alloc& _Al = _Alloc()) 
// 			:_Mybase(_First, _Last, _Al)
// 	{};

//新建的构造函数
public:
	string(bool b) _NOEXCEPT;
	string(char c) _NOEXCEPT;
	string(byte b) _NOEXCEPT;
	string(short sh) _NOEXCEPT;
	string(ushort ush) _NOEXCEPT;
	string(int i) _NOEXCEPT;
	string(uint ui) _NOEXCEPT;
	string(long l) _NOEXCEPT;
	string(ulong ul)_NOEXCEPT;

#if _MSC_VER > 1700
	string(long long ll) _NOEXCEPT;
	string(ulonglong ull) _NOEXCEPT;
#endif

	string(float f) _NOEXCEPT;
	string(double d) _NOEXCEPT;

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

#if _MSC_VER > 1700
	const _Myt& operator+=(long long ll);
	const _Myt& operator+=(ulonglong ull);
#endif

	const _Myt& operator+=(float f);
	const _Myt& operator+=(double d);

//转换API
public:
	bool toBool() const;
	byte toByte() const;
	short toShort() const;
	ushort toUShort() const;
	int toInt() const;
	uint toUInt() const;
	long toLong() const;
	ulong toULong() const;
	long long toLongLong() const;
	ulonglong toULongLong() const;
	float toFloat() const;
	double toDouble() const;
	std::vector<string> split(string split_str, int offset = 0) const;

	bool contain(const string& str) const;

};

typedef std::basic_string<byte> binary_string;

SHAKER_NS_END;
#endif