//1103334 楊明寰
//半暴力解，我只要用一個subfunction 來判斷
//integers[i] + integer[j]是否等於target 並且i<j
#include<iostream>
using namespace std;

int ans[2] = { };
int integers[] = { 2,7,11,15 };
void compare(int a, int b, int t)
{
	if (a < b and (integers[a] + integers[b] == t))
	{
		ans[0] = a;
		ans[1] = b;
	}
}

int main()
{

	int target = 0;
	while (cin >> target)
	{
		for (int i = 0,j=0; i < 4; i++,j=0)
		{
			compare(i, j, target);
			compare(i, ++j, target);
			compare(i, ++j, target);
			compare(i, ++j, target);
		}

		cout << ans[0] << " " << ans[1] << endl;
	}
	
}