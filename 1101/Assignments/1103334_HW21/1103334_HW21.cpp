/*
* �m�W: ������
* �Ǹ�: 1103334
* �Q�k: �Ф@��array �A�r����ascii ��@index �A�A�Τ@��n�h�p���J��ĴX��
*/
#include<iostream>
using namespace std;
int main()
{
	char c;
	int index[128];
	int n = 0;
	for (int i = 0; i <128; i++)
		index[i] = -1;
	while (cin >> c)
	{
		if (c == 24)
			break;
		index[(int)c] = n++;
	}
	while (cin >> c)
	{
		if (c == 24)
			break;
		cout << "index = " << index[(int)c] << endl;
	}
}