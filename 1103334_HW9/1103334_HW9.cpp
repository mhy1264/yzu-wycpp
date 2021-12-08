#include<iostream>
using namespace std;
void printStar(int n)
{
	for (int i = 0; i < n; i++)
		cout << "*";
}
void printSpace(int n)
{
	for (int i = 0; i < n; i++)
		cout << " ";
}
int main()
{
	int n;
	while (cin >> n)
	{
		int middle = n / 2;
		int space = middle;
		int star = 1;
		for (int i = 0; i < n; i++)
		{
			if (i<middle)
			{
				printSpace(space--);
				printStar(star);
				star+= 2;
			}
			else if (i>middle)
			{
				star -= 2;
				printSpace(++space);
				printStar(star);
			}
			else
				printStar(n);
			cout << endl;
		}
	}
}