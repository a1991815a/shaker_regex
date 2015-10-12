#ifndef __FILEOPTION__
#define __FILEOPTION__
#include "shaker_define.h"
#include <fcntl.h>
#include <sys\types.h>
#include <sys\stat.h>
#include <share.h>
#include <errno.h>


SHAKER_NS_START;

class FileIOAccess
{
public:
	//定义所有枚举
	static const int

		APPEND = _O_APPEND,									//Repositions a file pointer to the end of the file before every write operation.
		BINARY = _O_BINARY,									//Opens a file in binary(untranslated) mode. (See fopen for a description of binary mode.)
		CREAT = _O_CREAT,									//Creates a file and opens it for writing.Has no effect if the file specified by filename exists.
		CREAT_SHORT_LIVED = _O_CREAT | _O_SHORT_LIVED,		//Creates a file as temporary and if possible does not flush to disk.
		CREAT_TEMPORARY = _O_CREAT | _O_TEMPORARY,			//Creates a file as temporary; the file is deleted when the last file descriptor is closed.
		CREAT_EXCL = _O_CREAT | _O_EXCL,					//Returns an error value if the file specified by filename exists.Applies only when used with _O_CREAT.
		NOINHERIT = _O_NOINHERIT,							//Prevents creation of a shared file descriptor.
		RANDOM = _O_RANDOM,									//Specifies primarily random access from disk.
		RDONLY = _O_RDONLY,									//Opens a file for reading only.Cannot be specified with _O_RDWR or _O_WRONLY.
		RDWR = _O_RDWR,										//Opens a file for both reading and writing.Cannot be specified with _O_RDONLY or _O_WRONLY.
		SEQUENTIAL = _O_SEQUENTIAL,							//Specifies primarily sequential access from disk.
		TEXT = _O_TEXT,										//Opens a file in text(translated) mode. (For more information, see Text and Binary Mode File I / O and fopen.)
		TRUNC = _O_TRUNC,									//Opens a file and truncates it to zero length; the file must have write permission.Cannot be specified with _O_RDONLY._O_TRUNC used with _O_CREAT opens an existing file or creates a file.
		WRONLY = _O_WRONLY,									//Opens a file for writing only.Cannot be specified with _O_RDONLY or _O_RDWR.
		U16TEXT = _O_U16TEXT,								//Opens a file in Unicode UTF - 16 mode.
		U8TEXT = _O_U8TEXT,									//Opens a file in Unicode UTF - 8 mode.
		WTEXT = _O_WTEXT;									//Opens a file in Unicode mode.
};

enum class FileSharedAccess
{
	DENYRW = _SH_DENYRW,								//Denies read and write access to a file.
	DENYWR = _SH_DENYWR,								//Denies write access to a file.
	DENYRD = _SH_DENYRD,								//Denies read access to a file.
	DENYNO = _SH_DENYNO,								//Permits read and write access.
};

enum class FilePermissionMode
{
	WRITE = _S_IWRITE,								//Writing permitted.
	READ = _S_IREAD,								//Reading permitted.
	READ_WRITE = _S_IREAD | _S_IWRITE,				//Reading and writing permitted.
};

enum class FileOpenResult 
	:int
{
	SUCCESS_ERROR = 0,							//success
	ACCESS_ERROR = EACCES,						//The given path is a directory, or the file is read - only, but an open - for - writing operation was attempted.
	EXIST_ERROR = EEXIST,						//_O_CREAT and _O_EXCL flags were specified, but filename already exists.
	INVALID_ARGS_ERROR = EINVAL,				//Invalid oflag, shflag, or pmode argument, or pfh or filename was a null pointer.
	MFILE_ERROR = EMFILE,						//No more file descriptors available.
	NOENT_ERROR = ENOENT,						//File or path not found.
};

SHAKER_NS_END;
#endif