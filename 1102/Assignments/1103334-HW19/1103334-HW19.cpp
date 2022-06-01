#include<iostream>
#include<vector>
using namespace std;

template<typename ScaryVal>
class Stack
{
public :
	void push(ScaryVal val)
	{
		element.push_back(val);
		topind++;
	}

	ScaryVal pop()
	{
		topind--;
		return element[topind];
	}

	ScaryVal top()
	{
		return element[topind-1];
	}

private:
	vector <ScaryVal> element;
	int topind = 0;
};



int main()
{
	Stack<int>stack1;
	stack1.push(1);
	stack1.push(2);
	stack1.push(3);
	cout << stack1.pop() << endl;
	cout << stack1.top() << endl;

	Stack<string>stack2;
	stack2.push("Hello");
	stack2.push("World");
	cout << stack2.top() << endl;;

}