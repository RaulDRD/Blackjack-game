#include "Deck.h"
#include "Card.h"
#include <vector>
#include<iostream>
#include<random>
#include<algorithm>

using namespace std;


Deck::Deck() {
	vector<string>suit = { "Hearts", "Diamonds", "Spades", "Clubs" };
	vector<string>symbol = { "A","2","3","4","5","6","7","8","9","10","J","Q","K" };

	for (int i = 0;i < suit.size();i++)
	{
		for (int j = 0;j < symbol.size();j++)
		{
			deck.push_back(Card(suit[i], symbol[j]));
		}
	}
}

void Deck::Shuffle()
{
	srand(time(NULL));
	for (int i = 0; i < deck.size(); ++i) {

		int j = rand() % deck.size();
		swap(deck[i], deck[j]);

	}

};

/*void Deck::Afiseaza() {
	for (int i = 0;i < deck.size();i++)
	{
		cout << deck[i].getSuit() << " of " << deck[i].getSymbol() <<i<<endl;
	}

}*/

void Deck::giveCardP() {

	Player.push_back(deck[ct]);
	deck.pop_back();
	ct++;

}

vector <Card> Deck::giveHandP() {

	return Player;
}

void Deck::giveCardD() {

	Dealer.push_back(deck[ct]);
	deck.pop_back();

	ct++;
}

void Deck::showHandD() {
	cout << "Dealer's Hand:" << endl;
	for (int i = 0;i < Dealer.size();i++)
	{
		cout << Dealer[i].getSymbol() << " of " << Dealer[i].getSuit() << endl;
	}
	cout << endl;
}

int Deck::ScoreP() {
	int scoreP = 0;
	for (int i = 0;i < Player.size();i++)
	{

		if (Player[i].getSymbol() == "J" || Player[i].getSymbol() == "Q" || Player[i].getSymbol() == "K" || Player[i].getSymbol() == "10")
		{
			scoreP = scoreP + 10;
		}
		else if (Player[i].getSymbol() == "A") {
			if (scoreP + 11 > 21)
			{
				scoreP = scoreP + 1;
			}
			else
			{
				scoreP = scoreP + 11;
			}
		}
		else {
			scoreP = scoreP + stoi(Player[i].getSymbol());
		}
	}
	return scoreP;
}

int Deck::ScoreD() {
	int scoreD = 0;
	for (int i = 0;i < Dealer.size();i++)
	{

		if (Dealer[i].getSymbol() == "J" || Dealer[i].getSymbol() == "Q" || Dealer[i].getSymbol() == "K" || Dealer[i].getSymbol() == "10")
		{
			scoreD = scoreD + 10;
		}
		else if (Dealer[i].getSymbol() == "A") {
			if (scoreD + 11 > 21)
			{
				scoreD = scoreD + 1;
			}
			else
			{
				scoreD = scoreD + 11;
			}
		}
		else {
			scoreD = scoreD + stoi(Dealer[i].getSymbol());
		}
	}
	return scoreD;
}
