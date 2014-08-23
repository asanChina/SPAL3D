/**
*	@file Block.h contains the definition of the class "Block"
*	@author Pengjie Zhang
*	@date 2014-6-30
*/

#ifndef _BLOCK_H_
#define _BLOCK_H_

#include "Metric.h"
#include "Cuboid.h"
/**
*	@brief class "Block" is specific for our project
*
*	class "Block" on one hand have all properties inherit from "Cuboid", the meanings of member variables are the same with in "Cuboid", on the other hand, for our project, "Block" should have some other info to record its position after interpolating the "GridLayer", so we will add "indexing" properties to "Block" 
*/
class Block: public Cuboid{
	public:
		///default constructor
		Block(){
			singlePartHeight= 0.0;
		}
		///constructor set indexing information for this block
		Block(int _rowIndex, int _columnIndex, int _lowerLayerIndex, int _upperLayerIndex){
			rowIndex = _rowIndex;
			columnIndex = _columnIndex;
			lowerLayerIndex = _lowerLayerIndex;
			upperLayerIndex = _upperLayerIndex;
			singlePartHeight = 0.0;
		}
		///constructor set some real geometric information and indexing information for the block
		Block(double _longitude, double _latitude, double _length, Metric _lengthMetric, double _width, Metric _widthMetric, double _height, Metric _heightMetric, double _groundToLowerBase, int _rowIndex, int _columnIndex, int _lowerLayerIndex, int _upperLayerIndex):Cuboid(_longitude, _latitude, _length, _lengthMetric, _width, _widthMetric, _height, _heightMetric, _groundToLowerBase){
			rowIndex = _rowIndex;
			columnIndex = _columnIndex;
			lowerLayerIndex = _lowerLayerIndex;
			upperLayerIndex = _upperLayerIndex;
			singlePartHeight = 0.0;
		}
		~Block(){}
	public:
		///> getter. get the row index of the block
		int getRowIndex();
		///> getter. get the column index of the block
		int getColumnIndex();
		///> getter. get the lower layer index
		int getLowerLayerIndex();
		///> getter. get the upper layer index
		int getUpperLayerIndex();
		///> getter. get the single length used by this block
		double getSinglePartHeight();
		///> getter. get the value store in this block
		long long getValue();
		///> getter. get the "multiplier" used by "value"
		int getMultiplier();
	public:
		///> setter. set the row index of the block, seldom used, included here just for completeness
		void setRowIndex(int _rowIndex);
		///> setter. set the column index of the block, seldom used, included here just for completeness
		void setColumnIndex(int _columnIndex);
		///> setter. set the lower layer index of the block, seldom used, included here just for completeness
		void setLowerLayerIndex(int _lowerLayerIndex);
		///> setter. set the upper layer index of the block, seldom used, included here just for completeness
		void setUpperLayerIndex(int _upperLayerIndex);
		///> setter. set the single length used by this block.
		void setSinglePartHeight(double _singlePartHeight);
		///> setter. set the value stores in block
		void setValue(long long _value);
		///> setter. set the "multiplier" used by "value"
		void setMultiplier(int _multiplier);
	private:
		int rowIndex; ///< the row index of the base cell of this block  
		int columnIndex; ///< the column index of the base cell of this block
		int lowerLayerIndex; ///< the lower layer index in the interpolated grid layer
		int  upperLayerIndex; ///< the upper layer index in the interpolated grid layer
		double singlePartHeight; ///< equal to this.length/(upperLayerIndex - lowerLayerIndex+1)
		long long value;
		int multiplier;
};

#endif
