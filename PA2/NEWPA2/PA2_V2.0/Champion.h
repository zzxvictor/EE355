#ifndef CHAMPION_H
#define CHAMPION_H

#include <vector>


class Hunter;
class Palico;
class HunterBook;
class PalicoBook;

class Champion 
{
	private:
		Hunter * hp;
		Palico * pp;
		int x;
		int y;
		std::string color;
	public:
		Champion(Hunter * h, Palico *p);
		int getX();
		int getY();
		std::string getColor();
		std::string getName();	
		void setXY(int nx, int ny);
		Hunter* getHunter();
		Palico* getPalico();


};


class ChampionBook 
{
	private:
		int listSize;
		std::vector<Champion *> ChampionList;
	public:
		ChampionBook();
		void add(Champion* item);
		void remove(std::string name);
		Champion* indexAccess(int index);
		int getListSize();
		void save(HunterBook * h, PalicoBook *p);

};
#endif 