#ifndef __SHAKER_TYPE__
#define __SHAKER_TYPE__

enum class BaseType 
	:unsigned int
{
//��������
	BT_UNKNOWN,
	BT_VOID,
	BT_BOOL,
	BT_CHAR,
	BT_BYTE,
	BT_UNCHAR = BT_BYTE,
	BT_SHORT,
	BT_USHORT,
	BT_INT,
	BT_UINT,
	BT_LONG,
	BT_ULONG,
	BT_LONGLONG,
	BT_ULONGLONG,
	BT_FLOAT,
	BT_DOUBLE,
//�� �������ṹ
	BT_CLASS,
	BT_STRUCT,
	BT_ENUM,
	BT_UNION,
//ָ��
	BT_POINTER,
};

//20������
#endif