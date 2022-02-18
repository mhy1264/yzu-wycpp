#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		int i, j;

		int **arr = new int *[n+2];

		for (i = 0; i < n+2; i++)
			arr[i] = new int[n+2];

		for (i = 0; i < n + 2; i++)
			for (j = 0; j < n + 2; j++)
				arr[i][j] = -1;

		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				arr[i][j] = 0;


		int x = n, y = 1;

		int dir = 3;
		int counter = 1;
		while (counter <= n * n)
		{
			arr[x][y] = counter;
			if (dir % 4 == 1) // down
			{
				x++;
				if (arr[x][y] != 0)
				{
					dir++;
					x--;
					y--;
				}
			}
			else if (dir % 4 == 2) // left
			{
				y--;
				if (arr[x][y] != 0)
				{
					dir++;
					y++;
					x--;
				}
			}

			else if (dir % 4 == 3) // up
			{
				x--;
				if (arr[x][y] != 0)
				{
					dir++;
					x++;
					y++;
				}
			}
			else if (dir % 4 == 0) // rigth
			{
				y++;
				if (arr[x][y] != 0)
				{
					dir++;
					y--;
					x++;
				}
			}
			counter++;
		}


		if (n % 2) // odd
			arr[n / 2 + 1][n / 2 + 1] = counter;
		else
			arr[(n + 1) / 2][(n + 1) / 2] = counter;



		for (i = 1; i <= n; i++)
		{
			for (j = 1; j < n + 1; j++)
				cout << setw(3) << arr[i][j] << " ";
			cout << endl;
		}

		for (i = 0; i < n; i++)
			delete[] arr[i];
		delete[] arr;
	}
}
