// 1103334 ������
//in main() :
//	�Τ@��loop�h�]�W�ɩM�U��
//in getNum() :
//	�]���ܼ�res�h�O���쥻n����
//	��while()�h�B�z�C�@�Ӧ��
//	�p�Gop == 0 �άOres % op != 0���� �N return 0;
//	�����H��n�n/10
//	�p�G���e���S�Qreturn �^�h����
//		�N�N��n��X�o�Ӽ�

#include<iostream>
using namespace std;
int getNum(int n)
{
	int res = n;
	int op;
	while (n)
	{
		op = n % 10;
		if (op and (res% op) != 0)
			return 0;
		n /= 10;
	}
	return 1;
}



int main()
{
	int a, b;
	while (cin >> a >> b)
	{
 		for (int i = a; i <= b; i++)
		{
			if (getNum(i))
				cout << i << " ";
		}
		cout << endl;
	}
}