#include <conio.h>
#include <iostream>
#include "regex.h"
using namespace std;
#include "smart_ptr.hpp"
#include "FileIO.h"
#include <stdarg.h>
#include "regex_cache.h"
#include "shaker_timer.h"
#include <windows.h>
#include "shaker_string.h"
#include <intsafe.h>

void pp(const char* text, ...);

int main() {

// 	shaker::regex re(".{4}");
// 	auto ret = re.match_all("a111 a222 a333b44 a123456789 ");
// 
// 
// 
// 	for(auto& obj: ret)
// 	{
// 		cout << obj.c_str() << endl;
// 	}

// 	std::string out;
// 
// 	shaker::FileIO io;
// 	io.open("regex.txt");
// 	io >> out;
// 	io << "¿ªÊ¼";
// 	cout << out.c_str() << endl;

	/*S_REGEX_CACHE->load_regex("regex.txt");*/

// 	shaker::shaker_string ss = "asdasdasdsad";
// 
// 	cout << ss.c_str() << endl;

	double x = DBL_MAX;
	std::string ss = "asdasdasdasd";
	shaker::shaker_string text;
	text += ss;

	cout << text.c_str() << endl;

	_getch();
	return 0;
};


void pp(const char* text, ...)
{
	va_list ap;
	va_start(ap, text);
	int len = vsnprintf(nullptr, 0, text, ap);
	cout << len << endl;
	va_end(ap);
}

