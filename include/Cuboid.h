/**
*	@brief class "Cuboid" is a cuboid which exist in 3D geometric space
*
*	This class defines fundamental properties and functions of a "Cuboid". These is an issue with function "setLength(...)", "setLengthMetric(...)", should we combine these two as one function since these two are strongly related
*/


#ifndef _CUBOID_H_
#define _CUBOID_H_

#include "Metric.h"


class Cuboid{
	public:
		Cuboid(){
			lengthMetric = widthMetric = heightMetric = METER;
		}
		Cuboid(double _longitude, double _latitude, double _length, Metric _lengthMetric, double _width, Metric _widthMetric, double _height, Metric _heightMetric, double _groundToLowerBase):longitude(_longitude), latitude(_latitude), length(_length), lengthMetric(_lengthMetric), width(_width), widthMetric(_widthMetric), height(_height), heightMetric(_heightMetric), groundToLowerBase(_groundToLowerBase){}
		Cuboid(double _longitude, double _latitude, double _length, double _width, double _height, double _groundToLowerBase):longitude(_longitude), latitude(_latitude), length(_length), width(_width), height(_height), groundToLowerBase(_groundToLowerBase){
			lengthMetric = widthMetric = heightMetric = METER;
		}
		~Cuboid(){}
	public:
		///> getter. get the longitude of the bounding cuboid
		double getLongitude();
		///> getter. get the latitude of the bounding cuboid
		double getLatitude();
		///> getter. get the length of the bounding cuboid
		double getLength();
		///> getter. get the metric used by length
		Metric getLengthMetric();
		///> getter. get the width of the bounding cuboid
		double getWidth();
		///> getter. get the metric used by width
		Metric getWidthMetric();
		///> getter. get the height of the bounding cuboid
		double getHeight();
		///> getter. get the metric used by height
		Metric getHeightMetric();
		///> getter. get the vertical distance from ground to lower base
		double getGroundToLowerBase();
	public:
		///> setter. set the longitude of the bounding cuboid
		void setLongitude(double _longitude);
		///> setter. set the latitude of the bounding cuboid
		void setLatitude(double _latitude);
		///> setter. set the length of the bounding cuboid
		void setLength(double _length);
		///> setter. set the metric used by "length"
		void setLengthMetric(Metric _lengthMetric);
		///> setter. set the width of the bounding cuboid
		void setWidth(double _width);
		///> setter. set the metric used by "width"
		void setWidthMetric(Metric _widhtMetric);
		///> setter. set the height of the cuboid
		void setHeight(double _height);
		///> setter. set the metric used by "height"
		void setHeightMetric(Metric _heightMetric);
		///> setter. set the ground to lower base distance
		void setGroundToLowerBase(double _groundToLowerBase);
	public:
		///> get the area of the base. parameter metric designate the metric used when calculating
		double getBaseAreaSize(const Metric &metric);
		///> get the shell area size
		double getShellAreaSize(const Metric &metric);
		///> get the cuboid's volume size
		double getVolumeSize(const Metric &metric);
	protected:
		///> longitude of southwest point of the lower base
		double longitude;
		///> latitude of southwest point of the lower base
		double latitude;
		///> distance from west to east
		double length;
		///> metric used by "length"
		Metric lengthMetric;
		///> distance from north to south
		double width;
		///> metric used by "width"
		Metric widthMetric;
		///> vertical distance from lower base to upper base
		double height;
		///> metric used by "height", this metric is same with metric used by "groundToLowerBase"
		Metric heightMetric;
		///> vertical distance from earth surface to lower base
		double groundToLowerBase;
};


#endif
