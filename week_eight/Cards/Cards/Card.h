/*
* script: Card.h
* action: Contains the card class
* author: D.M
* date: 29MAR25
*/

#include <string>

#ifndef CARD_H
#define CARD_H

class Card {
public:

	// Contains the rank and suit of the cards
	enum Face {
		Ace, Duece, Three, Four, Five, Six, Seven
		, Eight, Nine, Ten, Jack, Queen, King
	};

	enum Suit { Hearts, Diamonds, Clubs, Spades };

	// Default constructor for the card class
	Card();

	// Constructor to initialize the card with a face and suit
	Card(Face face, Suit suit);

	// Function to convert the contents of the card to a string
	std::string toString() const;
	

private:
	// Member variables to store the face and suit of the card
	Face face;
	Suit suit;

};

#endif
