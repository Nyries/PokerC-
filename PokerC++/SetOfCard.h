#ifndef SETOFCARD_H
#define SETOFCARD_H

#include "Card.h"

#include <vector>

class SetOfCard{
protected:
	vector<Card*> cards;
	int findCard(Card* card);
public:
	//Constructor, Destructor
	SetOfCard();
	virtual ~SetOfCard();

	//Getter
	virtual int getNumberOfCards() = 0;
	virtual Card* getCardByIndex(int index) = 0;
	vector<Card*> getCards();

	//Setter
	void setFacesUp();
	void setFacesDown();

	//State function
	bool isEmpty();

	//Display function
	void displayCards();

	void changeCardFace();
	void addCard(Card* card);
	void addCardFrom(vector<Card*> cards);
	void removeCard(Card* card);
	Card* popCard();
	void takeLastCardFrom(SetOfCard* setOfCard);
	void clearHandTo(SetOfCard* setOfCard);

};

#endif // !SETOFCARD_H