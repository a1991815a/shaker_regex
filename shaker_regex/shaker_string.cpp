#include "shaker_string.h"

SHAKER_NS_START;

shaker_string::shaker_string() _NOEXCEPT
	:_Mybase()
{

}

shaker_string::shaker_string(const _Myt& _Right)
	: _Mybase(_Right)
{

}

shaker_string::shaker_string(const _Myt& _Right, const _Alloc& _Al)
	: _Mybase(_Right, _Al)
{

}

shaker_string::shaker_string(const _Alloc& _Al) _NOEXCEPT
	: _Mybase(_Al)
{

}

shaker_string::shaker_string(const _Myt& _Right, size_type _Roff, size_type _Count /*= npos*/)
	: _Mybase(_Right, _Roff, _Count)
{

}

shaker_string::shaker_string(const _Myt& _Right, size_type _Roff, size_type _Count, const _Alloc& _Al)
	: _Mybase(_Right, _Roff, _Count, _Al)
{

}

shaker_string::shaker_string(const _Elem *_Ptr, size_type _Count)
	: _Mybase(_Ptr, _Count)
{

}

shaker_string::shaker_string(const _Elem *_Ptr, size_type _Count, const _Alloc& _Al)
	: _Mybase(_Ptr, _Count, _Al)
{

}

shaker_string::shaker_string(const _Elem *_Ptr)
	: _Mybase(_Ptr)
{

}

shaker_string::shaker_string(const _Elem *_Ptr, const _Alloc& _Al)
	: _Mybase(_Ptr, _Al)
{

}

shaker_string::shaker_string(size_type _Count, _Elem _Ch)
	: _Mybase(_Count, _Ch)
{

}

shaker_string::shaker_string(size_type _Count, _Elem _Ch, const _Alloc& _Al)
	: _Mybase(_Count, _Ch, _Al)
{

}

shaker_string::shaker_string(bool b) _NOEXCEPT
{
	if (b)
		*this = "true";
	else
		*this = "false";
}

shaker_string::shaker_string(char c) _NOEXCEPT
{
	push_back(c);
}

shaker_string::shaker_string(byte b) _NOEXCEPT
{
	char buf[4] = { 0 };
	sprintf_s(buf, "%d", b);
	*this = buf;
}

shaker_string::shaker_string(short sh) _NOEXCEPT
{
	char buf[6] = { 0 };
	sprintf_s(buf, "%d", sh);
	*this = buf;
}

shaker_string::shaker_string(ushort ush) _NOEXCEPT
{
	char buf[6] = { 0 };
	sprintf_s(buf, "%u", ush);
	*this = buf;
}

shaker_string::shaker_string(int i) _NOEXCEPT
{
	char buf[11] = { 0 };
	sprintf_s(buf, "%d", i);
	*this = buf;
}

shaker_string::shaker_string(uint ui) _NOEXCEPT
{
	char buf[11] = { 0 };
	sprintf_s(buf, "%u", ui);
	*this = buf;
}

shaker_string::shaker_string(long l) _NOEXCEPT
{
	char buf[11] = { 0 };
	sprintf_s(buf, "%ld", l);
	*this = buf;
}

shaker_string::shaker_string(ulong ul) _NOEXCEPT
{
	char buf[11] = { 0 };
	sprintf_s(buf, "%lu", ul);
	*this = buf;
}

shaker_string::shaker_string(long long ll) _NOEXCEPT
{
	char buf[21] = { 0 };
	sprintf_s(buf, "%lld", ll);
	*this = buf;
}

shaker_string::shaker_string(ulonglong ull) _NOEXCEPT
{
	char buf[21] = { 0 };
	sprintf_s(buf, "%llu", ull);
	*this = buf;
}

shaker_string::shaker_string(float f) _NOEXCEPT
{
	char buf[47] = { 0 };
	sprintf_s(buf, "%f", f);
	*this = buf;
}

shaker_string::shaker_string(double d) _NOEXCEPT
{
	char buf[318] = { 0 };
	sprintf_s(buf, "%lf", d);
	*this = buf;
}

const shaker_string::_Myt& shaker_string::operator+=(const _Myt& str)
{
	_Mybase::operator+=(str);
	return *this;
}

const shaker_string::_Myt& shaker_string::operator+=(_Myt&& str)
{
	_Mybase::operator+=(str);
	return *this;
}

const shaker_string::_Myt& shaker_string::operator+=(bool b)
{
	_Mybase::operator+=(shaker_string(b));
	return *this;
}

const shaker_string::_Myt& shaker_string::operator+=(char c)
{
	_Mybase::operator+=(shaker_string(c));
	return *this;
}

const shaker_string::_Myt& shaker_string::operator+=(byte b)
{
	_Mybase::operator+=(shaker_string(b));
	return *this;
}

const shaker_string::_Myt& shaker_string::operator+=(short s)
{
	_Mybase::operator+=(shaker_string(s));
	return *this;
}

const shaker_string::_Myt& shaker_string::operator+=(ushort us)
{
	_Mybase::operator+=(shaker_string(us));
	return *this;
}

const shaker_string::_Myt& shaker_string::operator+=(int i)
{
	_Mybase::operator+=(shaker_string(i));
	return *this;
}

const shaker_string::_Myt& shaker_string::operator+=(uint ui)
{
	_Mybase::operator+=(shaker_string(ui));
	return *this;
}

const shaker_string::_Myt& shaker_string::operator+=(long l)
{
	_Mybase::operator+=(shaker_string(l));
	return *this;
}

const shaker_string::_Myt& shaker_string::operator+=(ulong ul)
{
	_Mybase::operator+=(shaker_string(ul));
	return *this;
}

const shaker_string::_Myt& shaker_string::operator+=(long long ll)
{
	_Mybase::operator+=(shaker_string(ll));
	return *this;
}

const shaker_string::_Myt& shaker_string::operator+=(ulonglong ull)
{
	_Mybase::operator+=(shaker_string(ull));
	return *this;
}

const shaker_string::_Myt& shaker_string::operator+=(float f)
{
	_Mybase::operator+=(shaker_string(f));
	return *this;
}

const shaker_string::_Myt& shaker_string::operator+=(double d)
{
	_Mybase::operator+=(shaker_string(d));
	return *this;
}

SHAKER_NS_END;