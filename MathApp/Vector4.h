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
	inline double getW() const { return w; }
	inline void setW(double ww) { w = ww; }
	inline double getX() const { return x; }
	inline void setX(double xx) { x = xx; }
	inline double getY() const { return y; }
	inline void setY(double yy) { y = yy; }
	inline double getZ() const { return z; }
	inline void setZ(double zz) { z = zz; }

	// methods - math functions that will do cooler things
	// these methods' functionality are briefly explained in Vector2.cpp
	inline Vector4 add(const Vector4&) const;
	inline Vector4 add(double, double, double, double) const;
	inline Vector4 sub(const Vector4&) const;
	inline Vector4 sub(double, double, double, double) const;
	Vector4 scalarMultiplication(double) const;
	double mag() const;
	Vector4 normalize() const;
	double dotProduct(const Vector4&) const;
	Vector4 rotateVector(double) const;

	Vector4 operator+(const Vector4& v) const { return Vector4(this->w + v.w, this->x + v.x, this->y + v.y, this->z + v.z); }
	Vector4 operator-(const Vector4& v) const { return Vector4(this->w - v.w, this->x - v.x, this->y - v.y, this->z - v.z); }

	// other useful methods that don't deal with math
	const inline void display() const { cout << "[" << w << ", " << x << ", " << y << ", " << z << "]" << endl; };
	inline void toString() const { cout << ""; }

private:
	// variables
	double w, x, y, z;

	// constructor(s) / destructor


	// methods

};

#endif // !VECTOR4_H