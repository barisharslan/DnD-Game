#include "character.h" //<string>, "roll.h" ( <ctime> & <stdlib.h> )
#include "rangedweapon.h" //"weapon.h" ( "item.h" )
#include <iostream>
#include <iomanip>


int main()
{
	srand(time(NULL));
	Character yourChar;
	yourChar.createChar();
	yourChar.getStats();
	Character drong = {"Drong", 8, 14, 10, 10, 8, 8, 6, 7, 1, 0, 15, 2, 30, 2, S };
	Item rope = { "Rope", 1, 0 };
	rope.getStats();
	Weapon club = { 1, 4, "Club", 1, 2 };
	club.getStats();
	RangedWeapon lightCrossbow = { 80, 320, 1, 8, "Crossbow, light", 25, 5 };
	lightCrossbow.getStats();
	


	return 0;
}