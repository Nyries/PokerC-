#include "SetOfCard.h"

int SetOfCard::findCard(Card* card){
	auto it = find_if(cards.begin(), cards.end(), [&card](Card* c) {
		return *c == *card;
		});
	if (it != cards.end()) {
		return distance(cards.begin(), it);
	}
	return -1;
}

SetOfCard::SetOfCard(){}

SetOfCard::~SetOfCard(){
	for (Card* card : cards) {
		delete card;
	}
	cards.clear();
}

vector<Card*> SetOfCard::getCards()
{
	return cards;
}

bool SetOfCard::isEmpty()
{
	return cards.empty();
}

void SetOfCard::displayCards(){
	if (cards.empty()) {
		cout << "No card to display" << endl;
		return;
	}
	
	const int numLines = 15;

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

void SetOfCard::changeCardFace()
{
	for (Card* card : cards) {
		card->setFace(!card->getFace());
	}
}

void SetOfCard::addCard(Card* card){
	if (findCard(card) != -1) {
		cards.push_back(card);
	}
	else {
		throw runtime_error("Erreur : Card already in the set");
	}
}

void SetOfCard::addCardFrom(vector<Card*> cards) {
	for (Card* card : cards) {
		addCard(card);
	}
}

void SetOfCard::removeCard(Card* card){
	int index = findCard(card);
	if (index != -1) {
		delete cards[index];
		cards.erase(cards.begin() + index);
	}
	else {
		throw runtime_error("Error : Card not found");
	}
}

Card* SetOfCard::popCard()
{
	if (cards.empty()) {
		throw runtime_error("No cards");
	}
	Card* card = cards.back();
	cards.pop_back();

	return card;
}

void SetOfCard::takeLastCardFrom(SetOfCard* setOfCard)
{
	this->cards.push_back(setOfCard->popCard());
}

void SetOfCard::clearHandTo(SetOfCard* setOfCard)
{
	setOfCard->cards.push_back(this->popCard());
}

