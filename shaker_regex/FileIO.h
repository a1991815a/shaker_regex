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
		FileIOAccess::CREAT,												//�ļ���дѡ��
		FileSharedAccess access = FileSharedAccess::DENYWR,					//�ļ�����ѡ��
		FilePermissionMode mode = FilePermissionMode::READ_WRITE			//�ļ���дѡ��
		);
	~FileIO();

	FileOpenResult open(
		const std::string& path, 
		int io_option = 
			FileIOAccess::BINARY |
			FileIOAccess::RDWR |
			FileIOAccess::APPEND |
			FileIOAccess::CREAT,											//�ļ���дѡ��
		FileSharedAccess access = FileSharedAccess::DENYWR,					//�ļ�����ѡ��
		FilePermissionMode mode = FilePermissionMode::READ_WRITE			//�ļ���дѡ��
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
	int				m_hFile;				//�ļ����
	std::string		m_sFileName;			//�ļ���
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
			FileIOAccess::RDONLY,											//�ļ���дѡ��
		FileSharedAccess access = FileSharedAccess::DENYWR,					//�ļ�����ѡ��
		FilePermissionMode mode = FilePermissionMode::READ_WRITE			//�ļ���дѡ��
		);			

	FileOpenResult open(
		const std::string& path,
		int io_option =
			FileIOAccess::BINARY |
			FileIOAccess::RDONLY,											//�ļ���дѡ��
		FileSharedAccess access = FileSharedAccess::DENYRD,					//�ļ�����ѡ��
		FilePermissionMode mode = FilePermissionMode::READ_WRITE			//�ļ���дѡ��
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
			FileIOAccess::CREAT,											//�ļ���дѡ��
		FileSharedAccess access = FileSharedAccess::DENYRD,					//�ļ�����ѡ��
		FilePermissionMode mode = FilePermissionMode::READ_WRITE			//�ļ���дѡ��
		);
	~FileOutput();

	FileOpenResult open(
		const std::string& path,
		int io_option =
			FileIOAccess::BINARY |
			FileIOAccess::WRONLY |
			FileIOAccess::TRUNC |
			FileIOAccess::CREAT,											//�ļ���дѡ��
		FileSharedAccess access = FileSharedAccess::DENYRD,					//�ļ�����ѡ��
		FilePermissionMode mode = FilePermissionMode::READ_WRITE			//�ļ���дѡ��
		);
private:
	std::string read() const {};
	std::string read(long len) const {};
	const FileIO& operator<<(const std::string& content) const;
};

SHAKER_NS_END;
#endif