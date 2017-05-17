/* The game logic (no view code or direct user interaction)
The game is a simple guess the word game on Mastermind

*/

#pragma once

#include "Include.h"

struct FBullCowCount {
	int32 Bulls, Cows;
};

enum EGuessStatut {
	Ok, NotIsogram, NotLowerCase, WrongLength, None
};


// BullCowGame Class, allow to play the Bull Gow game
// Contain an hidden word isogram
// The player has several tries to guess the correct word
class FBullCowGame {

	int32 MyCurrenTry;
	int32 MyMaxTries;
	FBullCowCount BCCount;
	std::string MyHiddenWord;

public:
	FBullCowGame(); // constructor
	
	int32 GetCurrentTry() const;
	int32 GetWordLength();
	int32 GetMaxTries() const;
	void PrintIntro();
	std::string GetGuess();
	bool IsIsogram(std::string Word) const;
	enum EGuessStatut CheckGuessValidity(std::string Guess);
	FBullCowCount SubmitGuess(std::string Guess);
	bool IsGameWon() const;
	void PlayGame();
	bool AskToPlayAgain();
};




