#include "Hand.h"

#include <chrono>
#include <thread>

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

void Hand::displayCards()
{
	if (cards.empty()) {
		cout << "No card to display" << endl;
		return;
	}

	const int numLines = 11;

	vector<vector<string>> cardDisplays;
	for (Card* card : cards) {
		cardDisplays.push_back(card->getCardDisplay());
	}
	for (int line = 0; line < numLines; line++) {
		for (size_t i = 0; i < cards.size(); i++) {
			cout << cardDisplays[i][line] << "  ";
		}
		cout << endl;
	}
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

