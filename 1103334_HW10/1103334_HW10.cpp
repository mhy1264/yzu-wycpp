// 1103334 楊明寰
//in main() :
//	用一個loop去跑上界和下界
//in getNum() :
//	設個變數res去記錄原本n的值
//	用while()去處理每一個位數
//	如果op == 0 或是res % op != 0的話 就 return 0;
//	做完以後n要/10
//	如果之前都沒被return 回去的話
//		就代表要輸出這個數

#include<iostream>
using namespace std;
int getNum(int n)
{
	int res = n;
	int op;
	while (n)
	{
		op = n % 10;
		if (op and (res% op) != 0)
			return 0;
		n /= 10;
	}
	return 1;
}



int main()
{
	int a, b;
	while (cin >> a >> b)
	{
 		for (int i = a; i <= b; i++)
		{
			if (getNum(i))
				cout << i << " ";
		}
		cout << endl;
	}
}