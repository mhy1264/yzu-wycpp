#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Point
{
public:
	
	Point(float, float);
	
	// default constructor
	Point();

	// show Point 
	void showPoint();

    // set the distance
    void setDistance();

	void showDistance ();

    int findLongest (int);

    int findShortest (int);

	Point operator-(Point);

private:

	float x;

	float y;

	float distance;
};

Point::Point()
{
	x = 0;
	y = 0;
	distance = 0;
}

Point::Point(float X, float Y)
{
	x = X;
	y = Y;
    distance=0;
}

Point Point::operator-(Point op2)
{
    Point buffer((*this).x-op2.x,(*this).y-op2.y);
    return buffer;
}

void Point ::showDistance()
{
    cout << "Distance: " << distance << endl;
}

void Point::setDistance()
{
    Point zero;
    Point buf = zero-(*this);
	distance = pow((pow(buf.x, 2) + pow(buf.y, 2)), 0.5);
}

void Point::showPoint()
{
	cout << "( " << x << " , " << y << " ) Distance => " << distance << endl;
}

int Point::findLongest(int i)
{
    static int ind = 0 ;
    static float dis=-1;

    if(dis<distance)
    {
        ind =i;
        dis = distance;
    }
    
    return ind ;
}

int Point::findShortest(int i)
{
    static int ind = 0 ;
    static float dis=-1;

    if(dis>distance)
    {
        ind =i;
        dis = distance;
    }
    
    return ind ;
}
int main()
{
	vector <Point> points;

	float x, y;

	while (cin >> x >> y)
	{
		Point buf(x, y);
        buf.setDistance();
		buf.showPoint();
		points.push_back(buf);
	}

	int i,longind=0,shortind=0,size = points.size();

    for (i=0;i<size;i++)
    {
        longind = points[i].findLongest(i);
        shortind = points[i].findShortest(i);
    }

    Point buffer=points[longind]-points[shortind];

    buffer.setDistance();

	cout << "Point #1 " ;
	points[longind].showPoint();
	cout << "Point #2 " ;
	points[shortind].showPoint();
    cout << "distance => ";
    buffer.showDistance() ;

}



































