/**
*	@file GridLayer.h contains the definition of class "GridLayer"
*	@author Pengjie Zhang
*	@date 2014-7-23
*/


#include "GridLayer.h"
/**
*	@brief constructor to set detailed info for the grid layer
*	@param layer the number of layers in the grid layer
*	@param row the number of rows in one layer
*	@param col the number of columns in one layer
*	@param value the value in all cells
*/
GridLayer::GridLayer(int layer, int row, int col, double _heightInterval, long long value)
{
	gridLayer = vector<vector<vector<long long> > > (layer, vector<vector<long long> > (row, vector<long long>(col, value)));
	heightInterval = _heightInterval;
}

/**
*	@brief copy constructor
*/
GridLayer::GridLayer(const vector<vector<vector<long long> > >& argu, double _heightInterval)
{
	gridLayer = argu;
	heightInterval = _heightInterval;
}

/// getter. get number of layers in the grid layer
int GridLayer::getNumOfLayers()
{
	return gridLayer.size();
}

/**
*	@brief getter, get number of rows in one layer.
*	@return -1 means grid layer holds nothing, otherwise greater than 0
*/
int GridLayer::getNumOfRows()
{
	if(getNumOfLayers() > 0)
		return gridLayer[0].size();
	else
	{
		cout << "Error in GridLayer::getNumOfRows(...), out of bound" << endl;
		exit(0);
	}
}

/**
*	@brief getter, get number of columns in one layer.
*	@return -1 means grid layer holds nothing, otherwise greater than 0
*/
int GridLayer::getNumOfColumns()
{
	if(getNumOfLayers() > 0 && gridLayer[0].size() > 0)
		return gridLayer[0][0].size();
	else
	{
		cout << "Error in GridLayer::getNumOfColumns(...), out of bound" << endl;
		exit(0);
	}
}

/**
*	@brief getter. get the height interval between two adjacent grids
*/
double GridLayer::getHeightInterval()
{
	return heightInterval;
}

Metric GridLayer::getHeightIntervalMetric()
{
	return heightIntervalMetric;
}

double GridLayer::getGroundToLowestLayer()
{
	return groundToLowestLayer;
}

Metric GridLayer::getGroundToLowestLayerMetric()
{
	return groundToLowestLayerMetric;
}

vector<vector<vector<long long> > > GridLayer::getAllLayers()
{
	return gridLayer;
}

/**
*	@brief get specific layer in the gridlayer
*	@param layer index starts from 0, so parameter should greater than -1 but must less than the number of layers, otherwise exit
*	@return the wanted layer
*/
vector<vector<long long> > GridLayer::getSpecificLayer(int layer)
{
	if(layer < 0 || layer >= getNumOfLayers())
	{
		cout << "Error in GridLayer::getSpecificLayer(...), out of bound!" << endl;
		exit(1);
	}
	return gridLayer[layer];
}

/**
*	@brief get specific cell value in the grid layer
*	@param layer index of the layer, remember the index starts from 0, if out of bound, error!
*	@param row row of the wanted cell
*	@param col column of the wanted cell
*	@return value stored in specific cell
*/
long long GridLayer::getCellValue(int layer, int row, int col)
{
	if(layer < 0 || layer >= getNumOfLayers() || row < 0 || row >= getNumOfRows() || col < 0 || col >= getNumOfColumns())
	{
		cout << "Error in GridLayer::getSpecificLayer(...), out of bound!" << endl;
		exit(1);
	}
	return gridLayer[layer][row][col];
}

DataInfo GridLayer::getDataInfo()
{
	return dataInfo;
}

GeometricInfo GridLayer::getGeometricInfo()
{
	return geometricInfo;
}





/**
*	@brief set grid layer
*/
void GridLayer::setAllLayers(const vector<vector<vector<long long> > >& argu)
{
	gridLayer = argu;
}


/**
*	@brief replace specific layer
*	@param index should greater than -1 and smaller than the number of existing layers, otherwise error
*/
void GridLayer::setSpecificLayer(int index, const vector<vector<long long> >& argu)
{
	if(index < 0 || index >= getNumOfLayers())
	{
		cout << "Error in GridLayer::setSpecificLayers(...), out of bound!" << endl;
		exit(1);
	}	
	gridLayer[index] = argu;
}


/**
*	@brief set specific cell value
*	@param layer the layer of the cell
*	@param row the row of the cell
*	@param col the column of the cell
*	@param newValue the new value of the cell
*/
void GridLayer::setCellValue(int layer, int row, int col, long long newValue)
{
	if(layer < 0 || layer >= getNumOfLayers() || row < 0 || row >= getNumOfRows() || col < 0 || col >= getNumOfColumns())
	{
		cout << "Error in GridLayer::setCellValue(...), out of bound!" << endl;
		exit(1);
	}
	gridLayer[layer][row][col] = newValue;
}

/**	
*	@brief setter. set height interval between any two adjacent grids
*/
void GridLayer::setHeightInterval(double _heightInterval)
{
	heightInterval = _heightInterval;
}

void GridLayer::setHeightIntervalMetric(Metric _metric)
{
	heightIntervalMetric = _metric;
}

void GridLayer::setGroundToLowestLayer(double _groundToLowestLayer)
{
	groundToLowestLayer = _groundToLowestLayer;
}

void GridLayer::setGroundToLowestLayerMetric(Metric _metric)
{
	groundToLowestLayerMetric = _metric;
}

void GridLayer::setDataInfo(const DataInfo &argu)
{
	dataInfo = argu;
}

void GridLayer::setGeometricInfo(const GeometricInfo &argu)
{
	geometricInfo = argu;
}




bool GridLayer::insertLayer(const vector<vector<long long> >& tmp, int layerIndex)
{
	if(tmp.size() <= 0)
		return false;
	if(layerIndex < 0 || layerIndex > getNumOfLayers())
		return false;
	if(getNumOfLayers() > 0 && (tmp.size() != getNumOfRows() || tmp[0].size() != getNumOfColumns()))
		return false;
	vector<vector<vector<long long> > >::iterator ite = gridLayer.begin();
	for(int i = 0; i < layerIndex; i++)
		ite++;
	gridLayer.insert(ite, tmp);	
	return true;
}

bool GridLayer::deleteLayer(int layerIndex)
{
	if(layerIndex < 0 || layerIndex >= getNumOfLayers())
		return false;
	vector<vector<vector<long long> > >::iterator ite = gridLayer.begin();
	for(int i = 0; i < layerIndex; i++)
		ite++;
	gridLayer.erase(ite);
}


