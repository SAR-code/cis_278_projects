/*
* script: Package_Delivery_Inheritance.cpp
* action: This is the main entry point for the Package_Delivery application.
*         This program demonstrates inheritance through a package delivery system.
*		  Part two of this assignment introduces polymorphism.
* author: D.M
* date: 18APR25
*/

#include <iostream>
#include "Package.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"
#include <iomanip>
#include <vector>

using namespace std;

//function prototypes
void packageBaseV2();

int main()
{
	// Displays upgraded package delivery system

	cout << "\nPackage Delivery System with Polymorphism and Vectors\n" << endl;
	// Invokes package base V2 with polymorphism and vectors
	packageBaseV2();

	return 0;
}



// Function to test V2 of package base class with polymorphism and vectors
void packageBaseV2()
{
	// Create a vector of Package pointers
	vector<Package*> packages;

	// Declare variables to assist with cost calculation
	double totalCost = 0.0;

	
	// Add different package types to the vector
	packages.push_back(new Package("John Doe",
		"123 Elm St",
		"Tucson",
		"AZ",
		"85735",
		"Jane Smith",
		"456 Oak St",
		"Lemoore",
		"CA",
		"93245",
		10.0,
		2.5));

	// Add a two day package
	packages.push_back(new TwoDayPackage("James Smith",
		"456 West St",
		"Phoenix",
		"AZ",
		"85001",
		"John Wick",
		"911 Porsche St",
		"Hanford",
		"CA",
		"93245",
		10.0,
		2.5,
		5.0));

	// Add an overnight package
	packages.push_back(new OvernightPackage("Tony Stark",
		"1289 Avengers St",
		"Houston",
		"TX",
		"77001",
		"Peter Parker",
		"2027 Web St",
		"Queens",
		"NY",
		"11106",
		10.0,
		2.5,
		15.0));

	// Display package details and total cost for each package
	for (const auto& package : packages)
	{
		cout << "\nPackage Details:" << endl;
		cout << "\nSender: " << package->getSenderInfo() << endl;
		cout << "Recipient: " << package->getRecipientInfo() << endl;
		cout << "Weight(oz): " << package->getWeightInOunces() << endl;
		cout << "Cost per ounce: $"
			<< fixed << setprecision(2)
			<< package->getCostPerOunce() << endl;

		// declare variable to calculation method
		double cost = package->calculateCost();

		// Check for package type and display additional information
		if (dynamic_cast<TwoDayPackage*>(package))
		{
			// Cast to TwoDayPackage to access specific methods
			cout << "Package Type: Two Day Package" << endl;
			cout << "Flat Fee: $"
				<< fixed << setprecision(2)
				<< static_cast<TwoDayPackage*>(package)->getFlatFee() << endl;

		}
		else if (dynamic_cast<OvernightPackage*>(package))
		{
			// Cast to OvernightPackage to access specific methods
			cout << "Package Type: Overnight Package" << endl;
			cout << "Overnight Fee: $"
				<< fixed << setprecision(2)
				<< static_cast<OvernightPackage*>(package)->getOvernightFee() << endl;
		}
		else
		{
			// Default package type
			cout << "Package Type: Standard Package" << endl;
		}
		cout << fixed << setprecision(2);
		cout << "Shipping Cost: $" << cost << endl;
		cout << "***********************************\n";

		// Add to total cost
		totalCost += cost;
	}

	// Display total cost
	cout << "\nTotal Cost of All Packages: $"
		<< fixed << setprecision(2)
		<< totalCost << endl;

	// Clean up memory
	for (const auto& package : packages)
	{
		delete package;
	}
} 
