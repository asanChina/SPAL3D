#include "LinearInterpolate.h"

bool LinearInterpolate::interpolate(GridLayer &gl, vector<vector<vector<long long> > > &valueSet, DataInfo &datainfo, GeometricInfo &geometricinfo, int intervalIndex)
{
	if(intervalIndex < 0 || intervalIndex >= gl.getNumOfLayers()-1)
		return false;

	datainfo = gl.getDataInfo();		
	long long minValue = datainfo.minValue * datainfo.multiplier;
	long long maxValue = datainfo.maxValue * datainfo.multiplier;
	long long step = datainfo.step * datainfo.multiplier;
	double noValuePercent = datainfo.noValuePercent;
	geometricinfo = gl.getGeometricInfo();

	int n = (maxValue - minValue)/step;
	if(n > 10)
	{
		cout << "Warning in LinearInterpolate::interpolate(...), step for GridLayer value is too small\n";
		return false;
	}
	int leastCommonMultiple = 2;
	for(int i = 2; i <= n; i++)
		leastCommonMultiple = leastCommonMultiple*i*2/euclideanAlgo(leastCommonMultiple, i*2);

	int rows = gl.getNumOfRows();
	int columns = gl.getNumOfColumns();
	vector<vector<vector<long long> > > valueset(leastCommonMultiple, vector<vector<long long> >(rows, vector<long long>(columns, 0)));
	for(int r = 0; r < rows; r++)
		for(int c = 0; c < columns; c++)
		{
			int lowerValue = gl.getCellValue(intervalIndex, r, c);
			int upperValue = gl.getCellValue(intervalIndex+1, r, c);
			if(lowerValue == datainfo.noValue || upperValue == datainfo.noValue)
			{
				for(int k = 0; k < leastCommonMultiple; k++)		
					valueset[k][r][c] = datainfo.noValue;
				continue;
			}
			int subtraction = upperValue - lowerValue;
			int share = abs(subtraction)/step;
			int newStep = subtraction/share;
			for(int i = 0; i < share; ++i)
			{
				int subShare = leastCommonMultiple/share;
				for(int j = i*subShare; j < i*subShare+subShare/2; j++)
					valueset[j][r][c] = lowerValue+i*newStep;
				for(int j = i*subShare+subShare/2; j < (i+1)*subShare; j++)
					valueset[j][r][c] = lowerValue+(i+1)*newStep;
			}
		}
	valueSet = valueset;
	return true;
}

int LinearInterpolate::euclideanAlgo(int first, int second)
{
	if(first <= 0 || second <= 0)
		return -1;

	int maximum = first>second?first:second;
	int minimum = first>second?second:first;

	if(maximum%minimum == 0)
		return minimum;

	while(maximum%minimum != 0)
	{
		int tmp = maximum%minimum;
		maximum = minimum;
		minimum = tmp;	
	}
	return minimum;
}
