/*
	�m�W: ������
	�Ǹ�: 1103334
	�ڥΨ�array �h�O������e�M����᪺��m
	�۴���sum

	�p�Gsum �������O0 �N��O�^��
	�u�n���@�Ӥ��O�s �N���O�^��
*/
#include<iostream>
#include<string>
using namespace std;
bool isZero(int sum[], int size)
{
	for (int i = 0; i < size; i++)
		if (sum[i] != 0)
			return 0;
	return 1;
}
int main()
{
	string str;
	while (getline(cin, str))
	{
		int i, j;
		int size = str.length();
		int* normal = new int[size]();
		int* reverse = new int[size] ();
		int* sum = new int[size]();
		for (i = 0, j = size - 1; i < size; i++, j--)
			reverse[j] = normal[i] = (int)str[i] - '0';

		for (i = 0; i < size; i++)
			sum[i] = normal[i] - reverse[i];

		if (isZero(sum, size))
			cout << "is Polinadrome" << endl;
		else
			cout << "isn't Palidrome" << endl;
		delete[] sum;
		delete[] normal;
		delete[] reverse; 
	}

}