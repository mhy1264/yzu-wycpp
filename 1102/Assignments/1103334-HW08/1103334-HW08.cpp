#include<iostream>
using namespace std;

class X
{
public :
	int operator-();
	int operator!();
	int operator-(X x2);
	X(int);
private:
	int n;
};

X::X(int temp)
{
	n = temp;
}
int X::operator-(X x2)
{
	 n= n - x2.n;
	 return n;
}
int X::operator-()
{
	return -1 * n;
}
int X::operator!()
{
	if (n > 10)
		return 1;
	return 0;
}

int main()
{
	X x1(16), x2(7);

	cout << !x1 << endl;

	cout << x1 - x2 << endl;

	cout << !x1 << endl;

	cout << x1 - (-x2) << endl;

	cout << !x1 << endl;
}