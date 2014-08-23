#include "Volume.h"

long long Volume::getValue()
{
	return value;
}

int Volume::getMultiplier()
{
	return multiplier;
}

int Volume::getNumOfPlanes()
{
	return storage.size();
}

vector<Block> Volume::getSpecificPlane(int index)
{
	if(getNumOfPlanes() <= index)
	{
		return vector<Block>();
	}	
	return storage[index];
}





void Volume::setValue(long long _value)
{
	value = _value;	
}

void Volume::setMultiplier(int _multiplier)
{
	multiplier = _multiplier;
}

bool Volume::setSpecificPlane(const vector<Block> &argu, int index)
{
	if(index > getNumOfPlanes())
		return false;
	vector<vector<Block> >::iterator ite = storage.begin();
	for(int i = 0; i < index; i++)
		ite++;
	storage.insert(ite, argu);
	return true;
}



///> haven't been finished
Cuboid Volume::getBoundingCuboid()
{
	Cuboid tmp;
	return tmp;
}

///> haven't been finished
double Volume::getRealVolumeSize(const Metric &metric)
{
	return 0.0;
}

///> haven't been finished
double Volume::getRealShellAreaSize(const Metric &metric)
{
	return 0.0;
}
