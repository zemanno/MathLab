/// Author: Norbert Zeman
/// Date: Wednesday September 19, 2018
/// File: Vector2.h
/// Description: This is a header file that defines all variables/constructors/destructor/methods
///				 for performing mathematical computations on 4-dimensionsal vector variables

#pragma once
#ifndef VECTOR4_H
#define VECTOR4_H
#define PI 3.141592
#include <string>
#include <iostream>
#include "Utility.h"
using namespace std;

class Vector4
{
public:
	// variables


	// constructor(s) / destructor
	Vector4() {};
	Vector4(double ww, double xx, double yy, double zz) : w(ww), x(xx), y(yy), z(zz) {};
	~Vector4() {};

	// methods - accessors and mutators
	inline double getW() { return w; }
	inline void setW(double ww) { w = ww; }
	inline double getX() { return x; }
	inline void setX(double xx) { x = xx; }
	inline double getY() { return y; }
	inline void setY(double yy) { y = yy; }
	inline double getZ() { return z; }
	inline void setZ(double zz) { z = zz; }

	// methods - math functions that will do cooler things
	// these methods' functionality are briefly explained in Vector2.cpp
	inline Vector4 add(const Vector4&);
	inline Vector4 add(double, double, double, double);
	inline Vector4 sub(const Vector4&);
	inline Vector4 sub(double, double, double, double);
	Vector4 scalarMultiplication(double);
	double getMagnitude();
	Vector4 normalize();
	double getDotProduct(const Vector4&);
	Vector4 rotateVector(double);

	Vector4 operator+(const Vector4& v) { return Vector4(this->w + v.w, this->x + v.x, this->y + v.y, this->z + v.z); }
	Vector4 operator-(const Vector4& v) { return Vector4(this->w - v.w, this->x - v.x, this->y - v.y, this->z - v.z); }

	// other useful methods that don't deal with math
	inline void display();
	inline void toString() { cout << ""; }

private:
	// variables
	double w, x, y, z;

	// constructor(s) / destructor


	// methods

};

#endif // !VECTOR4_H