#ifndef __SHAKER_POINTER_SERIALIZE__
#define __SHAKER_POINTER_SERIALIZE__
#include "shaker_define.h"
#include <unordered_map>

#define _POINTER_SERIALIZE \
shaker::serialize::shaker_pointer_serialize::getInstance()

#define _POINTER_SERIALIZE_DESTROY \
shaker::serialize::shaker_pointer_serialize::destroyInstance()


SHAKER_NS_START;
namespace serialize {
	
	struct shaker_pointer_chunk {
		shaker_pointer_chunk()
			:pointer(nullptr), size(0), count(0)
		{};
		void*		pointer;
		size_t		size;
		size_t		count;
		bool		is_array;

		template<typename _Ty>
		void alloc_array(size_t count = 1) {
			SASSERT(pointer == nullptr, "The pointer is not nullptr!");
			this->size = sizeof(_Ty);
			this->count = count;
			this->pointer = new _Ty[count];
			is_array = true;
		};

		template<typename _Ty>
		void alloc_object() {
			SASSERT(pointer == nullptr, "The pointer is not nullptr!");
			this->size = sizeof(_Ty);
			this->count = 1;
			this->pointer = new _Ty();
			is_array = false;
		};
	};

	class shaker_pointer_serialize {
	public:
		static shaker_pointer_serialize* getInstance() {
			if (m_instance == nullptr)
				m_instance = new shaker_pointer_serialize();
			return m_instance;
		};
		static void destroyInstance() {
			if (m_instance) {
				delete m_instance;
				m_instance = nullptr;
			}
		};
	private:
		static shaker_pointer_serialize* m_instance;
	public:
		template<typename _Ty>
		void push_array(_Ty*& pointer, size_t count = 1) {
			SASSERT(m_pointerList.find((size_t)pointer) == m_pointerList.end(), "Set: It is exist pointer");
			shaker_pointer_chunk chunk;
			chunk.alloc_array<_Ty>(count);
			memcpy_s(
				chunk.pointer, chunk.count * chunk.size,
				pointer, chunk.count * chunk.size
				);
			m_pointerList.insert(decltype(m_pointerList)::value_type((size_t)pointer, chunk));
		};

		template<typename _Ty>
		void push_object(_Ty*& pointer) {
			SASSERT(m_pointerList.find((size_t)pointer) == m_pointerList.end(), "Set: It is exist pointer");
			if (pointer == nullptr)
				return;
			shaker_pointer_chunk chunk;
			chunk.alloc_object<_Ty>();
			memcpy_s(chunk.pointer, sizeof(_Ty), pointer, sizeof(_Ty));
			m_pointerList.insert(decltype(m_pointerList)::value_type((size_t)pointer, chunk));
		};

		template<typename _Ty>
		_Ty* get_pointer(_Ty* pointer) {
			if (pointer == nullptr)
				return nullptr;
			SASSERT(m_pointerList.find((size_t)pointer) != m_pointerList.end(), "Set: It is not exist pointer");
			return (_Ty*)m_pointerList.at((size_t)pointer).pointer;
		}

	private:
		std::unordered_map<size_t, shaker_pointer_chunk>
			m_pointerList;
	};

	shaker_pointer_serialize* shaker_pointer_serialize::m_instance = nullptr;

};
SHAKER_NS_END;
#endif