#include<iostream>
using namespace std;

class LogicGate
{
public:
	bool getOutput()
	{
		result = performLogicGate();
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

class AND :public binary
{
public:
	bool performLogicGate()
	{
		cout << "in And perform" << endl;
		if (x * y != 1)
			result = false;
		else
			result = true;

		return result;
	}

	void setNextPin(bool next)
	{
		y = x;
		x = next;
		cout << "current Pin" << x << " " << y << endl;

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

class NOR :public binary
{
public:
	NOR()
	{
		;
	}
	bool performLogicGate()
	{
		if (x + y == 1)
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

class SRGate :public LogicGate
{
public:
	SRGate(bool P1, bool P2, bool P3)
	{
		p1 = P1;
		p2 = P2;
		p3 = P3;
	}

	SRGate(bool P1, bool P2)
	{
		p1 = P1;
		p2 = P2;
		p3 = false;
	}

	bool performLogicGate()
	{
		NOR nor1;
		nor1.setNextPin(p1);
		nor1.setNextPin(p2);

		NOR nor2;

		Connector Conn1(&nor1, &nor2);
		nor2.setNextPin(p3);

		return nor2.performLogicGate();

	}

	void setNextPin(bool next)
	{
		p3 = p2;
		p2 = p1;
		p1 = next;
	}

	bool getOutput()
	{
		result = performLogicGate();
		printf("%d %d %d ", p1, p2, p3);
		return result;
	}

private:
	bool p1 = false, p2 = false, p3 = false;
};

int main()
{
	SRGate s1(0, 0);
	bool q1 = s1.getOutput();
	cout << " => " << q1 << endl;

	SRGate s2(0, 0, q1);
	bool q2 = s2.getOutput();
	cout << " => " << q2 << endl;


	SRGate s3(1, 0, q2);
	bool q3 = s3.getOutput();
	cout << " => " << q3 << endl;

	SRGate s4(0, 1, q3);
	bool q4 = s4.getOutput();
	cout << " => " << q4 << endl;

}