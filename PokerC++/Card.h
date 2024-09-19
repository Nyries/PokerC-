#ifndef CARD_HPP  // Protection contre les inclusions multiples
#define CARD_HPP

#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

enum Suit { HEARTS, DIAMONDS, CLUBS, SPADES , NUMBEROFSUIT};  // Les 4 couleurs
enum Rank { TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE, NUMBEROFRANK};  // Valeurs des cartes

class Card {
private:
    Suit suit;  // Couleur de la carte
    Rank rank;  // Valeur de la carte
    bool isFaceUp;
public:
    // Constructor
    Card(Suit s, Rank r);

    // Méthodes pour obtenir la chaîne de caractères des valeurs et couleurs
    string getRankAsString() const;
    string getSuitAsString() const;
    vector<string> getCardDisplay() const;
    bool getFace();

    //Setter
    void setFace(bool isFaceUp);

    // Méthode pour afficher la carte
    void infoCard() const;
    void displayCard() const;

    // Getters
    Rank getRank() const;
    Suit getSuit() const;

    bool operator==(const Card& other) const;
};

#endif  // Fin de la protection contre les inclusions multiples
