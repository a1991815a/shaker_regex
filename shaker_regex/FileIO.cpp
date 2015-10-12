#include "FileIO.h"
#include <io.h>

SHAKER_NS_START;

FileIO::FileIO()
	:m_hFile(0), m_sFileName()
{

}

FileIO::FileIO(
	const std::string& path, 
	int io_option /*= FileIOAccess::BINARY | FileIOAccess::RDWR | FileIOAccess::CREAT*/, /*文件读写选项 */ 
	FileSharedAccess access /*= FileSharedAccess::DENYRD*/, /*文件分享选项 */
	FilePermissionMode mode /*= FilePermissionMode::READ_WRITE /*文件读写选项 */)
{
	this->open(path, io_option, access, mode);
}

FileIO::~FileIO()
{
	close();
}

FileOpenResult FileIO::open(
	const std::string& path,
	int io_option /*= FileIOAccess::BINARY | FileIOAccess::RDWR | FileIOAccess::CREAT*/, /*文件读写选项 */ 
	FileSharedAccess access /*= FileSharedAccess::DENYRD*/, /*文件分享选项 */ 
	FilePermissionMode mode /*= FilePermissionMode::READ_WRITE /*文件读写选项 */)
{
	return (FileOpenResult)::_sopen_s(&m_hFile, path.c_str(), io_option, (int)access, (int)mode);
}

void FileIO::close()
{
	if (m_hFile != 0)
	{
		::_close(m_hFile);
		m_hFile = 0;
	}
}

std::string FileIO::read() const
{
	throw_noopen_error();
	return this->read(length());
}

std::string FileIO::read(long len) const
{
	throw_noopen_error();
	std::string out_text;

	long remain_bytes = length() - len;
	if (remain_bytes < 0)
		remain_bytes = 0;

	for (; len > remain_bytes; len -= 128)
	{
		char buf[128] = { 0 };
		::_read(m_hFile, buf, len);
		out_text += buf;
	}
	return out_text;
}

void FileIO::write(const std::string& text) const
{
	throw_noopen_error();
	::_write(m_hFile, text.c_str(), text.size());
}

bool FileIO::is_open() const
{
	return m_hFile != 0;
}

long FileIO::seek(long offset, int fromwhere /*=SEEK_SET */) const
{
	throw_noopen_error();
	return ::_lseek(m_hFile, offset, fromwhere);
}

bool FileIO::eof() const
{
	throw_noopen_error();
	return ::_eof(m_hFile) == 1;
}

long FileIO::length() const
{
	throw_noopen_error();
	return ::_filelength(m_hFile);
}

bool FileIO::rename(const std::string& old_name, const std::string& new_name)
{
	return ::rename(old_name.c_str(), new_name.c_str()) == 0;
}

bool FileIO::resize(int size) const
{
	throw_noopen_error();
	return ::_chsize(m_hFile, size) == 0;
}

const FileIO& FileIO::operator<<(const std::string& content) const
{
	throw_noopen_error();
	this->write(content);
	return *this;
}

void FileIO::operator>>(std::string& content) const
{
	throw_noopen_error();
	content = this->read();
}


void FileIO::throw_noopen_error() const
{
	if (m_hFile == 0)
		while (true)
			throw std::runtime_error("File is not open!");
}


void FileIO::throw_hasopened_error() const
{
	if (m_hFile != 0)
		while (true)
			throw std::runtime_error("File has been opened!");
}





FileInput::FileInput()
{

}

FileInput::FileInput(const std::string& path, int io_option /*= FileIOAccess::BINARY | FileIOAccess::RDONLY*/, /*文件读写选项 */ FileSharedAccess access /*= FileSharedAccess::DENYRD*/, /*文件分享选项 */ FilePermissionMode mode /*= FilePermissionMode::READ_WRITE /*文件读写选项 */)
	:FileIO(path, io_option, access, mode)
{
	
}

FileOpenResult FileInput::open(const std::string& path, int io_option /*= FileIOAccess::BINARY | FileIOAccess::RDONLY*/, /*文件读写选项 */ FileSharedAccess access /*= FileSharedAccess::DENYRD*/, /*文件分享选项 */ FilePermissionMode mode /*= FilePermissionMode::READ_WRITE /*文件读写选项 */)
{
	return FileIO::open(path, io_option, access, mode);
}

FileInput::~FileInput()
{
	close();
}


FileOutput::FileOutput()
{

}




FileOpenResult FileOutput::open(const std::string& path, int io_option /*= FileIOAccess::BINARY | FileIOAccess::WRONLY | FileIOAccess::CREAT*/, /*文件读写选项 */ FileSharedAccess access /*= FileSharedAccess::DENYRD*/, /*文件分享选项 */ FilePermissionMode mode /*= FilePermissionMode::READ_WRITE /*文件读写选项 */)
{
	return FileIO::open(path, io_option, access, mode);
}

FileOutput::FileOutput(const std::string& path, int io_option /*= FileIOAccess::BINARY | FileIOAccess::WRONLY | FileIOAccess::CREAT*/, /*文件读写选项 */ FileSharedAccess access /*= FileSharedAccess::DENYRD*/, /*文件分享选项 */ FilePermissionMode mode /*= FilePermissionMode::READ_WRITE /*文件读写选项 */)
	:FileIO(path, io_option, access, mode)
{

}

FileOutput::~FileOutput()
{
	close();
}

SHAKER_NS_END;

