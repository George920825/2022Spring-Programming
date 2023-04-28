#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H

#include <string>
#include "Package.h"
using namespace std;

class OvernightPackage : public Package
{
public:
	OvernightPackage(
	const string &, const string &, const string &, 
	const string &, int, const string &, const string &, const string &, 
    const string &, int, double, double, double );
	
	void setadditionalFeePerOunce( double );
	
	virtual double calculateCost() const;
private:
	double additionalFeePerOunce;
};

#endif
