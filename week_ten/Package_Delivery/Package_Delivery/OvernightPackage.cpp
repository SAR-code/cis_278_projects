
/*
* script: OvernightPackage.cpp
* action: Contains the two day package class
*		  inheriting from the base package class
* author: D.M
* date: 10APR25
*/

#include <iostream>
#include <cstring>
#include <iomanip>
#include <stdexcept>
#include <sstream>
#include "OvernightPackage.h"

using namespace std;


// Default constructor for OvernightPackage class
OvernightPackage::OvernightPackage(const string& sName, 
				const string& sAddress, 
				const string& sCity, 
				const string& sState, 
				const string& sZip, 
				const string& rName, 
				const string& rAddress, 
				const string& rCity, 
				const string& rState, 
				const string& rZip, 
				double wOunces, 
		        double cPerOunce, 
	            double overnightFee)
				: Package(sName,
						sAddress,
						sCity,
						sState,
						sZip,
						rName,
						rAddress,
						rCity,
						rState,
						rZip,
						wOunces,
					    cPerOunce),
						overnightFee(overnightFee)
{
	setOvernightFee(overnightFee);
}


// Copy constructor
OvernightPackage::OvernightPackage(const OvernightPackage& other) : Package(other)
{
	// Initialize private variables from the other object
	this->overnightFee = other.overnightFee;
}


// Destructor
OvernightPackage::~OvernightPackage()
{
	// Destructor implementation
	// Not sure if this is needed for memory but included for completeness
}


// overnight fee getters and setters
void OvernightPackage::setOvernightFee(double)
{
	// Ensure onverinight fee is greater than 0
	if (overnightFee < 0)
	{
		throw invalid_argument("Overnight fee must be greater than 0");
	}
}


double OvernightPackage::getOvernightFee() const
{
	return overnightFee;
}


// Override calculateCost method to include overnight fee
double OvernightPackage::calculateCost() const
{
	return (getWeightInOunces() * getCostPerOunce()) + overnightFee;
	
}


// string representation of the OvernightPackage class
std::string OvernightPackage::toString() const
{
	// String representation of the OvernightPackage

	ostringstream oss;
	oss << "Overnight Package: \n"
		<< Package::toString()
		<< "\nOvernight Fee: $"
		<< fixed << setprecision(2)
		<< overnightFee;

	return oss.str();
}
