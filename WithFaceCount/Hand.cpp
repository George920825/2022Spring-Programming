#include <iostream>
#include <vector>
#include <algorithm>
#include "Hand.h"
using namespace std;

Hand::Hand( DeckOfCards &deck )
{
for( int i = 0; i < 5; i++ )
{
    Card temp = deck.dealCard();
    hand.push_back( temp );
}
for( int i = 0 ; i < 13; i++ )
{
   faceCount.push_back( 0 );
}
	
for( int i = 0; i < 5; i++ )
	{
		for( int j = 0; j < 13; j++ )
	 {
	 	if( hand[ i ].getFace() == j )
	 	 faceCount[ j ] = faceCount[ j ] + 1;
	 }
	}
}

void Hand::print() const
{
for( int i = 0; i < hand.size(); i++ )
{
    cout << hand[ i ].toString() << endl;
}
cout << endl;
}

bool Hand::pair() const
{
int p = 0;

for( int i = 0; i < 13; i++ )
	if( faceCount[ i ] == 2 )
    	p++;
	
if ( p == 1 )
    return true;
else
    return false;
}

bool Hand::twoPair() const
{
int tp = 0;

for( int i = 0; i < 13; i++ )
	if( faceCount[ i ] == 2 )
    	tp++;
    	
if ( tp == 2 )
    return true;
else
    return false;
}

bool Hand::threeOfAKind() const
{
int toak = 0;

for( int i = 0; i < 13; i++ )
	if( faceCount[ i ] == 2 )
    	toak++;
    	
if ( toak == 3 )
	return true;
else
	return false;
}

bool Hand::fourOfAKind() const
{
int foak = 0;

for( int i = 0; i < 13; i++ )
	if( faceCount[ i ] == 2 )
    	foak++;
    	
if ( foak == 3 )
	return true;
else
	return false;
}

bool Hand::flush() const
{
for ( int i = 0; i < 4; i++ )
{
    int f = 0;
    for ( int j = 0; j < hand.size(); j++ )
    {
        if ( hand[ j ].getSuit() == i )
            f++;
    }
    if ( f == 5 )
        return true;
}
return false;
}

bool Hand::straight() const
{
for ( int face = 0; face < 9; face++ )
{
	for ( int i = 0; i < hand.size(); i++ )
		if ( hand[ i ].getFace() == face )
			for ( int j = 0; j < hand.size(); j++ )
				if ( hand[ j ].getFace() == face + 1 )
					for ( int k = 0; k < hand.size(); k++ )
						if ( hand[ k ].getFace() == face + 2 )
							for ( int l = 0; l < hand.size(); l++ )
								if ( hand[ l ].getFace() == face + 3 )
									for ( int m = 0; m < hand.size(); m++ )
										if ( hand[ m ].getFace() == face + 4 )
											return true;
}
for ( int i = 0; i < hand.size(); i++ )
	if ( hand[ i ].getFace() == 9 )
		for ( int j = 0; j < hand.size(); j++ )
			if ( hand[ j ].getFace() == 9 + 1 )
				for ( int k = 0; k < hand.size(); k++ )
					if ( hand[ k ].getFace() == 9 + 2 )
						for ( int l = 0; l < hand.size(); l++ )
							if ( hand[ l ].getFace() == 9 + 3 )
								for ( int m = 0; m < hand.size(); m++ )
									if ( hand[ m ].getFace() == 0 )
										return true;
return false;
}


