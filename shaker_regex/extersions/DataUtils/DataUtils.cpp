#include "DataUtils.h"
#include "zlib\zlib.h"
#include "lzma\lzmat.h"
#include "base64\base64.h"

#if defined(_DEBUG)
#include <iostream>
#define CHECK_ERROR(err, suc, msg) \
do{	\
	if (err != suc)	\
		std::cout << msg << " error: " << err << std::endl;	\
} while(0)
#else
#define CHECK_ERROR(err, suc, msg) 
#endif

#define BUFFER_SIZE 1024

#define CHECK_ZLIB_ERROR(err, msg) CHECK_ERROR(err, 0, msg)


void reallocStream(z_stream& stream, Data_Binary_t& data_binary) {
	size_t offset = data_binary.size();
	data_binary.resize(data_binary.size() + BUFFER_SIZE);
	stream.next_out = data_binary.data() + offset;
	stream.avail_out = BUFFER_SIZE;
};

void finishStream(z_stream& stream, Data_Binary_t& data_binary){
	data_binary.resize(data_binary.size() - stream.avail_out);
};


DataUtils* DataUtils::m_instance = nullptr;

DataUtils* DataUtils::getInstance()
{
	if (m_instance == nullptr)
		m_instance = new DataUtils();
	return m_instance;
}

void DataUtils::destroyInstance()
{
	if (m_instance)
	{
		delete m_instance;
		m_instance = nullptr;
	}
}

byte* DataUtils::getData()
{
	byte* out = nullptr;
	m_buf.moveData(out);
	return out;
}

Data_Binary_t DataUtils::zlib_compress(const byte* in_data, size_t len, ZlibLevel level /*= ZlibLevel::Default*/)
{
	m_buf.resize(BUFFER_SIZE);
	int err = 0;
	
	z_stream stream;
	stream.zalloc = nullptr;
	stream.zfree = nullptr;
	stream.opaque = nullptr;
	
	stream.next_in = (z_const byte *)in_data;
	stream.next_out = m_buf.data();
	stream.avail_in = len;
	stream.avail_out = BUFFER_SIZE;
	
	err = deflateInit(&stream, (int)level);
	CHECK_ZLIB_ERROR(err, "deflateInit");

	while (stream.avail_in != 0)
	{
		err = deflate(&stream, Z_NO_FLUSH);
		CHECK_ZLIB_ERROR(err, "deflate");
		if (stream.avail_out == 0)
			reallocStream(stream, m_buf);
	}

	while (true)
	{
		err = deflate(&stream, Z_FINISH);
		if (err == Z_STREAM_END)
			break;
		CHECK_ZLIB_ERROR(err, "deflate");
		if (stream.avail_out == 0)
			reallocStream(stream, m_buf);
	}
	finishStream(stream, m_buf);
	deflateEnd(&stream);

	return std::move(m_buf);
}

Data_Binary_t DataUtils::zlib_uncompress(const byte* in_data, size_t len)
{
	m_buf.resize(BUFFER_SIZE);
	int err = 0;

	z_stream stream;
	stream.zalloc = nullptr;
	stream.zfree = nullptr;
	stream.opaque = nullptr;

	stream.next_in = (z_const byte *)in_data;
	stream.next_out = m_buf.data();
	stream.avail_in = len;
	stream.avail_out = BUFFER_SIZE;

	err = inflateInit(&stream);
	CHECK_ZLIB_ERROR(err, "inflateEnd");
	while (true)
	{
		err = inflate(&stream, Z_NO_FLUSH);
		if(err == Z_STREAM_END)
			break;
		CHECK_ZLIB_ERROR(err, "inflate");
		if (stream.avail_out == 0)
			reallocStream(stream, m_buf);
	}
	finishStream(stream, m_buf);
	inflateEnd(&stream);

	return std::move(m_buf);
}

Data_Binary_t DataUtils::base64_encode(const byte* in_data, size_t len)
{
	char* tmp_buf = nullptr;
	int result = base64Encode(in_data, len, &tmp_buf);
	m_buf.attach((byte*)tmp_buf, result);
	return std::move(m_buf);
}

Data_Binary_t DataUtils::base64_decode(const byte* in_data, size_t len)
{
	byte* tmp_buf = nullptr;
	int result = base64Decode(in_data, len, &tmp_buf);
	m_buf.attach(tmp_buf, result);
	return std::move(m_buf);
}

Data_Binary_t DataUtils::lzmat_compress(const byte* in_data, size_t len)
{
	int err = 0;
	MP_U32 tmp_size = MAX_LZMAT_ENCODED_SIZE(len);
	m_buf.resize(tmp_size + sizeof(MP_U32));
	memcpy_s(m_buf.data(), m_buf.size() - tmp_size, &tmp_size, sizeof(MP_U32));

	err = lzmat_encode(
		m_buf.data() + sizeof(MP_U32), (MP_U32*)m_buf.data(),
		(byte*)in_data, len
		);
	CHECK_ZLIB_ERROR(err, "lzmat_encode");

	m_buf.resize(*(MP_U32*)m_buf.data() + sizeof(MP_U32));
	*(MP_U32*)m_buf.data() = len;
	return std::move(m_buf);
}

Data_Binary_t DataUtils::lzmat_uncompress(const byte* in_data, size_t len)
{
	int err = 0;
	MP_U32 tmp_size = *(MP_U32*)in_data;
	MP_U32 out_size = tmp_size;
	m_buf.resize(tmp_size);
	err = lzmat_decode(m_buf.data(), &out_size, (byte*)(in_data + sizeof(MP_U32)), len);

	return std::move(m_buf);
}

