
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int h;
//	scanf("請輸入台灣時間 : %d",&h); 
	cout<<"請輸入台灣時間";
	cin>>h;
	h-=24;
	if(h<0)
		h+=24;
	cout<<"美國時間 : "<<h<<endl; 
}
