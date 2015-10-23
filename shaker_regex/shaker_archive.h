#ifndef __SHAKER_ARCHIVE__
#define __SHAKER_ARCHIVE__
#include "shaker_define.h"
#include "shaker_string.h"
#include "shaker_pointer_serialize.h"

SHAKER_NS_START;

class shaker_archive {
public:
	shaker_archive()
		:m_data(), m_isStorage(false), m_readIndex(0)
	{};
	shaker_archive(const shaker_archive& archive)
		:m_data(archive.m_data), m_readIndex(0), m_isStorage(archive.m_isStorage)
	{};
	shaker_archive(shaker_archive&& archive)
		:m_data(std::move(archive.m_data)), m_readIndex(archive.m_readIndex), m_isStorage(archive.m_isStorage)
	{};

	template<typename _vTy>
	shaker_archive& operator&(const _vTy& val) {

		if (m_isStorage)
			this->operator>>(val);
		else
			this->operator<<(val);
		return *this;
	};

	template<typename _vTy>
	shaker_archive& operator<<(const _vTy& val) {
		size_t size = sizeof(val);
		size_t offset = m_data.size();
		m_data.resize(m_data.size() + size);
 		const void* res_buf = &val;
		void* dst_buf = (void*)(m_data.data() + offset);
		memcpy_s(dst_buf, size, res_buf, size);

		return *this;
	};

	template<typename _vTy>
	shaker_archive& operator>>(_vTy& val) {
		const size_t size = sizeof(val);

		const void* res_buf = (const void*)(m_data.data() + m_readIndex);
		void* dst_buf = (void*)&val;
		memcpy_s(dst_buf, size, res_buf, size);
		m_readIndex += size;

		return *this;
	};

	void setStorage(bool flag) {
		m_isStorage = flag;
	}

	bool isStorage() const {
		return m_isStorage;
	};

	template<typename _Ty>
	void SerializePointer(_Ty*& pointer) {
		if (!m_isStorage)
			setPointer(pointer);
		else
			getPointer(pointer);
	};

	template<typename _Ty>
	void setArray(_Ty*& pointer, size_t _Count = 0) {
		this->operator<<(pointer);
		_POINTER_SERIALIZE->push_array<_Ty>(pointer, _Count);
	};

	template<typename _Ty>
	void getPointer(_Ty*& pointer) {
		this->operator>>(pointer);
		pointer = _POINTER_SERIALIZE->get_pointer<_Ty>(pointer);
	};

	template<typename _Ty>
	void setPointer(_Ty*& pointer) {
		this->operator<<(pointer);
		_POINTER_SERIALIZE->push_object<_Ty>(pointer);
	};


	const binary_string& getData() const {
		return m_data;
	};

	void writeToFile(FILE* file) const {
		fwrite(m_data.c_str(), 1, m_data.size(), file);
	};

	void readFromFile(FILE* file) {
		fseek(file, 0, SEEK_END);
		size_t len = ftell(file);
		rewind(file);
		m_data.resize(len);
		byte* dst_buf = (byte*)m_data.data();
		fread_s(dst_buf, m_data.size(), 1, len, file);
	};

private:
	binary_string	m_data;
	size_t			m_readIndex;
	bool			m_isStorage;
};

SHAKER_NS_END;
#endif