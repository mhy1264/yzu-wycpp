#include<iostream>
using namespace std;

class Rectangle
{
public:
    void draw(int, int);
    void set(int, int);
private:
    int h;
    int w;

};

void Rectangle::set(int x, int y)
{
    h = x;
    w = y;
}
void Rectangle::draw(int h, int w)
{
    for (int i = 0; i < w; i++)
        cout << "*";
    cout << endl;

    for (int j = 0; j < h - 2; j++)
    {
        cout << "*";
        for (int i = 0; i < w - 2; i++)
            cout << " ";
        cout << "*" << endl;;
    }


    for (int i = 0; i < w; i++)
        cout << "*";
    cout << endl;
}

int main()
{
    int w, h;
    while (cin >> w >> h)
    {
        Rectangle obj;
        obj.set(h, w);
        obj.draw(h, w);
    }
}