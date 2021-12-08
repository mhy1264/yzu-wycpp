#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		int i, j;
		int** arr = new int* [n + 2];

		for (i = 0; i < n + 2; i++)
			arr[i] = new int[n + 2];

		for (i = 0; i < n + 2; i++)
			for (j = 0; j < n + 2; j++)
				arr[i][j] = -1;

		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				arr[i][j] = 0;


		int x = 1, y = 1;
		int round = n-1;
		int dir = 0;
		int counter = n * n;




		for (int i = 0; i < n; i++)
			arr[x][y++] = counter--;
		y--;
		x++;

		while (counter>0)
		{
			for (int i = 0; i <= round; i++)
			{
				//cout << i << endl;
				if (dir % 4 == 0)  //down
				{
					arr[x++][y] = counter--;
					//cout << "x " << x << " y " << y << endl;
					if (arr[x][y] != 0)
					{
						x--;
						y--;
						dir++;
					}
				}
				else if (dir % 4 == 1)  // left
				{
					arr[x][y--] = counter--;
					if (arr[x][y] != 0)
					{
						y++;
						x--;
						dir++;
						round--;
					}
				}
				else if (dir % 4 == 2) //up
				{
					arr[x--][y] = counter--;
					if (arr[x][y] != 0)
					{
						x++;
						y++;
						dir++;
					}
				}
				else if (dir % 4 == 3) //right
				{
					arr[x][y++] = counter--;
					if (arr[x][y] != 0)
					{
						x++;
						y--;
						dir++;
						round--;
					}
				}
			}
		}

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