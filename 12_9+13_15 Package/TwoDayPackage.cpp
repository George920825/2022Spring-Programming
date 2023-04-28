#include <iostream>
#include "TwoDayPackage.h"
using namespace std;

TwoDayPackage::TwoDayPackage(
	const string &sname, const string &saddress, const string &scity, const string &sstate, int szip,
	const string &rname, const string &raddress, const string &rcity, const string &rstate, int rzip,
	double w, double cpo, double ff )
	: Package( sname, saddress, scity, sstate, szip,
	rname, raddress, rcity, rstate, rzip,
	w, cpo)
{
	setFlatFee( ff );
}

void TwoDayPackage::setFlatFee( double ff )
{
	flatFee = ( ff < 0.0 ) ? 0.0 : ff;
}

double TwoDayPackage::calculateCost() const
{
	return flatFee + Package::calculateCost();
}
