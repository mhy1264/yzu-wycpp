#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Book
{
private:
	string title, author;
	int price;
public :
	Book(string ,string ,int);
	void show();
	int getPrice();
	int getBiggest(int,int);
	void showEach();
};

Book::Book(string str1,string str2,int num)
{
	title = str1;
	author = str2;
	price = num;
}
void Book::showEach()
{
	cout << title << " " << author << " " << price << endl;
}

int Book::getBiggest(int i,int currentPrice)
{
	static int indd = 0;
	static int price = 0;
	if (price < currentPrice)
	{
		indd = i;
		price = currentPrice;
	}
		
	return indd;
}

void Book::show()
{
	cout << "max " << title << " " << author << " " << price << endl;
}

int Book::getPrice()
{
	return price;
}
int main()
{
	vector <Book> books;

	string names[] = { "AAA","BBB","CCC" };
	string auth[] = { "MHY","Ming","Huan" };

	for (int i = 0; i < 3; i++)
	{
		Book buffer(names[i], auth[i], rand() % 1000 + 100);
		buffer.showEach();
		books.push_back(buffer);
	}

	int ind;
	
	for (int i = 0; i < 3; i++)
	{
		ind = books[i].getBiggest(i, books[i].getPrice());
	}

	books[ind].showEach();
}	