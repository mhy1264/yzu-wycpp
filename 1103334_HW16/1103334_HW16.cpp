//Name : ·¨©ú¾È
//studentID : 1103334
//Description: let user input numbers, then use sort() in algorithm to sort array
//then outut it 
#include<iostream>
#include<algorithm>
using namespace std;
const int arraySize = 100;

int main()
{
	int data[arraySize] = { 0 };

	int n, count = 0;
	while (cin >> n)
	{
		data[count++] = n;
	}
	sort(data, data + count);
	for (int i = 0; i < count; i++)
		cout << data[i] << " ";

}