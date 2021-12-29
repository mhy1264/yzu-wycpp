#include <iostream>
using namespace std;

void sort(int n, int* ptr)
{
	int i, j, t;
	for (i = 0; i < n; i++) {

		for (j = i + 1; j < n; j++) {

			if (*(ptr + j) < *(ptr + i)) {

				t = *(ptr + i);
				*(ptr + i) = *(ptr + j);
				*(ptr + j) = t;
			}
		}
	}

	for (i = 0; i < n; i++)
		printf("%d ", *(ptr + i));
}

// Driver code
int main()
{

    int n;
    while(cin>>n)
    {
        int *arr = new int [n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
   	    sort(n, arr);  
        delete []arr;   
    }


	return 0;
}
