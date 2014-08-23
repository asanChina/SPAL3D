/**
*	@file LinearInterpolate.h declare class "LinearInterpolate", this class is used to linearly interpolate GridLayer
*	@author Pengjie Zhang
*	@date 2014-7-28
*/

#ifndef _LINEAR_INTERPOLATE_H_
#define _LINEAR_INTERPOLATE_H_

#include "Interpolate.h"
/**
*	@brief LinearInterpolate is used to interpolate GridLayer linearly
*
*	This class inherit from "Interpolate", implement pure virtual function "interpolate"
*/
class LinearInterpolate:public Interpolate{
	public:
		///> default constructor
		LinearInterpolate(){}
		///> destructor
		~LinearInterpolate(){}
	public:
		bool interpolate(GridLayer &gl, vector<vector<vector<long long> > > &valueSet, DataInfo &datainfo, GeometricInfo &geometricinfo, int intervalIndex);	
		///> this function implement "Euclidean Algorithm" to calculate the greatest common divisor between "first" and "second". "first" and "second" should be positive integer. return greatest common divisor if successfull, otherwise return -1.
		int euclideanAlgo(int first, int second);
};

#endif

