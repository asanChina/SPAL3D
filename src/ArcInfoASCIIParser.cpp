#include "ArcInfoASCIIParser.h"
#include <fstream>
using namespace std;

bool ArcInfoASCIIParser::parse(GridLayer &gl, int multiplier /*= 1*/)
{
	//first we need to read in data
	ifstream ifs(filePath.c_str());	
	//get file header info from the file
	char tmp[50];
	double xllcorner, yllcorner, cellsize;
	int novalue;
	int nrows, ncols;
	ifs >> tmp >> ncols >> tmp >> nrows;
	ifs >> tmp >> xllcorner >> tmp >> yllcorner >> tmp >> cellsize >> tmp >> novalue;
	GeometricInfo geoinfo(xllcorner, yllcorner, cellsize, METER);
	gl.setGeometricInfo(geoinfo);

	//next we need to open meta file, save this meta info into gl.dataInfo if gl.dataInfo is not exist
	string meta("_meta");
	ifstream metaifs((filePath+meta).c_str());
	DataInfo datainfo;
	metaifs >> datainfo;
	datainfo.multiplier = multiplier;
	datainfo.noValue = novalue;
	gl.setDataInfo(datainfo);
	metaifs.close();
	
	vector<vector<long long> > layer(nrows, vector<long long>(ncols));
	for(int i = 0; i < nrows; i++)
		for(int j = 0; j < ncols; j++)
		{
			double u;
			ifs >> u;
			long long v = u * multiplier;
			layer[i][j] = v;
		}
	ifs.close();
	return gl.insertLayer(layer, gl.getNumOfLayers());
}
