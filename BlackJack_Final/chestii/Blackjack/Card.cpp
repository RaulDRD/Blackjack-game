#include "Card.h"



Card::Card(string suit, string symbol) {
	this->suit = suit;
	this->symbol = symbol;

}
string Card::getSuit()  {
	return suit;
}


string Card::getSymbol()  {
	return symbol;
}