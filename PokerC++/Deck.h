#ifndef DECK_H
#define DECK_H

#include <random>
#include <algorithm>

#include "SetOfCard.h"

class Deck : public SetOfCard {
public:	
	//Constructor, Destructor
	Deck();
	~Deck();

	//Getter, Setter
	int getNumberOfCards();
	Card* getCardByIndex(int index);

	//Display function
	void displayDeck();

	//Other functions
	void addCardFrom(vector<Card*> cards);
	void shuffle();
};

#endif;

