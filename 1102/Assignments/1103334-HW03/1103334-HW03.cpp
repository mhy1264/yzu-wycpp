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

void DoSort(int n, int* ptr)
{
    int i, j, t;
  
    // Sort the numbers using pointers
    for (i = 0; i < n; i++) {
  
        for (j = i + 1; j < n; j++) {
  
            if (*(ptr + j) < *(ptr + i)) {
  
                t = *(ptr + i);
                *(ptr + i) = *(ptr + j);
                *(ptr + j) = t;
            }
        }
    }
  
}
int main()
{
    const int n =10;
    srand(time(NULL));
    Book books[n];
    int arr[n];

    for (int i=0;i<n;i++)
        arr[i]=rand() %1000;

    DoSort(n,arr);

    for(int i=0;i<n;i++)
    books[i].set(arr[i]);

    for(int i=0;i<n;i++)
       cout<<books[i].get()<<" ";

}