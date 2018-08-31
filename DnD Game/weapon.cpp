#include "weapon.h"

Weapon::Weapon() : Item()
{
	rolls = 0;
	damage = 0;
}
Weapon::Weapon(int r, int d, std::string n, int c, double w)
	: Item(n, c, w)
{
	rolls = r;
	damage = d;
}

void Weapon::getStats()
{
	Item::mainStats();
	std::cout<< std::setw(40)
		<< std::left << "	Damage: " << std::right << rolls << "d" << damage << std::endl;
}