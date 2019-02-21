#include "FBullCowGame.h"
#include <map>
#define TMap std::map;

using int32 = int;
using FString = std::string;

FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetCurrentTry() const{return MyCurrentTry;}
int32 FBullCowGame::GetHiddenWordLength() const {return MyHiddenWord.length();}
bool FBullCowGame::IsGameWon() const{return bGameIsWon;}

int32 FBullCowGame::GetMaxTries() const 
{
	std::map<int32, int32> WORDLENGTHTO_MAX_TRIES{ {3,5},{4,6},{5,7}, { 6,8 }};
	return WORDLENGTHTO_MAX_TRIES[MyHiddenWord.length()]; }



EWordStatus FBullCowGame::CheckGuessValidity(FString guess) const{
	if (!ISISOGRAM(guess)) 
	{
		return EWordStatus::NOT_ISOGRAM;
	}
	else if (!IsLowwer(guess)) 
	{
		return EWordStatus::NOT_LOWERCASE;
	}
	else if (guess.length() != GetHiddenWordLength()) 
	{
		return EWordStatus::WRONG_LENGTH;
	}
	else 
	{
		return EWordStatus::OK;
	}
	
	return EWordStatus::OK;
}

void FBullCowGame::Reset()
{

	const FString HIDDEN_WORD = "YAHOO";
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	return;
}

FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;

	FBullCowCount BullCowCount;
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++)
	{
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++) 
		{
			if (Guess[GChar] == MyHiddenWord[MHWChar]) 
			{
				if (MHWChar == GChar) 
				{
					BullCowCount.Bulls++;
				}
				else 
				{
					BullCowCount.Cows++;
				}
			}
		}
	}
	if (BullCowCount.Bulls == HiddenWordLength) 
	{
		bGameIsWon = true;	
	}
	else { bGameIsWon = false; }
	return BullCowCount;
}

bool FBullCowGame::ISISOGRAM(FString Word) const
{
	if (Word.length() <= 1) { return true; }
	std::map<char, bool> LetterSeen;
	for (auto Letter : Word)
	{
		Letter = tolower(Letter);
		if (LetterSeen[Letter]) 
		{
			return false;
		}
		else 
		{
			LetterSeen[Letter] = true;
		}
	}
	return true;
}

bool FBullCowGame::IsLowwer(FString Word) const
{
	for (auto letter : Word) 
	{
		if (!islower(letter)) 
		{
			return false;
		}
	}
	return true;
}

