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
        // 先把輸入的 char 轉為 int ，例如 '0' 轉為 48
        // 然後再把arr的第48項+1
    }
    while (cin >> in)
    {
        // 確認arr的第 (int)in 項是否為零 
        // 如果不為零 -> 輸出存在後歸0
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
