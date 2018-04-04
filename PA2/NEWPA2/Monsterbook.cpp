#include "MyHeader.h"



Monsterbook::Monsterbook()
{
	header = NULL;
	listSize = 0;
}

void Monsterbook::add()
{
	struct Node *temp = new (struct Node);
	struct Node *insertPlace = findPosition(temp);
	std::cout<<"add needs implementation!"<<std::endl;
}
void Monsterbook::remove()
{
	std::cout<<"remove needs implementation!"<<std::endl;
}
void Monsterbook::save()
{
	std::cout<<"save needs implementation!"<<std::endl;
}
void Monsterbook::search(char * keyword)
{
	std::cout<<"search needs implementation!"<<std::endl;
}

Node* Monsterbook::findPosition(struct Node * item)
{
	std::cout<<"findPosition needs implementation!"<<std::endl;
}

int main ()
{
	Monsterbook *book = new Monsterbook();
	book->save();
	book->add();
	//book->search();

}