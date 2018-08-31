#ifndef __ITEM_H__INCLUDED__
#define __ITEM_H__INCLUDED__

#include <string>
#include <iostream>
#include <iomanip>

class Item 
{
protected:
	std::string name;
	int cost;
	double weight;

public:
	Item();
	Item(std::string, int, double);
	virtual void getStats();
	void mainStats(); 
};


#endif
