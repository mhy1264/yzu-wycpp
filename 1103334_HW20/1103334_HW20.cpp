/*
	姓名: 楊明寰
	學號: 1103334
	我用兩array 去記錄反轉前和反轉後的位置
	相減放到sum

	如果sum 全部都是0 代表是回文
	只要有一個不是零 就不是回文
*/
#include<iostream>
#include<string>
using namespace std;
bool isZero(int sum[], int size)
{
	for (int i = 0; i < size; i++)
		if (sum[i] != 0)
			return 0;
	return 1;
}
int main()
{
	string str;
	while (getline(cin, str))
	{
		int i, j;
		int size = str.length();
		int* normal = new int[size]();
		int* reverse = new int[size] ();
		int* sum = new int[size]();
		for (i = 0, j = size - 1; i < size; i++, j--)
			reverse[j] = normal[i] = (int)str[i] - '0';

		for (i = 0; i < size; i++)
			sum[i] = normal[i] - reverse[i];

		if (isZero(sum, size))
			cout << "is Polinadrome" << endl;
		else
			cout << "isn't Palidrome" << endl;
		delete[] sum;
		delete[] normal;
		delete[] reverse; 
	}

}