/**
*	@file GeometricInfo.h contains some structs related to geometric information
*	@brief in reality, all grids, blocks, volumes should have bunch of geometric information with them
*	@author Pengjie Zhang
*	@date 2014-6-30
*/

#ifndef _METRIC_H_
#define _METRIC_H_


/**
*	@brief enum structure to denote the metric 
*/
enum Metric{
	DEGREE, ///< degree, means the metric is degree, in some instance to denote the cellsize
	METER, ///< meter, means the metric is meter.
	KILOMETER ///< kilometer, means the metric is kilometer
};

#endif
