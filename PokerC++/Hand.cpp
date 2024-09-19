#include "Hand.h"

Hand::Hand(){
}

Hand::~Hand()
{
}

int Hand::getNumberOfCards()
{
	return 0;
}

Card* Hand::getCardByIndex(int index)
{
	return nullptr;
}

void Hand::dealCardsFrom(Deck* deck){
	cards.push_back(deck->popCard());
	cards.push_back(deck->popCard());
}

void Hand::addCardFrom(vector<Card*> cards) {
}

void Hand::clearHandTo(Deck* deck) {
	for (int i = 0; i < 2; i++) {
		deck->addCardFrom(cards);
		cards.clear();
	}
}

