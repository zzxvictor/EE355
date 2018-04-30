#include "MyHeader.h"



Monsterbook::Monsterbook()
{
	header = NULL;
}

void Monsterbook::add()
{
	struct Node *newNode = new struct Node;
	bool flag = true;
	struct Node *insertPlace = findPosition(newNode,flag);
	//insert
	if (flag == false)
		;
	else
	{
		if ((insertPlace == header)&&(getListSize() == 0))
		{
			newNode->next = header;
			header = newNode;
			if (newNode->next != NULL)
				newNode->next->previous = newNode;
		}
		else 
		{
			newNode->next = insertPlace->next;
			newNode->previous = insertPlace;
			insertPlace->next = newNode;
			if (newNode->next != NULL)
				newNode->next->previous = newNode;
		}
		//std::cout<<"item added!"<<std::endl;
	}

}

void Monsterbook::add(int x)
{
	struct Node *newNode = new struct Node(1);
	bool flag = true;
	struct Node *insertPlace = findPosition(newNode,flag);
	//insert
	if (flag == false)
		;
	else
	{
		if ((insertPlace == header)&&(getListSize() == 0))
		{
			newNode->next = header;
			header = newNode;
			if (newNode->next != NULL)
				newNode->next->previous = newNode;
		}
		else 
		{
			newNode->next = insertPlace->next;
			newNode->previous = insertPlace;
			insertPlace->next = newNode;
			if (newNode->next != NULL)
				newNode->next->previous = newNode;
		}
		//std::cout<<"item added!"<<std::endl;
	}

}


void Monsterbook::remove(std::string item)
{
	//search 
	struct Node *pointer = header;
	if (pointer == NULL)
		std::cout<<"the list is empty, nothing to remove"<<std::endl;
	else
	{
		while (pointer!=NULL)
		{
			std::string itemName = pointer->rathalos->getName();
			if (itemName.compare(item) == 0)
			{
				//remove
				if (getListSize() == 1)
				{
					delete header;
					header = NULL;
					break;
				}
				else if (pointer->next == NULL)
				{
					//last item
					struct Node *temp = pointer->previous;
					delete pointer;
					temp->next = NULL;
					break;
				}
				else if(pointer->previous == NULL)
				{
					//first item 
					header = pointer->next;
					pointer->next->previous = NULL;
					delete pointer;
					break;

				}
				else
				{
					pointer->next->previous = pointer->previous;
					pointer->previous->next = pointer->next;
					delete pointer;
					break;
				}

			}
			else
				pointer = pointer->next;
		}
	} 

}


void Monsterbook::display()
{
	//first display the list 
	struct Node *pointer = header;
	if (pointer == NULL)
		std::cout<<"the list is empty"<<std::endl;
	else
	{
		while (pointer!=NULL)
		{
			std::cout<<pointer->rathalos->getName()<<", ";
			std::cout<<pointer->rathalos->getGender()<<", ";
			std::cout<<"Age: "<<pointer->rathalos->getAge()<<std::endl;
			std::cout<<"Attack: "<<pointer->rathalos->getAttack()<<std::endl;
			std::cout<<"HP: "<<pointer->rathalos->getHP()<<std::endl;
			std::cout<<"Defense: "<<pointer->rathalos->getDefense()<<std::endl;
			std::cout<<"X: "<<pointer->rathalos->getX()<<std::endl;
			std::cout<<"Y: "<<pointer->rathalos->getY()<<std::endl;
			pointer = pointer->next;
		}
	} 
}


void Monsterbook::search(std::string keyword)
{
	//
	struct Node *pointer = header;
	if (pointer == NULL)
		std::cout<<"the list is empty"<<std::endl;
	else
	{
		while (pointer!=NULL)
		{
			std::string temp = pointer->rathalos->getName();
			if(temp.compare(keyword) == 0)
			{
				std::cout<<"item found!"<<std::endl;
				std::cout<<pointer->rathalos->getName()<<", ";
				std::cout<<pointer->rathalos->getGender()<<", ";
				std::cout<<"Age: "<<pointer->rathalos->getAge()<<std::endl;
				std::cout<<"Attack: "<<pointer->rathalos->getAttack()<<std::endl;
				std::cout<<"HP: "<<pointer->rathalos->getHP()<<std::endl;
				std::cout<<"Defense: "<<pointer->rathalos->getDefense()<<std::endl;
				return;
			}
			pointer = pointer->next;

		}
		std::cout<<"Item Not Found"<<std::endl;
	} 
}


void Monsterbook::save()
{
	std::ofstream outputFile;
	outputFile.open(MONSTERBOOKFILE);
	struct Node *pointer = header;
	if (pointer == NULL)
		outputFile<<"the list is empty. \n";
	else
	{
		while (pointer!=NULL)
		{
			//outputFile<<pointer->value1<<" "<<pointer->value2<<'\n';
			outputFile<<pointer->rathalos->getName()<<", ";
			outputFile<<pointer->rathalos->getGender()<<", ";
			outputFile<<pointer->rathalos->getAge()<<'\n';
			pointer = pointer->next;
		}
	} 
	outputFile.close();
	std::cout<<"filed saved!"<<std::endl;

}
Node* Monsterbook::findPosition(struct Node * item, bool& flag)
{
	struct Node * temp = header;
	std::string inputValue = item->rathalos->getName();
	//std::cout<<"new node value:"<<inputValue<<std::endl;

	if (getListSize() == 0)
		//no element in the list
		return header;
	while (temp != NULL)
	{
		std::string nodeValue = temp->rathalos->getName();
		//std::cout<<"previous node value: "<<nodeValue<<std::endl;
		int result = nodeValue.compare(inputValue);
		//std::cout<<"compare results: "<<result<<std::endl;
		if (result == 0)
			//same name
		{
			std::cout<<"item already exists, error"<<std::endl;
			flag = false;
			break;
		}
		else if (result <0)
		{
			//move forward 
			if (temp->next == NULL)
				return temp;
			else
				temp = temp->next;
		}
		else
		{
			//move backward
			if (temp->previous == NULL)
			{
				return header;
			}
			else
			{
				return temp->previous;
			}
		}
	}

}

Monster* Monsterbook::indexAccess (int index )
{
	if (index >= getListSize())
	{
		std::cout<<"index out of range !"<<std::endl;
		return NULL;
	}
	else
	{
		struct Node *pointer = header;
		for (int i = 0; i<index; i++)
		{
			pointer = pointer->next;
		}
		return pointer->rathalos;
	}
}

int Monsterbook::getListSize()
{
	struct Node * temp = header;
	int listSize = 0;
	while (temp!=NULL)
	{
		temp = temp->next;
		listSize++;
	}
	return listSize;
}


//testing code
/*
int main ()
{
	Monsterbook *book = new Monsterbook();
	book->add();
	book->add();
	book->add();
	book->add();
	book->add();
	
	std::string userIput;
	std::cin>>userIput;
	book->remove(userIput);
	book->display();
	book->save();
	//book->search();
	std::string userInput ;
	std::cin>>userInput;
	book->search(userInput);

}*/