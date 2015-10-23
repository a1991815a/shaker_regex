#ifndef __SHAKER_FILE__
#define __SHAKER_FILE__
#include "shaker_define.h"

#include "shaker_file/FileOption.h"
#include "shaker_file/FileIO.h"
#include "shaker_file/FileStream.h"

SHAKER_NS_START;


typedef FileIO			shaker_file;
typedef FileInput		shaker_ifile;
typedef FileOutput		shaker_ofile;

typedef FileStream		shaker_fstream;
typedef iFileStream		shaker_ifstream;
typedef oFileStream		shaker_ofstream;

SHAKER_NS_END;
#endif