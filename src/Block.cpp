/**
*	@file Block.cpp contains the definition of the class "Block"
*	@author Pengjie Zhang
*	@date 2014-6-30
*/

#include "Block.h"

int Block::getRowIndex()
{
	return rowIndex;
}

int Block::getColumnIndex()
{
	return columnIndex;
}

int Block::getLowerLayerIndex()
{
	return lowerLayerIndex;
}

int Block::getUpperLayerIndex()
{
	return upperLayerIndex;
}

double Block::getSinglePartHeight()
{
	return singlePartHeight;
}

long long Block::getValue()
{
	return value;
}

int Block::getMultiplier()
{
	return multiplier;
}



void Block::setRowIndex(int _rowIndex)
{
	rowIndex = _rowIndex;
}

void Block::setColumnIndex(int _columnIndex)
{
	columnIndex = _columnIndex;
}

void Block::setLowerLayerIndex(int _lowerLayerIndex)
{
	lowerLayerIndex = _lowerLayerIndex;
}

void Block::setUpperLayerIndex(int _upperLayerIndex)
{
	upperLayerIndex = _upperLayerIndex;
}

void Block::setSinglePartHeight(double _singlePartHeight)
{
	singlePartHeight = _singlePartHeight;
}

void Block::setValue(long long _value)
{
	value = _value;
}

void Block::setMultiplier(int _multiplier)
{
	multiplier = _multiplier;
}

