#include "Utility.h"

Utility* Utility::instance = nullptr;

Utility* Utility::getInstance()
{
	if (instance == nullptr) 
		instance = new Utility();
	return instance;
}

double Utility::roundTo(double d, double n) { return round(d * pow(10,n)) / pow(10, n); }
double Utility::r2d(double r) { return r * (180 / PI); }
double Utility::d2r(double d) { return d * (PI / 180); }