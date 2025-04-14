/*
* script: OvernightPackage.h
* action: Contains the two day package class
*	  inheriting from the base package class
* author: D.M
* date: 10APR25
*/

#include <iostream>
#include <string>
#include "Package.h"

#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H

class OvernightPackage : public Package
{
public:

	// Default constructor for OvernightPackage class
	explicit OvernightPackage(const std::string& sName,
		const std::string& sAddress,
		const std::string& sCity,
		const std::string& sState,
		const std::string& sZip,
		const std::string& rName,
		const std::string& rAddress,
		const std::string& rCity,
		const std::string& rState,
		const std::string& rZip,
		double wOunces = 0.0,
		double cPerOunce = 0.0,
		double overnightFee = 0.0
	);


	// Copy constructor
	OvernightPackage(const OvernightPackage& other);


	// Destructor
	~OvernightPackage();


	// Setters and getters for the overnight fee
	void setOvernightFee(double);
	double getOvernightFee() const;

	// Override calculateCost method
	double calculateCost() const;

	// string representation of the OverinightPackage class
	std::string toString() const;

private:

	// Private variable for overnight fee
	double overnightFee;
};

#endif
