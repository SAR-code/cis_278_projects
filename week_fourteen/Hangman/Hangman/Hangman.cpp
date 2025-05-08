/*
* script: Hangman.cpp
* action: This program starts the game of hangman
*         This program utilizes OOP concepts with the Game 
*         and WordReader classes
* author: D.M
* date: 07MAY25
*/

#include <iostream>
#include <algorithm>
#include <random>
#include "Game.h"
#include "WordReader.h"

#define WORD_FILE "words.txt"

using namespace std;

// Function prototype
void startGame();



int main()
{
    // Invoke function to start game
	startGame();

    return 0;
}


void startGame() {

    // Creates an object of the WordReader class
    WordReader reader(WORD_FILE);

    // Reads the words from the file
    if (!reader.readWords()) {
		cerr << "No words found in the file." << endl;
        exit(1);
    }

    // Gets the words from the file
    const vector<string>& words = reader.getWords();

    // Randomly selects a word from the vector
    random_device rd;
	mt19937 generator(rd());
	uniform_int_distribution<int> distribution(0, words.size() - 1);

	// Selects a random word
    string response;

	// Do while loop to start the game and to check if the user wants to play again
    do {
		string selectedWord = words[distribution(generator)];
		Game game(selectedWord);
		game.playGame();

        cout << "Do you want to play again? (y/n): ";
        cin >> response;

		// Converts the response to lowercase
		transform(response.begin(), response.end(), response.begin(), ::tolower);
    } while (response == "y");

	cout << "Thanks for playing!" << endl;
    
}