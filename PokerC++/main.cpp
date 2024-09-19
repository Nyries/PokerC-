#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Poker.h"

int main() {
	//Test for the cards
	Card carte(CLUBS, TWO);
	carte.setFace(true);
	carte.displayCard();

	//Test for players and table
	Deck deck = Deck(); // Deck generated
	Pot pot = Pot(0); //Middle pot
	deck.shuffle();
	Player jean = Player("Jean", 10);
	Player michel = Player("Michel", 10);
	Player annie = Player("Annie", 10);
	CircularPlayerList table = CircularPlayerList();
	table.addPlayer(&jean);
	table.addPlayer(&michel);
	table.addPlayer(&annie);
	table.dealTheCardsFrom(&deck);
	table.playerChoices(&pot, &deck);

	//Poker poker(player1, player2);
	//poker.launch();
	return 1;
}