#include<iostream>
using namespace std;

template <typename ScaryVal>
class A
{
public:
	A(ScaryVal num)
	{
		data = new ScaryVal[num]();
	}
	
	void setVal(int index, ScaryVal val)
	{
		data[index] = val;
		ind = index + 1;
	}

	void setVal(ScaryVal val)
	{
		setVal(ind, val);
	}

	ScaryVal getVal(int index)
	{
		return data[index];
	}
private:
	ScaryVal* data;
	int ind=0;
};

int main()
{
	A<double>doubleA(3);
	doubleA.setVal(1);
	doubleA.setVal(2);
	doubleA.setVal(0, 999);
	doubleA.setVal(3);
	doubleA.setVal(4);

	for (int i = 0; i < 3; i++)
		cout << doubleA.getVal(i) << " ";
	cout << endl;
}