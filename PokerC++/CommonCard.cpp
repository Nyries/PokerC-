#include "CommonCard.h"

CommonCard::CommonCard()
{
}

CommonCard::~CommonCard()
{
	cards.clear();
	delete &cards;
}

int CommonCard::getNumberOfCards()
{
	return static_cast<int>(cards.size());
}

Card* CommonCard::getCardByIndex(int index)
{
	return nullptr;
}

void CommonCard::flop(Deck* deck)
{
	takeLastCardFrom(deck);
	takeLastCardFrom(deck);
	takeLastCardFrom(deck);
}

void CommonCard::turn(Deck* deck)
{
	takeLastCardFrom(deck);
}

void CommonCard::river(Deck* deck)
{
	takeLastCardFrom(deck);
}
