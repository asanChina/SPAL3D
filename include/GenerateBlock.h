/**
*	@file GenerateBlock.h contains the class used to generate block from GridLayer
*	@author Pengjie Zhang
*	@date 2014-7-23
*/

#ifndef _GENERATE_BLOCK_H_
#define _GENERATE_BLOCK_H_

#include "Interpolate.h"
#include "Block.h"
#include "GridLayer.h"


/**
*	@brief class GenerateBlock is used to generate Blocks from interpolated GridLayer
*
*	This class only provide methods, so it's a functional class
*/
class GenerateBlock{
	public:
		GenerateBlock(){}
		~GenerateBlock(){}
	public:
		/**
		*	@brief this function use specified interpolating algorithm to interpolate GridLayer, then extract all Blocks. Blocks which have the same interior value will be stored in the same 1D array.
		*
		*	@param gl. gl is GridLayer instantiation
		*	@param tool. tool is interpolating algorithm
		*	@param result. result is a 1D array, will store Blocks have the same interior value equal to "value"
		*	@param value. specified the value you are interested
		*	@param intervalIndex. specific the interval layer you are interested
		*	@return true means successfully generate all blocks, false means failed
		*/
		bool generate(GridLayer &gl, Interpolate &tool, vector<Block>  &result, int value, int intervalIndex);
};

#endif
