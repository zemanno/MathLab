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
	Matrix2(const Vector2& r1, const Vector2& r2) : row00(r1), row01(r2) {}
	Matrix2(double a, double b, double c, double d) : row00(Vector2(a, b)), row01(Vector2(c, d)) {}
	~Matrix2() { delete u; };

	// methods
	inline Vector2 getRow00() { return row00; }
	inline Vector2 getRow01() { return row01; }
	inline void setRow00(Vector2 r0) { row00 = r0; }
	inline void setRow01(Vector2 r1) { row01 = r1; }

	Vector2 mul(const Vector2&) const;
	inline void display() const;
	void setMatrix(const Vector2&, const Vector2&);
	void setRotationMatrix(double);
	void setScalingMatrix(double, double);
	void setIdentityMatrix();
	void addMatrix(Matrix2&);
	void subMatrix(Matrix2&);
	void transpose();

	double determinant(const Matrix2& m) const { return (m.row00.getX() * m.row01.getY()) - (m.row00.getY() * m.row01.getX()); }

	Matrix2 mul(Matrix2&);
	Matrix2& operator+(Matrix2& m)
	{
		return Matrix2
		(
			Vector2(this->row00.getX() + m.row00.getX(), this->row00.getY() + m.row00.getY()),
			Vector2(this->row01.getX() + m.row01.getX(), this->row01.getY() + m.row01.getY())
		);
	}

	Matrix2& operator-(Matrix2& m)
	{
		return Matrix2
		(
			Vector2(this->row00.getX() - m.row00.getX(), this->row00.getY() - m.row00.getY()),
			Vector2(this->row01.getX() - m.row01.getX(), this->row01.getY() - m.row01.getY())
		);
	}

private:
	// variables
	Vector2 row00, row01;
	double r1c1=0, r1c2=0, r2c1=0, r2c2=0;
	Utility *u = Utility::getInstance();
};

#endif // !MATRIX2_H