#include <iostream>
#include "OvernightPackage.h"
using namespace std;

OvernightPackage::OvernightPackage(
	const string &sname, const string &saddress, const string &scity, const string &sstate, int szip,
	const string &rname, const string &raddress, const string &rcity, const string &rstate, int rzip,
	double w, double cpo, double afpo )
	: Package( sname, saddress, scity, sstate, szip,
	rname, raddress, rcity, rstate, rzip,
	w, cpo )
{
	setadditionalFeePerOunce( afpo );
}

void OvernightPackage::setadditionalFeePerOunce( double afpo )
{
	additionalFeePerOunce = ( afpo < 0.0 ) ? 0.0 : afpo;
}

double OvernightPackage::calculateCost() const
{
	return Package::getWeight() * (Package::getCostPerOunce() + additionalFeePerOunce) ;
}
