#include <iostream>
#include <vector>
using namespace std;

string suits[] = { "梅花","黑桃","紅心","方塊" };
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

// default constructor 
// set the suit and face
Card::Card(int s, int f)
{
	suit = s;
	face = f;
}

// get suit item
int Card::getSuit(int i)
{
	return suit;
}

// get face item
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

// Cards default constructor
// put 52 cards to cards 
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

// show each cards
void Cards::show()
{
	for (int i = 0; i < 52; i++)
		cout << suits[cards[i].getSuit(i)] << " " << faces[cards[i].getFace(i)] << endl;;
}

// shuffle the card
void Cards::shuffle()
{
	// init the cards order 
	int order[52] = {};
	for (int i = 0; i < 52; i++)
		order[i] = i;

	srand(time(NULL));
	// shuffle the cards
	for (int i = 0; i < 52; i++)
	{
		int buffer = rand() % 52;
		
		int t = order[i];
		order[i] = order[buffer];
		order[buffer] = t;
	}

	// get the top six card
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