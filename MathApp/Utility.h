#pragma once
#ifndef UTILITY_H
#define UTILITY_H
#define PI 3.141592

#include <cmath>



class Utility
{
public:
	// variables
	

	// destructor
	~Utility() {};

	// methods
	static Utility* getInstance();
	static double roundTo(double d, double n);
	static double d2r(double);
	static double r2d(double);

private:
	// variables
	static Utility* instance;
	
	// constructor
	Utility() {};

	// methods
	
};

#endif // !UTILITY_H