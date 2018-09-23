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

double Vector3::dotProduct(const Vector3& v) const { return (this->x * v.x) + (this->y * v.y) + (this->z * v.z); }

double Vector3::mag()const
{
	double sumx2y2z2 = pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2);
	return sqrt(sumx2y2z2);
}

double Vector3::getAngleBetweenVector(Vector3& v)const
{
	double magA = mag();
	double magB = v.mag();
	double dot = dotProduct(v);
	return (acos((dot / (magA * magB)))) * (180 / PI);
}

// NEEDS WORK
Vector3 Vector3::rotateVector(double a)const
{

	return Vector3();
}

double Vector3::discriminant()const
{
	return 0;
}

double Vector3::getRoot()const
{
	return 0;
}

/*
Vector3 Vector3::operator*(const Vector3& ref)
{
Vector3 ans;
ans.x *= ref.x;
ans.y *= ref.y;
ans.z *= ref.z;
return ans;
}

Vector3 Vector3::operator/(const Vector3& ref)
{
Vector3 ans;
ans.x /= ref.x;
ans.y /= ref.y;
ans.z /= ref.z;
return ans;
}

double Vector3::max(const Vector3& v)
{
if (v.x > v.y && v.x > v.z) return v.x;
if (v.y > v.x && v.y > v.z) return v.y;
if (v.z > v.x && v.z > v.y) return v.z;
}

Vector3 Vector3::max(const Vector3& v1, const Vector3& v2)
{
Vector3 ans;
v2.x > v1.x ? ans.x = v2.x : ans.x = v1.x;
v2.y > v1.y ? ans.y = v2.y : ans.y = v1.y;
v2.z > v1.z ? ans.z = v2.z : ans.z = v1.z;
return ans;
}

Vector3 Vector3::add(const Vector3& v1, const Vector3& v2) { return Vector3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z); }
Vector3 Vector3::subtract(const Vector3& v1, const Vector3& v2) { return Vector3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z); }
Vector3 Vector3::multiply(double d, const Vector3& v) { return Vector3(d * v.x, d * v.y, d * v.z); }
double Vector3::vectorSquared(const Vector3& v) { return pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2); }
Vector3 Vector3::toVector3(double d) { return Vector3(d, 0, 0); }
Vector3 Vector3::homogenousCoordinates(Vector2 v) { return Vector3(v.x, v.y, 1); }

Vector3 Vector3::getUprightSpace(const Vector3& pos, const Vector3& right, const Vector3& up, const Vector3& forward, const Vector3& objSpace)
{
Vector3 ans;
ans.x = (objSpace.x * right.x) + (objSpace.y * right.y) + (objSpace.z * right.z);
ans.y = (objSpace.x * up.x) + (objSpace.y * up.y) + (objSpace.z * up.z);
ans.z = (objSpace.x * forward.x) + (objSpace.y * forward.y) + (objSpace.z * forward.z);
return ans;
}

Vector3 Vector3::getWorldSpace(const Vector3& pos, const Vector3& right, const Vector3& up, const Vector3& forward, const Vector3& objSpace)
{
Vector3 ans;
ans.x = pos.x + (objSpace.x * right.x) + (objSpace.y * up.x) + (objSpace.z * forward.x);
ans.y = pos.y + (objSpace.x * right.y) + (objSpace.y * up.y) + (objSpace.z * forward.y);
ans.z = pos.z + (objSpace.x * right.z) + (objSpace.y * up.z) + (objSpace.z * forward.z);
return ans;
}

double Vector3::discriminant(const Vector3& v) { return pow(v.y, 2) - (4 * v.x * v.z); }
double Vector3::discriminant(double a, double b, double c) { return pow(b, 2) - (4 * a * c); }
double Vector3::getRoot(const Vector3& v) { return -v.y / (2 * v.x); }
double Vector3::getRoot(double a, double b, double c) { return -b / (2 * a); }
Vector2 Vector3::getRoots(const Vector3& v) { return Vector2((-v.y + sqrt(discriminant(v))) / (2 * v.x), (-v.y - sqrt(discriminant(v))) / (2 * v.x)); }
Vector2 Vector3::getRoots(double a, double b, double c) { return Vector2((-b + sqrt(discriminant(a, b, c))) / (2 * a), (-b - sqrt(discriminant(a, b, c))) / (2 * a)); }
Vector3 Vector3::div(const Vector3& v, double d) { return Vector3(v.x / d, v.y / d, v.z / d); }

Vector3 Vector3::normalize(const Vector3& v)
{
Vector3 ans;
ans.x = v.x / Utility::mag(v);
ans.y = v.y / Utility::mag(v);
ans.z = v.z / Utility::mag(v);
return ans;
}

Vector3 Vector3::cross(const Vector3& a, const Vector3& b)
{
Vector3 ans;
ans.x = (a.y * b.z) - (b.y * a.z);
ans.y = (a.z * b.x) - (b.z * a.x);
ans.z = (a.x * b.y) - (b.x * a.y);
return ans;
}

Vector2 Vector3::solve2Equations(const Vector3& const a, const Vector3& const b)
{
Vector2 ans;
ans.y = sqrt((a.z - ((a.x*b.z) / b.x)) / (a.y - ((a.x*b.y) / b.x)));
ans.x = sqrt((a.z - (a.y * pow(ans.y,2)) / a.x));
return ans;
}

//void Vector3::display(const Vector3& v) { cout << "X = " << v.x << ", Y = " << v.y << ", Z = " << v.z << endl; }
void Vector3::display(Vector3 v[]) { for (int i = 0; i < sizeof(v); i++) cout << "X = " << v[i].x << ", Y = " << v[i].y << ", Z = " << v[i].z << endl; }

void Vector3::display(double a, double b, double c)
{
string s;

if (a == 1) s += "x^2";
else if (a == -1) s += "-x^2";
else s += to_string(a) + "x^2";

if (b == 1) s += " + y^2";
else if (b == -1) s += " - y^2";
else
{
if (b > 0) { s += " + " + to_string(b) + "y^2"; }
else if (b < 0) { s += " - " + to_string(b*-1) + "y^2"; }
}

s += " = " + to_string(c);
cout << s << endl;
}

void Vector3::displayEquation(const Vector3& const v)
{
string s;

if (v.x == 1) s += "x^2";
else if (v.x == -1) s += "-x^2";
else s += to_string(v.x) + "x^2";

if (v.y == 1) s += " + y^2";
else if (v.y == -1) s += " - y^2";
else
{
if (v.y > 0) { s += " + " + to_string(v.y) + "y^2"; }
else if (v.y < 0) { s += " - " + to_string(v.y*-1) + "y^2"; }
}

s += " = " + to_string(v.z);
cout << s << endl;
}
*/