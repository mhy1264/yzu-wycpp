#include<iostream>
using namespace std;
void getprime(int n)
{
	cout << n << " = 1";
	int i = 2;
	while (i <= n)
	{
		while (n % i == 0)
		{
			cout << " * " << i;
			n /= i;
		}
		i++;
	}
	cout << endl;
}
int main()
{
	int n;
	while (cin >> n and n)
		for (int i = 1; i <= n; i++)
			getprime(i);
}