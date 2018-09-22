/// Author: Norbert Zeman
/// Date: Wednesday September 19, 2018
/// File: Vector2.h
/// Description: This is a header file that defines all variables/constructors/destructor/methods
///				 for performing mathematical computations on 3x3 matrix variables

#pragma once
#ifndef MATRIX3_H
#define MATRIX3_H
#define PI 3.141592
#include <string>
#include <iostream>
#include "Utility.h"
#include "Vector3.h"
using namespace std;

class Matrix3
{
public:
	// variables


	// constructor(s) / destructor
	Matrix3() {};
	Matrix3(const Vector3& v1, const Vector3& v2, const Vector3& v3) : column1(v1), column2(v2), column3(v3) {};
	~Matrix3() {};

	// methods


	Matrix3& operator+(Matrix3& m)
	{
		return Matrix3
		(
			Vector3(this->column1.getX() + m.column1.getX(), this->column2.getX() + m.column2.getX(), this->column3.getX() + m.column3.getX()),
			Vector3(this->column1.getY() + m.column1.getY(), this->column2.getY() + m.column2.getY(), this->column3.getY() + m.column3.getY()),
			Vector3(this->column1.getZ() + m.column1.getZ(), this->column2.getZ() + m.column2.getZ(), this->column3.getZ() + m.column3.getZ())
		);
	}
	Matrix3& operator-(Matrix3& m)
	{
		return Matrix3
		(
			Vector3(this->column1.getX() - m.column1.getX(), this->column2.getX() - m.column2.getX(), this->column3.getX() - m.column3.getX()),
			Vector3(this->column1.getY() - m.column1.getY(), this->column2.getY() - m.column2.getY(), this->column3.getY() - m.column3.getY()),
			Vector3(this->column1.getZ() - m.column1.getZ(), this->column2.getZ() - m.column2.getZ(), this->column3.getZ() - m.column3.getZ())
		);
	}

	void transpose();
	inline void display();

private:
	// variables
	Vector3 column1, column2, column3;
	double r1c1 = 0, r1c2 = 0, r2c1 = 0, r2c2 = 0;

	// constructor(s) / destructor


	// methods

};

#endif // !MATRIX3_H