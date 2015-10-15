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
#include "basetype_traits.h"
#include "function_traits.h"
#include "value_traits.h"
#include "lua.hpp"
#include "shaker_function.h"

// template<typename TT>
// struct pprint {
// 	const static int ss = 0;
// };
// 
// template<>
// struct pprint<int>{
// 	const static int ss = 1;
// };
// 
// template<>
// struct pprint<char> {
// 	const static int ss = 2;
// };
// 
// template<>
// struct pprint<float> {
// 	const static int ss = 3;
// };
// 
// 
// template<typename... ARGS>
// struct print
// {
// 	const static int count = sizeof...(ARGS);
// 	const static int a[count];
// };
// 
// template<typename... ARGS>
// const int 
// print<ARGS...>::a[print<ARGS...>::count] = {
// 	pprint<ARGS>::ss...,
// };

template<typename T>
struct TypeOnce {
	typedef T v_type;
};

template<typename... ARGS>
struct TypeList 
	:public TypeOnce<ARGS>...
{
};


int pppp(int a, int b){
	return a + b;
};


int main() {
	
	
// 	cout << print<int, char, float>::a[0] << endl;
// 	cout << print<int, char, float>::a[1] << endl;
// 	cout << print<int, char, float>::a[2] << endl;
// 	cout << print<int, char, float>::count << endl;
// 	for (auto& obj : print<int, char, float>::a)
// 	{
// 		cout << obj << endl;
// 	}

// 	shaker::regex_cache::getInstance()->load_regex("regex.txt");
// 	shaker::regex_cache::getInstance();
	
	shaker::shaker_function f((shaker::S_FuncPtr)pppp);
	int ret = f.callThis<int>(5, 6);
	cout << ret << endl;

	_getch();
	return 0;
};

