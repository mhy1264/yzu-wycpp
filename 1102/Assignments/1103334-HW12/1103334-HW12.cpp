// Assignment-12 2022.04.29
// 楊明寰 1103334
// if the comment is garbled, please visit https://gist.github.com/7d6fb28e5b4a84fac5ab8a10451e7a3c.git
// 
// 用Point 紀錄x,y 兩點
// 然後正方形的面積是兩點的距離的平方，所以就在 Square 的 建構子順道計算面積
// 之後 Cube 繼承 Square 的兩點 再加上新的一點，所以就可以求出高和體積
// Circle 和 Cyclinder 類似上述 


#include<iostream>
using namespace std;

// 印出形狀的體積
class Shape
{
public:
	virtual void getV() = 0;
};

// 代表 X Y 兩點
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

// 算出正方形面積
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

// 算出圓形面積
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













