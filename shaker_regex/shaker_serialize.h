#ifndef __SHAKER_SERIALIZE__
#define __SHAKER_SERIALIZE__

/**
*		非侵入式序列化库
*		version:1.0
*		声明S_SERIALIZE_DECL(类)
*		
*/

#define S_MOC_HEADER "shaker_moc_header.hpp"
//序列化宏定义
#define S_SERIALIZE				
#define S_SERIALIZE_POINTER		
#define S_SERIALIZE_ARRAY		
#define S_SERIALIZE_DECL(_Class) friend void shaker::serialize::Serialize<_Class>(shaker::serialize::archive&, _Class&, uint&)


#include "shaker_archive.h"					//存档
#include "shaker_pointer_serialize.h"		//指针序列化器
#include "shaker_serialization.h"			//序列化模板
#include S_MOC_HEADER						//meta object 序列化模板


#endif