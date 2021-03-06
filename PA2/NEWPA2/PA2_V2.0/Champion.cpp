#include "MyHeader.h"

Champion::Champion(Hunter * h, Palico *p)
{
	hp = h;
	pp = p;

	x = hp->getX();
	y = hp->getY();

	color = hp->getColor();
}

int Champion::getX()
{
   return x;
}

int Champion::getY()
{
   return y;
}

std::string Champion::getName()
{
	return hp->getName();
}

std::string Champion::getColor()
{
   return color;
}

void Champion::setXY(int nx, int ny)
{
	x = x + nx;
	y = y + ny;
	if (x>15)
		x = 15;
	if (x<0)
		x = 0;
	if (y>15)
		y = 15;
	if (y<0)
		y = 0;
}

Hunter* Champion::getHunter()
{
	return hp;
}
Palico* Champion::getPalico()
{
	return pp;
}







ChampionBook::ChampionBook()
{
	listSize = 0;
}

void ChampionBook::add(Champion * item)
{
	ChampionList.push_back(item);
	listSize++;
}
void ChampionBook::remove(std::string name)
{
	for (int i = 0; i<listSize; i++)
	{
		std::string itemName = ChampionList.at(i)->getName();
		if (itemName.compare(name) == 0)
		{
			//remove item 
			ChampionList.erase(ChampionList.begin() + i);
			listSize--;
			return ;
		}
	}
}
Champion* ChampionBook::indexAccess(int index)
{
	if (index >= listSize)
		std::cout<<"index out of range"<<std::endl;
	else
		return ChampionList.at(index);
}

int ChampionBook::getListSize()
{
	return listSize;
}

void ChampionBook::save(HunterBook * h, PalicoBook *p)
{
	//add all elements into corresponding classes
	//add hunters
	for (int i =0; i<listSize; i++)
	{
		std::cout<<"_-----------X1"<<std::endl;
		h->externalAdd(ChampionList.at(i)->getHunter());
		std::cout<<"_-----------X2"<<std::endl;
		p->externalAdd(ChampionList.at(i)->getPalico());
		std::cout<<"_-----------X3"<<std::endl;
	}
	//add palicos
}