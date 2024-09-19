#ifndef COMMON_CARD_H
#define COMMON_CARD_H
#include "SetOfCard.h"
#include "Deck.h"

class CommonCard : public SetOfCard{
public:
	//Constructor, Destructor
	CommonCard();
	~CommonCard();

	//Getter
	int getNumberOfCards();
	Card* getCardByIndex(int index);

	//Other functions
	void flop(Deck* deck);
	void turn(Deck* deck);
	void river(Deck* deck);
};

#endif;