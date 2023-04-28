#include <vector>
#include <stdlib.h>
#include <time.h>
#include "DeckOfCards.h"
using namespace std;

DeckOfCards::DeckOfCards()
{
currentCard = 0;

for ( int i = 0; i < 4; i++ )
{
    for ( int j = 0; j < 13; j++ )
    {
        Card temp( j, i );
        deck.push_back( temp );
    }
}
}

void DeckOfCards::shuffle()
{
srand ( time(0) );

for ( int i = 0; i < deck.size(); i++ )
{
    int j = rand() % deck.size();
    Card temp = deck [ i ];
    deck [ i ] = deck [ j ];
    deck [ j ] = temp;
}
}

Card DeckOfCards::dealCard()
{
currentCard++;
return deck.at( currentCard - 1 );
}

bool DeckOfCards::moreCards() const
{
if ( currentCard < deck.size() )
	return true;
else
    return false;
}
