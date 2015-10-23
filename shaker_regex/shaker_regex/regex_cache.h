#ifndef __REGEX_CACHE__
#define __REGEX_CACHE__
#include "../shaker_define.h"
#include <unordered_map>
#include <string>
#include "regex.h"

SHAKER_NS_START;

#define REGEX_SCRIPT "script"
#define S_REGEX_CACHE shaker::regex_cache::getInstance()

class regex_cache{
public:
	static regex_cache* getInstance();
	static void destroyInstance();
private:
	static regex_cache* m_instance;
public:
	regex_cache();
	~regex_cache();


//文件IO API
	void load_regex(const std::string& path);
	void load_regex_bydata(const std::string& data);
	

//管理器基本API
	void clear();
	void push_regex(const std::string& key,const std::string& pattern);
	void push_regex(const std::string&key, regex& re);
	void pop_regex(const std::string& key);
	void pop_regex(const regex& re);
	regex& get_regex(const std::string& key);
	const regex& get_regex(const std::string& key) const;
private:
	std::unordered_map<std::string, regex> m_mapRegexList;
};

SHAKER_NS_END;
#endif