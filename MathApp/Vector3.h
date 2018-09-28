/// Author: Norbert Zeman
/// Date: Wednesday September 19, 2018
/// File: Vector2.h
/// Description: This is a header file that defines all variables/constructors/destructor/methods
///				 for performing mathematical computations on 3-dimensionsal vector variables

#pragma once
#ifndef VECTOR3_H
#define VECTOR3_H
#define PI 3.141592
#include <string>
#include <iostream>
#include "Utility.h"
#include "Vector2.h"
using namespace std;

class Vector3
{
public:
	// constructor(s) / destructor
	Vector3() {};
	Vector3(double xx, double yy, double zz) : x(xx), y(yy), z(zz) {};
	~Vector3() {};

	// methods - accessors and mutators
	inline double getX() const { return x; }
	inline double getY() const { return y; }
	inline double getZ() const { return z; }
	inline void setX(double xx) { x = xx; }
	inline void setY(double yy) { y = yy; }
	inline void setZ(double zz) { z = zz; }

	// methods - math functions that will do cooler things
	// these methods' functionality are briefly explained in Vector2.cpp
	inline Vector3 add(const Vector3&) const;
	inline Vector3 add(double, double, double) const;
	inline Vector3 sub(const Vector3&) const;
	inline Vector3 sub(double, double, double) const;
	inline Vector3 crossProduct(const Vector3&) const;
	inline Vector3 getUprightSpace(const Vector3&, const Vector3&, const Vector3&, const Vector3&, const Vector3&) const;
	inline Vector3 getWorldSpace(const Vector3&, const Vector3&, const Vector3&, const Vector3&, const Vector3&) const;
	inline Vector3 normalize() const;
	inline Vector3 rotateVector(double) const;
	inline Vector3 scalarMultiplication(double) const;
	inline Vector3 toVector3(double) const;
	inline Vector3 toVector3(const Vector2&) const;
	inline Vector3 vectorSquared() const;
	
	inline double dotProduct(const Vector3& const) const;
	inline double getAngleBetweenVector(Vector3&) const;
	inline double mag() const;
	inline double max() const;

	inline const Vector3 operator+(const Vector3& const v) const { return Vector3(this->x + v.x, this->y + v.y, this->z + v.z); }
	inline const Vector3 operator-(const Vector3& const v) const { return Vector3(this->x - v.x, this->y - v.y, this->z - v.z); }

	// other useful methods that don't deal with math
	inline const void display() const { cout << "X = " << x << ", Y = " << y << ", Z = " << z << endl; };
	inline void toString() const { cout << ""; }

private:
	// variables
	double x, y, z;
};

#endif // !VECTOR3_H