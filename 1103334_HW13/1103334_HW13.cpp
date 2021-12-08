#include<iostream>
using namespace std;
const int arraySize = 100;
int main()
{
	int n, i, j;
	while (cin >> n >> i >> j)
	{
		int fib[arraySize] = {};
		fib[0] = (fib[1] = 1);
		int count = 2;
		while (1)
		{
			fib[count] = fib[count - 1] + fib[count - 2];
			if (fib[count] > n)
				break;
			count++;
		}
		cout << count << " ";
		for (int c = i; c <= j; c++)
			cout << fib[c] << " ";
	}

}	