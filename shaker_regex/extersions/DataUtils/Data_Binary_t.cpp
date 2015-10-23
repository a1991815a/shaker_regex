#include "Data_Binary_t.h"
#include <memory>

Data_Binary_t::Data_Binary_t()
	:m_data(nullptr), m_size(0)
{

}

Data_Binary_t::Data_Binary_t(const Data_Binary_t& data)
	: m_data(nullptr), m_size(0)
{
	if (!data.empty())
	{
		m_size = data.size();
		resize(m_size);
		memcpy_s(m_data, m_size, data.m_data, m_size);
	}
}

Data_Binary_t::Data_Binary_t(Data_Binary_t&& data)
	: m_data(data.m_data), m_size(data.m_size)
{
	data.m_data = nullptr;
	data.m_size = 0;
}

Data_Binary_t::~Data_Binary_t()
{
	if (m_data)
		free(m_data);
}

void Data_Binary_t::attach(byte* data, size_t len)
{
	deattach();
	m_data = data;
	m_size = m_capacity = len;
	resize(m_size);
}

void Data_Binary_t::deattach()
{
	if (m_data)
		free(m_data);
	else
		return;
	m_data = nullptr;
	m_size = 0;
	m_capacity = 0;
}

const byte* Data_Binary_t::data() const
{
	return m_data;
}

byte* Data_Binary_t::data()
{
	return m_data;
}

size_t Data_Binary_t::size() const
{
	return m_size;
}

size_t Data_Binary_t::capacity() const
{
	return m_capacity;
}

size_t Data_Binary_t::remain_capacity() const
{
	return m_capacity - m_size;
}

bool Data_Binary_t::empty() const
{
	return m_size == 0;
}

void Data_Binary_t::clear()
{
	if (m_data)
	{
		memset(m_data, 0, m_size);
		m_size = 0;
	}
}

void Data_Binary_t::resize(size_t size, byte b /*= 0*/)
{
	if (size == m_size)
		return;
	
	if (size > m_size)
	{
		reserve(size);
		if (b != 0)
			memset(m_data + m_size, b, size - m_size);
	}
	else
		memset(m_data + size, 0, m_size - size);
	m_size = size;
}

void Data_Binary_t::reserve(size_t size)
{
	if (size <= m_size)
		return;
	
	if (m_data == nullptr)
	{
		m_data = (byte*)malloc(size);
	}
	else
	{
		m_data = (byte*)realloc(m_data, size);
		memset(m_data + m_capacity, 0, size - m_capacity);
	}
	m_capacity = size;
}

void Data_Binary_t::copyData(void* dst_buf, size_t len)
{
	memcpy_s(dst_buf, len, m_data, m_size);
}

Data_Binary_t Data_Binary_t::operator+(const Data_Binary_t& data) const
{
	Data_Binary_t tmp_data = *this;
	tmp_data += data;
	return tmp_data;
}

const Data_Binary_t& Data_Binary_t::operator+=(const Data_Binary_t& data)
{
	size_t offset = m_size;
	resize(m_size + data.m_size);
	memcpy_s(m_data + offset, data.m_size, data.m_data, data.m_size);

	return *this;
}

const Data_Binary_t& Data_Binary_t::operator=(const Data_Binary_t& data)
{
	clear();
	resize(data.m_size);
	memcpy_s(m_data, m_size, data.m_data, m_size);
	return *this;
}
