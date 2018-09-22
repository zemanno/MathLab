/// Author: Norbert Zeman
/// Date: Wednesday September 19, 2018
/// File: Vector2.cpp
/// Description: This is the source file for the Vector2.h header. Here is where those 
///				 pre-defined methods will be given instructions to carry out their tasks.

// gotta make sure the Vector2.h header makes it here, right?
#include "Vector3.h"

Vector3 Vector3::add(const Vector3& v) { return Vector3(v.x + this->x, v.y + this->y, v.z + this->z); }
Vector3 Vector3::add(double a, double b, double c) { return Vector3(a + this->x, b + this->y, c + this->z); }

Vector3 Vector3::sub(const Vector3& v) { return Vector3(this->x - v.x, this->x - v.y, this->z = v.z); }
Vector3 Vector3::sub(double a, double b, double c) { return Vector3(this->x - a, this->x - b, this->z - c); }

Vector3 Vector3::scalarMultiplication(double a) { return Vector3(this->x * a, this->y * a, this->z * a); }

Vector3 Vector3::normalize() { return Vector3(this->x / mag(), this->y / mag(), this->z / mag()); }

double Vector3::dotProduct(const Vector3& v) { return (this->x * v.x) + (this->y * v.y) + (this->z * v.z); }

double Vector3::mag()
{
	double sumx2y2z2 = pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2);
	return sqrt(sumx2y2z2);
}

double Vector3::getAngleBetweenVector(Vector3& v)
{
	double magA = mag();
	double magB = v.mag();
	double dot = dotProduct(v);
	return (acos((dot / (magA * magB)))) * (180 / PI);
}

// NEEDS WORK
Vector3 Vector3::rotateVector(double a)
{

	return Vector3();
}

double Vector3::discriminant()
{
	return 0;
}

double Vector3::getRoot()
{
	return 0;
}