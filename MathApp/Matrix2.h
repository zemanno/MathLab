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
	Matrix2(const Vector2& c1, const Vector2& c2) : row01(c1), row02(c2) {}
	Matrix2(double a, double b, double c, double d) : row01(Vector2(a, b)), row02(Vector2(c, d)) {}
	~Matrix2() { delete u; };

	// methods
	inline Vector2 getRow01() { return row01; }
	inline Vector2 getRow02() { return row02; }
	Vector2 mulMatrixByColVec(const Vector2&) const;

	inline void setRow01(Vector2 r1) { row01 = r1; }
	inline void setRow02(Vector2 r2) { row02 = r2; }
	inline void display() const;
	void setMatrix(const Vector2&, const Vector2&);
	void setRotationMatrix(double);
	void setScalingMatrix(double, double);
	void setIdentityMatrix();
	void addMatrix(Matrix2&);
	void subMatrix(Matrix2&);
	void transpose();

	double determinant(const Matrix2& m) const { return (m.row01.getX() * m.row02.getY()) - (m.row01.getY() * m.row02.getX()); }

	Matrix2 mulMatrix(Matrix2&);
	Matrix2 operator+(Matrix2& m) 
	{ 
		return Matrix2
		(
			Vector2(this->row01.getX() + m.row01.getX(), this->row02.getX() + m.row02.getX()),
			Vector2(this->row01.getY() + m.row01.getY(), this->row02.getY() + m.row02.getY())
		); 
	}

	Matrix2 operator-(Matrix2& m)
	{
		return Matrix2
		(
			Vector2(this->row01.getX() - m.row01.getX(), this->row02.getX() - m.row02.getX()),
			Vector2(this->row01.getY() - m.row01.getY(), this->row02.getY() - m.row02.getY())
		);
	}

private:
	// variables
	Vector2 row01, row02;
	double r1c1=0, r1c2=0, r2c1=0, r2c2=0;
	Utility *u = Utility::getInstance();

	// constructor(s) / destructor


	// methods

};

#endif // !MATRIX2_H

/*
public static Vector2 MulMatrixByColumnVector(Vector2 rowZero, Vector2 rowOne, Vector2 columnVector)
{
Vector2 ans = new Vector2();
ans.x = (rowZero.x * columnVector.x) + (rowZero.y * columnVector.y);
ans.y = (rowOne.x * columnVector.x) + (rowOne.y * columnVector.y);
return ans;
}

public static Matrix2 Multiply(Matrix2 m1, Matrix2 m2)
{
Matrix2 ans = new Matrix2();
ans.x.x = (m1.x.x * m2.y.x) + (m1.x.y * m2.y.x);
ans.x.y = (m1.x.x * m2.y.y) + (m1.x.y * m2.y.y);
ans.y.x = (m1.y.x * m2.x.x) + (m1.y.y * m2.y.x);
ans.y.y = (m1.y.x * m2.x.y) + (m1.y.y * m2.y.y);
return ans;
}

public static Matrix2 RotationMatrix(double angle)
{
Matrix2 m = new Matrix2();
// angle *= (180 / Math.PI);
m.x.x = Math.Cos(Utility.RadiansToDegrees(angle));
m.x.y = -Math.Sin(Utility.RadiansToDegrees(angle));
m.y.x = Math.Sin(Utility.RadiansToDegrees(angle));
m.y.y = m.x.x;
return m;
}

public static Matrix2 ScalingMatrix(Vector2 scaleFactor)
{
Matrix2 m = new Matrix2();
m.x.x = scaleFactor.x;
m.x.y = 0;
m.y.x = 0;
m.y.y = scaleFactor.y;
return m;
}

public static Matrix2 UnitMatrix()
{
Matrix2 m = new Matrix2();
m.x.x = 1;
m.x.y = 0;
m.y.x = 0;
m.y.y = 1;
return m;
}

public static void Display(Matrix2 m)
{
Console.WriteLine(Utility.Round(m.x.x, 4) + " " + Utility.Round(m.x.y, 4) + "\n" + Utility.Round(m.y.x, 4) + " " + Utility.Round(m.y.y, 4));
}
*/