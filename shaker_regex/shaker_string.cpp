#include "shaker_string.h"

SHAKER_NS_START;

string::string() _NOEXCEPT
	:_Mybase()
{

}

string::string(const _Myt& _Right)
	: _Mybase(_Right)
{

}

string::string(const _Myt& _Right, const _Alloc& _Al)
	: _Mybase(_Right, _Al)
{

}

string::string(const _Alloc& _Al) _NOEXCEPT
	: _Mybase(_Al)
{

}

string::string(const _Myt& _Right, size_type _Roff, size_type _Count /*= npos*/)
	: _Mybase(_Right, _Roff, _Count)
{

}

string::string(const _Myt& _Right, size_type _Roff, size_type _Count, const _Alloc& _Al)
	: _Mybase(_Right, _Roff, _Count, _Al)
{

}

string::string(const _Elem *_Ptr, size_type _Count)
	: _Mybase(_Ptr, _Count)
{

}

string::string(const _Elem *_Ptr, size_type _Count, const _Alloc& _Al)
	: _Mybase(_Ptr, _Count, _Al)
{

}

string::string(const _Elem *_Ptr)
	: _Mybase(_Ptr)
{

}

string::string(const _Elem *_Ptr, const _Alloc& _Al)
	: _Mybase(_Ptr, _Al)
{

}

string::string(size_type _Count, _Elem _Ch)
	: _Mybase(_Count, _Ch)
{

}

string::string(size_type _Count, _Elem _Ch, const _Alloc& _Al)
	: _Mybase(_Count, _Ch, _Al)
{

}

string::string(bool b) _NOEXCEPT
{
	if (b)
		*this = "true";
	else
		*this = "false";
}

string::string(char c) _NOEXCEPT
{
	push_back(c);
}

string::string(byte b) _NOEXCEPT
{
	char buf[4] = { 0 };
	sprintf_s(buf, "%d", b);
	*this = buf;
}

string::string(short sh) _NOEXCEPT
{
	char buf[6] = { 0 };
	sprintf_s(buf, "%d", sh);
	*this = buf;
}

string::string(ushort ush) _NOEXCEPT
{
	char buf[6] = { 0 };
	sprintf_s(buf, "%u", ush);
	*this = buf;
}

string::string(int i) _NOEXCEPT
{
	char buf[11] = { 0 };
	sprintf_s(buf, "%d", i);
	*this = buf;
}

string::string(uint ui) _NOEXCEPT
{
	char buf[11] = { 0 };
	sprintf_s(buf, "%u", ui);
	*this = buf;
}

string::string(long l) _NOEXCEPT
{
	char buf[11] = { 0 };
	sprintf_s(buf, "%ld", l);
	*this = buf;
}

string::string(ulong ul) _NOEXCEPT
{
	char buf[11] = { 0 };
	sprintf_s(buf, "%lu", ul);
	*this = buf;
}

#if _MSC_VER > 1700
string::string(long long ll) _NOEXCEPT
{
	char buf[21] = { 0 };
	sprintf_s(buf, "%lld", ll);
	*this = buf;
}

string::string(ulonglong ull) _NOEXCEPT
{
	char buf[21] = { 0 };
	sprintf_s(buf, "%llu", ull);
	*this = buf;
}
#endif

string::string(float f) _NOEXCEPT
{
	char buf[47] = { 0 };
	sprintf_s(buf, "%f", f);
	*this = buf;
}

string::string(double d) _NOEXCEPT
{
	char buf[318] = { 0 };
	sprintf_s(buf, "%lf", d);
	*this = buf;
}

const string::_Myt& string::operator+=(const _Myt& str)
{
	_Mybase::operator+=(str);
	return *this;
}

const string::_Myt& string::operator+=(_Myt&& str)
{
	_Mybase::operator+=(str);
	return *this;
}

const string::_Myt& string::operator+=(bool b)
{
	_Mybase::operator+=(string(b));
	return *this;
}

const string::_Myt& string::operator+=(char c)
{
	_Mybase::operator+=(string(c));
	return *this;
}

const string::_Myt& string::operator+=(byte b)
{
	_Mybase::operator+=(string(b));
	return *this;
}

const string::_Myt& string::operator+=(short s)
{
	_Mybase::operator+=(string(s));
	return *this;
}

const string::_Myt& string::operator+=(ushort us)
{
	_Mybase::operator+=(string(us));
	return *this;
}

const string::_Myt& string::operator+=(int i)
{
	_Mybase::operator+=(string(i));
	return *this;
}

const string::_Myt& string::operator+=(uint ui)
{
	_Mybase::operator+=(string(ui));
	return *this;
}

const string::_Myt& string::operator+=(long l)
{
	_Mybase::operator+=(string(l));
	return *this;
}

const string::_Myt& string::operator+=(ulong ul)
{
	_Mybase::operator+=(string(ul));
	return *this;
}

#if _MSC_VER > 1700
const string::_Myt& string::operator+=(long long ll)
{
	_Mybase::operator+=(string(ll));
	return *this;
}

const string::_Myt& string::operator+=(ulonglong ull)
{
	_Mybase::operator+=(string(ull));
	return *this;
}
#endif

const string::_Myt& string::operator+=(float f)
{
	_Mybase::operator+=(string(f));
	return *this;
}

const string::_Myt& string::operator+=(double d)
{
	_Mybase::operator+=(string(d));
	return *this;
}

bool string::toBool() const
{
	if (*this == "true" || this->toInt() != 0)
		return true;
	else
		return false;
}

byte string::toByte() const
{
	return (byte)atoi(this->c_str());
}

short string::toShort() const
{
	return (short)atoi(this->c_str());
}

shaker::ushort string::toUShort() const
{
	return (ushort)atoi(this->c_str());
}

int string::toInt() const
{
	return atoi(this->c_str());
}

shaker::uint string::toUInt() const
{
	return strtoul(this->c_str(), nullptr, 10);
}

long string::toLong() const
{
	return atol(this->c_str());
}

shaker::ulong string::toULong() const
{
	return strtoul(this->c_str(), nullptr, 10);
}

#if _MSC_VER > 1700

long long string::toLongLong() const
{
	return strtoll(this->c_str(), nullptr, 10);
}

shaker::ulonglong string::toULongLong() const
{
	return strtoull(this->c_str(), nullptr, 10);
}

#endif

float string::toFloat() const
{
	return atof(this->c_str());
}

double string::toDouble() const
{
	return strtod(this->c_str(), nullptr);
}

std::vector<string> string::split(string split_str, int offset /*= 0*/) const
{
	std::vector<string> ret_list;
	int left_index = offset;
	int right_index = 0;
	if ((right_index = this->find(split_str, left_index)) == string::npos)
	{
		ret_list.push_back(this->c_str());
		return ret_list;
	};

	ret_list.push_back(this->substr(left_index, right_index - left_index));
	left_index = right_index + split_str.size();

	while ((right_index = this->find(split_str, left_index)) != string::npos)
	{
		string ins_str = this->substr(left_index, right_index - left_index);
		if(!ins_str.empty())
			ret_list.push_back(ins_str);
		left_index = right_index + split_str.size();
	}
	string ins_str = this->substr(left_index, split_str.size() - left_index);
	if(!ins_str.empty())
		ret_list.push_back(ins_str);

	return ret_list;
}

SHAKER_NS_END;