#include <iostream>
#include <vector>
using namespace std;

string suits[] = { "黑陶","梅花","愛心","方塊" };
string faces[] = { "A","2","3","4","5","6","7","8","9","J","Q","K" };

class Card
{
public:
	Card(int s, int f);
	int getSuit(int i);
	int getFace(int i);
private:
	int suit, face;
};


Card::Card(int s, int f)
{
	suit = s;
	face = f;
}

int Card::getSuit(int i)
{
	return suit;
}
int Card::getFace(int i)
{
	return face;
}
class Cards
{
private:
	vector<Card> cards;
public:
	Cards();
	void shuffle();
	void show();
};




Cards::Cards()
{
	for (int face = 0; face < 13; face++)
	{
		for (int suit = 0; suit < 4; suit++)
		{
			Card buff(suit, face);
			cards.push_back(buff);
		}
	}

}

void Cards::show()
{
	for (int i = 0; i < 52; i++)
		cout << suits[cards[i].getSuit(i)] << " " << faces[cards[i].getFace(i)] << endl;;
}


void Cards::shuffle()
{
	int order[52] = {};
	for (int i = 0; i < 52; i++)
		order[i] = i;

	srand(time(NULL));

	for (int i = 0; i < 52; i++)
	{
		int buffer = rand() % 52;
		
		int t = order[i];
		order[i] = order[buffer];
		order[buffer] = t;
	}


	for (int i = 0; i < 6; i++)
		cout << suits[cards[order[i]].getSuit(order[i])] << " " << faces[cards[order[i]].getFace(order[i])] << endl;;
}


int main()
{
	Cards object;

	cout << "obj.show()" << endl;
	object.show();
	cout << "obj.shuffle()" << endl;
	object.shuffle();
}