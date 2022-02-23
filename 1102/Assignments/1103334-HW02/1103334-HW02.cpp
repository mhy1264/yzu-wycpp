#include<iostream>
#include<string>
using namespace std;
struct Node
{
    char ch;
    int count;
};



int main()
{
    Node node[52];
    string str;
    string dict = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";


    for (int i = 0; i < 52; i++)
    {
        node[i].count = 0;
        node[i].ch = dict[i];
    }


    while (cin >> str)
    {
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] >= 'a' && str[i] <= 'z')
                node[(int)str[i] - 'a'].count++;
            else
                node[(int)str[i] - 'A' + 26].count++;
        }

        for (int i = 0; i < 52; i++)
            if(node[i].count)
             cout << node[i].ch << " ->>> " << node[i].count << endl;
    }


}