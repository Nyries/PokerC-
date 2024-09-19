#include "CircularPlayerList.h"

int CircularPlayerList::getNumberOfPlayerAlive() {
	if (!head) {
		throw runtime_error("No players currently.");
	}
	int numberOfPlayerAlive=0;
	PlayerNode* temp = head;
	do {
		if (!temp->player->isDead()) numberOfPlayerAlive++;
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
	} while (temp != head);
	return numberOfPlayerFold;
}

vector<int> CircularPlayerList::getPlayerChips()
{
	return vector<int>();
}

bool CircularPlayerList::isOnePlayerAlive() {
	if (!head) {
		throw runtime_error("No players currently.");
	}
	int numberOfPlayerAlive = getNumberOfPlayerAlive();
	if (numberOfPlayerAlive == 1) {
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
	int numberOfPlayerNotFold = getNumberOfPlayerFold();
	if (numberOfPlayerNotFold == 1) {
		return true;
	}
	else {
		return false;
	}
}

bool CircularPlayerList::isBetPotEqual() {
	if (!head) {
		throw runtime_error("No players currently.");
	}
	PlayerNode* temp = head;
	do {
	} while (temp != head);
	return false;
	
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
	do {
		temp->player->choice(pot, deck);
	} while (temp != head);
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
