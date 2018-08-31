#ifndef __CHARACTER_H_INCLUDED__
#define __CHARACTER_H_INCLUDED__

#include <string>
#include <vector>
#include "roll.h"

enum Size { S, M, L };
enum Race { //check input > change to lower and remove space >switch case for possible strings > return number
	MTN_DWARF, HILL_DWARF, HIGH_ELF,
	WOOD_ELF, DARK_ELF, STOUT_HALFLING, LIGHTFOOT_HALFLING,
	HUMAN, DRAGONBORN, FOREST_GNOME, ROCK_GNOME,
	HALFELF, HALFORC, TIEFLING, OTHER
};
enum Class {
	BARBARIAN, BARD, CLERIC, DRUID,
	FIGHTER, MONK, PALADIN, RANGER, ROGUE,
	SORCERER, WARLOCK, WIZARD, NONE
};

class Character
{
protected:
	std::string name;
	int strength;
	int dexterity;
	int constitution;
	int intelligence;
	int wisdom;
	int charisma;
	int hitDie;
	int health;
	int lvl;
	int exp;
	int armor;
	int initiative;
	int speed;
	int proficiency;
	
	Size size;
	
	Race race;
	
	Class playerClass;
	

public:
	Character();
	Character(std::string, int, int, int, int, int,
		int, int, int, int, int, int, int, int, int, Size);
	Character(std::string, int, int, int, int, int,
		int, int, int, int, int, int, int, int, int, Size, Race, Class);
	std::string getName();
	int getStr();
	int getDex();
	int getCon();
	int getInt();
	int getWis();
	int getCha();
	int getHitDie();
	int getHp();
	int getLvl();
	int getExp();
	int getAc();
	int getIni();
	int getPro();
	int getSpd();
	std::string getSize();
	std::string getRace();
	std::string getClass();
	void getStats();

	void setName(std::string);
	void setStr(int);
	void setDex(int);
	void setCon(int);
	void setInt(int);
	void setWis(int);
	void setCha(int);
	void setHitDie(int);
	void setHp(int);
	void setLvl();
	void setExp(int);
	void addExp(int);
	void setAc(int);
	void setIni(int);
	void setPro(int);
	void setSpd(int);
	void setSize(int);
	Race askRace();
	void setRace(Race);
	void initRace();
	Class askClass();
	void setClass(Class);
	void initClass();

	void createChar();
	void assignScores();
	int initScores(std::vector<int>&, std::string);

	int modifier(int);
};





#endif