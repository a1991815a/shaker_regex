#ifndef __DATAUTILS__
#define __DATAUTILS__
#include "Data_Binary_t.h"
#include <string>

#define _dataUtils DataUtils::getInstance()

enum class ZlibLevel 
	:int
{
	Default = -1,
	No_Compression = 0,
	Best_Speed = 1,
	Best_Compression = 9,
};

class DataUtils{
public:
	static DataUtils* getInstance();
	static void destroyInstance();
private:
	static DataUtils* m_instance;
public:
	byte* getData();

	Data_Binary_t zlib_compress(const byte* in_data, size_t len, ZlibLevel level = ZlibLevel::Default);
	Data_Binary_t zlib_uncompress(const byte* in_data, size_t len);
	Data_Binary_t base64_encode(const byte* in_data, size_t len);
	Data_Binary_t base64_decode(const byte* in_data, size_t len);
	Data_Binary_t lzmat_compress(const byte* in_data, size_t len);
	Data_Binary_t lzmat_uncompress(const byte* in_data, size_t len);
	
private:
	Data_Binary_t m_buf;			//二进制数据缓冲区
};


#endif