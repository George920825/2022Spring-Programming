#include <iostream>
#include "Package.h"
using namespace std;

Package::Package(
	const string &sname, const string &saddress, const string &scity, const string &sstate, int szip,
	const string &rname, const string &raddress, const string &rcity, const string &rstate, int rzip,
	double w, double cpo )
	: senderName( sname ), senderAddress( saddress ), senderCity( scity ), senderState( sstate ), senderZIP( szip ),
	  recipientName( rname ), recipientAddress( raddress ), recipientCity( rcity ), recipientState( rstate ), recipientZIP( rzip )
{
	setWeight( w );
	setCostPerOunce( cpo );
}

void Package::setSenderName( const string &sname )
{
	senderName = sname;
}

string Package::getSenderName() const
{
	return senderName;
}

void Package::setSenderAddress( const string &saddress )
{
	senderAddress = saddress;
}

string Package::getSenderAddress() const
{
	return senderAddress;
}

void Package::setSenderCity( const string &scity )
{
	senderCity = scity;
}

string Package::getSenderCity() const
{
	return senderCity;
}

void Package::setSenderState( const string &sstate )
{
	senderState = sstate;
}

string Package::getSenderState() const
{
	return senderState;
}

void Package::setSenderZIP( int szip )
{
	senderZIP = szip;
}

int Package::getSenderZIP() const
{
	return senderZIP;
}

void Package::setRecipientName( const string &rname )
{
	recipientName = rname;
}

string Package::getRecipientName() const
{
	return recipientName;
}

void Package::setRecipientAddress( const string &raddress )
{
	recipientAddress = raddress;
}

string Package::getRecipientAddress() const
{
	return recipientAddress;
}

void Package::setRecipientCity( const string &rcity )
{
	recipientCity = rcity;
}

string Package::getRecipientCity() const
{
	return recipientCity;
}

void Package::setRecipientState( const string &rstate )
{
	recipientState = rstate;
}

string Package::getRecipientState() const
{
	return recipientState;
}

void Package::setRecipientZIP( int rzip )
{
	recipientZIP = rzip;
}

int Package::getRecipientZIP() const
{
	return recipientZIP;
}

void Package::setWeight( double w )
{
	weight = ( w < 0.0 ) ? 0.0 : w;
}

double Package::getWeight() const
{
	return weight;
}

void Package::setCostPerOunce( double cpo )
{
	costPerOunce =  ( cpo < 0.0 ) ? 0.0 : cpo;
}

double Package::getCostPerOunce() const
{
	return costPerOunce;
}

double Package::calculateCost() const
{
	return weight * costPerOunce;
}
