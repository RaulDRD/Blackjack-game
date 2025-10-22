#pragma once
#include <string>

using namespace std;

class Card
{
private:
	string suit;
	string symbol;

public:
	string getSuit();
	string getSymbol();

	Card(string suit, string symbol);
	
};