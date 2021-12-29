#include<iostream>
#include<cstring>
using namespace std;
void reverse(char *str)
{
    char *ptr_s,*ptr_e,ch;
    ptr_s = str;
    ptr_e = str+strlen(str)-1;

    for(int i=0;i<strlen(str)/2;i++)
    {
	ch = *ptr_e;
	*ptr_e=*ptr_s;
	*ptr_s=ch;

	ptr_s++;
	ptr_e--;
    }
}
int main()
{
	while(1)
	{

    char str[100];
    cin>>str;
    reverse(str);
    cout<<str<<endl;
	}
}
