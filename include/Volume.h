/**
*	@file Volume.h contains the declaration of class "Volume"
*	@author Pengjie Zhang
*	@date 2014-7-23
*/
#ifndef _VOLUME_H_
#define _VOLUME_H_

#include "Metric.h"
#include "Block.h"
#include <vector>
using namespace std;


/**
*	@brief class "Volume" declare basic information for infarctate volume
*
*	class "Volume" consists of many "Block"s, these "Block"s are stored in a specific order for saving of space and analysing time.
*/
class Volume{
	public:
		///> default constructor
		Volume(){}
		///> overloaded constructor
		Volume(long long _value, int _multiplier):value(_value), multiplier(_multiplier){}
		///> overloaded constructor
		Volume(const Volume &v)
		{
			this->value = v.value; 
			this->multiplier = v.multiplier;
			this->storage = v.storage;
		}
		Volume(vector<vector<Block> > &s)
		{
			this->storage = s;
			if(s.size() > 0 && s[0].size() > 0)
			{
				this->value = s[0][0].getValue();
				this->multiplier = s[0][0].getMultiplier();
			}
		}
		///> destructor
		~Volume(){}
	public:
		///> get the value of the volume
		long long getValue();
		///> get the multiplier used by "value"
		int getMultiplier();
		///> get the number of rows of the volume
		int getNumOfPlanes();
		///> get specific row. all blocks in this row line up, they stands vertically 
		vector<Block> getSpecificPlane(int index);
	public:
		///> set teh value for this volume
		void setValue(long long _value);
		///> set the multiplier used by "value"
		void setMultiplier(int _multiplier);
		///> set specific row of Blocks
		bool setSpecificPlane(const vector<Block> &argu, int index);
	public:
		///> get the bounding cuboid of this volume
		Cuboid getBoundingCuboid();
		///> get the occupied 3D space of the volume, parameter metric designate the metric used, can be "METER" or "KILOMETER" etc
		double getRealVolumeSize(const Metric &metric);
		///> get the shell area of the volume, paramter metric designate the metric used, can be "METER" or "KILOMETER" etc
		double getRealShellAreaSize(const Metric &metric);
	private:
		vector<vector<Block> > storage;
		long long value;
		int multiplier;
};

#endif
