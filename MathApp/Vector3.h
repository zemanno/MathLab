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
using namespace std;

class Vector3
{
public:
	// variables


	// constructor(s) / destructor
	Vector3() { u = Utility::getInstance(); };
	Vector3(double xx, double yy, double zz) : x(xx), y(yy), z(zz) { u = Utility::getInstance(); };
	~Vector3() { delete u; };

	// methods - accessors and mutators
	inline double getX() { return x; }
	inline void setX(double xx) { x = xx; }
	inline double getY() { return y; }
	inline void setY(double yy) { y = yy; }
	inline double getZ() { return z; }
	inline void setZ(double zz) { z = zz; }

	// methods - math functions that will do cooler things
	// these methods' functionality are briefly explained in Vector2.cpp
	inline Vector3 add(const Vector3&);
	inline Vector3 add(double, double, double);
	inline Vector3 sub(const Vector3&);
	inline Vector3 sub(double, double, double);
	Vector3 scalarMultiplication(double);
	Vector3 normalize();
	Vector3 rotateVector(double);


	inline double dotProduct(const Vector3& const);
	double getAngleBetweenVector(Vector3&);
	double mag();
	double discriminant();
	double getRoot();
	double vectorSquared();
	double max();


	const Vector3 operator+(const Vector3& const v) { return Vector3(this->x + v.x, this->y + v.y, this->z + v.z); }
	const Vector3 operator-(const Vector3& const v) { return Vector3(this->x - v.x, this->y - v.y, this->z - v.z); }

	// other useful methods that don't deal with math
	const inline void display() { cout << "X = " << x << ", Y = " << y << ", Z = " << z << endl; };
	inline void toString() { cout << ""; }

	/*
	Vector2 getRoots(const Vector3& const);
	Vector2 getRoots(double, double, double);
	Vector2 solve2Equations(const Vector3& const, const Vector3& const);

	Vector3 cross(const Vector3& const, const Vector3& const);
	Vector3 div(const Vector3&, double);
	Vector3 getUprightSpace(const Vector3&, const Vector3&, const Vector3&, const Vector3&, const Vector3&);
	Vector3 getWorldSpace(const Vector3&, const Vector3&, const Vector3&, const Vector3&, const Vector3&);
	Vector3 homogenousCoordinates(Vector2);
	Vector3 max(const Vector3&, const Vector3&);
	Vector3 multiply(double, const Vector3&);
	Vector3 normalize(const Vector3&);
	Vector3 subtract(const Vector3& const, const Vector3& const);
	Vector3 toVector3(double);
	*/

private:
	// variables
	Utility *u;
	double x, y, z;

	// constructor(s) / destructor


	// methods

};

#endif // !VECTOR3_H