#include "CircularPlayerList.h"

int CircularPlayerList::getNumberOfPlayerAlive() {
	if (!head) {
		throw runtime_error("No players currently.");
	}
	int numberOfPlayerAlive=0;
	PlayerNode* temp = head;
	PlayerNode* prev = nullptr;

	do {
		if (!temp->player->isDead()) numberOfPlayerAlive++;
		temp = temp->next;
	} while (temp != head);
	return numberOfPlayerAlive;
}

int CircularPlayerList::getNumberOfPlayerFold() {
	if (!head) {
		throw runtime_error("No players currently.");
	}
	int numberOfPlayerFold = 0;
	PlayerNode* temp = head;

	do {
		if (!temp->player->isFold()) numberOfPlayerFold++;
		temp = temp->next;
	} while (temp != head);
	return numberOfPlayerFold;
}

vector<int> CircularPlayerList::getPlayerChips()
{
	return vector<int>();
}

int CircularPlayerList::getMaxBet()
{
	int maxBet = 0;
	PlayerNode* temp = head;
	do {
		if (temp->player->getState() != DEAD or temp->player->getState() != IDLE) {
			if (temp->player->getBetChips() > maxBet) maxBet = temp->player->getBetChips();
		}
	} while (temp != head);
	return maxBet;
}

vector<int> CircularPlayerList::getBetChips()
{
	vector<int> betChips;
	PlayerNode* temp = head;
	do {
		if (temp->player->getState() == CHECK or temp->player->getState() == BET or temp->player->getState() == IDLE) {
			betChips.push_back(temp->player->getBetChips());
		}
		temp = temp->next;
	} while (temp != head);
	return betChips;
}

bool CircularPlayerList::isOnePlayerAlive() {
	if (!head) {
		throw runtime_error("No players currently.");
	}
	if (getNumberOfPlayerAlive() == 1) {
		return true;
	}
	else {
		return false;
	}
}

bool CircularPlayerList::isOnePlayerNotFold() {
	if (!head) {
		throw runtime_error("No players currently.");
	}
	if (getNumberOfPlayerFold() == 1) {
		return true;
	}
	else {
		return false;
	}
}

bool CircularPlayerList::isNoPlayerIdle()
{
	if (!head) {
		throw runtime_error("No players currently.");
	}
	PlayerNode* temp = head;
	do {
		if (temp->player->getState() == IDLE) {
			return false;
		}
		temp = temp->next;
	} while (temp != head);
	return true;
}

bool CircularPlayerList::isBetPotEqual()
{
	vector<int> betChips = getBetChips();
	PlayerNode* temp = head;
	int prev = betChips[0];
	for (int chips : betChips) {
		if (prev != chips) {
			return false;
		}
	}
	return true;
	
}


void CircularPlayerList::addPlayer(Player* player) {
	PlayerNode* newNode = new PlayerNode(player);
	if (!head) {
		head = newNode;
		tail = newNode;
		newNode->next = head;
	}
	else {
		tail->next = newNode;
		newNode->next = head;
		tail = newNode;
	}
}

void CircularPlayerList::removePlayer(const string& name) {
	if (!head) {
		throw runtime_error("No players currently.");
	}

	PlayerNode* temp = head;
	PlayerNode* prev = nullptr;

	do {
		if (temp->player->getName() == name) {
			
			if (temp == head) {
				//First Player
				if (head == tail) {
					//Only Player
					delete head;
					head = nullptr;
					tail = nullptr;
				}
				else {
					tail->next = head->next;
					delete head;
					head = tail->next;
				}
			}
			else {
				prev->next = temp->next;
				if (temp == tail) {
					tail = prev; //Last Player
				}
				delete temp;
			}
			return;
		}
		prev = temp;
		temp = temp->next;
	} while (temp != head);
}

void CircularPlayerList::playerChoices(Pot* pot, Deck* deck) {
	if (!head) {
		throw runtime_error("No player.");
	}
	PlayerNode* temp = head;
	int maxBet = 0;
	do {
		if (temp->player->getState() != DEAD or temp->player->getState() != FOLD) {
			maxBet = getMaxBet();
			temp->player->choice(pot, deck, maxBet);
		}
		if (isOnePlayerNotFold()) break;
		temp = temp->next;
	} while (!isBetPotEqual() or !isNoPlayerIdle()); //un seul joueur n'a pas fold ou les bets parmi les joueurs CHECK, BET et IDLE sont égaux
	cout << "Yo" << endl;
}

void CircularPlayerList::setChips(int chips){
	if (!head) {
		throw runtime_error("No player.");
	}

	PlayerNode* temp = head;
	do {
		temp->player->setChips(chips);
	} while (temp != head);
}

void CircularPlayerList::dealTheCardsFrom(Deck* deck) {
	if (!head) {
		throw runtime_error("No player.");
	}

	PlayerNode* temp = head;
	int numberOfCardForEachPlayer = 2;
	for (int i = 0; i < numberOfCardForEachPlayer; i++) {
		do {
			temp->player->dealCardFrom(deck);
			temp = temp->next;
		} while (temp != head);
	}
}
