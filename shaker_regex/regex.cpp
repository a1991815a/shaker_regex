#include "regex.h"
#include <iostream>

int shaker::regex::s_pPcreOption = 
PCRE_BSR_ANYCRLF |
PCRE_EXTENDED;

void shaker::regex::setOption(RegexOptions flag, bool onoff /*= true*/)
{
	if (onoff)
		s_pPcreOption |= (int)flag;
	else
		s_pPcreOption &= (~((int)flag));
}

bool shaker::regex::getOption(RegexOptions flag)
{
	return (s_pPcreOption & (int)flag) != 0;
}


shaker::regex::regex()
	:m_pRegexBox(nullptr)
{

}


shaker::regex::regex(const std::string& patten)
{
	load(patten);
}

shaker::regex::regex(const regex& re)
{	
	m_pRegexBox = re.m_pRegexBox;
	std::cout << "引用计数:" << m_pRegexBox.getReferenceCount() << std::endl;
}

shaker::regex::~regex()
{
	
}

bool shaker::regex::match_check_full(const std::string& text) const
{
	int result_list[RESULT_SIZE] = { 0 };

	int num = pcre_exec(m_pRegexBox->m_regex, m_pRegexBox->m_extra, text.c_str(), text.size(),
		0, 0, result_list, RESULT_SIZE);

	if (num != 1)
		return false;

	if (result_list[1] - result_list[0] != text.size())
		return false;
	return true;
}

bool shaker::regex::match_check(const std::string& text, int offset /*= 0*/, int* out /*= nullptr*/) const
{
	int result_list[RESULT_SIZE] = { 0 };

	int num = pcre_exec(m_pRegexBox->m_regex, m_pRegexBox->m_extra, text.c_str(), text.size(),
		offset, 0, result_list, RESULT_SIZE);

	if (num <= 0)
		return false;

	if (out)
		*out = result_list[1];

	return true;
}

bool shaker::regex::match_check_first(const std::string& text) const
{
	return match_check(text);
}

std::string shaker::regex::match(const std::string& text, int offset /*= 0*/, int* out /*= nullptr*/) const
{
	std::string ret_text;

	int result_list[RESULT_SIZE] = { 0 };

	int num = pcre_exec(m_pRegexBox->m_regex, m_pRegexBox->m_extra, text.c_str(), text.size(),
		offset, 0, result_list, RESULT_SIZE);

	if (num <= 0)
		return ret_text;
	
	ret_text = text.substr(result_list[0], result_list[1] - result_list[0]);

	if (out)
		*out = result_list[1];

	return ret_text;
}

std::string shaker::regex::match_first(const std::string& text) const
{
	return match(text);
}

std::vector<std::string> shaker::regex::match_all(
	const std::string& text, 
	int offset /*= 0*/) const
{
	std::vector<std::string> ret_list;

	int result_list[RESULT_SIZE] = { 0 };

	int num = 0;

	while ((num = 
		pcre_exec(
			m_pRegexBox->m_regex, m_pRegexBox->m_extra, 
			text.c_str(), text.size(),
			offset, 0, 
			result_list, RESULT_SIZE))
			> 0)
	{
		size_t size = result_list[1] - result_list[0];
		if(size == 0)
			continue;
		std::string ret_text = text.substr(result_list[0], size);
		ret_list.push_back(ret_text);
		offset = result_list[1];
		memset(result_list, 0, sizeof(result_list));
	}

	return ret_list;
}

bool shaker::regex::operator==(const regex& re) const
{
	return m_pRegexBox == re.m_pRegexBox;
}

bool shaker::regex::isInit() const
{
	return m_pRegexBox != nullptr;
}

void shaker::regex::load(const std::string& patten)
{
	char error_buf[128] = { 0 };
	const char* error_ptr = error_buf;
	int error_offset = 0;
	pcre* re = pcre_compile(patten.c_str(), s_pPcreOption, &error_ptr, &error_offset, 0);
	pcre_extra* extra = pcre_study(re, PCRE_STUDY_JIT_COMPILE, &error_ptr);
	m_pRegexBox = new RegexBox(re, extra);
}

