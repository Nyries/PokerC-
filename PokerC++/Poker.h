#ifndef POKER_H
#define POKER_H

#include "CircularPlayerList.h"
#include "CommonCard.h"
#include "Deck.h"
#include "Pot.h"


/*Déroulé d'une partie (Poker Texas Hold'em)
Initialisation de la partie:
Chaque joueur commence sans carte et avec 10(comme on veut) jetons

Le jeu se découpe ensuite en round:
-Distribution de 2 cartes aux joueurs
-Choix des joueurs (check, bet/allin, fold) (preflop
-Tirage de 3 cartes au milieu 
-flop
-Tirage d'une carte au milieu (turn)
-turn
-Tirage d'une carte au milieu (river)
-river
-Showdown
*/
class Poker{
private:
	CircularPlayerList* table;
	CommonCard* commonCard;
	Deck* deck;
	Pot* pot;
public:
	//Constructor, Destructor
	Poker();
	~Poker();

	//Game actions
	void launch();
	void gameLoop();
	void flop();
	void turn();
	void river();
	//Shuffle les cartes et lance un round. Distribution des cartes -> attentes des choix des joueurs -> 
};

#endif