/*
* script: DeckOfCards.cpp
* action: Contains the constructor and methods
*		  for the deck of cards.
* author: D.M
* date: 29MAR25
*/


#include <iostream>
#include <algorithm>
#include <random>
#include "DeckOfCards.h"
#include "Card.h"


using namespace std;

// Constructor to initialize the deck of cards

DeckOfCards::DeckOfCards() : currentCard(0) {

	int index = 0;

	// Initialize index to 0 to keep track of the current position in the deck
	// Loops through the faces and suits of the cards to create the playing deck
	for (int suit = 0; suit < 4; suit++) {
		for (int face = 0; face < 13; face++) {

			// Create a new card with the current face and suit
			deck[index++] = Card(static_cast<Card::Face>(face), static_cast<Card::Suit>(suit));
			
		};
	};
};

// Function to shuffle the deck
void DeckOfCards::shuffleCards() {
	static random_device randomCard;
	static mt19937 generator(randomCard());

	shuffle(deck.begin(), deck.end(), generator);
	currentCard = 0;

};

// Function method to deal a card from the deck
Card DeckOfCards::dealCard() {

	if (remainingCards()) {
		// Return the card at the current position in the deck
		return deck[currentCard++];
	}
	else {
		// If there are no more cards left, return a default card or handle it as needed
		throw out_of_range("No more cards left in the deck.");
	};
}

// Function method to check for remaining cards in the deck
bool DeckOfCards::remainingCards() const {
	// Check if the current card position is less than the total number of cards in the deck
	return currentCard < 52;
};