#include<iostream>
using namespace std;
bool self(int n)
{
	int res = n;
	int op;
	while (n)
	{
		op = n % 10;
		if (op and (res % op) != 0)
			return 0;
		n /= 10;
	}
	return 1;

}
int main()
{
	int n, m;
	while (cin >> m >> n)
	{
		for (int i = m; i <= n; i++)
		{
			if (self(i))
				cout << i << " ";
		}
		cout << endl;
	}
}

