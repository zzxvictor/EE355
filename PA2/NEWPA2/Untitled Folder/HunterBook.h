#ifndef HUNTERBOOK2_H
#define HUNTERBOOK2_H

#define HUNTERBOOKFILE "Hunter.txt"
class Hunter;

class HunterBook
{
	private:
		std::forward_list <Hunter *> hb;
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
		Hunter * search(std::string keyword, int x);
		int getListSize();
};
#endif 