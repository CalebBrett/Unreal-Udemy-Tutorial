#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount 
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EWordStatus
{
	INVALID_STATUS,
	OK,
	NOT_ISOGRAM,
	WRONG_LENGTH,
	NOT_LOWERCASE
};


class FBullCowGame 
{
public:

	FBullCowGame();

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EWordStatus CheckGuessValidity(FString) const;

	void Reset();


	FBullCowCount SubmitValidGuess(FString);


private:
	int MyCurrentTry;
	int MyMaxTries;
	FString MyHiddenWord;
	bool bGameIsWon;

	bool ISISOGRAM(FString) const;
	bool IsLowwer(FString) const;
};