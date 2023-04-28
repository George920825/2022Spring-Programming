#include <string>
#include "Card.h"
using namespace std;

const string Card::faceNames[ Card::totalFaces ] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", 
											    "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
const string Card::suitNames[ Card::totalSuits ] = { "Hearts", "Diamonds", "Clubs", "Spades" };

Card::Card( int cardFace, int cardSuit )
{
    face = cardFace;
    suit = cardSuit;
}

string Card::toString() const 
{
    string FACE = faceNames[ face ];
    string SUIT = suitNames[ suit ];
    string prep = " of ";
    string ret = FACE + prep + SUIT;
    return ret;
}
