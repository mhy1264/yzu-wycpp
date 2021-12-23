/*
姓名 :楊明寰
學號 : 1103334
----------------

就是一開始先固定字串的第一個字
剩下的幾個字在先固定第一格字 之後交換 輸出
以此類推

*/

#include <string>
#include <iostream>
using namespace std;
void permute(string a, int l, int r)
{
	if (l == r)
		cout << a << endl;
	else
	{
		for (int i = l; i <= r; i++)
		{
			swap(a[l], a[i]);
			permute(a, l + 1, r);
			swap(a[l], a[i]);
		}
	}
}

int main()
{
	string str;
	getline(cin, str);
	int n = str.size();
	permute(str, 0, n - 1);
	return 0;
}