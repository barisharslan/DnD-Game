#include "roll.h"

int roll(int dice)
{
	int lower = 1;
	int upper = dice;
	int yourRoll = rand() % dice + lower;
	return yourRoll;
}

int roll(int dice, int howMany, int additions)
{
	
	int lower = 1;                                                                                        
	int upper = dice;                                                                                     
	int sum = 0;
	int yourRoll = 0;

	for (int i = 1; i <= howMany; i++)                                                                   
	{
		yourRoll = rand() % dice + lower;                                                                                    
		sum += yourRoll;                                                                                 
	}                                      
	sum += additions;                                                                                     
	return sum;
}

