#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;
int main()
{
	string str;
	while(getline(cin,str))
	{
		pair <char,int> data[str.length()];
		int i,j;
		int count =1;
		bool check=1;
		
		for (i =0;i<str.length();i++)
		{
			data[i].first='0';
			data[i].second=0;
		}
		for(i=0;i<str.length();i++)
		{
			for (j=0;j<count;j++)
			{
				if(data[j].first == str[i])
				{
					data[j].second++;
					check=0;
				}
			}
			
			if(check)
			{
				count++;
				data[count-1].first=str[i];
				data[i].second =1;
			}
		}
		
		for(i=0;i<count;i++)
			if(!data[i].second)
				printf("%c => %d\n",data[i].first,data[i].second);
			
	}
 } 
