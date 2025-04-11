/*
* script: Package_Delivery.cpp
* action: This is the main entry point for the Package_Delivery application.
*         This program demonstrates inheritance through a package delivery system.
* author: D.M
* date: 10APR25
*/

#include <iostream>
#include "Package.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"
#include <iomanip>

using namespace std;

//function prototypes
void packageBase();
void twoDayPackageTest();
void overnightPackageTest();

int main()
{
	// Invokes the package base class
	packageBase();

	// Invokes the two day package test
	twoDayPackageTest();

	// Invokes the overnight package test
	overnightPackageTest();
	
	return 0;
}


// Function for package base class
void packageBase()
{
	// test package
	Package package1("John Doe",
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
		2.5);

	// Display package details
	cout << "Package Details:" << endl;
	cout << package1.toString() << endl;
	cout << "Total Cost: $"
		<< fixed << setprecision(2)
		<< package1.calculateCost() << endl;
	
}

// Function for two day package test
void twoDayPackageTest()
{
	// test two day package
	TwoDayPackage twoDayPackage1("James Smith",
		"123 Elm St",
		"Tucson",
		"AZ",
		"85735",
		"John Wick",
		"456 Oak St",
		"Lemoore",
		"CA",
		"93245",
		10.0,
		2.5,
		5.0);

	// Display two day package details
	cout << "\nTwo Day Package Details:" << endl;
	cout << twoDayPackage1.toString() << endl;
	cout << "Total Cost: $"
		<< fixed << setprecision(2)
		<< twoDayPackage1.calculateCost() << endl;
}

// Function to test overnight package
void overnightPackageTest()
{
	// test overnight package
	OvernightPackage overnightPackage1("Tony Stark",
		"123 Elm St",
		"Tucson",
		"AZ",
		"85735",
		"Peter Parker",
		"456 Oak St",
		"Lemoore",
		"CA",
		"93245",
		10.0,
		2.5,
		15.0);

	// Display overnight package details
	cout << "\nOvernight Package Details:" << endl;
	cout << overnightPackage1.toString() << endl;
	cout << "Total Cost: $"
		<< fixed << setprecision(2)
		<< overnightPackage1.calculateCost() << endl;
}


