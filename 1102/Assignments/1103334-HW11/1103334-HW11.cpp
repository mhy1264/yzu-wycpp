#include<iostream>
using namespace std;
class LogicGate
{
public :
	LogicGate()
	{
		result = false;
	}

	void showResult()
	{
		cout << "result ==> " << result << endl;
	}

protected:
	bool result;
};
class Unary :public LogicGate
{
public :
	Unary()
	{
		cout << "Input one boolean value ";
		cin >> x;
	}
protected:
	bool x;
};
class NOT :public Unary
{
public:
	NOT() : Unary()
	{
		if (x == true)
			result = false;
		else
			result = true;
	}
};
class Binary :public LogicGate
{
public:
	Binary()
	{
		cout << "Input two boolean value ";
		cin >> x >> y;
	}

protected:
	bool x, y;
};
class AND :public Binary
{
public:
	AND() : Binary()
	{
		if (x * y == 1)
			result = true;
		else
			result = false;
	}
};

class OR :public Binary
{
public:
	OR() : Binary()
	{
		if (x + y == 0)
			result = false;
		else
			result = true;
	}
};

int main()
{
	cout << "test NOT Gate" << endl;
	for (int i = 0; i < 2; i++)
	{
		NOT g;
		g.showResult();
	}

	cout << endl;
	cout << "Test AND Gate" << endl;
	for (int i = 0; i < 4; i++)
	{
		AND g2;
		g2.showResult();
	}

	cout << endl;
	cout << "Test OR Gate" << endl;
	for (int i = 0; i < 4; i++)
	{
		OR g3;
		g3.showResult();
	}

}