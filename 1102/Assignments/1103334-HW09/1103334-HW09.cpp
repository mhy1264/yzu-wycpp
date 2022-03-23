#include<iostream>
#include<vector>

using namespace std;

class Set
{
public:
	void show();
	void add(int);
	bool contain(int);
	Set operator|(Set);
	Set operator&(Set);
	Set();
	Set(const Set& set);
private:
	vector <int> set;

};

Set::Set()
{
	;
}

Set::Set(const Set& temp)
{
	for (int i = 0; i < temp.set.size(); i++)
		set.push_back(temp.set[i]);
}

void Set::show()
{
	int size = set.size();

	for (int i = 0; i < size; i++)
		cout << set[i] << " ";
	cout << endl;
}

bool Set::contain(int temp)
{
	int size = set.size();

	bool check=true;

	for (int i = 0; i < size; i++)
		if (temp == set[i])
			return true;
	return false;

}

void Set::add(int n)
{
	if (!contain(n))
		set.push_back(n);
}

Set Set::operator|(Set right)
{
	Set buffer(right);

	for (int i = 0; i < set.size(); i++)
		if (!buffer.contain(set[i]))
			buffer.set.push_back(set[i]);

	return buffer;
}

Set Set::operator&(Set right)
{
	Set buffer;

	for (int i = 0; i < set.size(); i++)
		if (right.contain(set[i]))
			buffer.set.push_back(set[i]);

	return buffer;
}
int main()
{
	Set set1, set2;


	int arr1[] = {1,2,3,4,5};

	for (int i = 0; i < 5; i++)
		set1.add(arr1[i]);

	int arr2[] = { 5,6,7,8,9 };

	for (int i = 0; i < 5; i++)
		set2.add(arr2[i]);

	cin.ignore();



	Set set3 = set1 | set2;
	Set set4 = set1 & set2;

	set3.show();
	set4.show();
}