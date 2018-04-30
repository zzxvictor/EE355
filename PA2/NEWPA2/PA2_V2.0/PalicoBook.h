#ifndef PALICOBOOK_H
#define PALICOBOOK_H
#include <queue>
#include <vector>

#define PALICOBOOKFILE "Palico.txt"


class Palico;

class compare
{
	public:
		bool operator() (  Palico* lhs,   Palico* rhs) ;
};


class PalicoBook
{
	private:
		std::priority_queue <Palico*, std::vector<Palico*>, compare >  palicoQueue;
		std::vector <Palico*> rawInput;
		int listSize;
	public:
		PalicoBook();
		void add();
		void add(int x);
		void changeMode(int Indicator);
		Palico* max(int Indicator );
		void remove(std::string userInput);
		void search(std::string userInput);
		void save();
		void display();
		void cleanHeap();
		Palico* indexAccess(int index);
		int getListSize();
		void externalAdd(Palico * p);
};


#endif 