#include <iostream>
#include<vector>
using namespace std;
int main()
{
    int arr[128] = { 0 };
    char in;
    while (cin >> in)
    {
        if (in == '0')
            break;
        arr[(int)in]++;
    }
    while (cin >> in)
    {
        if (arr[(int)in]) // is in arr
        {
            cout << "Exist" << endl;
            arr[(int)in] = 0;
        }
        else
        {
            cout << "Not Exist" << endl;
        }
    }
}