#include "DataGenerator.h"

void DataGenerator::setFileName(const string& _fileName)
{
	fileName = _fileName;
}

void DataGenerator::setFileName(const char* _fileName)
{
	fileName = string(_fileName);
}

void DataGenerator::setFileDirectory(const string& _fileDirectory)
{
	fileDirectory = _fileDirectory;
}

void DataGenerator::setFileDirectory(const char* _fileDirectory)
{
	fileDirectory = string(_fileDirectory);
}

void DataGenerator::setFileType(FileType _fileType)
{
	fileType = _fileType;
}

string DataGenerator::getFileName()
{
	return fileName;
}

string DataGenerator::getFileDirectory()
{
	return fileDirectory;
}

FileType DataGenerator::getFileType()
{
	return fileType;
}
