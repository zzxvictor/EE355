#ifndef GUI_H
#define GUI_H
#define OBJSIZE 16
#include "bmplib.h"


class HunterBook; //forward declaration 
class Monsterbook;
class PalicoBook;
class ChampionBook;


class GUI
{
	private:
		unsigned char image[SIZE][SIZE][RGB];
	public:
		GUI();
		void display(HunterBook* hb, Monsterbook* mb, PalicoBook *pb, ChampionBook *cb);
		void addHunter(HunterBook* hb);
		void addMonster(Monsterbook* mb);
		void addPalico(PalicoBook* pb);
		void addChampion(ChampionBook *cb);
		void clearScreen();
		void printObj(int x, int y, std::string color,  int option);
};
#endif 