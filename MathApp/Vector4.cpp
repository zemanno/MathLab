#include "Vector4.h"

Vector4 Vector4::add(const Vector4& v) const { return Vector4(this->w+v.w, this->x+v.x, this->y+v.y, this->z+v.z); }
Vector4 Vector4::add(double a, double b, double c, double d) const { return Vector4(this->w+a, this->x+b, this->y+c, this->z+d); }

Vector4 Vector4::sub(const Vector4& v) const { return Vector4(this->w-v.w, this->x-v.x, this->y-v.y, this->z-v.z); }
Vector4 Vector4::sub(double a, double b, double c, double d) const { return Vector4(this->w-a, this->x-b, this->y-c, this->z-d); }

Vector4 Vector4::scalarMultiplication(double a) const { return Vector4(this->w * a, this->x * a, this->y * a, this->z * a); }
Vector4 Vector4::normalize() const { return Vector4(this->w/mag(), this->x/mag(), this->y/mag(), this->z/mag()); }

double Vector4::dotProduct(const Vector4& v) const { return (this->w * v.x) + (this->x * v.x) + (this->y * v.y) + (this->z * v.z); }
double Vector4::mag() const { return sqrt(pow(this->w, 2) + pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2)); }

Vector4 Vector4::rotateVector(double d) const 
{
	return Vector4();
}