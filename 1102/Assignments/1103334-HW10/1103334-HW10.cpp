#include<iostream>
using namespace std;

class twoD
{
public:
	twoD();
	twoD(float, float);
	double twoPoint(twoD);
	float squareSum();
	twoD operator-(twoD);
protected:
	float x, y;
};

twoD::twoD(float X, float Y)
{
	x = X;
	y = Y;
}

twoD::twoD()
{
	x = 0;
	y = 0;
}

twoD twoD::operator-(twoD X2)
{
	float deltaX = x - X2.x;
	float deltaY = y - X2.y;

	twoD temp(deltaX, deltaY);
	return temp;
}

float twoD::squareSum()
{
	return x * x + y * y;
}

double twoD::twoPoint(twoD two)
{
	twoD one(x, y);
	twoD temp = one - two;
	return pow(static_cast<double>(temp.squareSum()), 0.5);
}


class threeD :public twoD
{
public:
	threeD();
	threeD(float, float, float);
	threeD operator-(threeD);
	float squareSum();
	double threePoint(threeD);
private:
	float z;
};

threeD::threeD()
{
	x = y = z = 0;
}

threeD::threeD(float X, float Y, float Z) :twoD(x, y)
{
	z = Z;
}

threeD threeD::operator-(threeD x2)
{
	threeD temp(x - x2.x, y - x2.y, z - x2.z);
	return temp;
}

float threeD::squareSum()
{
	return x * x + y * y + z * z;
}

double threeD::threePoint(threeD two)
{
	threeD one(x, y, z);
	threeD temp = one - two;
	return pow(static_cast<double>(temp.squareSum()), 0.5);
}


int main()
{
	threeD one(1, 2, 3);
	threeD two(4, 5, 6);
	double temp =one.threePoint(two);
	cout << temp;

	twoD three(0,3);
	twoD four(4,0);
	double temp3 = three.twoPoint(four);
	cout << temp3 << endl;
}