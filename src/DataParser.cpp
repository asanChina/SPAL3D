/**
*	@file this file contains the definition of virtual class "DataParser"
*	@author Pengjie Zhang
*	@date 2014-7-23
*/

#include "DataParser.h"

void DataParser::setFilePath(const string& _filePath)
{
	filePath = _filePath;
}

void DataParser::setFilePath(const char* _filePath)
{
	filePath = string(_filePath);
}

string DataParser::getFilePath()
{
	return filePath;
}

