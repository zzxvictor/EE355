#ifndef MONSTERBOOK_H
#define MONSTERBOOK_H


//class Monster;//forward declaration 
struct Node 
{
	//Monster *monsterPointer = new Monster();
	int value;
	struct Node *next;
	struct Node *previous;
	
};

class Monsterbook
{
	private:
		struct Node *header;
		int listSize;
	public:
		Monsterbook();
		void add();
		void remove();
		void save();
		void search(char * keyword);
		Node *findPosition(struct Node * item);

};

#endif 