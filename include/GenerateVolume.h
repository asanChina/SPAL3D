/**
*	@file GenerateVolume.h contains the declaration of data sturctures used to generate volumes
*	@author Pengjie Zhang
*	@date 2014-7-23
*/


#ifndef _GENERATE_VOLUME_H_
#define _GENERATE_VOLUME_H_

#include "Block.h"
#include "GridLayer.h"
#include "Interpolate.h"
#include "Volume.h"

/**
*	@brief this class is used to generate volumes	
*
*	This class only provide methods, so only member function delcarations exist
*/
class GenerateVolume{
	public:
		GenerateVolume(){}
		~GenerateVolume(){}
	public:
		/**
		*	@brief this function is used to generate volumes which have the specified value. All extracting volumes will be stored in 1D array and these volumes must exist in specified interval
		*	@param gl. gl provide the GridLayer we are working on
		*	@param tool. tool is the interpolating algorithm we are using to interpolate the gl
		*	@param result. result is 1D array, stores all extracting volumes
		*	@param value. value specify the interior value we are interested in
		*	@param intervalIndex. intervalIndex specify the interval of the gl we are interested in, must range from "0"(included) to "gl.getNumOfLayers()-2"(included
		*	@return true means extracting specified volumes successfully, otherwise falied
		*/
		bool generate(GridLayer &gl, Interpolate &tool, vector<Volume> &result, int value, int intervalIndex);
};

#endif
