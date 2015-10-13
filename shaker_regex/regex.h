#ifndef __REGEX__
#define __REGEX__
#include "shaker_define.h"
#include "pcre/pcre.h"
#include <string>
#include <vector>
#include "nocopy.h"
#include <assert.h>
#include "shared_ptr.hpp"

#define RESULT_SIZE 30

SHAKER_NS_START;

struct RegexBox: nocopy {
	RegexBox(pcre* re, pcre_extra* study)
		:m_regex(re), m_extra(study)
	{};
	~RegexBox() {
		pcre_free_study(m_extra);
		pcre_free(m_regex);
	};

	pcre*		m_regex;
	pcre_extra* m_extra;
};

enum class RegexOptions
	:unsigned int
{
	ANCHORED = PCRE_ANCHORED,						//Force pattern anchoring
	AUTO_CALLOUT = PCRE_AUTO_CALLOUT,				//Compile automatic callouts
	BSR_ANYCRLF = PCRE_BSR_ANYCRLF,					//\R matches only CR, LF, or CRLF
	BSR_UNICODE = PCRE_BSR_UNICODE,					//\R matches all Unicode line endings
	CASELESS = PCRE_CASELESS,						//Do caseless matching
	DOLLAR_ENDONLY = PCRE_DOLLAR_ENDONLY,			//$ not to match newline at end
	DOTALL = PCRE_DOTALL,							//.matches anything including NL
	DUPNAMES = PCRE_DUPNAMES,						//Allow duplicate names for subpatterns
	EXTENDED = PCRE_EXTENDED,						//Ignore white space and # comments
	EXTRA = PCRE_EXTRA,								//PCRE extra features (not much use currently)
	FIRSTLINE = PCRE_FIRSTLINE,						//Force matching to be before newline
	JAVASCRIPT_COMPAT = PCRE_JAVASCRIPT_COMPAT,		//JavaScript compatibility
	MULTILINE = PCRE_MULTILINE,						//^ and $ match newlines within data
	NEVER_UTF = PCRE_NEVER_UTF,						//Lock out UTF, e.g.via(*UTF)
	NEWLINE_ANY = PCRE_NEWLINE_ANY,					//Recognize any Unicode newline sequence
	NEWLINE_ANYCRLF = PCRE_NEWLINE_ANYCRLF,			//Recognize CR, LF, and CRLF as newline sequences
	NEWLINE_CR = PCRE_NEWLINE_CR,					//Set CR as the newline sequence
	NEWLINE_CRLF = PCRE_NEWLINE_CRLF,				//Set CRLF as the newline sequence
	NEWLINE_LF = PCRE_NEWLINE_LF,					//Set LF as the newline sequence
	NO_AUTO_CAPTURE = PCRE_NO_AUTO_CAPTURE,			//Disable numbered capturing paren - theses(named ones available)
	NO_AUTO_POSSESS = PCRE_NO_AUTO_POSSESS,			//Disable auto - possessification
	NO_START_OPTIMIZE = PCRE_NO_START_OPTIMIZE,		//Disable match - time start optimizations
	NO_UTF16_CHECK = PCRE_NO_UTF16_CHECK,			//Do not check the pattern for UTF - 16 validity(only relevant if UTF16 is set)
	NO_UTF32_CHECK = PCRE_NO_UTF32_CHECK,			//Do not check the pattern for UTF - 32 validity(only relevant if UTF32 is set)
	NO_UTF8_CHECK = PCRE_NO_UTF8_CHECK,				//Do not check the pattern for UTF - 8 validity(only relevant if UTF8 is set)
	UCP = PCRE_UCP,									//Use Unicode properties for \d, \w, etc.
	UNGREEDY = PCRE_UNGREEDY,						//Invert greediness of quantifiers
	UTF16 = PCRE_UTF16,								//Run in pcre16_compile() UTF - 16 mode
	UTF32 = PCRE_UTF32,								//Run in pcre32_compile() UTF - 32 mode
	UTF8 = PCRE_UTF8,								//Run in compile() UTF - 8 mode
};

class regex {
public:
	static void setOption(RegexOptions flag, bool onoff = true);
	static bool	getOption(RegexOptions flag);
private:
	static int	s_pPcreOption;
public:
	regex();
	regex(const std::string& patten);
	regex(const regex& re);
	~regex();

	bool isInit() const;
	void load(const std::string& patten);
	bool match_check_full(const std::string& text) const;
	bool match_check(const std::string& text, int offset = 0, int* out = nullptr) const;
	bool match_check_first(const std::string& text) const;
	std::string match(const std::string& text, int offset = 0, int* out = nullptr) const;
	std::string match_first(const std::string& text) const;
	std::vector<std::string> match_all(const std::string& text, int offset = 0) const;

	bool operator==(const regex& re) const;
private:
	shared_ptr<RegexBox*> m_pRegexBox;
};

SHAKER_NS_END;
#endif