#include "FileStream.h"
#include <unordered_map>

SHAKER_NS_START;
#pragma warning(disable:4800)

string FileStream::get_all()
{
	string out_text;
	char ch = 0;
	while ((ch = this->get()) != EOF)
		out_text.push_back(ch);
	return out_text;
}

long long FileStream::filelength()
{
	_Mybase::seekg(0, SEEK_END);
	long long len = _Mybase::tellg();
	rewindg();
	return len;
}

void FileStream::rewindg()
{
	_Mybase::seekg(0, SEEK_SET);
}

void FileStream::rewindp()
{
	_Mybase::seekp(0, SEEK_SET);
}


string iFileStream::get_all()
{
	string out_text;
	char ch = 0;
	while ((ch = this->get()) != EOF)
		out_text.push_back(ch);
	return out_text;
}

long long iFileStream::filelength()
{
	_Mybase::seekg(0, SEEK_END);
	long long len = _Mybase::tellg();
	rewindg();
	return len;
}

void iFileStream::rewindg()
{
	_Mybase::seekg(0, SEEK_SET);
}


void oFileStream::rewindp()
{
	_Mybase::seekp(0, SEEK_SET);
}


#pragma warning(default:4800)
SHAKER_NS_END;
