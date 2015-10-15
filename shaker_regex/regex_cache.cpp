#include "regex_cache.h"
#include "FileIO.h"
#include "shaker_debug.h"

SHAKER_NS_START;

regex_cache* regex_cache::m_instance = nullptr;

regex_cache* regex_cache::getInstance()
{
	if (m_instance == nullptr)
		m_instance = new regex_cache();
	return m_instance;
}
void regex_cache::destroyInstance()
{
	if (m_instance)
		SHAKER_SAFE_DELETE(m_instance);
}

regex_cache::regex_cache()
{
	push_regex(REGEX_SCRIPT, ".+?:[\\d\\D]+?(?=(\\\\;))");
}

regex_cache::~regex_cache()
{

}

void regex_cache::load_regex(const std::string& path)
{
	FileInput input(path);
	std::string scrpit = input.read();
	input.close();
	load_regex_bydata(scrpit);
}

void shaker::regex_cache::load_regex_bydata(const std::string& data)
{
	regex& re = m_mapRegexList.at(REGEX_SCRIPT);
	auto string_list = re.match_all(data);
	if (string_list.size() == 0)
		throw std::runtime_error("regex script's format is error or null!");
	for (size_t i = 0; i < string_list.size(); ++i)
	{
		auto& script_obj = string_list.at(i);
		int split_index = script_obj.find(':');
		auto& key = script_obj.substr(0, split_index);
		auto& pattern = script_obj.substr(split_index + 1, script_obj.size() - split_index);
		push_regex(key, pattern);
		SHAKER_DEBUG("key: %s", key.c_str());
		SHAKER_DEBUG("pattern: %s", pattern.c_str());
	}
}

void regex_cache::clear()
{
	m_mapRegexList.clear();
}

void regex_cache::push_regex(const std::string& key, const std::string& pattern)
{
	m_mapRegexList[key] = regex(pattern);
}

void regex_cache::push_regex(const std::string& key, regex& re)
{
	m_mapRegexList[key] = re;
}

void regex_cache::pop_regex(const std::string& key)
{
	m_mapRegexList.erase(key);
}

void regex_cache::pop_regex(const regex& re)
{
	auto itor = m_mapRegexList.begin();
	for (; itor != m_mapRegexList.end(); ++itor)
		if (itor->second == re)
			m_mapRegexList.erase(itor);
}

regex& regex_cache::get_regex(const std::string& key)
{
	return m_mapRegexList.at(key);
}

const regex& regex_cache::get_regex(const std::string& key) const
{
	return m_mapRegexList.at(key);
}

SHAKER_NS_END;