// Assignment-12 2022.04.29
// ������ 1103334
// if the comment is garbled, please visit https://gist.github.com/7d6fb28e5b4a84fac5ab8a10451e7a3c.git
// 
// ��Point ����x,y ���I
// �M�᥿��Ϊ����n�O���I���Z��������A�ҥH�N�b Square �� �غc�l���D�p�⭱�n
// ���� Cube �~�� Square �����I �A�[�W�s���@�I�A�ҥH�N�i�H�D�X���M��n
// Circle �M Cyclinder �����W�z 


#include<iostream>
using namespace std;

// �L�X�Ϊ�����n
class Shape
{
public:
	virtual void getV() = 0;
};

// �N�� X Y ���I
class Point
{
public:
	Point(float X, float Y)
	{
		x = X;
		y = Y;
	}
	float x, y;
};

// ��X����έ��n
class Square
{
public:
	Square(Point p1, Point p2)
	{
		len = pow (pow((p1.x - p2.x),2)+pow((p1.y-p2.y),2),0.5);
		area = len * len;
	}

protected:
	float len;
	float area;

};

// ��X��έ��n
class Circle
{
public:
	Circle(Point x1, Point x2)
	{
		rad = pow(pow((x1.x - x2.x), 2) + pow((x1.y - x2.y), 2), 0.5);
		area = rad * rad * 3.14;
	}
protected:
	float rad, area;

};

class Cube : public Square, public Shape
{
public:
	Cube(Point p1, Point p2, Point p3) :Square(p1, p2)
	{
		high = pow(pow((p1.x - p3.x), 2) + pow((p1.y - p3.y), 2), 0.5);
		V = area * high;
	}

	void getV()
	{
		cout << " V of Cube ====>" << V << endl;
	}
private:
	float high, V;
};

class Cylinder :public Circle, public Shape
{
public:
	Cylinder(Point p1, Point p2, Point p3) :Circle(p1, p2)
	{
		high = pow(pow((p1.x - p3.x), 2) + pow((p1.y - p3.y), 2), 0.5);
		V = area * high;
	}
	void getV()
	{
		cout << " V of Cylinder ====>" << V << endl;
	}
	
private:
	float high, V;
};


int main()
{

	Cube cube(Point(0, 0), Point(0, 5), Point(5, 0));

	Shape* s1 = &cube;
	s1->getV();

	Cylinder cyclinder(Point(0, 0), Point(0, 5), Point(5, 0));
	Shape* s2 = &cyclinder;
	s2->getV();
}













