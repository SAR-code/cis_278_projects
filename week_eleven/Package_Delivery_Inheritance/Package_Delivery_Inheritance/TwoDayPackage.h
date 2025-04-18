/*
* script: TwoDayPackage.h
* action: Contains the two day package class
*	  inheriting from the base package class
* author: D.M
* date: 18APR25
*/

#include <iostream>
#include <string>
#include "Package.h"

#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

class TwoDayPackage : public Package
{
public:

	// Default constructor for TwoDayPackage class
	explicit TwoDayPackage(const std::string& sName,
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
		double flatFee = 0.0
	);


	// Copy constructor
	TwoDayPackage(const TwoDayPackage& other);


	// Destructor
	~TwoDayPackage();


	// Setters and getters for the flat fee
	void setFlatFee(double);
	double getFlatFee() const;

	// Override calculateCost method
	virtual double calculateCost() const override;

	// string representation of the TwoDayPackage
	std::string toString() const;


private:

	// Private variable for flat fee
	double flatFee;
};

#endif