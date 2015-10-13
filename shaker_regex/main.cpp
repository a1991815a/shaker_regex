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

#define TOSTRING(A) #A
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

	shaker::string text =
		"dfgdf;1231;48979;16587;956sd";
	auto vv = text.split(";");
	cout << vv.size() << endl;
	for (auto& obj: vv)
		cout << obj.c_str() << endl;



	_getch();
	return 0;
};


void pp(const char* text, ...)
{
	va_list ap;
	va_start(ap, text);
	int len = vsnprintf_s(nullptr, 0, UINT_MAX, text, ap);
	cout << len << endl;
	va_end(ap);
}

