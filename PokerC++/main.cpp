#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Poker.h"

int main() {
	//Premier test
	Card carte(CLUBS, TWO);
	carte.setFace(true);
	carte.displayCard();
	//Hand hand = Hand();
	//deck.shuffle();
	//hand.dealCardsFrom(&deck);
	//hand.displayCards();
	//player1.dealCardsFrom(&deck);
	//player1.displayHand();
	
	//Poker poker(player1, player2);
	//poker.launch();
	return 1;
}