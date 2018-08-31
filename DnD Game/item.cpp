#include "item.h"

Item::Item()
{
	name = "";
	cost = 0;
	weight = 0.0;
}

Item::Item(std::string n, int c, double w)
{
	name = n;
	cost = c;
	weight = w;
}

void Item::getStats()
{
	Item::mainStats();
}

void Item::mainStats()
{
	std::cout << std::endl << std::setw(47)
		<< std::left << "Item Name: " << std::right << name << std::endl
		<< std::setw(40)
		<< std::left << "	Cost: " << std::right << cost << " gp" << std::endl
		<< std::setw(40)
		<< std::left << "	Weight: " << std::right << weight << " lb" << std::endl;
}