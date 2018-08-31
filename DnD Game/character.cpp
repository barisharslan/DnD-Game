#include "character.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string.h>
#include <vector>
#include <string>

Character::Character() 
{
	name = "";
	strength = 0;
	dexterity = 0;
	constitution = 0;
	intelligence = 0;
	wisdom = 0;
	charisma = 0;
	hitDie = 0;
	health = 0;
	lvl = 0;
	exp = 0;
	armor = 0;
	initiative = 0;
	speed = 0;
	proficiency = 0;
}
Character::Character(std::string n, int s, int d, int c, int i, int w,
	int ch, int hd, int hp, int lv, int xp, int ac, int in, int spd, int pro, Size si)
{
	name = n;
	strength = s;
	dexterity = d;
	constitution = c;
	intelligence = i;
	wisdom = w;
	charisma = ch;
	hitDie = hd;
	health = hp;
	lvl = lv;
	exp = xp;
	armor = ac;
	initiative = in;
	speed = spd;
	proficiency = pro;

	size = si;
	race = OTHER;
	playerClass = NONE;
}
Character::Character(std::string n, int s, int d, int c, int i, int w,
	int ch, int hd, int hp, int lv, int xp, int ac, int in, int spd, int pro, Size si, Race ra, Class cl)
{
	name = n;
	strength = s;
	dexterity = d;
	constitution = c;
	intelligence = i;
	wisdom = w;
	charisma = ch;
	hitDie = hd;
	health = hp;
	lvl = lv;
	exp = xp;
	armor = ac;
	initiative = in;
	speed = spd;
	proficiency = pro;

	size = si;

	race = ra;

	playerClass = cl;
}

std::string Character::getName() { return name; }
int Character::getStr() { return strength; }
int Character::getDex() { return dexterity; }
int Character::getCon() { return constitution; }
int Character::getInt() { return intelligence; }
int Character::getWis() { return wisdom; }
int Character::getCha() { return charisma; }
int Character::getHitDie() { return hitDie; }
int Character::getHp() { return health; }
int Character::getLvl() { return lvl; }
int Character::getExp() { return exp; }
int Character::getAc() { return armor; }
int Character::getIni() { return initiative; }
int Character::getPro() { return proficiency; }
int Character::getSpd() { return speed; }
std::string Character::getSize() 
{
	switch (size)
	{
	case S: return "Small";
	case M: return "Medium";
	case L: return "Large";
	}
}
std::string Character::getRace() 
{ 
	switch (race)
	{
	case MTN_DWARF: return "Mountain Dwarf";
	case HILL_DWARF: return "Hill Dwarf";
	case HIGH_ELF: return "High Elf";
	case WOOD_ELF: return "Wood Elf";
	case DARK_ELF: return "Drow";
	case STOUT_HALFLING: return "Stout Halfling";
	case LIGHTFOOT_HALFLING: return "Lightfoot Halfling";
	case HUMAN: return "Human";
	case DRAGONBORN: return "Dragonborn";
	case FOREST_GNOME: return "Forest Gnome";
	case ROCK_GNOME: return "Rock Gnome";
	case HALFELF: return "Half Elf";
	case HALFORC: return "Half Orc";
	case TIEFLING: return "Tiefling";
	case OTHER: return "Other";
	}
}
std::string Character::getClass()
{
	switch (playerClass) //proficiencies
	{
	case BARBARIAN: return "Barbarian";
	case BARD: return "Bard";
	case CLERIC: return "Cleric";
	case DRUID: return "Druid";
	case FIGHTER: return "Fighter";
	case MONK: return "Monk";
	case PALADIN: return "Paladin";
	case RANGER: return "Ranger";
	case ROGUE: return "Rogue";
	case SORCERER: return "Sorcerer";
	case WARLOCK: return "Warlock";
	case WIZARD: return "Wizard";
	case NONE: return "None";
	}
}
void Character::getStats()
{
	std::cout << std::endl << std::setw(47)
		<< std::left << "Player name: " << std::right << name << std::endl
		<< std::setw(40)
		<< std::left << "	Race: " << std::right << Character::getRace() << std::endl
		<< std::setw(40)
		<< std::left << "	Class: " << std::right << Character::getClass() << std::endl
		<< std::setw(40)
		<< std::left << "	Size: " << std::right << Character::getSize() << std::endl
		<< std::setw(40)
		<< std::left << "	Speed: " << std::right << speed << std::endl
		<< std::setw(40)
		<< std::left << "	Strength: " << std::right << strength << std::endl
		<< std::setw(40)
		<< std::left << "	Dexterity: " << std::right << dexterity << std::endl
		<< std::setw(40)
		<< std::left << "	Constitution: " << std::right << constitution << std::endl
		<< std::setw(40)
		<< std::left << "	Intelligence: " << std::right << intelligence << std::endl
		<< std::setw(40)
		<< std::left << "	Wisdom: " << std::right << wisdom << std::endl
		<< std::setw(40)
		<< std::left << "	Charisma: " << std::right << charisma << std::endl;
}

void Character::setName(std::string n) { name = n; }
void Character::setStr(int s) { strength = s; }
void Character::setDex(int d) { dexterity = d; }
void Character::setCon(int c) { constitution = c; }
void Character::setInt(int i) { intelligence = i; }
void Character::setWis(int w) { wisdom = w; }
void Character::setCha(int c) { charisma = c; }
void Character::setHitDie(int h) { hitDie = h; }
void Character::setHp(int hp) { health = hp; }
void Character::setLvl()
{
	if (exp >= 0 && exp < 300)
		lvl = 1;
	else if (exp >= 300 && exp < 900)
		lvl = 2;
	else if (exp >= 900 && exp < 2700)
		lvl = 3;
	else if (exp >= 2700)
		lvl = 4;
}
void Character::setExp(int xp) { exp = xp; }
void Character::addExp(int xp) { exp += xp; }
void Character::setAc(int ac) { armor = ac; }
void Character::setIni(int i) { initiative = i; }
void Character::setPro(int p) { proficiency = p; }
void Character::setSpd(int s) { speed = s; }
void Character::setSize(int s) { size = static_cast<Size>(s); }
Race Character::askRace()
{
	char ch[30];
	std::string r;
	int c = 0;
	bool error = 0;
	do {
		if (c != 0) {						//checks for first time
			std::cout << "Invalid input, please check your spelling and try again.\n";
		}
		std::cout << "Choose your race. " << std::endl
			<< "You can choose Mountain Dwarf, Hill Dwarf, " << std::endl
			<< "High Elf, Wood Elf, Drow, Stout Halfling, " << std::endl
			<< "Lightfoot Halfling, Human, Dragonborn, " << std::endl
			<< "Forest Gnome, Rock Gnome, Halfelf, " << std::endl
			<< "Halforc, or Tiefling. " << std::endl;
		std::cin.getline(ch, 30);
		for (int i = 0; i < strlen(ch); i++)
			ch[i] = tolower(ch[i]);								//change to lowercase
		r = ch;
		r.erase(std:: remove(r.begin(), r.end(),' '), r.end()); // remove whitespace
		c++;
		if (r == "mountaindwarf")
			return MTN_DWARF;
		else if (r == "hilldwarf")
			return HILL_DWARF;
		else if (r == "highelf")
			return HIGH_ELF;
		else if (r == "woodelf")
			return WOOD_ELF;
		else if (r == "drow" || r == "darkelf")
			return DARK_ELF;
		else if (r == "stouthalfling")
			return STOUT_HALFLING;
		else if (r == "lightfoothalfling")
			return LIGHTFOOT_HALFLING;
		else if (r == "human")
			return HUMAN;
		else if (r == "dragonborn")
			return DRAGONBORN;
		else if (r == "forestgnome")
			return FOREST_GNOME;
		else if (r == "rockgnome")
			return ROCK_GNOME;
		else if (r == "halfelf")
			return HALFELF;
		else if (r == "halforc")
			return HALFORC;
		else if (r == "tiefling")
			return TIEFLING;
		else
			error = 1;
	} while (error = 1);
}
void Character::setRace(Race r)//calls initRace 
{
	race = r;
	Character::initRace();
}
void Character::initRace() //sets ability increases, size, and speed
{
	switch (race)
	{
		case MTN_DWARF:
			Character::setCon(constitution + 2);
			Character::setStr(strength + 2);
			Character::setSize(M);
			Character::setSpd(25);
			break;

		case HILL_DWARF:
			Character::setCon(constitution + 2);
			Character::setWis(wisdom + 1);
			Character::setSize(M);
			Character::setSpd(25);
			break;

		case HIGH_ELF:
			Character::setDex(dexterity + 2);
			Character::setInt(intelligence + 1);
			Character::setSize(M);
			Character::setSpd(30);
			break;

		case WOOD_ELF:
			Character::setDex(dexterity + 2);
			Character::setWis(wisdom + 1);
			Character::setSize(M);
			Character::setSpd(30);
			break;

		case DARK_ELF:
			Character::setDex(dexterity + 2);
			Character::setCha(charisma + 1);
			Character::setSize(M);
			Character::setSpd(30);
			break;

		case STOUT_HALFLING:
			Character::setDex(dexterity + 2);
			Character::setCon(constitution + 1);
			Character::setSize(S);
			Character::setSpd(25);
			break;

		case LIGHTFOOT_HALFLING:
			Character::setDex(dexterity + 2);
			Character::setCha(charisma + 1);
			Character::setSize(S);
			Character::setSpd(25);
			break;

		case HUMAN:
			Character::setStr(strength + 1);
			Character::setDex(dexterity + 1);
			Character::setCon(constitution + 1);
			Character::setInt(intelligence + 1);
			Character::setWis(wisdom + 1);
			Character::setCha(charisma + 1);
			Character::setSize(M);
			Character::setSpd(30);
			break;

		case DRAGONBORN:
			Character::setStr(strength + 2);
			Character::setCha(charisma + 1);
			Character::setSize(M);
			Character::setSpd(30);
			break;

		case FOREST_GNOME:
			Character::setInt(intelligence + 2);
			Character::setDex(dexterity + 1);
			Character::setSize(S);
			Character::setSpd(25);
			break;

		case ROCK_GNOME:
			Character::setInt(intelligence + 2);
			Character::setCon(constitution + 1);
			Character::setSize(S);
			Character::setSpd(25);
			break;

		case HALFELF:
			Character::setCha(charisma + 2);
			// + 1 to 2 stats of player choice
			Character::setSize(M);
			Character::setSpd(30);
			break;

		case HALFORC:
			Character::setStr(strength + 2);
			Character::setCon(constitution + 1);
			Character::setSize(M);
			Character::setSpd(30);
			break;

		case TIEFLING:
			Character::setCha(charisma + 2);
			Character::setInt(intelligence + 1);
			Character::setSize(M);
			Character::setSpd(30);
			break;

	}
}
Class Character::askClass()
{
	char ch[30];
	std::string r;
	bool error = 0;
	int c = 0;
	do {
		if (c != 0) { 						//checks for first time
			std::cout << "Invalid input, please check your spelling and try again.\n";
		}
		std::cout << "Choose your class. " << std::endl
			<< "You can choose Barbarian, Bard, Cleric," << std::endl
			<< "Druid, Fighter, Monk, Paladin, Ranger" << std::endl
			<< "Rogue, Sorcerer, Warlock, or Wizard." << std::endl;
		std::cin.getline(ch, 30);
		for (int i = 0; i < strlen(ch); i++)
			ch[i] = tolower(ch[i]);								//change to lowercase
		r = ch;
		r.erase(std::remove(r.begin(), r.end(), ' '), r.end()); // remove whitespace
		c++;
		if (r == "barbarian")
			return BARBARIAN;
		else if (r == "bard")
			return BARD;
		else if (r == "cleric")
			return CLERIC;
		else if (r == "druid")
			return DRUID;
		else if (r == "fighter")
			return FIGHTER;
		else if (r == "monk")
			return MONK;
		else if (r == "paladin")
			return PALADIN;
		else if (r == "ranger")
			return RANGER;
		else if (r == "rogue")
			return ROGUE;
		else if (r == "sorcerer")
			return SORCERER;
		else if (r == "warlock")
			return WARLOCK;
		else if (r == "wizard")
			return WIZARD;
		else
			error = 1;
	} while (error = 1);
}
void Character::setClass(Class c) 
{
	playerClass = c; 
	Character::initClass();
}
void Character::initClass() //sets hitDie and hp
{
	switch (playerClass) //proficiencies
	{
		case BARBARIAN:
			Character::setHitDie(12);
			Character::setHp(hitDie + Character::modifier(constitution));
			break;

		case BARD:
			Character::setHitDie(8);
			Character::setHp(hitDie + Character::modifier(constitution));
			break;

		case CLERIC:
			Character::setHitDie(8);
			Character::setHp(hitDie + Character::modifier(constitution));
			break;

		case DRUID:
			Character::setHitDie(8);
			Character::setHp(hitDie + Character::modifier(constitution));
			break;

		case FIGHTER:
			Character::setHitDie(10);
			Character::setHp(hitDie + Character::modifier(constitution));
			break;

		case MONK:
			Character::setHitDie(8);
			Character::setHp(hitDie + Character::modifier(constitution));
			break;

		case PALADIN:
			Character::setHitDie(10);
			Character::setHp(hitDie + Character::modifier(constitution));
			break;

		case RANGER:
			Character::setHitDie(10);
			Character::setHp(hitDie + Character::modifier(constitution));
			break;

		case ROGUE:
			Character::setHitDie(8);
			Character::setHp(hitDie + Character::modifier(constitution));
			break;

		case SORCERER:
			Character::setHitDie(6);
			Character::setHp(hitDie + Character::modifier(constitution));
			break;

		case WARLOCK:
			Character::setHitDie(8);
			Character::setHp(hitDie + Character::modifier(constitution));
			break;

		case WIZARD:
			Character::setHitDie(6);
			Character::setHp(hitDie + Character::modifier(constitution));
			break;


	}
}

void Character::createChar()
{
	Class classChoice;
	Race raceChoice;
	char nameCh[30];
	std::string nameChoice;
	std::cout << "Enter your character's name." << std::endl;
	std::cin.getline(nameCh, 30);
	classChoice = askClass();
	raceChoice = askRace();
	nameChoice = nameCh;
	assignScores();
	setName(nameChoice);
	setClass(classChoice);
	setRace(raceChoice);
	
}
void Character::assignScores() 
{
	std::cout << "Rolling your ability scores..." << std::endl;
	std::vector<int> scores;
	
	for (int i = 0; i < 6; i++)
		scores.push_back(roll(20, 1, 0));
	std::cout << "Your rolls are ";
	for (int i = 0; i < scores.size(); i++)
		std::cout << scores[i] << " ";
	std::cout << std::endl;


	std::cout << "Enter which score you want for... " << std::endl;
	strength = initScores(scores, "Strength");
	dexterity = initScores(scores, "Dexterity");
	constitution = initScores(scores, "Constitution");
	intelligence = initScores(scores, "Intelligence");
	wisdom = initScores(scores, "Wisdom");
	charisma = initScores(scores, "Charisma");



}

int Character::initScores(std::vector<int> & v, std::string ability)
{
	
	int c = 0;
	bool error = false;
	do {

		if (c != 0) {
			std::cout << "That isn't one of your scores. Try again. " << std::endl;
		}
		int choice;
		std::cout << ability << ": ";
		std::cin >> choice;
		auto iter = std::find(v.begin(), v.end(), choice);
		if (iter != v.end())
		{
			v.erase(iter);
			if (!v.empty())
				std::cout << "Your remaining rolls are ";
			for (int i = 0; i < v.size(); i++)
				std::cout << v[i] << " ";
			std::cout << std::endl;
			return choice;
		}
		else
		{
			c++;
			error = true;
		}
	} while (error);
}

int Character::modifier(int stat)
{
	switch (stat)
	{
		case 1:
			return -5;
		case 2:
		case 3:
			return -4;
		case 4:
		case 5:
			return -3;
		case 6:
		case 7:
			return -2;
		case 8:
		case 9:
			return -1;
		case 10:
		case 11:
			return 0;
		case 12:
		case 13:
			return 1;
		case 14:
		case 15:
			return 2;
		case 16:
		case 17:
			return 3;
		case 18:
		case 19:
			return 4;
		case 20:
		case 21:
			return 5;
		case 22:
		case 23:
			return 6;
		case 24:
		case 25:
			return 7;
		case 26:
		case 27:
			return 8;
		case 28:
		case 29:
			return 9;
		case 30:
			return 10;
		default:
			return 0;
	}
}