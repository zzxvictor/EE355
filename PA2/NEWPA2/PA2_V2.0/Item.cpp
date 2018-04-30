#include "MyHeader.h"

Item::Item()
{
	std::string namePool[4] = {"Alpha", "Beta", "Gamma", "Theta"};
	name = namePool[rand()%4];
}

Sword::Sword()
{
	attack = ATTACKVALUE;
}

int Sword::getAttack()
{
	return attack;
}
std::string Sword::getName()
{
	return name;
}

Equipment::Equipment()
{
	defense = DEFENSEVALUE;
}

int Equipment::getDefense()
{
	return defense;
}

std::string Equipment::getName()
{
	return name;
}

