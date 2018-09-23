/// Author: Norbert Zeman
/// Date: Wednesday September 19, 2018
/// File: Vector2.cpp
/// Description: This is the source file for the Vector2.h header. Here is where those 
///				 pre-defined methods will be given instructions to carry out their tasks.

// gotta make sure the Vector2.h header makes it here, right?
#include "Vector2.h"

Vector2 Vector2::add(const Vector2& v) const { return Vector2(v.x + this->x, v.y + this->y); }
Vector2 Vector2::add(double a, double b) const { return Vector2(a + this->x, b + this->y); }
Vector2 Vector2::sub(const Vector2& v) const { return Vector2(this->x - v.x, this->x - v.y); }
Vector2 Vector2::sub(double a, double b) const { return Vector2(this->x - a, this->x - b); }
Vector2 Vector2::scalarMultiplication(double a) const { return Vector2(this->x * a, this->y * a); }
Vector2 Vector2::normalize() const { return Vector2(this->x / mag(), this->y / mag()); }
Vector2 Vector2::lerp(Vector2& v, double t) const { return Vector2(((1 - t) * this->x) + (t * v.x), ((1 - t) * this->y) + (t * v.y)); }
Vector2 Vector2::perpendicular() const { return Vector2(-y, x); }
double Vector2::dotProduct(const Vector2& v) const { return (this->x * v.x) + (this->y * v.y); }

double Vector2::mag() const
{
	double x2 = this->x * this->x;
	double y2 = this->y * this->y;
	double sumx2y2 = x2 + y2;
	return sqrt(sumx2y2);
}

double Vector2::getAngleInDegrees() const
{
	double thetarad = atan2(this->y, this->x); 
	return thetarad * (180 / PI);
}

double Vector2::getAngleBetweenVector(Vector2& v) const
{
	double magA = mag();
	double magB = v.mag();
	double dot = dotProduct(v);
	return (acos((dot / (magA * magB)))) * (180 / PI);
}

Vector2 Vector2::rotateVector(double a) const
{
	double xRotate = (this->x * cos(u->d2r(a))) - (this->x * sin(u->d2r(a)));
	double yRotate = (this->x * sin(u->d2r(a))) + (this->y * cos(u->d2r(a)));
	return Vector2(xRotate, yRotate);
}

double Vector2::max(const Vector2& v) const
{
	double d;
	v.x > v.y ? d = v.x : d = v.y;
	return d;
}

bool Vector2::isPerpendicularTo(const Vector2& v) const
{
	bool result;
	dotProduct(v) == 0 ? result = true : result = false;
	return result;
}