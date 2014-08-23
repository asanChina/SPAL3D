/**
*	@file GridLayer.h
*	@brief This file contains one class and several auxiliary data structure.
*
*	even most data file provide float value, the grid layer should only store integer for easy of analysing. So actually, the
*	value type in grid layer is alwasy "long long int", if necessary, we will try to use bigInt library later. 
*	All float values in data file  will be transfer to integer before storing into a gridlayer either by multiplying 
*	a multiplier then rounded or dividing by a divisor then rounded. For a data file, all its numeric will be under the same processing
*	@author Pengjie Zhang
*	@date 2014-7-23
*/
#ifndef _GRID_LAYER_H_
#define _GRID_LAYER_H_

#include <vector>
#include <stdlib.h>
#include <iostream>
#include "FileType.h"
#include "Metric.h"
using namespace std;

/**
*	@brief data structure to keep some detailed information for the data in a data file
*
*	If we generate data by ourselves, then there must be some properties associated with the data, 
*	we can use this meta data to help us interpolate the gridlayers.
*/
struct DataInfo{
	double minValue, maxValue, step, noValuePercent;
	long long noValue;
	int numOfDecimals;
	int multiplier;
	///> default constructor
	DataInfo()
	{
		minValue = maxValue = step = noValuePercent = 0.0;
		noValue = 0L;
		numOfDecimals = 0;
		multiplier = 1;
	}
	///> overloaded constructor
	DataInfo(double _minValue, double _maxValue, double _step, int _numOfDecimals, double _noValuePercent)
	{
		minValue = _minValue; 
		maxValue = _maxValue; 
		step = _step; 
		numOfDecimals = _numOfDecimals; 
		noValuePercent = _noValuePercent;
		multiplier = 1;
	}
	///> overloaded constructor
	DataInfo(double _minValue, double _maxValue, double _step, int _numOfDecimals, double _noValuePercent, int _multiplier)
	{
		minValue = _minValue; 
		maxValue = _maxValue; 
		step = _step; 
		numOfDecimals = _numOfDecimals; 
		noValuePercent = _noValuePercent;
		multiplier = _multiplier;
	}
	///> overloaded constructor
	DataInfo(double _minValue, double _maxValue, double _step, int _numOfDecimals, long long _noValue, double _noValuePercent, int _multiplier)
	{
		minValue = _minValue; 
		maxValue = _maxValue; 
		step = _step; 
		numOfDecimals = _numOfDecimals; 
		noValue = _noValue;
		noValuePercent = _noValuePercent;
		multiplier = _multiplier;
	}
	///> copy constructor
	DataInfo(const DataInfo& di)
	{
		minValue = di.minValue; 
		maxValue = di.maxValue; 
		step = di.step; 
		numOfDecimals = di.numOfDecimals; 
		noValuePercent = di.noValuePercent;
		multiplier = di.multiplier;
		noValue = di.noValue;
	}
	///> overload assign operator
	DataInfo& operator=(const DataInfo &right)
	{
		this->minValue = right.minValue;
		this->maxValue = right.maxValue;
		this->step = right.step;
		this->numOfDecimals = right.numOfDecimals;
		this->noValuePercent = right.noValuePercent;
		this->multiplier = right.multiplier;
		this->noValue = right.noValue;
		return *this;
	}
	friend ostream& operator<<(ostream& os, const DataInfo& di)
	{
		os << di.minValue << ' ' << di.maxValue << ' ' << di.step << ' ' << di.numOfDecimals << ' ' << di.noValue << ' ' << di.noValuePercent;
		return os;
	}
	friend istream& operator>>(istream& is, DataInfo& di)
	{	
		is >> di.minValue >> di.maxValue >> di.step >> di.numOfDecimals >> di.noValuePercent;
		if(!is)
			di = DataInfo();
		return is;
	}
};
		
/**
*	@brief GeometricInfo data structure is used to record ths geometric info about the grids in a grid layer
*
*	The grids in a gridlayer have some geometric info, such as the origin, the metric, the cell size. All grids
*	in a gridlayer should be homogeneous, this means the grids should not only have the same rows and columns, but
*	also have the some origin, cell size, metric.
*/
struct GeometricInfo{
	/// default constructor
	GeometricInfo(){}
	/// overloaded constructor
	GeometricInfo(double _longitude, double _latitude, double _cellSize, Metric _cellMetric)
	{
		longitude = _longitude;
		latitude = _latitude;
		cellLength = cellWidth = _cellSize;
		cellLengthMetric = cellWidthMetric = _cellMetric;
	}
	/// overloaded constructor
	GeometricInfo(double _longitude, double _latitude, double _cellLength, double _cellWidth)
	{
		longitude = _longitude;
		latitude = _latitude;
		cellLength = _cellLength;
		cellWidth = _cellWidth;
		cellLengthMetric = cellWidthMetric = METER;
	}	
	/// overloaded constructor
	GeometricInfo(double _longitude, double _latitude, double _cellLength, Metric _cellLengthMetric, double _cellWidth, Metric _cellWidthMetric){
		latitude = _latitude; 
		longitude = _longitude; 
		cellLength = _cellLength;
		cellLengthMetric = _cellLengthMetric;
		cellWidth = _cellWidth;
		cellWidthMetric = _cellWidthMetric;
	}
	/// assignment operator
	GeometricInfo& operator=(const GeometricInfo& right)
	{
		this->longitude = right.longitude;
		this->latitude = right.latitude;
		this->cellLength = right.cellLength;
		this->cellLengthMetric = right.cellLengthMetric;
		this->cellWidth = right.cellWidth;
		this->cellWidthMetric = right.cellWidthMetric;
		return *this;
	}
	double longitude; ///< longitude of the origin
	double latitude; ///< latitude of the origin
	double cellLength; ///< length of the cell
	Metric cellLengthMetric; ///< metric used by cell length
	double cellWidth; ///< width of the cell
	Metric cellWidthMetric; ///< metric used by cell "width"
};

/**
*	@brief class accept only integer value. 
*
*	Currently, the grid layer only store "long long int" type. Later we may resort to external library "bigInt"
*	in case of large integers
*/
class GridLayer{
	public:
		/// default constructor
		GridLayer(){}
		GridLayer(int layer, int row, int col, double heightInterval, long long value);
		GridLayer(const vector<vector<vector<long long> > >& argu, double heightInterval);
		/// destructor
		~GridLayer(){}
	public:
		///> getter. return number of layers
		int getNumOfLayers();
		///> getter. return number of rows for each layer. each layer should have the same number of rows
		int getNumOfRows();
		///> getter. return number of columns for each layer. each layer should have the same number of columns
		int getNumOfColumns();
		///> getter. return the height between adjacent layers, "n" layers have "n-1" intervals
		double getHeightInterval();
		///> getter. return the metric used by "heightInterval", could be "METER", "KILOMETER" or "MILE"
		Metric getHeightIntervalMetric();
		///> getter. return the height between earth surface to the lowest layer
		double getGroundToLowestLayer();
		///> getter. return the metric used by "groundToLowestLayer", could be "METER", "KILOEMETER" or "MILE"
		Metric getGroundToLowestLayerMetric();
		///> getter. return all layers as 3D matrix 
		vector<vector<vector<long long> > > getAllLayers();
		///> getter. return a specific layer as 2D matrix
		vector<vector<long long> > getSpecificLayer(int layer);
		///> getter. return value stored in a specific cell
		long long getCellValue(int layer, int row, int col);
		///> getter. get the data info
		DataInfo getDataInfo();
		///> getter. get the geometric info
		GeometricInfo getGeometricInfo();
	public:
		///> setter. set all layers
		void setAllLayers(const vector<vector<vector<long long> > >& argu);
		///> setter. set specific layer. "index" must only vary from "0" to "getNumOfLayers()"(included) 
		void setSpecificLayer(int index, const vector<vector<long long> >& argu);
		///> setter. set the height interval between every adjacent layers
		void setHeightInterval(double height);
		///> setter. set the metric used by "heightInterval"
		void setHeightIntervalMetric(Metric metric);
		///> setter. set the height between earth surface to the lowest layer
		void setGroundToLowestLayer(double _groundToLowestLayer);
		///> setter. set the metric used by "groundToLowestLayer"
		void setGroundToLowestLayerMetric(Metric metric); 
		///> setter. set new value for a specific cell
		void setCellValue(int layer, int row, int col, long long  newValue);
		///> setter. set the dataInfo
		void setDataInfo(const DataInfo &argu);
		///> setter. set the geometricInfo
		void setGeometricInfo(const GeometricInfo &argu);
	public:
		///> insert new layer into a index, "layerIndex" should range from 0 to getNumOfLayers() (included)
		bool insertLayer(const vector<vector<long long> >& tmp, int layerIndex);
		///> delete a layer, "layerIndex" should range from 0 to "getNumOfLayers()-1" (included)
		bool deleteLayer(int layerIndex);
	private:
		/// detailed information about the data in the file, every layer has its own data info, in a grid layer, all layers data info should be the same.
		DataInfo dataInfo;
		/// geometric info about the grids in the gridlayer. remember all the grids in a gridlayer should be homogeneous
		GeometricInfo geometricInfo;
	private:
		/// real height between two adjacent grids
		double heightInterval;
		/// metric used by "heightInterval", can be "METER", "KILOMETER",...
		Metric heightIntervalMetric;
		/// the height from ground to lowest layer's distance
		double groundToLowestLayer;
		/// metric used by "groundToLowestLayerHeight"
		Metric groundToLowestLayerMetric;
		/// actual storage for grid layer
		vector<vector<vector<long long> > > gridLayer;
};


#endif
