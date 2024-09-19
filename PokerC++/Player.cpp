#include "Player.h"

Player::Player(string name, int chips) : name(name), pot(new Pot(chips)), betPot(new Pot(0)), hand(new Hand), state(static_cast<State>(0))
{
}

Player::~Player()
{
}

string Player::getName()
{
	return name;
}

int Player::getChips() {
	return pot->getChips();
}

Pot* Player::getPot() {
	return this->pot;
}

Pot* Player::getBetPot()
{
	return this->betPot;
}

Hand* Player::getHand() {
	return hand;
}

vector<Card*> Player::getCards()
{
	return hand->getCards();
}

State Player::getState()
{
	return state;
}

void Player::setChips(int chips)
{
	this->pot->setChips(chips);
}

void Player::setCard(vector<Card*> hand) {
}

void Player::setState(State state) {
	this->state = state;
}

bool Player::isFold()
{
	return hand->isEmpty();
}

bool Player::isDead()
{
	if (pot->isEmpty()) {
		return true;
	}
	else {
		return false;
	}
}

void Player::dealCardFrom(Deck* deck) {
	hand->takeLastCardFrom(deck);
}

void Player::displayHand()
{
	hand->displayCards();
}

void Player::choice(Pot* pot, Deck* deck){
	string playerChoice;
	cout << "What do you play ? (check, bet, allin, fold, show)" << endl;
	cin >> playerChoice;
	while (playerChoice != "check" or playerChoice != "bet" or playerChoice != "allin" or playerChoice != "fold" or playerChoice != "show") {
		cout << "Please write an appropriate playerChoice." << endl;
		cin >> playerChoice;
	}
	if (playerChoice == "check") {
		check();
	}
	else if (playerChoice == "bet") {
		bet();
	}
	else if (playerChoice == "allin") {
		allin();
	}
	else if (playerChoice == "fold") {
		fold(deck);
	}
	else if (playerChoice == "show") {
		show();
		choice(pot, deck);
	}
}

void Player::check() {
	cout << "You check." << endl;
	this->state = CHECK;
}

void Player::bet() {
	this->state = BET;
	int chipsBet=0;
	cout << "How many chips do you want to bet ?" << endl;
	cin >> chipsBet;
	while (chipsBet <= 0 or chipsBet > this->pot->getChips()) {
		cout << "Please put a reasonable amount. You have " << this->pot->getChips() << " chips." << endl;
		cin >> chipsBet;
	}
	this->pot->giveChipsTo(chipsBet, this->betPot);

}

void Player::allin()
{
	this->state = BET;
	this->betPot->giveChipsTo(this->pot->getChips(), pot);
	cout << "You all in." << endl;
}

void Player::fold(Deck* deck)
{
	this->state = FOLD;
	this->hand->clearHandTo(deck);
}

void Player::show() {
	this->hand->displayCards();
}

