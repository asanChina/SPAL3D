#include "ArcInfoASCIIGenerator.h"
#include <fstream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;

bool ArcInfoASCIIGenerator::generate(double minValue, double maxValue, double step, int numOfDecimals, double noValuePercent)
{
	//we need to save this functions parameters in another meta file, because this parameters should help in GridLayer
	string meta = fileDirectory + fileName + string("_meta");
	ofstream metaofs(meta.c_str());
	metaofs << minValue << ' ' << maxValue << ' ' << step << ' ' << numOfDecimals << ' ' << noValuePercent << endl;
	metaofs.close();


	//now begin file the data file
	ofstream ofs((fileDirectory+fileName).c_str());

	//first output the file header into the open file
	ofs << fileHeader;	

	//next restrict all minValue, maxValue, step to the requirement---numOfDecimals
	int multiplier = pow(10, numOfDecimals);
	int tempmin = minValue * multiplier;	minValue = (double)tempmin/multiplier;
	int tempmax = maxValue * multiplier;	maxValue = (double)tempmax/multiplier;
	int tempstep = step * multiplier;	step = (double)tempstep/multiplier;

	//we would make a map to store all values that can appear in data file
	//in using this method, the maxValue may never exist in data file
	//say minValue = 2.0, step = 2.0, maxValue = 16.0; then we can have 2.0, 4.0, 6.0, 8.0, 10.0, 12.0, 14.0, 16.0 in data file
	int num = (maxValue - minValue)/step + 1;
	vector<double> map(num);
	for(int i = 0; i < num; i++)
		map[i] = minValue + step * i;
	
	//begin generate the data
	srand(time(NULL));
	for(int i = 0; i < fileHeader.nRows; i++)
	{
		for(int j = 0; j < fileHeader.nCols; j++)
		{
			if((double)rand()/(double)RAND_MAX < noValuePercent)
				ofs << fileHeader.noValue << ' ';
			else
				ofs << map[rand()%num] << ' ';
		}
		ofs << endl;
	}
	ofs.close();
	return true;
}

void ArcInfoASCIIGenerator::setHeader(int nrows, int ncols, double xllcorner, double yllcorner, double cellsize, int novalue)
{
	fileHeader.nRows = nrows;
	fileHeader.nCols = ncols;
	fileHeader.xllCorner = xllcorner;
	fileHeader.yllCorner = yllcorner;
	fileHeader.cellSize = cellsize;
	fileHeader.noValue = novalue;
}

void ArcInfoASCIIGenerator::setHeader(ArcInfoASCIIGenerator::FileHeader &tmpHeader)
{
	fileHeader = tmpHeader;
}

ArcInfoASCIIGenerator::FileHeader& ArcInfoASCIIGenerator::getHeader()
{
	return this->fileHeader;
}

bool ArcInfoASCIIGenerator::isValid()
{
	if( fileHeader.nCols > 0 && fileHeader.nRows > 0)
		return true;
	else
		return false;
}

ostream& operator<<(ostream& os, const ArcInfoASCIIGenerator::FileHeader& fh)
{
	os << "ncols	" << fh.nCols << endl \
		<<"nrows	" << fh.nRows << endl \
		<<"xllcorner	" << fh.xllCorner << endl \
		<<"yllcorner	" << fh.yllCorner << endl \
		<<"cellsize	" << fh.cellSize << endl \
		<<"NODATA_VALUE	" << fh.noValue << endl;
	return os;
}

istream& operator>>(istream& is, ArcInfoASCIIGenerator::FileHeader& fh)
{
	is >> fh.nCols >> fh.nRows >> fh.xllCorner >> fh.yllCorner >> fh.cellSize >> fh.noValue;
	if(!is)
		fh = ArcInfoASCIIGenerator::FileHeader();
	return is;
}

