#include <iostream>
#include <sstream>
#include "ArcInfoASCIIGenerator.h"
#include "ArcInfoASCIIParser.h"
#include "GridLayer.h"
#include "Block.h"
#include "Volume.h"
#include "Interpolate.h"
#include "LinearInterpolate.h"
using namespace std;

int main()
{
	//ArcInfoASCIIGenerator pengjie(20, 10, 0.0, 0.0, 50.0, -9999);
	for(int i = 0; i < 10; i++)
	{
		ArcInfoASCIIGenerator pengjie(20, 10, 0.0, 0.0, 50.0, -9999);
		ostringstream os;
		os << i;
		string fileName = string("ArcInfoASCII")+os.str();
		pengjie.setFileName(fileName);
		pengjie.generate(0,3,1,0,0.07);
		sleep(1);
	}
/*
	ArcInfoASCIIParser zhang("./ArcInfoASCII");
	GridLayer gl;
	zhang.parse(gl, 1); 
*/	
	Block b;
	LinearInterpolate haha;
	return 0;
}
