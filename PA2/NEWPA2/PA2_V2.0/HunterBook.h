#ifndef HUNTERBOOK_H
#define HUNTERBOOK_H

#define HUNTERBOOKFILE "Hunter.txt"
class Hunter; //forward declaration 


struct Node2
{
	Hunter *hunter;
	struct Node2 *next = NULL;
	Node2()
	{
		hunter = new Hunter();
	}
	Node2(int x)
	{
		hunter = new Hunter(1);
	}
	Node2(Hunter* hp)
	{
		hunter = hp;
	}
};

struct Node3
{
	Hunter *hunter;
	struct Node3 *next = NULL;
};

class HunterBook
{
	private:
		struct Node2 *header;
		int listSize;
	public:
		HunterBook();
		void add();
		void add(int x);
		void externalAdd(Hunter* hp);
		void sort(int s);
		Hunter * getMax(int s);
		Hunter * indexAccess (int index );
		void remove(std::string item);
		void display();
		void save();
		void search(std::string keyword);
		int getListSize();
};
#endif 