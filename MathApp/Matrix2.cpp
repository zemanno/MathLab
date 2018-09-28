#include "Matrix2.h"

void Matrix2::setMatrix(const Vector2& row1, const Vector2& row2)
{
	row00 = row1;
	row01 = row2;
}

void Matrix2::setRotationMatrix(double a)
{
	row00 = Vector2(cos(u->r2d(a)), -sin(u->r2d(a)));
	row01 = Vector2(sin(u->r2d(a)), row01.getX());
}

void Matrix2::setScalingMatrix(double scaleX, double scaleY)
{
	row00 = Vector2(scaleX, 0);
	row01 = Vector2(0, scaleY);
}

void Matrix2::setIdentityMatrix()
{
	row00 = Vector2(1, 0);
	row01 = Vector2(0, 1);
}

void Matrix2::addMatrix(Matrix2& m)
{
	row00 = Vector2(this->row00.getX() + m.row00.getX(), this->row00.getY() + m.row00.getY());
	row01 = Vector2(this->row01.getX() + m.row01.getX(), this->row01.getY() + m.row01.getY());
}

void Matrix2::subMatrix(Matrix2& m)
{
	row00 = Vector2(this->row00.getX() - m.row00.getX(), this->row00.getY() - m.row00.getY());
	row01 = Vector2(this->row01.getX() - m.row01.getX(), this->row01.getY() - m.row01.getY());
}

Matrix2 Matrix2::mul(Matrix2& m)
{
	return Matrix2
	(
		this->row00.getX() * m.row01.getX() + this->row00.getY() * m.row01.getX(),
		this->row00.getX() * m.row01.getY() + this->row00.getY() * m.row01.getY(),
		this->row01.getX() * m.row00.getX() + this->row01.getY() * m.row01.getX(),
		this->row01.getX() * m.row00.getY() + this->row01.getY() * m.row01.getY()
	);
}

void Matrix2::transpose()
{
	Vector2 row00(this->row00.getX(), this->row01.getX());
	Vector2 row01(this->row00.getY(), this->row01.getY());
	setMatrix(row01, row01);
}

void Matrix2::display() const
{
	cout << "|" << this->row00.getX() << " " << this->row00.getY() << "|" << endl;
	cout << "|" << this->row01.getX() << " " << this->row01.getY() << "|" << endl;
}

Vector2 Matrix2::mul(const Vector2& v) const
{
	return Vector2
	(
		this->row00.getX() * v.getX() + this->row00.getY() * v.getY(),
		this->row01.getX() * v.getX() + this->row01.getY() * v.getY()
	);
}