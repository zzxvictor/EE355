#include "MyHeader.h"

Item::Item()
{
	name = "A Random Name ";
}

Sword::Sword()
{
	attack = ATTACKVALUE;
}

int Sword::getAttack()
{
	return attack;
}


Equipment::Equipment()
{
	defense = DEFENSEVALUE;
}

int Equipment::getDefense()
{
	return defense;
}

