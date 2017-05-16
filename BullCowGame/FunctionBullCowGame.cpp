#include "HeaderBullCowGame.h"
#define TMap std::map

const std::string HIDDEN_WORD = "planet";

using namespace std;


FBullCowGame::FBullCowGame() {
	Init();
}

// initilisation
void FBullCowGame::Init() {
	MyCurrenTry = 1;
	MyHiddenWord = HIDDEN_WORD;
	BCCount.Bulls = 0;
	BCCount.Cows = 0;

}

// Return the number MyCurrenTry
int32 FBullCowGame::GetCurrentTry() const {
	return MyCurrenTry;
}

// Return the length of the Hidden word
int32 FBullCowGame::GetWordLength() {
	return MyHiddenWord.length();
}

// Return the number MyMaxTries
int32 FBullCowGame::GetMaxTries() const {
	TMap < int32, int32 > WordLengthToMaxTries{ {3,4}, {4,7}, {5,10}, {6,16}, {7,20}, {8,25}, {9,32} };
	return WordLengthToMaxTries[MyHiddenWord.length()];
}

//get a guess from the player
std::string FBullCowGame::GetGuess() {
	string Guess = "";
	cout << "Try " << GetCurrentTry() << ": Enter your guess: ";
	getline(cin, Guess);

	return Guess;
}

// optimized function to check is a word is an Isogram
bool FBullCowGame::IsIsogram(std::string Word) const {

	TMap < char, int> CharList;
	for (char letter : Word) // for each letters of word (the input)

		if (CharList[letter] == 1) { //if the letter is already in the list
			return false;
		}
		else {
			CharList[letter] = 1;
		}
	return true;
}



//guess validation, increment MycurrentTry if guess valid
EGuessStatut FBullCowGame::CheckGuessValidity(std::string Guess) {
	if (Guess.length() != GetWordLength()) { //length check
		cout << "Guess had incorrect length, retry with a ";
		cout << GetWordLength() << " letters long word \n\n";
		return WrongLength;
	}

	for (int k = 0; k < GetWordLength(); k++) {
		if (isupper(Guess[k]) != 0) { //case check
			cout << "Guess had upper case, retry\n\n";
			return NotLowerCase;
		}
	}

	if (IsIsogram(Guess) == false) {
		cout << "Guess is not isogram, retry with a word without repeating letter\n\n";
		return NotIsogram;
	}

	return Ok;
}

// receives a VALID guess, increments Bulls and Cows
FBullCowCount FBullCowGame::SubmitGuess(std::string Guess) {

	int32 WordLength = MyHiddenWord.length();
	BCCount.Bulls = 0;
	BCCount.Cows = 0;

	for (int32 i = 0; i < WordLength; i++) { // go through all letters in the guess
		for (int32 j = 0; j < WordLength; j++) { // go through all letters in the hidden word
			if (Guess[i] == MyHiddenWord[j]) { // if they match then
				if (i == j) {	// if they're in the same place
					BCCount.Bulls++; // incriment bulls
				}
				else {
					BCCount.Cows++; // incriment cows
				}
			}
		}
	}
	cout << "Bulls: " << BCCount.Bulls;
	cout << " Cows: " << BCCount.Cows;
	cout << " Try left: " << GetMaxTries()-GetCurrentTry() << endl;
	cout << endl;
	MyCurrenTry++;
	return BCCount;
}

bool FBullCowGame::IsGameWon() const {
	if (BCCount.Bulls == 6) {
		return true;
	}
	return false;
}


// intoduce the game
void PrintIntro(FBullCowGame BCGame) {
	cout << "\n\n Welcome to Bulls and Cows, a fun word game." << endl;
	cout << endl;
	cout << "          }   {         ___ " << endl;
	cout << "          (o o)        (o o) " << endl;
	cout << "   /-------\\ /          \\ /-------\\ " << endl;
	cout << "  / | BULL |O            O| COW  | \\ " << endl;
	cout << " *  |-,--- |              |-(--)-|  * " << endl;
	cout << "    ^      ^              ^  ''  ^ " << endl;
	cout << "Can you guess the " << BCGame.GetWordLength();
	cout << " letters isogram I'm thinking of?\n";
	cout << BCGame.GetMaxTries() << " tries availables\n\n";
}


// loop repeating SubmitGuess until the game is won or n times where n is defined by GetMaxTries()
void PlayGame(FBullCowGame BCGame) {
	string Guess = "";
	while (BCGame.GetCurrentTry() <= BCGame.GetMaxTries() && BCGame.IsGameWon() == false){
		EGuessStatut GuessStatut = None;
		do {
			Guess = BCGame.GetGuess(); // get the guess
			GuessStatut = BCGame.CheckGuessValidity(Guess); // check guess validity
		} while (GuessStatut != Ok); // loop continually until the user gives a valid guess
		BCGame.SubmitGuess(Guess); //incriment Bulls ands Cows
	}

	if (BCGame.IsGameWon() == false) {
		cout << "No more try left." << endl;
	} else {	
		cout << "CONGRATULATION YOU WON!" << endl;
	}

}

// Return true if the first entry car is y or Y
bool AskToPlayAgain() {
	cout << "GAME OVER" << endl;
	cout << "Do you want to play again with the same word? (y/n)" << endl;
	string Answer = "";
	getline(cin, Answer);

	if (Answer[0] == 'y' || Answer[0] == 'Y') {
		return true;

	}

	return false;
}
