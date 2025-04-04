/*
* script: PolynomialProject.cpp
* action: This is the main entry point for the PolynomialProject application.
*         This project demonstrates the various methods of operator overloading
* author: D.M
* date: 01APR25
*/

#include <iostream>
#include "Polynomial.h" // Include the Polynomial class header

using namespace std;


int main()
{
	// Declaring the polynomials
	
	Polynomial p1(2);

	// 3x^2 + 5x^1 - 2
	p1.setCoefficient(2, 3); // 3x^2
	p1.setCoefficient(1, 5); // 5x^1
	p1.setCoefficient(0, -2); // -2

	Polynomial p2(2);

	// 4x^2 - 5x^1 + 6
	p2.setCoefficient(2, 4); // 4x^2
	p2.setCoefficient(1, -5); // -5x^1
	p2.setCoefficient(0, 6); // 6


	// Output Title
	cout << "\n*** ESTABLISHING POLYNOMIALS ***" << endl;
	
	// Displays p1
	cout << "Polynomial p1: ";
	p1.display();

	// Displays p2
	cout << "Polynomial p2: ";
	p2.display();

	// Addition Title
	cout << "\n*** ADDING POLYNOMIALS ***" << endl;

	// Demonstrate addition of two polynomials
	Polynomial sum = p1 + p2;
	cout << "Sum of p1 and p2: ";
	sum.display(); 

	// Subtraction Title
	cout << "\n*** SUBTRACTING POLYNOMIALS ***" << endl;

	// Demonstrate subtraction of two polynomials
	Polynomial difference = p1 - p2;
	cout << "Difference of p1 and p2: ";
	difference.display();

	// Multiply Title
	cout << "\n*** MULTIPLYING POLYNOMIALS ***" << endl;

	// Demonstrate multiplication of two polynomials
	Polynomial product = p1 * p2;
	cout << "Product of p1 and p2: ";
	product.display();


	// += Assignment Title
	cout << "\n*** += ASSIGNMENT OPERATOR ***" << endl;

	// Demonstrate += assignment operator
	p1 += p2; 
	cout << "After p1 += p2: ";
	// Displays the updated p1 after the addition
	p1.display(); 


	// -= Assignment Title
	cout << "\n*** -= ASSIGNMENT OPERATOR ***" << endl;

	// Demonstrate -= assignment operator
	p1 -= p2;
	cout << "After p1 -= p2: ";
	// Displays the updated p1 after the subtraction
	p1.display();


	// *= Assignment Title
	cout << "\n*** *= ASSIGNMENT OPERATOR ***" << endl;

	// Demonstrate *= assignment operator
	p1 *= p2;
	cout << "After p1 *= p2: ";
	// Displays the updated p1 after multiplication
	p1.display();
}


