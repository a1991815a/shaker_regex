#ifndef __SHAKER_SERIALIZATION__
#define __SHAKER_SERIALIZATION__
#include "shaker_define.h"
#include "shaker_archive.h"
#include "shaker_serialization.h"

#define SSERIALIZE_NS_START namespace serialize{
#define SSERIALIZE_NS_END	}
#define USING_NS_SSERIALIZE using namespace shaker::serialize

SHAKER_NS_START;
SSERIALIZE_NS_START;

typedef shaker_archive archive;

template<typename _Ty>
void Serialize(archive& ar, _Ty& obj, uint version) {
	size_t size = sizeof(_Ty);
	ar & version;
	ar & obj;
};

SSERIALIZE_NS_END;
SHAKER_NS_END;
#endif