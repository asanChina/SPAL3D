/**
*	@file ArcInfoASCIIParser.h
*	@brief this file only contains one subclass ArcInfoASCIIParser, which is inherited from class DataParser
*	@author Pengjie Zhang
*	@date 2014/6/23
*/
#ifndef _ARC_INFO_ASCII_PARSER_H_
#define _ARC_INFO_ASCII_PARSER_H_

#include "DataParser.h"

/**
*	@brief class ArcInfoASCIIParser is only used to parse Arc/Info ASCII data file
*/
class ArcInfoASCIIParser: public DataParser{
	public:
		///default constructor
		ArcInfoASCIIParser(){}
		///constructor set the filepath
		ArcInfoASCIIParser(const string& _filePath):DataParser(_filePath){}
		///constructor set the filepath
		ArcInfoASCIIParser(const char* _filePath):DataParser(_filePath){}
		///destructor
		~ArcInfoASCIIParser(){}
	public:
		bool parse(GridLayer &gl, int multiplier = 1);
};


#endif
