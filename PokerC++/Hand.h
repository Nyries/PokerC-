#ifndef HAND_H
#define HAND_H

#include "SetOfCard.h"
#include "Deck.h"

class Hand : public SetOfCard{
public:
	//Constructor, Destructor
	Hand();
	~Hand();

	//Getter, Setter
	int getNumberOfCards();
	Card* getCardByIndex(int index);

	//Other Functions
	void dealCardsFrom(Deck* deck);
	void addCardFrom(vector<Card*> cards);
	void clearHandTo(Deck* deck);
};
#endif // !HAND_H
