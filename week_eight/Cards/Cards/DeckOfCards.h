/*
* script: DeckOfCards.h
* action: Contains the methods and variables
		  for the deck of cards.
* author: D.M
* date: 29MAR25
*/


#include <array>
#include "Card.h"


#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H



class DeckOfCards {
public:
	// constructor to initialize deck of cards
	DeckOfCards();

	// Function method to shuffle the deck of cards
	void shuffleCards();

	// Function method to deal a card from the deck
	Card dealCard();

	// Function method to check for remaining cards in the deck
	bool remainingCards() const;

private:
	std::array<Card, 52> deck;
	size_t currentCard;
    
};

#endif 