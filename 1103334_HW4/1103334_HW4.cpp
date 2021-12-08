//學號 1103334 姓名 楊明寰
/***************************
用一個多的變數去暫存a的value

這樣就可以了 
***************************/ 

#include<iostream>
using namespace std;
int main()
{
	int a,b,t;
	cin>>a>>b;
	cout<<"(交換前) a = "<<a<<", b = "<<b<<endl; 
	t=a;
	a=b;
	b=t;
	cout<<"(交換後) a = "<<a<<", b = "<<b<<endl;
}
