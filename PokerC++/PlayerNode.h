#ifndef NODE_H
#define NODE_H

#include "Player.h"

class PlayerNode{
public:
	Player* player;
	PlayerNode* next;

	PlayerNode(Player* p) : player(p), next(nullptr) {};
};

#endif // !NODE_H