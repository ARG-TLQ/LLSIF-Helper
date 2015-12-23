#include "tokenCollection.h"
#include "LLSIFBase.h"
#include <cmath>

//Class constructor
tokenCollection::tokenCollection()
{
	difficulty = 0;				//Difficulty of song: Easy/Normal/Hard/Expert
	currentTokens = 0;			//The user's current event tokens.
	pointsPerSong = 1;			//Points per song, entered by user.
	tokenSong = 1;				//The token cost per event song
	scoreMultiplier = 0.0;		//Multiplier based on score.
	comboMultiplier = 0.0;		//Multiplier based on combo.
	estimatedPoints= 0;			//The estimated number of points the user has after calculations.

}

//Precondition:		pSong is the amount of points the user obtains in a song, an int, >0
//					tokens is the amount of tokens has when they initially start tracking their event data, >=0
//					currentPoints is the current number of points the player has, expressed as an int, >=0.
//					targetPoints is the number of points the player is aiming for, >= currentPoints.
//Postcondition:	If valid inputs are given, the object is instantiated with these values.
//					If ANY of the inputs are invalid, the object is instantiated with the default constructor.
tokenCollection::tokenCollection(int currentpoints, int tokens, int pSong,int targetpoints)
{
	//fix implementation to properly handle the post-condition
	setCurrentPoints(currentpoints);
	setTargetPoints(targetpoints);
	currentTokens = tokens;
	pointsPerSong = pSong;
}

//Precondition:		tokenCollection Constructor has been invoked on the object before.
//Postcondition:	Returns the number of current tokens as an int.
int tokenCollection::getCurrentTokens()
{
	return currentTokens;
}

//Precondition:		tokenCollection Constructor invoked on the object before.
//Postcondition:	returns the amount of tokens a song will cost the player based on the difficulty
int tokenCollection::setTokenSong(int difficulty)
{
	if (difficulty == 1)		//Easy song
	{
		tokenSong = 15;
	}
	else if (difficulty == 2)	//Normal song
	{
		tokenSong = 30;
	}
	else if (difficulty == 3)	//Hard song
	{
		tokenSong = 45;
	}
	else if (difficulty == 4)	//Expert song
	{
		tokenSong = 75;
	}

	//NOTE** see error checking issue for proposed enhancement
	else						//Return error.
	{
		return 1;
	}
	return 0;					//Return OK.
}

//Function to set song difficulty
//If function detects difficulty is incorrect, it will not set difficulty, and return 1
//If function can set tokenSong correctly, it will set difficulty and return 0
int tokenCollection::setDifficulty(int diff)
{
	if (setTokenSong(diff) == 1)
		return 1;
	difficulty = diff;
	return 0;
}
//Function to get song difficulty
int tokenCollection::getDifficulty()
{
	return difficulty;
}

//Function to get (average) event points obtained per song
int tokenCollection::getPointsPerSong()
{
	return pointsPerSong;
}

//Function to calculate the estimated number of points.
//Precondition:		setData() member function, or
//Postcondition:	Calculates the estimated points obtainable, and stores it in member field estimatedPoints.  Allows for getEstimatedPoints() member function to be invoked.
void tokenCollection::calculateEstimatedPoints()
{
	double plays = 0;
	plays = (double)(currentTokens) / (double)(tokenSong);
	estimatedPoints = (int)round(getCurrentPoints() + pointsPerSong * plays);
}

//Precondition: tokenCollection Constructor has been invoked on the object before.
//Postcondition: Returns the number of estimated points as an int.
int tokenCollection::getEstimatedPoints()
{
	return estimatedPoints;
}

//Precondition:	tokenCollection Constructor has been invoked on the object before.
//Postcondition: Calculates the number of tokens needed to reach targetPoints, based off of the current difficulty selected, and stores it in member field tokensNeeded.
void tokenCollection::calculateTokensNeeded()
{
	tokensNeeded = (getTargetPoints() - getCurrentPoints());		//calculate number of tokens needed to reach user's target event points.
}



