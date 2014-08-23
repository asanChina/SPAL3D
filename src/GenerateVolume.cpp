#include "GenerateVolume.h"

bool GenerateVolume::generate(GridLayer &gl, Interpolate &tool, vector<Volume> &result, int value, int intervalIndex)
{
	if(intervalIndex < 0 || intervalIndex >= gl.getNumOfLayers()-1)
		return false;
	
	DataInfo datainfo;
	GeometricInfo geometricinfo;
	vector<vector<vector<long long> > > valueSet;
	tool.interpolate(gl, valueSet, datainfo, geometricinfo, intervalIndex);

	/*
	 unfinished
	*/
	return true;
}
