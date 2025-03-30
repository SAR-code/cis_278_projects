/*
* script: Card.cpp
* action: Contains the card class
* author: D.M
* date: 29MAR25
*/

#include <iostream>
#include "Card.h"

using namespace std;



// Default constructor for the card class
Card::Card()
{
}

// Constructor to initialize the card with a face and suit
Card::Card(Face face, Suit suit) : face(face), suit(suit) {};

// Function to convert the card's face to a string

string Card::toString() const {
	static const string faces[] = { "Ace", "Duece", "Three", "Four", "Five", "Six",
		"Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"
	};
	static const string suits[] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	return faces[face] + " of " + suits[suit];
}