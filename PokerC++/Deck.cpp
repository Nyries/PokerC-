#include "Deck.h"

Deck::Deck()
{
	for (int i = 0; i < static_cast<int>(Suit::NUMBEROFSUIT); i++) {
		for (int j = 0; j < static_cast<int>(Rank::NUMBEROFRANK); j++) {
			cards.push_back(new Card(static_cast<Suit>(i), static_cast<Rank>(j)));
		}
	}
}

Deck::~Deck()
{
}

int Deck::getNumberOfCards()
{
	return static_cast<int>(cards.size());
}

Card* Deck::getCardByIndex(int index)
{
	if (!(index >= 0 and index <= cards.size())) {
		throw runtime_error("Error : index out of range");
	}
	return cards[index];
}

void Deck::displayDeck()
{
	for (Card* card : cards) {
		card->displayCard();
	}
}

void Deck::addCardFrom(vector<Card*> cards)
{
}

void Deck::shuffle() {
	random_device rd;
	mt19937 g(rd());  

	std::shuffle(cards.begin(), cards.end(), g);
}



