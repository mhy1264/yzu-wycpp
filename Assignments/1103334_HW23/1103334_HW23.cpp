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
			cout << "�b��" << i << "�ӧ��l�A��X�F" << temp << "���n" << endl;;
			sum += temp;
		}
		cout << "�@��X" << sum << endl;
		sum = 0;
			
	}
}