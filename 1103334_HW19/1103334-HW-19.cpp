/*
姓名: 楊明寰
學號: 1103334 
想法: 把每個字元的ascii 值當作 index
把value 當作出現的次數
第二個迴圈用來判斷值是否為0
如果!=0 就輸出*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	getline(cin, str);
	int ascii[128] = { 0 },i;
	for (i = 0; i < str.length(); i++)
		ascii[(int)str[i]]++;
	for (i = 22; i < 128; i++)  // 21=> space 
		if (ascii[i])
			cout << (char)i << " => " << ascii[i] << endl;
}
