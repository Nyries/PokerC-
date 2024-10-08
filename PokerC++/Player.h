#include <vector>

#include "Card.h"
#include "Hand.h"
#include "Deck.h"
#include "Pot.h"

enum State {IDLE, CHECK, BET, ALLIN, FOLD, DEAD};

class Player{
private:
	string name;
	Pot* pot;
	Pot* betPot;
	Hand* hand;
	State state;
public:
	//Constructeurs
	Player(string name, int chips);
	~Player();

	//Getter
	string getName();
	int getChips();
	int getBetChips();
	Pot* getPot();
	Pot* getBetPot();
	Hand* getHand();
	vector<Card*> getCards();
	State getState();

	//Setter
	void setChips(int chips);
	void setCard(vector<Card*> hand);
	void setState(State state);

	//State functions
	bool isFold();
	bool isDead();

	//Autres Fonctions
	void dealCardFrom(Deck* deck);
	void displayHand();

	//Player actions
	void choice(Pot* pot, Deck* deck, int maxBet);
	void check();
	void bet(int maxBet);
	void allin();
	void fold(Deck* deck);
	void show();

};

