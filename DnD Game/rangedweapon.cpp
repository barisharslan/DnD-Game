#include "rangedweapon.h"

RangedWeapon::RangedWeapon() : Weapon()
{
	lowerRange = 0;
	upperRange = 0;
}
RangedWeapon::RangedWeapon(int lr, int ur, int r, int d, std::string n, int c, double w)
	: Weapon(r, d, n, c, w)
{
	lowerRange = lr;
	upperRange = ur;
}

void RangedWeapon::getStats()
{
	Item::mainStats();
	std::cout << std::setw(40)
		<< std::left << "	Damage: " << std::right << rolls << "d" << damage << std::endl
		<< std::left << "	Range: " << std::right << lowerRange << "/" << upperRange
		<< std::endl;
}