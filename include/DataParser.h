/**
*	@file DataParser.h
*	@brief this file only contains one virtual class "DataParser"
*	@author Pengjie Zhang
*	@date 2014/6/23
*/
#ifndef _DATA_PARSER_H_
#define _DATA_PARSER_H_

#include "DataGenerator.h"
#include "GridLayer.h"

/**
*	@brief virtual class DataParser is used to parse various data file format, extracting corresponding data into grid layer
*
*	currently, we only accept parse data from disk file, and the accepted file format should register in FileType structure, this
*	is a function class, only provides some functions.
*/
class DataParser{
	public:
		///default constructor
		DataParser(){}
		///overloaded constructor accept a parameter, setting the file path 
		DataParser(const string &_filePath):filePath(_filePath){}
		///overloaded constructor accept one parameter, setting the file path
		DataParser(const char *_filePath):filePath(string(_filePath)){}
		///destructor
		virtual ~DataParser(){}

	public:
		///setter. set the file path
		void setFilePath(const string& _filePath);
		void setFilePath(const char* _filePath);
		///getter. get the file path
		string getFilePath(); 
		/**
		*	@brief pure virtual member function used to parse data into a int-valued grirdlayer
		*	@param filePath the file path in disk
		*	@param gl the integer-valued grid layer to extract data to
		*	@param multiplier sometime all data in data file are small double, say 0.0032, the user can designate a multiplier, say 10000, then all data in grid layer will be multiplied by this multiplier, default to 1
		*	@return true means successful, otherwise failed
		*/
		virtual bool parse(GridLayer &gl, int multiplier = 1) = 0; 
	protected:
		string filePath;
};

#endif
