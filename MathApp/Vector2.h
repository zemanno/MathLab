/// Author: Norbert Zeman
/// Date: Wednesday September 19, 2018
/// File: Vector2.h
/// Description: This is a header file that defines all variables/constructors/destructor/methods
///				 for performing mathematical computations on 2-dimensionsal vector variables

#pragma once
#ifndef VECTOR2_H
#define VECTOR2_H
#define PI 3.141592
#include <string>
#include <iostream>
#include "Utility.h"
using namespace std;

class Vector2
{
public:
	// variables
	

	// constructor(s) / destructor
	Vector2() {};
	Vector2(double xx, double yy) : x(xx), y(yy) {};
	~Vector2() { delete u; };

	// methods - accessors and mutators
	inline double getX() const { return x; }
	inline double getY() const { return y; }
	inline void setX(double xx) { x = xx; }
	inline void setY(double yy) { y = yy; }

	// methods - math functions that will do cooler things
	// these methods' functionality are briefly explained in Vector2.cpp
	inline Vector2 add(const Vector2&) const;
	inline Vector2 add(double, double) const;
	inline Vector2 sub(const Vector2&) const;
	inline Vector2 sub(double, double) const;
	inline Vector2 scalarMultiplication(double) const;
	inline Vector2 normalize() const;
	inline Vector2 perpendicular() const;
	inline Vector2 lerp(Vector2&, double) const;
	inline Vector2 rotateVector(double) const;

	inline double max(const Vector2&) const;
	inline double dotProduct(const Vector2&) const;
	inline double mag() const;
	inline double getAngleInDegrees() const;
	inline double getAngleBetweenVector(Vector2&) const;
	
	inline bool isPerpendicularTo(const Vector2&) const;

	// overloading operators
	inline const Vector2 operator+(const Vector2& const v) const { return Vector2(this->x + v.x, this->y + v.y); }
	inline const Vector2 operator-(const Vector2& const v) const { return Vector2(this->x - v.x, this->y - v.y); }

	// other useful methods that don't deal with math
	inline const void display() const { cout << "[" << x << ", " << y << "]" << endl; };
	inline const void toString() const { cout << ""; }

private:
	// variables
	double x, y;
	Utility *u = Utility::getInstance();

	// constructor(s) / destructor


	// methods

};

#endif // !VECTOR2_H