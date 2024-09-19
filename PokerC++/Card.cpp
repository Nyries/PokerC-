#include "Card.h"  // Inclusion du fichier d'en-tête

// Constructeur de la classe Card
Card::Card(Suit s, Rank r) : suit(s), rank(r), isFaceUp(false){}

// Méthode pour obtenir la chaîne de caractères de la valeur de la carte
string Card::getRankAsString() const {
    switch (rank) {
    case TWO: return "2";
    case THREE: return "3";
    case FOUR: return "4";
    case FIVE: return "5";
    case SIX: return "6";
    case SEVEN: return "7";
    case EIGHT: return "8";
    case NINE: return "9";
    case TEN: return "10";
    case JACK: return "J";
    case QUEEN: return "Q";
    case KING: return "K";
    case ACE: return "A";
    default: return "?";
    }
}

// Méthode pour obtenir la chaîne de caractères de la couleur de la carte
string Card::getSuitAsString() const {
    switch (suit) {
    case HEARTS: return "H";
    case DIAMONDS: return "D";
    case CLUBS: return "C";
    case SPADES: return "S";
    default: return "?";
    }
}

vector<string> Card::getCardDisplay() const {
    vector<string> cardDisplay;
    if (this->isFaceUp) {
        cardDisplay.push_back("-----------------");
        cardDisplay.push_back("|" + getSuitAsString() + "                |");
        cardDisplay.push_back("|               |");
        cardDisplay.push_back("|               |");
        cardDisplay.push_back("|               |");
        cardDisplay.push_back("|       " + getRankAsString() + "       |");
        cardDisplay.push_back("|               |");
        cardDisplay.push_back("|               |");
        cardDisplay.push_back("|               |");
        cardDisplay.push_back("|              " + getSuitAsString() + "|");
        cardDisplay.push_back("-----------------");
    }
    else {
        cardDisplay.push_back("-----------------");
        cardDisplay.push_back("|               |");
        cardDisplay.push_back("|               |");
        cardDisplay.push_back("|               |");
        cardDisplay.push_back("|               |");
        cardDisplay.push_back("|               |");
        cardDisplay.push_back("|               |");
        cardDisplay.push_back("|               |");
        cardDisplay.push_back("|               |");
        cardDisplay.push_back("|               |");
        cardDisplay.push_back("-----------------");
    }
    return cardDisplay;
}

bool Card::getFace()
{
    return isFaceUp;
}

void Card::setFace(bool isFaceUp)
{
    this->isFaceUp = isFaceUp;
}

void Card::infoCard() const{
    cout << getRankAsString() << getSuitAsString() << endl;
}

// Méthode pour afficher la carte
void Card::displayCard() const {
    if (this->isFaceUp) {
        cout << "---------------" << endl;
        cout << "|" << getSuitAsString() << "            |" << endl;
        cout << "|             |" << endl;
        cout << "|             |" << endl;
        cout << "|             |" << endl;
        cout << "|      " << getRankAsString() << "      |" << endl;
        cout << "|             |" << endl;
        cout << "|             |" << endl;
        cout << "|             |" << endl;
        cout << "|            " << getSuitAsString() << "|" << endl;
        cout << "---------------" << endl;
    }
    else {
        cout << "---------------" << endl;
        cout << "|             |" << endl;
        cout << "|             |" << endl;
        cout << "|             |" << endl;
        cout << "|             |" << endl;
        cout << "|             |" << endl;
        cout << "|             |" << endl;
        cout << "|             |" << endl;
        cout << "|             |" << endl;
        cout << "|             |" << endl;
        cout << "---------------" << endl;
    }
}

// Getters pour la valeur et la couleur
Rank Card::getRank() const { return rank; }
Suit Card::getSuit() const { return suit; }

bool Card::operator==(const Card& other) const {
    return (suit == other.suit) && (rank == other.rank);
}