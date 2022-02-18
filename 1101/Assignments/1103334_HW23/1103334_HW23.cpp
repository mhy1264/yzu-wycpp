#include<iostream>
using namespace std;
int duck(int n)
{
	if (n == 1)
		return 2;
	else
		return 2 * duck(n - 1);

}
int main()
{
	int n;
	while (cin >> n)
	{
		int sum = 0, temp = 0;
		for (int i = 1; i <= n; i++)
		{
			temp = duck((n-i+1));
			cout << "在第" << i << "個村子，賣出了" << temp << "隻鴨" << endl;;
			sum += temp;
		}
		cout << "共賣出" << sum << endl;
		sum = 0;
			
	}
}