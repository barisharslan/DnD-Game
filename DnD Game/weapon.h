#ifndef __WEAPON_H_INCLUDED__
#define __WEAPON_H_INCLUDED__

#include "item.h"

class Weapon : public Item
{
protected:
	int rolls;
	int damage;

public:
	Weapon();
	Weapon(int r, int d, std::string n, int c, double w);
	void getStats();
};

#endif
