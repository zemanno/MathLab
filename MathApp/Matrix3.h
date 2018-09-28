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
	Matrix3(const Vector3& v1, const Vector3& v2, const Vector3& v3) : row01(v1), row02(v2), row03(v3) {};
	~Matrix3() {};

	// methods
	inline Vector3 getRow01() { return row01; }
	inline Vector3 getRow02() { return row02; }
	inline Vector3 getRow03() { return row03; }
	inline void setRow01(Vector3 r1) { row01 = r1; }
	inline void setRow02(Vector3 r2) { row02 = r2; }
	inline void setRow03(Vector3 r3) { row03 = r3; }



	Matrix3& operator+(Matrix3& m)
	{
		return Matrix3
		(
			Vector3(this->row01.getX() + m.row01.getX(), this->row01.getY() + m.row01.getY(), this->row01.getZ() + m.row01.getZ()),
			Vector3(this->row02.getX() + m.row02.getX(), this->row02.getY() + m.row02.getY(), this->row02.getZ() + m.row02.getZ()),
			Vector3(this->row03.getX() + m.row03.getX(), this->row03.getY() + m.row03.getY(), this->row03.getZ() + m.row03.getZ())
		);
	}

	Matrix3& operator-(Matrix3& m)
	{
		return Matrix3
		(
			Vector3(this->row01.getX() - m.row01.getX(), this->row01.getY() - m.row01.getY(), this->row01.getZ() - m.row01.getZ()),
			Vector3(this->row02.getX() - m.row02.getX(), this->row02.getY() - m.row02.getY(), this->row02.getZ() - m.row02.getZ()),
			Vector3(this->row03.getX() - m.row03.getX(), this->row03.getY() - m.row03.getY(), this->row03.getZ() - m.row03.getZ())
		);
	}

	/*
	Vector2 mulMatrixByColVec(const Vector2&) const;
	void setMatrix(const Vector2&, const Vector2&);
	void setRotationMatrix(double);
	void setScalingMatrix(double, double);
	void setIdentityMatrix();
	void addMatrix(Matrix2&);
	void subMatrix(Matrix2&);

	double determinant(const Matrix2& m) const { return (m.row01.getX() * m.row02.getY()) - (m.row01.getY() * m.row02.getX()); }

	Matrix2 mulMatrix(Matrix2&);
	*/
	void transpose();
	inline void display();

private:
	// variables
	Vector3 row01, row02, row03;
	double r00c00 = 0, r00c01 = 0, r00c02 = 0, 
		   r01c00 = 0, r01c01 = 0, r01c02 = 0, 
		   r02c00 = 0, r02c01 = 0, r02c02 = 0;

	// constructor(s) / destructor


	// methods

};

#endif // !MATRIX3_H