#include "Matrix2.h"

void Matrix2::setMatrix(const Vector2& row1, const Vector2& row2)
{
	row01 = row1;
	row02 = row2;
}

void Matrix2::setRotationMatrix(double a)
{
	row01 = Vector2(cos(u->r2d(a)), -sin(u->r2d(a)));
	row02 = Vector2(sin(u->r2d(a)), row01.getX());
}

void Matrix2::setScalingMatrix(double scaleX, double scaleY)
{
	row01 = Vector2(scaleX, 0);
	row02 = Vector2(0, scaleY);
}

void Matrix2::setIdentityMatrix()
{
	row01 = Vector2(1, 0);
	row02 = Vector2(0, 1);
}

void Matrix2::addMatrix(Matrix2& m)
{
	row01 = Vector2(this->row01.getX() + m.row01.getX(), this->row01.getY() + m.row01.getY());
	row02 = Vector2(this->row02.getX() + m.row02.getX(), this->row02.getY() + m.row02.getY());
}

void Matrix2::subMatrix(Matrix2& m)
{
	row01 = Vector2(this->row01.getX() - m.row01.getX(), this->row01.getY() - m.row01.getY());
	row02 = Vector2(this->row02.getX() - m.row02.getX(), this->row02.getY() - m.row02.getY());
}

Matrix2 Matrix2::mulMatrix(Matrix2& m)
{
	r1c1 = this->row01.getX() * m.row02.getX() + this->row01.getY() * m.row02.getX();
	r1c2 = this->row01.getX() * m.row02.getY() + this->row01.getY() * m.row02.getY();
	r2c1 = this->row02.getX() * m.row01.getX() + this->row02.getY() * m.row02.getX();
	r2c2 = this->row02.getX() * m.row01.getY() + this->row02.getY() * m.row02.getY();
	return Matrix2(r1c1, r1c2, r2c1, r2c2);
}

void Matrix2::transpose()
{
	Vector2 col1(this->row01.getX(), this->row02.getX());
	Vector2 col2(this->row01.getY(), this->row02.getY());
	this->setMatrix(col1, col2);
}

void Matrix2::display() const
{
	cout << "|" << this->row01.getX() << " " << this->row01.getY() << "|" << endl;
	cout << "|" << this->row02.getX() << " " << this->row02.getY() << "|" << endl;
}

Vector2 Matrix2::mulMatrixByColVec(const Vector2& v) const
{
	return Vector2
	(
		(this->row01.getX() * v.getX()) + (this->row01.getY() * v.getY()),
		(this->row02.getX() * v.getX()) + (this->row02.getY() * v.getY())
	);
}