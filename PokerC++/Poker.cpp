#include "Poker.h"

Poker::Poker() {
	this->pot = new Pot(0);
	this->commonCard = new CommonCard();
}

Poker::~Poker()
{
}

void Poker::launch(){
	cout << "Welcome in Poker Game in C++" << endl;
	cout << "This game uses the Texas Hold'em version of poker and is played by two players" << endl;
	cout << "It is recommended to play with console in fullscreen." << endl;
	cout << "How many players are you ? (Up to 8 players)" << endl;
	int numberOfPlayer;
	cin >> numberOfPlayer;
	while (numberOfPlayer < 1 or numberOfPlayer > 8) {
		cout << "Please put a reasonable amount of players." << endl;
		cin >> numberOfPlayer;
	}
	string name;
	for (int i = 0; i < numberOfPlayer; i++) {
		cout << "What is the name of player " << i << " ?" << endl;
		cin >> name;
		this->table->addPlayer(new Player(name, 0));
	}
	delete& name, & numberOfPlayer;
	int numberOfChips;
	cout << "how many chips do you begin the game with ?" << endl;
	cin >> numberOfChips;
	while (numberOfChips < 0) {
		cout << "Please put a reasonable number of chips." << endl;
		cin >> numberOfChips;
	}
	table->setChips(numberOfChips);
	delete& numberOfChips;
	cout << "Let's begin!" << endl;
	this->deck = new Deck();
	gameLoop();
}

void Poker::gameLoop() {
	while (!table->isOnePlayerAlive()) {
		cout << "Distribution des cartes." << endl;
		table->dealTheCardsFrom(deck);
		table->playerChoices(pot, deck);
	}
}
