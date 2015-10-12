#ifndef __FILEIO__
#define __FILEIO__
#include "shaker_define.h"
#include "nocopy.h"
#include "FileOption.h"
#include <string>

SHAKER_NS_START;

class FileIO 
	:nocopy
{
public:
	FileIO();
	FileIO(
		const std::string& path, 
		int io_option =
		FileIOAccess::BINARY |
		FileIOAccess::RDWR |
		FileIOAccess::APPEND |
		FileIOAccess::CREAT,												//文件读写选项
		FileSharedAccess access = FileSharedAccess::DENYWR,					//文件分享选项
		FilePermissionMode mode = FilePermissionMode::READ_WRITE			//文件读写选项
		);
	~FileIO();

	FileOpenResult open(
		const std::string& path, 
		int io_option = 
			FileIOAccess::BINARY |
			FileIOAccess::RDWR |
			FileIOAccess::APPEND |
			FileIOAccess::CREAT,											//文件读写选项
		FileSharedAccess access = FileSharedAccess::DENYWR,					//文件分享选项
		FilePermissionMode mode = FilePermissionMode::READ_WRITE			//文件读写选项
		);			

	static bool	rename(const std::string& old_name, const std::string& new_name);

	void		close();
	std::string read() const;
	std::string read(long len) const;
	void		write(const std::string& text) const;

	bool		is_open() const;
	long		seek(long offset, int fromwhere = SEEK_SET) const;
	bool		eof() const;
	long		length() const;
	bool		resize(int size) const;

	const FileIO& operator<<(const std::string& content) const;
	void operator>>(std::string& content) const;

protected:
	void throw_noopen_error() const;
	void throw_hasopened_error() const;
private:
	int				m_hFile;				//文件句柄
	std::string		m_sFileName;			//文件名
};

class FileInput
	:public FileIO{
public:
	FileInput();
	~FileInput();
	FileInput(
		const std::string& path,
		int io_option =
			FileIOAccess::BINARY |
			FileIOAccess::RDONLY,											//文件读写选项
		FileSharedAccess access = FileSharedAccess::DENYWR,					//文件分享选项
		FilePermissionMode mode = FilePermissionMode::READ_WRITE			//文件读写选项
		);			

	FileOpenResult open(
		const std::string& path,
		int io_option =
			FileIOAccess::BINARY |
			FileIOAccess::RDONLY,											//文件读写选项
		FileSharedAccess access = FileSharedAccess::DENYRD,					//文件分享选项
		FilePermissionMode mode = FilePermissionMode::READ_WRITE			//文件读写选项
		);			

private:
	void write(const std::string& text) const {};
	void operator>>(std::string& content) const;
};

class FileOutput 
	:public FileIO{
public:
	FileOutput();
	FileOutput(
		const std::string& path,
		int io_option =
			FileIOAccess::BINARY |
			FileIOAccess::WRONLY |
			FileIOAccess::TRUNC |
			FileIOAccess::CREAT,											//文件读写选项
		FileSharedAccess access = FileSharedAccess::DENYRD,					//文件分享选项
		FilePermissionMode mode = FilePermissionMode::READ_WRITE			//文件读写选项
		);
	~FileOutput();

	FileOpenResult open(
		const std::string& path,
		int io_option =
			FileIOAccess::BINARY |
			FileIOAccess::WRONLY |
			FileIOAccess::TRUNC |
			FileIOAccess::CREAT,											//文件读写选项
		FileSharedAccess access = FileSharedAccess::DENYRD,					//文件分享选项
		FilePermissionMode mode = FilePermissionMode::READ_WRITE			//文件读写选项
		);
private:
	std::string read() const {};
	std::string read(long len) const {};
	const FileIO& operator<<(const std::string& content) const;
};

SHAKER_NS_END;
#endif