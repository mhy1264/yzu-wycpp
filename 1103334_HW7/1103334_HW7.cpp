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
	cout << "��J�~��+: ";
	cin >> year;
   
	if(leap(year))
	{
		cout<<"Year "<<year<<"�|"<<endl;
	}
	else
	{
		cout<<"Year "<<year<<"��"<<endl;
	}

	system( "pause" );
}
