/*
* script: Polynomial.cpp
* action: Contains the polynomial class and methods
* author: D.M
* date: 01APR25
*/

#include <iostream>
#include <cstring>
#include "Polynomial.h"

using namespace std;

// Default constructor for polynomial class
Polynomial::Polynomial(int degree) {
	if (degree < 0) {
		degree = 0; // Ensure degree is non-negative
	}

	// Allocate memory for coefficients
	this->degree = degree;
	coefficients = new double[degree + 1];
	for (int i = 0; i <= degree; ++i) {
		coefficients[i] = 0.0; // Initialize coefficients to zero
	}
}

// Copy constructor
Polynomial::Polynomial(const Polynomial& other) {
	// Copy the degree
	this->degree = other.degree;
	// Allocate memory for coefficients
	coefficients = new double[this->degree + 1];
	// Copy the coefficients from the other polynomial
	for (int i = 0; i <= this->degree; ++i) {
		this->coefficients[i] = other.coefficients[i];
	}
}

// Destructor to free allocated memory
Polynomial::~Polynomial() {
	if (coefficients != nullptr) {
		delete[] coefficients; 

		// Set to nullptr to avoid dangling pointer
		coefficients = nullptr; 
	}
}

// Polynomial::operator+ overload implementation
Polynomial Polynomial::operator+(const Polynomial& other) const
{
	// Determine the maximum degree of the two polynomials
	int maxDegree = std::max(degree, other.degree);
	Polynomial result(maxDegree);

	// Add coefficients from both polynomials
	for (int i = 0; i <= maxDegree; ++i) {
		result.coefficients[i] = this->getCoefficient(i) + other.getCoefficient(i);
	}

	return result;
}

// Polynomial::operator- overload implementation
Polynomial Polynomial::operator-(const Polynomial& other) const
{
	// Determine the maximum degree of the two polynomials
	int maxDegree = std::max(degree, other.degree);
	Polynomial result(maxDegree);

	// Subtract coefficients from both polynomials
	for (int i = 0; i <= maxDegree; ++i) {
		result.coefficients[i] = this->getCoefficient(i) - other.getCoefficient(i);
	}

	return result;
}

// Assignment operator overload implementation
Polynomial& Polynomial::operator=(const Polynomial& other)
{
	// Checks for the self-assignment case
	if (this != &other) {
		delete[] coefficients;
		degree = other.degree;
		coefficients = new double[degree + 1];
		std::memcpy(coefficients, other.coefficients, (degree + 1) * sizeof(double));
	}
	return *this;
}

// Polynomial::operator* overload implementation
Polynomial Polynomial::operator*(const Polynomial& other) const
{
	// Multiplication of two polynomials results in a polynomial of degree
	int newDegree = this->degree + other.degree;
	Polynomial result(newDegree);

	// Perform polynomial multiplication
	for (int i = 0; i <= this->degree; ++i) {
		for (int j = 0; j <= other.degree; ++j) {
			result.coefficients[i + j] += this->coefficients[i] * other.coefficients[j];
		}
	}

	return result;
}

// Overloading the multiplication assignment operator (*=)
Polynomial& Polynomial::operator+=(const Polynomial& other)
{
	// Use the addition operator to perform the addition and assign it back to *this

	*this = *this + other;
	return *this;
}

// Overloading the subtraction assignment operator (-=)
Polynomial& Polynomial::operator-=(const Polynomial& other)
{
	// Use the subtraction operator to perform the subtraction and assign it back to *this

	*this = *this - other;
	return *this;
}

// Overloading the multiplication assignment operator (*=)
Polynomial& Polynomial::operator*=(const Polynomial& other)
{
	// Use the multiplication operator to perform the multiplication and assign it back to *this
	*this = *this * other;
	return *this;
}

// Set the coefficient for a specific degree
void Polynomial::setCoefficient(int degree, double value)
{
	// Check if the degree is non-negative
	if (degree < 0) {
		throw std::invalid_argument("Degree must be non-negative.");
	}

	// Resize the coefficients array if necessary
	if (degree > this->degree) {

		// Allocate coefficients array with the new degree
		double* newCoefficients = new double[degree + 1];
		for (int i = 0; i <= this->degree; ++i) {
			newCoefficients[i] = coefficients[i];
		}
		delete[] coefficients;
		coefficients = newCoefficients;
		this->degree = degree;
	}
	coefficients[degree] = value;
}

// Get the coefficient for a specific degree
double Polynomial::getCoefficient(int degree) const
{
	// Check if the degree is within the valid range

	if (degree < 0 || degree > this->degree) {
		throw std::out_of_range("Degree is out of range.");
	}
	return coefficients[degree];
}

// Display the polynomial
void Polynomial::display() const {

	// Handle the case of an empty polynomial (degree < 0)
	bool firstTerm = true;

	// If the polynomial has no coefficients, return 0
	for (int i = degree; i >= 0; --i) {
		if (coefficients[i] != 0) {
			if (!firstTerm) {
				std::cout << (coefficients[i] > 0 ? " + " : " - ");
			}
			else if (coefficients[i] < 0) {
				std::cout << "-";
			}

			// Print the absolute value of the coefficient
			std::cout << std::abs(coefficients[i]);
			if (i > 0) std::cout << "x^" << i;

			firstTerm = false;
		}
	}
	// If all coefficients are 0
	if (firstTerm) std::cout << "0"; 
	std::cout << std::endl;
}
