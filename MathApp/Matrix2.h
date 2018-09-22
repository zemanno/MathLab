/// Author: Norbert Zeman
/// Date: Wednesday September 19, 2018
/// File: Vector2.h
/// Description: This is a header file that defines all variables/constructors/destructor/methods
///				 for performing mathematical computations on 2x2 matrix variables

#pragma once
#ifndef MATRIX2_H
#define MATRIX2_H
#define PI 3.141592
#include <string>
#include <iostream>
#include "Utility.h"
#include "Vector2.h"
using namespace std;

class Matrix2
{
public:
	// variables


	// constructor(s) / destructor
	Matrix2() {};
	Matrix2(const Vector2& c1, const Vector2& c2) : column1(c1), column2(c2) {}
	Matrix2(double a, double b, double c, double d) : column1(Vector2(a, b)), column2(Vector2(c, d)) {}
	~Matrix2() { delete u; };

	// methods
	inline Vector2 getCol1() { return column1; }
	inline Vector2 getCol2() { return column2; }
	inline void setCol1(Vector2 col1) { column1 = col1; }
	inline void setCol2(Vector2 col2) { column2 = col2; }
	void setMatrix(const Vector2&, const Vector2&);
	void setRotationMatrix(double);
	void setScalingMatrix(double, double);
	void setIdentityMatrix();
	void addMatrix(Matrix2&);
	void subMatrix(Matrix2&);
	Matrix2 mulMatrix(Matrix2&);
	void transpose();

	Matrix2 operator+(Matrix2& m) 
	{ 
		return Matrix2
		(
			Vector2(this->column1.getX() + m.column1.getX(), this->column2.getX() + m.column2.getX()), 
			Vector2(this->column1.getY() + m.column1.getY(), this->column2.getY() + m.column2.getY())
		); 
	}

	Matrix2 operator-(Matrix2& m)
	{
		return Matrix2
		(
			Vector2(this->column1.getX() - m.column1.getX(), this->column2.getX() - m.column2.getX()),
			Vector2(this->column1.getY() - m.column1.getY(), this->column2.getY() - m.column2.getY())
		);
	}

	Matrix2 operator*(Matrix2& m)
	{
		return Matrix2();
	}

	inline void display();

private:
	// variables
	Vector2 column1, column2;
	double r1c1=0, r1c2=0, r2c1=0, r2c2=0;
	Utility *u = Utility::getInstance();

	// constructor(s) / destructor


	// methods

};

#endif // !MATRIX2_H