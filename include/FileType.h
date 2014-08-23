/**
*	@file FileType.h
*	@brief This file declares what kind of file formats are supported by our project
*
*	This file only contains a enum structure, all supported file formats should be registered in this structure, 
*	currently we only support ASCII file format, either in text version or binary version.
*	@author Pengjie Zhang
*	@date 2014/6/22
*/
#ifndef _FILE_TYPE_H_
#define _FILE_TYPE_H_

/**
*	@brief enum structure declares file format
*
*	all file formart should in uppercase word, there is a "null" file format, whenever users want to generate a data file
*	, if the file format is "null", stop
*/
enum FileType{
	///as word denotes, this file format is nonsense, used in situation in which no file format is used.
	NONSENSE, 
	ARCINFOASCII ///< denote standard ARC/INFO ASCII file format
};

#endif
