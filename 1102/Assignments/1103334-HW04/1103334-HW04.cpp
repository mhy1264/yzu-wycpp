#include<iostream>
using namespace std;

class Rectangle
{
public:
    // 劃出圖型
    void draw(int, int);
    // 設定長寬
    void set(int, int);
private:
    int h;
    int w;

};

void Rectangle::set(int x, int y)
    h = x;
    w = y;
}
void Rectangle::draw(int h, int w) 
{
    for (int i = 0; i < w; i++) // 最上方的邊界
        cout << "*";
    cout << endl;

    for (int j = 0; j < h - 2; j++) // 扣掉上下兩行
    {
        cout << "*";
        for (int i = 0; i < w - 2; i++) // 扣掉左右兩個*
            cout << " ";
        cout << "*" << endl;;
    }


    for (int i = 0; i < w; i++) //下邊界
        cout << "*";
    cout << endl;
}

int main()
{
    int w, h;
    while (cin >> w >> h)
    {
        Rectangle obj; // 宣告一個物件
        obj.set(h, w); // 設定長寬
        obj.draw(h, w); // 開始畫
    }
}
