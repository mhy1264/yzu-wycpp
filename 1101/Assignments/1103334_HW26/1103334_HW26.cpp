#include<iostream>
using namespace std;

void hanoi(int n, char A, char B, char C)
{
	if (n == 1)
		cout << "Move " << n << " from " << A << " to " << C << endl;
	else
	{
		hanoi(n - 1, A, C, B);
		cout << "Move " << n << " from " << A << " to " << C << endl;
		hanoi(n - 1, B,A,C);
	}
}
void twohanoi(int n, char A, char B, char C)
{
    if(n==1)
    {
        cout << "Move " << n << " from " << A << " to " << B << endl;
        cout << "Move " << n << " from " << A << " to " << C << endl;
    }
    else
    {
        hanoi(n - 1, A, B, C);
       cout << "Move " << n << " from " << A << " to " << B << endl;
        hanoi(n - 1, C, A, B);
       cout << "Move " << n << " from " << A << " to " << C << endl;
        hanoi(n - 1, B, A, C);
    }
}

int main()
{
    int n;
    while(cin>>n)
	    twohanoi(n,'A','B','C');
}
