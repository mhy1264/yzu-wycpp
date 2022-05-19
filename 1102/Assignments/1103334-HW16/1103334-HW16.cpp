#include<iostream>
using namespace std;

int stdId = 0;
int proId = 0;

class Person
{
public:

	void getData()
	{
		cout << " " << _name << " " << _age << " ";
	}

	void putData()
	{
		cin >> _name;
		cin >> _age;
	}

protected:
	char _name[10];
	int _age;
};

class Professor :public Person
{
public:

	void getData()
	{
		Person::getData();
		cout  << _publications << " "<<_proId<<endl;
	}

	void putData()
	{
		Person::putData();
		_proId = ++proId;
		cin >> _publications;
	}

private:
	int _publications;
	int _proId;
};

class Student :public Person
{
public:

	void getData()
	{
		int sum = 0;

		for (int i = 0; i < 6; i++)
			sum += _marks[i];

		Person::getData();
		cout <<   sum <<" " << _stdId <<endl;
	}

	void putData()
	{

		Person::putData();
		_stdId =++stdId;
		for (int i = 0; i < 6; i++)
			cin >> _marks[i];
	}

private:
	int _marks[6];
	int _stdId;
};

int main()
{
	int n;
	cin >> n;

	int* loc = new int[n]();
	Professor* pro = new Professor[n];
	Student* stu = new Student[n];

	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		if (t == 2)
		{
			loc[i] = 1;
			Student temp;
			temp.putData();
			stu[i] = temp;
		}
		if (t == 1)
		{
			loc[i] = 2;
			Professor temp;
			temp.putData();
			pro[i] = temp;
		}

	}

	for (int i = 0; i < n; i++)
	{
		if (loc[i] == 1)
			stu[i].getData();
		if (loc[i] == 2)
			pro[i].getData();
	}

}