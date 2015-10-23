#ifndef __SHAKER_SERIALIZE__
#define __SHAKER_SERIALIZE__

/**
*		������ʽ���л���
*		version:1.0
*		����S_SERIALIZE_DECL(��)
*		
*/

#define S_MOC_HEADER "shaker_moc_header.hpp"
//���л��궨��
#define S_SERIALIZE				
#define S_SERIALIZE_POINTER		
#define S_SERIALIZE_ARRAY		
#define S_SERIALIZE_DECL(_Class) friend void shaker::serialize::Serialize<_Class>(shaker::serialize::archive&, _Class&, uint&)


#include "shaker_archive.h"					//�浵
#include "shaker_pointer_serialize.h"		//ָ�����л���
#include "shaker_serialization.h"			//���л�ģ��
#include S_MOC_HEADER						//meta object ���л�ģ��


#endif