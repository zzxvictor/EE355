#ifndef MONSTERBOOK_H
#define MONSTERBOOK_H

#define MONSTERBOOKFILE "Monsters.txt"
class Monster;//forward declaration 
struct Node 
{
	//Monster *monsterPointer = new Monster();
	Monster *rathalos;
	struct Node *next = NULL;
	struct Node *previous = NULL;
	Node()
	{
		rathalos = new Monster();
	}
	Node(int x)
	{
		rathalos = new Monster(1);
	}
};

class Monsterbook
{
	private:
		struct Node *header;
		int listSize;
	public:
		Monsterbook();
		void add();
		void add(int x);
		void remove(std::string item);
		void display();
		void save();
		void search(std::string keyword);
		Node *findPosition(struct Node * item, bool& flag);
		Monster* indexAccess (int index );
		int getListSize();
		void removeViaIndex (int index);

};

#endif 