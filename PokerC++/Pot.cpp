#include "Pot.h"

Pot::Pot(int chips): chips(chips)
{
}

Pot::~Pot()
{
}

int Pot::getChips()
{
	return chips;
}

void Pot::setChips(int chips)
{
	this->chips = chips;
}

bool Pot::isEmpty()
{
	if (this->chips == 0) {
		return true;
	}
	else {
		return false;
	}
}

void Pot::addChips(int amount) {
	this->chips += amount;
}

void Pot::substractChips(int amount) {
	this->chips -= amount;
}

void Pot::takeChipsFrom(int amount, Pot* pot) {
	this->chips += amount;
	pot->substractChips(amount);
}

void Pot::giveChipsTo(int amount, Pot* pot) {
	this->chips -= amount;
	pot->addChips(amount);
}
