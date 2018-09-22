#include "Matrix2.h"

void Matrix2::setMatrix(const Vector2& col1, const Vector2& col2)
{
	column1 = col1;
	column2 = col2;
}

void Matrix2::setRotationMatrix(double a)
{
	column1 = Vector2(cos(u->d2r(a)), sin(u->d2r(a)));
	column2 = Vector2(-sin(u->d2r(a)), cos(u->d2r(a)));
}

void Matrix2::setScalingMatrix(double scaleX, double scaleY)
{
	column1 = Vector2(scaleX, 0);
	column2 = Vector2(0, scaleY);
}

void Matrix2::setIdentityMatrix()
{
	column1 = Vector2(1, 0);
	column2 = Vector2(0, 1);
}

void Matrix2::addMatrix(Matrix2& m)
{
	column1 = Vector2(this->column1.getX() + m.column1.getX(), this->column1.getY() + m.column1.getY());
	column2 = Vector2(this->column2.getX() + m.column2.getX(), this->column2.getY() + m.column2.getY());
}

void Matrix2::subMatrix(Matrix2& m)
{
	column1 = Vector2(this->column1.getX() - m.column1.getX(), this->column1.getY() - m.column1.getY());
	column2 = Vector2(this->column2.getX() - m.column2.getX(), this->column2.getY() - m.column2.getY());
}

Matrix2 Matrix2::mulMatrix(Matrix2& m)
{
	r1c1 = this->column1.getX() * m.column1.getX() + this->column2.getX() * m.column1.getY();
	r1c2 = this->column1.getX() * m.column2.getX() + this->column2.getX() * m.column2.getY();
	r2c1 = this->column1.getY() * m.column1.getX() + this->column2.getY() * m.column1.getY();
	r2c2 = this->column1.getY() * m.column2.getX() + this->column2.getY() * m.column2.getY();
	return Matrix2(r1c1, r1c2, r2c1, r2c2);
}

void Matrix2::transpose()
{
	Vector2 col1(this->column1.getX(), this->column2.getX());
	Vector2 col2(this->column1.getY(), this->column2.getY());
	this->setMatrix(col1, col2);
}

void Matrix2::display()
{
	cout << "|" << this->column1.getX() << " " << this->column2.getX() << "|" << endl;
	cout << "|" << this->column1.getY() << " " << this->column2.getY() << "|" << endl;
}