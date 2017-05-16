/*
This is the console executable, that makes use of the BullCow class. 
This act as the view in a MVC pattern, and is responsible for all user interaction.
For game logic see the FBULLCOWGame class.
*/


#include "HeaderBullCowGame.h"


int main() {
	
	FBullCowGame BCGame;
	bool GameState = false; // instantiate a  new game

	do {
		BCGame.Init();
		PrintIntro(BCGame);
		PlayGame(BCGame);
		GameState = AskToPlayAgain();
	} while (GameState == true);

	return 0;
}

/*
TODO for unreal use
using FTest = std::string;
using STring = std::string;

*/