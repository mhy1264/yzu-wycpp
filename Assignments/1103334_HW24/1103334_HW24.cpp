/*
姓名 :楊明寰
學號 : 1103334
將n-1盤子 ⇒ 
由來源木棒(A)移到輔助木棒(B)
將最大盤子 ⇒ 
由來源木棒(A)移到目的木棒(C)
將還沒到目的盤子中最大者 ⇒ 
由新的來源木棒(B)透過新的輔助木棒(A)移到目的木棒(C
*/
#include<iostream>
#include<cmath>
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
int main()
{

	int n;
	while (cin >> n)
	{
		hanoi(n, 'A', 'B', 'C');
		cout << pow(2, n) - 1 << endl;
	}

}