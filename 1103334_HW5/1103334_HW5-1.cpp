#include<iostream>
using namespace std;
int main()
{

	int h;
	cout<<"請輸入台灣時間";
	cin>>h;
	cout<<"美國時間 : "<<(h+24-15)%24<<endl; 
}
