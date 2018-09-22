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
	inline double getX() { return x; }
	inline void setX(double xx) { x = xx; }
	inline double getY() { return y; }
	inline void setY(double yy) { y = yy; }

	// methods - math functions that will do cooler things
	// these methods' functionality are briefly explained in Vector2.cpp
	inline Vector2 add(const Vector2&);
	inline Vector2 add(double, double);
	inline Vector2 sub(const Vector2&);
	inline Vector2 sub(double, double);
	inline Vector2 scalarMultiplication(double);
	inline Vector2 normalize();
	inline Vector2 perpendicular();
	Vector2 lerp(Vector2&, double);
	Vector2 rotateVector(double);

	inline double max(const Vector2&);
	inline double dotProduct(const Vector2&);
	double mag();
	double getAngleInDegrees();
	double getAngleBetweenVector(Vector2&);
	
	bool isPerpendicularTo(const Vector2&);

	// overloading operators
	const Vector2 operator+(const Vector2& const v) { return Vector2(this->x + v.x, this->y + v.y); }
	const Vector2 operator-(const Vector2& const v) { return Vector2(this->x - v.x, this->y - v.y); }

	// other useful methods that don't deal with math
	const inline void display() { cout << "X = " << x << ", Y = " << y << endl; };
	inline void toString() { cout << ""; }

private:
	// variables
	double x, y;
	Utility *u = Utility::getInstance();

	// constructor(s) / destructor


	// methods

};

#endif // !VECTOR2_H