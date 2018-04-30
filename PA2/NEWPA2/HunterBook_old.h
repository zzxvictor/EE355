#ifndef HUNTERBOOK_H
#define HUNTERBOOK_H

#define HUNTERBOOKFILE "Hunter.txt"
class Hunter; //forward declaration 


struct Node2
{
	Hunter hunter;
	struct Node2 *next = NULL;
};

class HunterBook
{
	private:
		struct Node2 *header;
		int listSize;
	public:
		HunterBook();
		void add();
		int size();
		void sort(int s);
		Hunter* getMax(int s);
		void remove(std::string item);
		void dispaly();
		void save();
		void search(std::string keyword);

};
#endif 