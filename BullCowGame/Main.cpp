#include <iostream>
#include <string>
#include "FBullCowGame.h"


using FText = std::string;
using int32 = int;

void Intro();
void PlayGame();
FText GetGuess();
bool AskPlayAgain();
void PrintGameSum();

FBullCowGame BCGAME;


int main() 
{
	do
	{
		Intro();
		PlayGame();
	} while (AskPlayAgain());

	return 0;
}

void Intro() 
{
	std::cout << "Welcome to bulls and cows" << std::endl;
	std::cout << "Can you guess the " << BCGAME.GetHiddenWordLength() << " letter isogram I'm thinking of?\n";

	return;
}

void PlayGame() 
{

	BCGAME.Reset();
	int32 MaxTries = BCGAME.GetMaxTries();

	while (!BCGAME.IsGameWon() && BCGAME.GetCurrentTry() <= MaxTries)
	{
		FText guess = GetGuess();

		FBullCowCount BCCOUNT = BCGAME.SubmitValidGuess(guess);

		std::cout << "Bulls = " << BCCOUNT.Bulls << "Cows = " << BCCOUNT.Cows << std::endl;
	}
	PrintGameSum();
}

FText GetGuess() 
{
	EWordStatus Status = EWordStatus::INVALID_STATUS;
	FText Guess = "";


	do {
		std::cout << "Tries = " << BCGAME.GetCurrentTry() << ". What is your guess? ";
		std::getline(std::cin, Guess);


		Status = BCGAME.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EWordStatus::WRONG_LENGTH:
			std::cout << "PLease enter a " << BCGAME.GetHiddenWordLength() << " letter word. \n";
			break;
		case EWordStatus::NOT_ISOGRAM:
			std::cout << "PLease enter a word with out repeating letters. \n";
			break;

		case EWordStatus::NOT_LOWERCASE:
			std::cout << "PLease enter all lowercase letters in your word. \n";
			break;

		default:
			break;
		}
		std::cout << std::endl;
	} while (Status != EWordStatus::OK);
	return Guess;
}

void PrintGameSum() 
{
	if (BCGAME.IsGameWon()) 
	{
		std::cout << "YOU WON!\n";
	}
	else 
	{
		std::cout << "Better luck next time!\n";
	}
}


bool AskPlayAgain() 
{
	std::cout << "Would you like to play again?\n";
	FText answer = "";
	std::cin >> answer;
	return (answer[0] == 'y' || answer[0] == 'Y');
}