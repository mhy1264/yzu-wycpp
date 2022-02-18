/*
* 姓名: 楊明寰
* 學號: 1103334
* 想法: 創一個array ，字元的ascii 當作index ，再用一個n去計算輸入到第幾個
*/
#include<iostream>
using namespace std;
int main()
{
	char c;
	int index[128];
	int n = 0;
	for (int i = 0; i <128; i++)
		index[i] = -1;
	while (cin >> c)
	{
		if (c == 24)
			break;
		index[(int)c] = n++;
	}
	while (cin >> c)
	{
		if (c == 24)
			break;
		cout << "index = " << index[(int)c] << endl;
	}
}