#ifndef __DATA_BINARY_T__
#define __DATA_BINARY_T__

typedef unsigned char byte;

class Data_Binary_t{
public:
	Data_Binary_t();
	Data_Binary_t(const Data_Binary_t& data);
	Data_Binary_t(Data_Binary_t&& data);
	~Data_Binary_t();

	void attach(byte* data, size_t len);
	void deattach();

	const byte* data() const;
	byte* data();

	size_t size() const;
	size_t capacity() const;
	size_t remain_capacity() const;

	bool empty() const;
	void clear();
	void resize(size_t size, byte b = 0);
	void reserve(size_t size);

//拷贝数据
	void copyData(void* dst_buf, size_t len);
//递交数据
	template<typename _Ty>
	void moveData(_Ty*& dst_buf) {
		dst_buf = m_data;
		m_data = nullptr;
		m_size = 0;
		m_capacity = 0;
	};

	const Data_Binary_t& operator=(const Data_Binary_t& data);
	Data_Binary_t operator+(const Data_Binary_t& data) const;
	const Data_Binary_t& operator+=(const Data_Binary_t& data);

private:
	byte*		m_data;
	size_t		m_size;
	size_t		m_capacity;
};
#endif