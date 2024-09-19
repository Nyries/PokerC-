#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"

int main() {
	//Premier test
	Card carte(CLUBS, TWO);
	carte.setFace(true);
	carte.displayCard();
	//Deck deck = Deck();
	//Hand hand = Hand();
	//deck.shuffle();
	//hand.dealCardsFrom(&deck);
	//hand.displayCards();
	Player player1 = Player("player1", 10);
	Deck deck = Deck();
	deck.shuffle();
	//player1.dealCardsFrom(&deck);
	//player1.displayHand();
	
	//Poker poker(player1, player2);
	//poker.launch();
	return 1;
}