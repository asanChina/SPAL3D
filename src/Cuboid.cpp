#include "Cuboid.h"

double Cuboid::getLongitude()
{
	return longitude;
}

double Cuboid::getLatitude()
{
	return latitude;
}

double Cuboid::getLength()
{
	return length;
}

Metric Cuboid::getLengthMetric()
{
	return lengthMetric;
}

double Cuboid::getWidth()
{
	return width;
}

Metric Cuboid::getWidthMetric()
{
	return widthMetric;
}

double Cuboid::getHeight()
{
	return height;
}

Metric Cuboid::getHeightMetric()
{
	return heightMetric;
}

double Cuboid::getGroundToLowerBase()
{
	return groundToLowerBase;
}




void Cuboid::setLongitude(double _longitude)
{
	longitude = _longitude;
}

void Cuboid::setLatitude(double _latitude)
{
	latitude = _latitude;
}

void Cuboid::setLength(double _length)
{
	length = _length;
}

void Cuboid::setLengthMetric(Metric _lengthMetric)
{
	lengthMetric = _lengthMetric;
}

void Cuboid::setWidth(double _width)
{
	width = _width;
}

void Cuboid::setWidthMetric(Metric _widthMetric)
{
	widthMetric = _widthMetric;
}

void Cuboid::setHeight(double _height)
{
	height = _height;
}

void Cuboid::setHeightMetric(Metric _heightMetric)
{
	heightMetric = _heightMetric;
}

void Cuboid::setGroundToLowerBase(double _groundToLowerBase)
{
	groundToLowerBase = _groundToLowerBase;
}




double Cuboid::getBaseAreaSize(const Metric &metric)
{
	double area = 0.0;

	switch(metric)
	{
		case METER:	
			switch(lengthMetric)
			{
				case METER:
					switch(widthMetric)
					{
						case METER: area = length*width; break;
						case KILOMETER: area = length*width*1000; break;
						default: area = -1.0; break;
					}
				case KILOMETER:
					switch(widthMetric)
					{
						case METER: area = length*width*1000; break;
						case KILOMETER: area = length*width*1000000; break;
						default: area = -1.0; break;
					}
				default: area = -1.0; break;
			}
		case KILOMETER:
			switch(lengthMetric)
			{
				case METER: 
					switch(widthMetric)
					{
						case METER: area = length*width/1000000; break;
						case KILOMETER: area = length*width/1000; break;
						default: area = -1.0; break;
					}
				case KILOMETER:
					switch(widthMetric)
					{
						case METER: area = length*width/1000; break;
						case KILOMETER: area = length*width; break;
						default: area = -1.0; break;
					}
				default: area = -1.0; break;
			}
		default: area = -1.0; break;		
	}
	return area;
}

double Cuboid::getShellAreaSize(const Metric &metric)
{
	double bases = 2*getBaseAreaSize(metric);
	if(bases < 0)
		return -1.0;

	double heightLengthSides = 0.0;
	double heightWidthSides = 0.0;
	switch(metric)
	{
		case METER:
			switch(heightMetric)
			{
				case METER:
					switch(lengthMetric)
					{
						case METER: heightLengthSides = 2*height*length; break;
						case KILOMETER: heightLengthSides = 2*height*length*1000; break;
						default: heightLengthSides = -1.0; break;
					}
					switch(widthMetric)
					{
						case METER: heightWidthSides = 2*height*width; break;
						case KILOMETER: heightWidthSides = 2*height*width*1000; break;
						default: heightWidthSides = -1.0; break;
					}
				case KILOMETER:
					switch(lengthMetric)
					{
						case METER: heightLengthSides = 2*height*length*1000; break;
						case KILOMETER: heightLengthSides = 2*height*length*1000000; break;
						default: heightLengthSides = -1.0; break;
					}
					switch(widthMetric)
					{
						case METER: heightWidthSides = 2*height*width*1000; break;
						case KILOMETER: heightWidthSides = 2*height*width*1000000; break;
						default: heightWidthSides = -1.0; break;
					}
				default: heightWidthSides = -1.0; heightLengthSides = -1.0; break;
			}			
		case KILOMETER:
			switch(heightMetric)
			{
				case METER:
					switch(lengthMetric)
					{
						case METER: heightLengthSides = 2*height*length/1000000; break;
						case KILOMETER: heightLengthSides = 2*height*length/1000; break;
						default: heightLengthSides = -1.0; break;
					}
					switch(widthMetric)
					{
						case METER: heightWidthSides = 2*height*width/1000000; break;
						case KILOMETER: heightWidthSides = 2*height*width/1000; break;
						default: heightWidthSides = -1.0; break;
					}
				case KILOMETER:
					switch(lengthMetric)
					{
						case METER: heightLengthSides = 2*height*length/1000; break;
						case KILOMETER: heightLengthSides = 2*height*length; break;
						default: heightLengthSides = -1.0; break;
					}
					switch(widthMetric)
					{
						case METER: heightWidthSides = 2*height*width/1000; break;
						case KILOMETER: heightWidthSides = 2*height*width; break;
						default: heightWidthSides = -1.0; break;
					}
				default: heightWidthSides = -1.0; heightLengthSides = -1.0; break;
			}
		default: heightLengthSides = heightWidthSides = -1.0; break;
	}
	if(heightLengthSides < 0 || heightWidthSides < 0)
		return -1.0;
	return bases+heightWidthSides+heightLengthSides;
}


double Cuboid::getVolumeSize(const Metric &metric)
{
	double base = getBaseAreaSize(metric);
	if(base < 0)
		return -1.0;
	
	switch(metric)
	{
		case METER:
			switch(heightMetric)
			{
				case METER: return base*height;
				case KILOMETER: return base*height*1000;
				default: return -1.0;
			}
		case KILOMETER:
			switch(heightMetric)
			{
				case METER: return base*height/1000;
				case KILOMETER: return base*height;
				default: return -1.0;
			}
		default: return -1.0;
	}
}
