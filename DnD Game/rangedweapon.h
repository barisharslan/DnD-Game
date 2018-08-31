#ifndef __RANGEDWEAPON_H_INCLUDED__
#define __RANGEDWEAPON_H_INCLUDED__

#include "weapon.h"

class RangedWeapon : public Weapon
{
protected:
	int lowerRange;
	int upperRange;

public:
	RangedWeapon();
	RangedWeapon(int lr, int ur, int r, int d, std::string n, int c, double w);
	void getStats();
};

#endif
