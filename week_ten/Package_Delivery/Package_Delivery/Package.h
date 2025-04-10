/*
* script: Package.h
* action: Contains the base package class
* author: D.M
* date: 10APR25
*/

#include <iostream>
#include <string>

#ifndef PACKAGE_H
#define PACKAGE_H

class Package {

public:

	// Default constructor for package class
	explicit Package();

private:

	// declare private member variables

	// variables for sender information
	std::string senderName;
	std::string senderaddress;
	std::string senderCity;
	std::string senderState;
	std::string senderZip;

	// variables for recipient information
	std::string recipientName;
	std::string recipientaddress;
	std::string recipientCity;
	std::string recipientState;
	std::string recipientZip;

	// variables for package information
	double weightInOunces;
	double costPerOunce;

};

#endif