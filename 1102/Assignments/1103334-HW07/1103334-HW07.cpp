#include<iostream>
#include<vector>
#include <cmath>
using namespace std;

class point
{
public:
	void show();
	int getLongest(int);
	point(float X, float Y);
private:
	float x, y,dis;
};


int point::getLongest(int currind )
{
	static float dis = -1;
	static int ind = -1;

	float currdis = pow((x * x + y * y), 0.5);
	if (currdis > dis)
	{
		dis = currdis;
		ind = currind;
	}

	return ind;
}



void point::show()
{
	cout << x << " " << y << " " << dis << endl;
}


point::point(float X, float Y)
{
	x = X;
	y = Y;
	dis = pow((x * x + y * y), 0.5);
}


int main()
{
	vector <point> points;
	
	for (int i = 0; i < 10; i++)
	{
		float x, y;
		cin >> x >> y;
		point buffer(x, y);
		points.push_back(buffer);
	}

	int longdis = -1;
	for (int i = 0; i < 10; i++)
		longdis = points[i].getLongest(i);

	points[longdis].show();
}