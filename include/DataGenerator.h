/**
*	@file DataGenerator.h
*	@brief describe virtual data generator class
*	
*	This file only contains one virtual class "DataGenerator", this class provides a pure virtual function for
*	subclass to inherit--generate(...), subclass should be responsible to fill the actual procedure to generate
*	corresponding data file. besides member function "generate(...)", this class also allow users to set the 
*	resulting directory, file name for generated file.
*
*	@author Pengjie Zhang
*	@date 2014-6-18
*/
#ifndef _DATA_GENERATOR_H_
#define _DATA_GENERATOR_H_

#include "FileType.h"
#include <string>
using namespace std;

/**
*	@brief virtual class to define general properties for data generator
*
*	This class provides several constructors, several setters and getters for users to set/retrieve corresponding
*	info associated with generated data file	
*/
class DataGenerator{
	public:
		/// default constructor, put the generated data file in "currently directory", file name to be "NONSENSE", file type to be "NONSENSE" 
		DataGenerator(){
			fileDirectory = string("./");
			fileName = string("NONSENSE");
			fileType = NONSENSE;
		}
		/// constructor utilize list initialization, accepts c++ string class as parameters type
		DataGenerator(const string& _fileName, const string& _fileDirectory, FileType _fileType):fileName(_fileName), fileDirectory(_fileDirectory), fileType(_fileType){}
		/// constructor set fileType with other default
		DataGenerator(FileType _fileType){
			fileDirectory = string("./");
			fileName = string("NONSENSEE");
			fileType = _fileType;
		}
		/// constructor utilize list initialization, accepts c chars as parameters type
		DataGenerator(const char* _fileName, const char* _fileDirectory, FileType _fileType){
			fileName = string(_fileName);
			fileDirectory = string(_fileDirectory);	
			fileType = _fileType;
		}	
		/// pure virtual destructor
		virtual ~DataGenerator(){}
	public:
		/// setter. overloaded member function, set the generated data file name, accept c++ string class as parameter type
		void setFileName(const string& _fileName);
		/// setter. overloaded member function, set the generated data file name, accept c chars as parameter type
		void setFileName(const char* _fileName);
		/// setter. overloaded member function, set the directory for the generated data file, accept string class as parameter type
		void setFileDirectory(const string& _fileDirectory);
		/// setter. overloaded member function, set the directory for the generated data file, accept c chars as parameter type
		void setFileDirectory(const char* _fileDirectory);
		/// setter. set the file type
		void setFileType(FileType _fileTyep);

		/// getter. get the generated data file name, including any prefix or postfix, not include directory
		string getFileName();
		/// getter. get the file directory of the generated data file, always have char "/" as the last character
		string getFileDirectory();
		/// getter. get the file type for the generated data file, value should exist in "enum FileType{...}"
		FileType getFileType();

		/**
		*	@brief pure virtual member function responsible for generating data file
		*
		*	@return true denotes generating data file successfully, false otherwise
		*	@param minValue minimum numeric data in data file
		*	@param maxValue maximum numeric data in data file
		*	@param step used to set numeric increment
		*	@param numOfDecimals indicate the number of digits in after decimal point, 0 means numeric data are all integers
		*	@param noValuePercent used to represent the percentage the null value should exist in a data file	
		*/
		virtual bool generate(double minValue, double maxValue, double step, int numOfDecimals, double noValuePercent) = 0;

	protected:
		FileType fileType;	///< denotes in which file format would the generated data file be
		string fileName;	///< denotes the file name of the generated data file, any prefix or postfix included.
		string fileDirectory;	///< denotes the file directory of the generated data file. the last character should be exactly the character "/"
};
#endif
