/*
* script: Polynomial.h
* action: Contains the polynomial class
* author: D.M
* date: 01APR25
*/
#include <iostream> 
#include <string>


#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

class Polynomial {


public:

	// Default constructor starting with 0
	explicit Polynomial(int degree = 0);

	// Copy constructor
	Polynomial(const Polynomial& other);

	// Destructor
	~Polynomial();

	// Overloading the addition operator
	Polynomial operator+(const Polynomial& other) const;

	// Overloading the subraction operator
	Polynomial operator-(const Polynomial& other) const;

	// Overloading the assignment operator to assign one polynomial to another
	Polynomial& operator=(const Polynomial& other);

	// Overloading the multiplication operator
	Polynomial operator*(const Polynomial& other) const;

	// Overloading the addition assignment operator (+=)
	Polynomial& operator+=(const Polynomial& other);

	// Overloading the subtraction assignment operator (-=)
	Polynomial& operator-=(const Polynomial& other);

	// Overloading the multiplication assignment operator (*=)
	Polynomial& operator*=(const Polynomial& other);

	// set the coefficient for a specific degree
	void setCoefficient(int degree, double value);

	// Get the coefficient for a specific degree
	double getCoefficient(int degree) const;

	// Displays the polynomial
	void display() const;

	
private:

	// Degree of the polynomial
	int degree;

	// Coefficients of the polynomial
	double* coefficients;
	
};

#endif