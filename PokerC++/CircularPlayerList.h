#ifndef CIRCULAR_PLAYER_LIST_H
#define CIRCULAR_PLAYER_LIST_H

#include "PlayerNode.h"
#include "Deck.h"

class CircularPlayerList{
private:
	PlayerNode* head;
	PlayerNode* tail;
public:

	CircularPlayerList() : head(nullptr), tail(nullptr) {};

	//Getter
	int getNumberOfPlayerAlive();
	int getNumberOfPlayerFold();
	vector<int> getPlayerChips();
	int getMaxBet();
	vector<int> getBetChips();

	//State function
	bool isOnePlayerAlive();
	bool isOnePlayerNotFold();
	bool isNoPlayerIdle();
	bool isBetPotEqual();

	void addPlayer(Player* player);
	void removePlayer(const string& name);
	void playerChoices(Pot* pot, Deck* deck);
	void setChips(int chips);
	void dealTheCardsFrom(Deck* deck);
};

#endif;