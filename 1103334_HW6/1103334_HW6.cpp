#include<iostream>
using namespace std;
int main()
{
	int n;
//	cout<<"請輸入你的座號:";
	cin>>n;
	cout<<"國文課所在組別 : "<<((n-1)/3)+1 <<"\n數學課所在組別 : "<<((n+2)%3)+1<<endl; 
}
