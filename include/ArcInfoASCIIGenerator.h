/**
*	@file ArcInfoASCIIGenerator.h
*	@brief contains only one class "ArcInfoASCIIGenerator", a subclass inherit from "DataGenerator"
*
*	@author Pengjie Zhang
*	@date 2014/6/22
*/
#ifndef _ARC_INFO_ASCII_GENERATOR_H_
#define _ARC_INFO_ASCII_GENERATOR_H_

#include "DataGenerator.h"

/**
*	@brief ArcInfoASCIIGenerator is inherited from DataGenerator, responsible for generating ARC/INFO ASCII data file
*
*	This class implements "DataGenerator::generate(...)" virtual function, also including some self-declared member functions for
*	setting/getting format specific infomation.
*/
class ArcInfoASCIIGenerator: public DataGenerator{
	public:
		///default constructor. use defualt values for both inherited member variables and self-declared variables
/*
		ArcInfoASCIIGenerator(){
			fileHeader.nCols = fileHeader.nRows = 0;		
			fileType = ARCINFOASCII;
			fileName = string("ArcInfoASCII");
		}
*/
		///constructor used to reset inherited member variables from DataGenerator
		ArcInfoASCIIGenerator(const string& _fileName, const string& _fileDirectory):DataGenerator(_fileName, _fileDirectory, ARCINFOASCII){
			fileHeader.nCols = fileHeader.nRows = 0;		
		}
		///constructor used to reset inherited member variables
		ArcInfoASCIIGenerator(const char* _fileName, const char* _fileDirectory):DataGenerator(_fileName, _fileDirectory, ARCINFOASCII){
			fileHeader.nCols = fileHeader.nRows = 0;		
		}
		///constructor used to reset both inherit members and self-declared members
		ArcInfoASCIIGenerator(const string& _fileName, const string& _fileDirectory, int _nRows, int _nCols, double _xllCorner, double _yllCorner, double _cellSize, int _noValue):DataGenerator(_fileName, _fileDirectory, ARCINFOASCII)
		{
			fileHeader.nCols = _nCols;
			fileHeader.nRows = _nRows;
			fileHeader.xllCorner = _xllCorner;
			fileHeader.yllCorner = _yllCorner;
			fileHeader.cellSize = _cellSize;
			fileHeader.noValue = _noValue;
		}
		///constructor initialize self-declared member variables
		ArcInfoASCIIGenerator(int _nRows, int _nCols, double _xllCorner, double _yllCorner, double _cellSize, int _noValue):DataGenerator(){
			fileHeader.nCols = _nCols;
			fileHeader.nRows = _nRows;
			fileHeader.xllCorner = _xllCorner;
			fileHeader.yllCorner = _yllCorner;
			fileHeader.cellSize = _cellSize;
			fileHeader.noValue = _noValue;
			fileType = ARCINFOASCII;
			fileName = string("ArcInfoASCII");
		}
		~ArcInfoASCIIGenerator(){}
	public:
	/**
	*	@brief file header for Arc/Info ASCII file format
	*
	*	This structure contains self describle members which correpsond to real Arc/Info ASCII file header
	*/
	struct FileHeader{
		FileHeader()
		{
			nCols = nRows = 0;
		}
		FileHeader(int _nCols, int _nRows, double _xllCorner, double _yllCorner, double _cellSize, int _noValue):nCols(_nCols), nRows(_nRows), xllCorner(_xllCorner), yllCorner(_yllCorner), cellSize(_cellSize), noValue(_noValue){}
		int nCols, nRows; ///< denote the number of rows and columns in data file
		double xllCorner, yllCorner; ///< the x, y value for the left-bottom point( or center point) of the left bottom cell
		double cellSize; ///< the cell size of the cell
		int noValue; ///< the same as Arc/Info ASCII file
		friend ostream& operator<<(ostream& os, const FileHeader& fh);
		friend istream& operator>>(istream& is, FileHeader& fh);
	};

	public:
		///function as describe in DataGenerator.h file
		bool generate(double minValue, double maxValue, double step, int numOfDecimals, double noValuePercent);	
		///setter. overloaded member function used to set the Arc/Info ASCII file header
		void setHeader(int nrows, int ncols, double xllcorner, double yllcorner, double cellsize, int novalue);
		///setter. overloaded member function used to set the Arc/Info ASCII file header
		void setHeader(FileHeader &tmp);
		///getter. member function used to get the file header
		FileHeader& getHeader();

	private:
		///used only for testing the validity of the generated file info. including file name, file directory, file header
		bool isValid();		

	private:
		///file header
		FileHeader fileHeader;
};



#endif
