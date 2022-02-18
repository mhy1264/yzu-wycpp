#include <iostream>
using namespace std;
bool leap(int year)
{
	if( year%400==0 or ( year%4==0 and year%100!=0 ) )
		return 1;
	else
		return 0;
} 
int main()
{
	int year;
	cout << "輸入年份+: ";
	cin >> year;
   
	if(leap(year))
	{
		cout<<"Year "<<year<<"閏"<<endl;
	}
	else
	{
		cout<<"Year "<<year<<"平"<<endl;
	}

	system( "pause" );
}
