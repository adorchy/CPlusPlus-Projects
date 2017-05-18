/*
This is the console executable, that makes use of the BullCow class. 
This act as the view in a MVC pattern, and is responsible for all user interaction.
For game logic see the FBULLCOWGame class.
*/


#include "BullCowGame.h"


int main() {
	
	FBullCowGame myGame;
	bool GameState = false; // instantiate a  new game

	do {
		myGame.PrintIntro();
		myGame.PlayGame();
		GameState = myGame.AskToPlayAgain();
	} while (GameState == true);

	return 0;
}

