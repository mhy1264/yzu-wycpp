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

class NAND :public binary
{
public:
	NAND()
	{
		x = y = false;
	}

	NAND(bool p1, bool p2)
	{
		x = p1;
		y = p2;
	}

	bool performLogicGate()
	{
		if (x * y == 1)
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

class AND :public binary
{
public:
	AND(bool p1, bool p2)
	{
		x = p1;
		y = p2;
	}

	bool performLogicGate()
	{
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

class SRGate:public LogicGate
{
public:
	SRGate(bool p1, bool p2)
	{
		s = p1;
		r = p2;
		q = false;
	}

	SRGate(bool p1, bool p2, bool p3)
	{
		s = p1;
		r = p2;
		q = p3;
	}

	bool performLogicGate()
	{
		NAND nand1(q, !r);
		NAND nand2;
		Connector conn(&nand1, &nand2);
		nand2.setNextPin(!s);
		result = nand2.performLogicGate();
		return result;

	}
	
	bool getOutput()
	{
		AND input(s, r);
		cout << s << " " << r << " " << q << " -> ";
		if (input.performLogicGate())
		{
			cout << "Undefined " << endl;
		}
		else
		{
			cout  << result << endl;
		}
		return result;
	}

	void setNextPin(bool next)
	{
		q = r;
		r = s;
		s = next;
	}

private:
	bool s, r, q;

};

int main()
{

	bool s[] = { 0,0,0,0,1,1,1,1 };
	bool r[] = { 0,0,1,1,0,0,1,1 };
	bool q[] = { 0,1,0,1,0,1,0,1 };

	for (int i = 0; i < 8; i++)
	{
		SRGate sr(s[i], r[i], q[i]);
		sr.performLogicGate();
		sr.getOutput();
	}

}