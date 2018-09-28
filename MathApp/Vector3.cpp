/// Author: Norbert Zeman
/// Date: Wednesday September 19, 2018
/// File: Vector2.cpp
/// Description: This is the source file for the Vector2.h header. Here is where those 
///				 pre-defined methods will be given instructions to carry out their tasks.

// gotta make sure the Vector2.h header makes it here, right?
#include "Vector3.h"

Vector3 Vector3::add(const Vector3& v) const { return Vector3(v.x + this->x, v.y + this->y, v.z + this->z); }
Vector3 Vector3::add(double a, double b, double c) const { return Vector3(a + this->x, b + this->y, c + this->z); }

Vector3 Vector3::sub(const Vector3& v) const { return Vector3(this->x - v.x, this->y - v.y, this->z - v.z); }
Vector3 Vector3::sub(double a, double b, double c) const { return Vector3(this->x - a, this->y - b, this->z - c); }

Vector3 Vector3::scalarMultiplication(double a) const  { return Vector3(this->x * a, this->y * a, this->z * a); }

Vector3 Vector3::normalize() const  { return Vector3(this->x / mag(), this->y / mag(), this->z / mag()); }

Vector3 Vector3::vectorSquared() const { return Vector3(this->x*this->x, this->y*this->y, this->z*this->z); }

Vector3 Vector3::toVector3(double d) const { return Vector3(d, 0, 0); }
Vector3 Vector3::toVector3(const Vector2& v) const { return Vector3(v.getX(), v.getY(), 1); }

double Vector3::dotProduct(const Vector3& v) const { return (this->x * v.x) + (this->y * v.y) + (this->z * v.z); }

double Vector3::mag() const { return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2)); }

double Vector3::getAngleBetweenVector(Vector3& v)const
{
	double magA = mag();
	double magB = v.mag();
	double dot = dotProduct(v);
	return (acos((dot / (magA * magB)))) * (180 / PI);
}

double Vector3::max() const
{
	if (this->x > this->y && this->x > this->z) return this->x;
	if (this->y > this->x && this->y > this->z) return this->y;
	if (this->z > this->x && this->z > this->y) return this->z;
}

Vector3 Vector3::getUprightSpace(const Vector3& pos, const Vector3& right, const Vector3& up, const Vector3& forward, const Vector3& objSpace) const
{
	return Vector3
	(
		(objSpace.x * right.x) + (objSpace.y * right.y) + (objSpace.z * right.z),
		(objSpace.x * up.x) + (objSpace.y * up.y) + (objSpace.z * up.z),
		(objSpace.x * forward.x) + (objSpace.y * forward.y) + (objSpace.z * forward.z)
	);
}

Vector3 Vector3::getWorldSpace(const Vector3& pos, const Vector3& right, const Vector3& up, const Vector3& forward, const Vector3& objSpace) const
{
	return Vector3
	(
		pos.x + (objSpace.x * right.x) + (objSpace.y * up.x) + (objSpace.z * forward.x),
		pos.y + (objSpace.x * right.y) + (objSpace.y * up.y) + (objSpace.z * forward.y),
		pos.z + (objSpace.x * right.z) + (objSpace.y * up.z) + (objSpace.z * forward.z)
	);
}

Vector3 Vector3::crossProduct(const Vector3& v) const
{
	return Vector3
	(
		(this->y * v.z) - (v.y * this->z),
		(this->z * v.x) - (v.z * this->x),
		(this->x * v.y) - (v.x * this->y)
	);
}

// NEEDS WORK
Vector3 Vector3::rotateVector(double a)const
{

	return Vector3();
}