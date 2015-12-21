#ifndef SCOREMATCHG_H
#define SCOREMATCHG_H
#include "LLSIFBase.h"

//****implement the position you end up being in (1,2,3,4) and then rank u got in the song (S,A,B,C,D) will let you calculate points you get for the round****

//target points inherits from base class

//lp needed = targetpts-currents/avgpoints * LPused for that difficulty
//NOTE** we will store the history of average points, and we will store the data in a linked list to be able to update the amount of lp needed

//Description:	A class purely for score match related stuff.

class scoreMatch : public LLSIFBase
{
public:
	//Default Constructor 
	scoreMatch();

	//Initial Constructor 
	scoreMatch(int currentpoints,int PtGoal, int AveScore);

	//Destructor
	~scoreMatch();
	
	int setDifficulty(int diff);
	//Precondition:		None.  diff is an int from 1 to 4 inclusive, with the following meanings:
	//					1 - Easy
	//					2 - Normal
	//					3 - Hard
	//					4 - Expert
	//Postcondition:	Sets the difficulty. Function returns 0 if the difficulty was set, else it returns 1 for an error.

	int getDifficulty();
	//Precondition:		scoreMatchG Constructor has been invoked on the object before.
	//Postcondition:	Returns the difficult as an int:
	//					1 - Easy
	//					2 - Normal
	//					3 - Hard
	//					4 - Expert

	int calcLP();		
	//Precondition:		scoreMatchG Constructor has been invoked on the object before.	
	//Postcondition:	Returns an estimated LP value to be able to reach the Target points 
private:
	int currentpoints;		//COMMENT
	int difficulty;			//Score Match difficulty
	/*int pointGoal;*/		//will be defined in base class
	int pointDiff;			
	int averageScore;		//Average score per game
	int LPReq;				//LP Required to reach goal

	//constants defined for LP costs
	const int LPEasy = 5; 
	const int LPNormal = 10;
	const int LPHard = 15;
	const int LPExpert = 25;

};
#endif //SCOREMATCHG_H
