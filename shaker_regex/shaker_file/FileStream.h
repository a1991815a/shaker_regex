#ifndef __FILESTREAM__
#define __FILESTREAM__
#include "../shaker_string.h"
#include "../nocopy.h"
#include <fstream>

SHAKER_NS_START;
typedef int access_t;

struct io_access{
	const static int read = std::ios::in;
	const static int write = std::ios::out;
	const static int ate = std::ios::ate;
	const static int append = std::ios::app;
	const static int binary = std::ios::binary;
	const static int no_create = std::ios::_Nocreate;
	const static int no_replace = std::ios::_Noreplace;
};

class FileStream
	:public std::fstream
{
public:
	typedef FileStream _Myt;
	typedef std::fstream _Mybase;
	typedef std::basic_filebuf<char, std::char_traits<char>> _Myfb;
	typedef std::basic_ios<char, std::char_traits<char>> _Myios;
	typedef char char_type;
	typedef std::char_traits<char> traits_type;
	typedef std::char_traits<char>::int_type int_type;
	typedef std::char_traits<char>::pos_type pos_type;
	typedef std::char_traits<char>::off_type off_type;
public:
	FileStream()
		: _Mybase()
	{}

	explicit FileStream(const char *_Filename,
		ios_base::openmode _Mode = ios_base::in | ios_base::out,
		int _Prot = (int)ios_base::_Openprot)
		: _Mybase(_Filename, _Mode, _Prot)
	{}

	explicit FileStream(const string& _Str,
		ios_base::openmode _Mode = ios_base::in | ios_base::out,
		int _Prot = (int)ios_base::_Openprot)
		: _Mybase(_Str, _Mode, _Prot)
	{}

	explicit FileStream(const wchar_t *_Filename,
		ios_base::openmode _Mode = ios_base::in | ios_base::out,
		int _Prot = (int)ios_base::_Openprot)
		: _Mybase(_Filename, _Mode, _Prot)
	{}

	explicit FileStream(const std::wstring& _Str,
		ios_base::openmode _Mode = ios_base::in | ios_base::out,
		int _Prot = (int)ios_base::_Openprot)
		: _Mybase(_Str, _Mode, _Prot)
	{}

#ifdef _NATIVE_WCHAR_T_DEFINED
	explicit FileStream(const unsigned short *_Filename,
		ios_base::openmode _Mode = ios_base::in | ios_base::out,
		int _Prot = (int)ios_base::_Openprot)
		: _Mybase(_Filename, _Mode, _Prot)
	{}
#endif /* _NATIVE_WCHAR_T_DEFINED */

	explicit FileStream(_Filet *_File)
		: _Mybase(_File)
	{}

	FileStream(_Myt&& _Right)
		: _Mybase(std::move(_Right))
	{}

	FileStream(const _Myt&) = delete;
	_Myt& operator=(const _Myt&) = delete;


	string get_all();
	long long filelength();
	void rewindg();
	void rewindp();
};

class iFileStream 
	:public std::ifstream
{
public:
	typedef iFileStream _Myt;
	typedef std::ifstream _Mybase;
	typedef std::basic_filebuf<char, std::char_traits<char>> _Myfb;
	typedef std::basic_ios<char, std::char_traits<char>> _Myios;

public:
	iFileStream()
		:_Mybase()
	{}

	explicit iFileStream(const char *_Filename,
		ios_base::openmode _Mode = ios_base::in,
		int _Prot = (int)ios_base::_Openprot)
		: _Mybase(_Filename, _Mode, _Prot)
	{}

	explicit iFileStream(const string& _Str,
		ios_base::openmode _Mode = ios_base::in,
		int _Prot = (int)ios_base::_Openprot)
		: _Mybase(_Str, _Mode, _Prot)
	{}

	explicit iFileStream(const wchar_t *_Filename,
		ios_base::openmode _Mode = ios_base::in,
		int _Prot = (int)ios_base::_Openprot)
		: _Mybase(_Filename, _Mode, _Prot)
	{}

	explicit iFileStream(const std::wstring& _Str,
		ios_base::openmode _Mode = ios_base::in,
		int _Prot = (int)ios_base::_Openprot)
		: _Mybase(_Str, _Mode, _Prot)
	{}

#ifdef _NATIVE_WCHAR_T_DEFINED
	explicit iFileStream(const unsigned short *_Filename,
		ios_base::openmode _Mode = ios_base::in,
		int _Prot = (int)ios_base::_Openprot)
		: _Mybase(_Filename, _Mode, _Prot)
	{}
#endif /* _NATIVE_WCHAR_T_DEFINED */

	explicit iFileStream(_Filet *_File)
		: _Mybase(_File)
	{}

	iFileStream(_Myt&& _Right)
		: _Mybase(std::move(_Right))
	{}

	iFileStream(const _Myt&) = delete;
	_Myt& operator=(const _Myt&) = delete;


	string get_all();
	long long filelength();
	void rewindg();
};

class oFileStream 
	:public std::ofstream
{
public:
	typedef oFileStream _Myt;
	typedef std::ofstream _Mybase;
	typedef std::basic_filebuf<char, std::char_traits<char>> _Myfb;
	typedef std::basic_ios<char, std::char_traits<char>> _Myios;

public:
	oFileStream()
		: _Mybase()
	{}

	explicit oFileStream(const char *_Filename,
		ios_base::openmode _Mode = ios_base::out,
		int _Prot = (int)ios_base::_Openprot)
		: _Mybase(_Filename, _Mode, _Prot)
	{}

	explicit oFileStream(const string& _Str,
		ios_base::openmode _Mode = ios_base::out,
		int _Prot = (int)ios_base::_Openprot)
		: _Mybase(_Str, _Mode, _Prot)
	{}

	explicit oFileStream(const wchar_t *_Filename,
		ios_base::openmode _Mode = ios_base::out,
		int _Prot = (int)ios_base::_Openprot)
		: _Mybase(_Filename, _Mode, _Prot)
	{}

	explicit oFileStream(const std::wstring& _Str,
		ios_base::openmode _Mode = ios_base::out,
		int _Prot = (int)ios_base::_Openprot)
		: _Mybase(_Str, _Mode, _Prot)
	{}

#ifdef _NATIVE_WCHAR_T_DEFINED
	explicit oFileStream(const unsigned short *_Filename,
		ios_base::openmode _Mode = ios_base::out,
		int _Prot = (int)ios_base::_Openprot)
		: _Mybase(_Filename, _Mode, _Prot)
	{}
#endif /* _NATIVE_WCHAR_T_DEFINED */

	explicit oFileStream(_Filet *_File)
		: _Mybase(_File)
	{}

	oFileStream(_Myt&& _Right)
		: _Mybase(std::move(_Right))
	{}

	oFileStream(const _Myt&) = delete;
	_Myt& operator=(const _Myt&) = delete;

	void rewindp();
};

SHAKER_NS_END;
#endif