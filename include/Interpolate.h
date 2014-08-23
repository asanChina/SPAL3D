/**
*	@file Interpolate.h defines virtual class "Interpolate", this class family is used to indicate how the data in "gridLayer" are interpolate
*	@author Pengjie Zhang
*	@date 2014-7-28
*/

#ifndef _INTERPOLATE_H_
#define _INTERPOLATE_H_

#include "GridLayer.h"
#include <vector>
using namespace std;


/**
*	@brief this virtual class defines basic interface used by interpolating data in "gridLayer"
*
*	this is a "functional" class, so only function supplied
*/
class Interpolate{
	public:
		///> default constructor
		Interpolate(){}
		///> destructor
		virtual ~Interpolate(){}
	public:
		/** @brief this is pure virtual function, implement how the gridLayer are intepolated
		*	@param gl. gl denote the gridLayer we are going to interpolating
		*	@param valueSet. valueSet will store the interpolated result
		*	@param intervalIndex. intervalIndex denote the interval we are going to interpolating, start from 0(included) to gl.size()-2(included)
		*	@return true means interpolate successfully, false means failed
		*/
		virtual bool interpolate(GridLayer &gl, vector<vector<vector<long long> > > &valueSet, DataInfo &datainfo, GeometricInfo &geometricinfo, int intervalIndex) = 0;
};



#endif
