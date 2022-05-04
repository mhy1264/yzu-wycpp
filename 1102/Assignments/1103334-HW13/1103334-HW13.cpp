#include<iostream>
using namespace std;

class LogicGate
{
public:
	bool getOutput()
	{	
		result = performLogicGate();
		cout << result << endl;;
		return result;
	}
	virtual bool performLogicGate() = 0;
	virtual void setNextPin(bool next) = 0;;

protected:
	bool result = false;
};

class Unary :public LogicGate
{
public:
	Unary()
	{
		x = false;
	}

protected:
	bool x;
};

class NOT :public Unary
{
public:
	bool performLogicGate()
	{
		if (x == true)
			result = false;
		else
			result = true;

		return result;
	}

	void setNextPin(bool next)
	{
		x = next;
	}
};

class binary :public LogicGate
{
protected:
	bool x = false;
	bool y = false;
};

class AND:public binary
{
public :
	bool performLogicGate()
	{
		cout << "in And perform" << endl;
		if (x*y!=1)
			result = false;
		else
			result = true;

		return result;
	}

	void setNextPin(bool next)
	{
		y = x;
		x = next;
		cout << "current Pin"<<x << " " << y << endl;

	}
};

class OR :public binary
{
public:
	bool performLogicGate()
	{
		if (x + y == 0)
			result = false;
		else
			result = true;

		return result;
	}

	void setNextPin(bool next)
	{
		y = x;
		x = next;
	}
};

class Connector
{
public:
	Connector(LogicGate* fgate, LogicGate* tgate)
	{
		fromGate = fgate;
		toGate = tgate;
		tgate->setNextPin(fromGate->getOutput());
	}
private:
	LogicGate* fromGate, * toGate;
};

int main()
{
	AND g1;
	OR g2, g3;
	NOT g4;

	g1.setNextPin(1);
	g1.setNextPin(0);
	g2.setNextPin(0);
	g2.setNextPin(0);

	Connector c1(&g1, &g3);
	Connector c2(&g2, &g3);
	Connector c3(&g3, &g4);

	g4.getOutput();





}