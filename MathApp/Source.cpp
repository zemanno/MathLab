// Author: Norbert Zeman
// Date: Tuesday September 18, 2018
// Purpose: Physics Calculator

#include "Matrix2.h"
#include "Vector3.h"
#include "Utility.h"
using namespace std;

int main()
{
	Utility *u = Utility::getInstance();
	Vector3 v1(1, 7, 10);
	Vector3 v2(11, 5, 3);

	Vector3 v3 = v1 - v2;
	v3.display();
	delete u;
	system("pause");
	return 0;
}