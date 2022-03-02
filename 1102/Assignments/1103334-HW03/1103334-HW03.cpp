#include<iostream>
#include<ctime>

using namespace std;

class Book
{
public:
    int get();
    void set(int);
private:
    int price;
};

void Book::set(int n)
{
    price = n;
}

int Book::get()
{
    return price;
}


int main()
{
    const int n =10;
    srand(time(NULL));
    Book books[n];

    for (int i=0;i<n;i++)
        books[i].set(rand() %1000);

    sort(books,books+n);

    for(int i=0;i<n;i++)
       cout<<books[i].get()<<" ";

}