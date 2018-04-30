#include "MyHeader.h"

HunterBook::HunterBook()
{
	header = NULL;
	listSize = 0;

}

void HunterBook::add()
{
	struct Node2 * temp = header;
	bool flag = false;
	if (listSize == 0)
	{
		//add directly
		struct Node2 *newNode2 = new struct Node2;
		header = newNode2;
		listSize++;
	}
	else
	{
		struct Node2 *newNode2 = new struct Node2;
		std::string newNode2Name = newNode2->hunter->getName();
		while(temp != NULL)
		{
			std::string oldNode2Name = temp->hunter->getName();
			if (oldNode2Name.compare(newNode2Name) != 0)
			{
				if (temp->next != NULL)
					temp = temp->next;
				else//already at the end of the list
					break;
			}
			else
			{
				std::cout<<"Item with the same name already exists"<<std::endl;
				delete newNode2;
				return;
			}

		}
		//no item with the same name
		temp->next = newNode2;
		listSize++;
	}
}

void HunterBook::add(int x)
{
	struct Node2 * temp = header;
	bool flag = false;
	if (listSize == 0)
	{
		//add directly
		struct Node2 *newNode2 = new struct Node2(1);
		header = newNode2;
		listSize++;
	}
	else
	{
		struct Node2 *newNode2 = new struct Node2(1);
		std::string newNode2Name = newNode2->hunter->getName();
		while(temp != NULL)
		{
			std::string oldNode2Name = temp->hunter->getName();
			if (oldNode2Name.compare(newNode2Name) != 0)
			{
				if (temp->next != NULL)
					temp = temp->next;
				else//already at the end of the list
					break;
			}
			else
			{
				std::cout<<"Item with the same name already exists"<<std::endl;
				delete newNode2;
				return;
			}

		}
		//no item with the same name
		temp->next = newNode2;
		listSize++;
	}
}
void HunterBook::externalAdd(Hunter* hp)
{
	struct Node2 * temp = header;
	if (listSize !=0)
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		//no item with the same name
		struct Node2 * newNode2 = new struct Node2(hp);
		temp->next = newNode2;
	}
	else
		header = new struct Node2 (hp);

	listSize++;
	

}


void HunterBook::sort(int s)
{
	struct Node2 *index1, *index2, *index3;
	index3 = header;
	for (index1 = header; index1->next!= NULL; index1= index1->next)
	{
		for (index2 = index1->next; index2 != NULL; index2 = index2 ->next)
		{
			if (s == 0)
			{
				if (index1->hunter->getEnergy() < index2->hunter->getEnergy())
				{
					//
					index3->next = index2;
					index1->next = index2->next;
					index2->next = index1;

				}
			}
			else if (s == 1)
			{
				if (index1->hunter->getHP() < index2->hunter->getHP())
				{
					//
					index3->next = index2;
					index1->next = index2->next;
					index2->next = index1;

				}
			}
			else if (s == 2)
			{
				if (index1->hunter->getAttack() < index2->hunter->getAttack())
				{
					//
					index3->next = index2;
					index1->next = index2->next;
					index2->next = index1;

				}
			}
			else if (s == 3)
			{
				if (index1->hunter->getDefense() < index2->hunter->getDefense())
				{
					//
					index3->next = index2;
					index1->next = index2->next;
					index2->next = index1;

				}
			}
			else
			{}
		}
		if (index1 != header)
			index3 = index3->next;
	}
}



Hunter* HunterBook:: getMax(int s)
{
	int value = 0;
	int tempValue = 0;
	struct Node2 *temp = header;
	Hunter * hunterPointer = NULL;
	while (temp != NULL)
	{
		if (s == 0)//Energy
			 tempValue = temp->hunter->getEnergy();
		else if (s == 1)//HP
			 tempValue = temp->hunter->getHP();
		else if (s == 2)//Attack
			 tempValue = temp->hunter->getAttack();
		else if (s == 3)//Defense
			 tempValue = temp->hunter->getDefense();
		else//corner case
		{
			std::cout<<"error!, wrong input number"<<std::endl;
			return NULL;
		}
		
		if (tempValue > value)
		{				//reassign 
			value = tempValue;
			hunterPointer = temp->hunter;
		}
		//moving forward
		temp = temp->next;
	}
	std::cout<<"Max item found!"<<std::endl;
	std::cout<<hunterPointer->getName()<<std::endl;
	return hunterPointer;


}

void HunterBook:: remove(std::string item)
{
		//search 
	struct Node2 *pointer1 = header;
	struct Node2 *pointer2 = header->next;
	std::cout<<"hunter remove start"<<std::endl;
	if (pointer1 == NULL)
		std::cout<<"the list is empty, nothing to remove"<<std::endl;
	else if (pointer2 == NULL)
	{
		//only one element in the list
		std::string itemName = pointer1->hunter->getName();
		if (itemName.compare(item) == 0)
		{
			delete header;
			listSize --;
			header = NULL;
			return;

		}
		else
		{
			std::cout<<"item not found"<<std::endl;
		}
	}	
	else
	{

		std::string itemName = pointer1->hunter->getName();
		if (itemName.compare(item) == 0)
		{
			header= pointer2;
			delete pointer1;
			listSize --;
			std::cout<<"hunter remove end"<<std::endl;
			return ;
		}

		while (pointer2 !=NULL)
		{
			std::string itemName = pointer2->hunter->getName();
			if (itemName.compare(item) == 0)
			{
				//item found
				pointer1->next = pointer2->next;
				delete pointer2;
				listSize --;
				std::cout<<"hunter remove end"<<std::endl;
				return;

			}
			else
			{
				//item not found
				pointer2 = pointer2->next;
				pointer1 = pointer1->next;
			}
			
		}
		std::cout<<"item not found"<<std::endl;
	} 
}

void HunterBook:: display()
{
		//first display the list 
	struct Node2 *pointer = header;
	if (pointer == NULL)
		std::cout<<"the list is empty"<<std::endl;
	else
	{
		while (pointer!=NULL)
		{
			std::cout<<pointer->hunter->getName()<<", ";
			std::cout<<pointer->hunter->getGender()<<", ";
			std::cout<<"Age: "<<pointer->hunter->getAge()<<std::endl;
			std::cout<<"Attack: "<<pointer->hunter->getAttack()<<std::endl;
			std::cout<<"HP: "<<pointer->hunter->getHP()<<std::endl;
			std::cout<<"Defense: "<<pointer->hunter->getDefense()<<std::endl;
			std::cout<<"X: "<<pointer->hunter->getX()<<std::endl;
			std::cout<<"Y: "<<pointer->hunter->getY()<<std::endl;
			pointer = pointer->next;
		}
	} 
}

void HunterBook:: save()
{
	std::ofstream outputFile;
	//sort(1);//sort elements before save
	outputFile.open(HUNTERBOOKFILE);
	struct Node2 *pointer = header;
	if (pointer == NULL)
		outputFile<<"the list is empty. \n";
	else
	{
		while (pointer!=NULL)
		{
			//outputFile<<pointer->value1<<" "<<pointer->value2<<'\n';
			outputFile<<pointer->hunter->getName()<<", ";
			outputFile<<pointer->hunter->getGender()<<", ";
			outputFile<<pointer->hunter->getAge()<<", ";
			outputFile<<"HP: "<<pointer->hunter->getHP()<<",";
			outputFile<<"Energy: "<<pointer->hunter->getEnergy()<<",";
			outputFile<<"HP: "<<pointer->hunter->getAttack()<<",";
			outputFile<<"Defense: "<<pointer->hunter->getDefense()<<", ";
			outputFile<<"Sword: "<<pointer->hunter->getSword().getName()<<", ";
			outputFile<<"Equipment: "<<pointer->hunter->getEqu().getName()<<'\n';

			pointer = pointer->next;
		}
	} 
	outputFile.close();
	std::cout<<"filed saved!"<<std::endl;
}

void HunterBook:: search(std::string keyword)
{
	struct Node2 *pointer = header;
	if (pointer == NULL)
		std::cout<<"the list is empty"<<std::endl;
	else
	{
		while (pointer!=NULL)
		{
			std::string temp = pointer->hunter->getName();
			if(temp.compare(keyword) == 0)
			{
				std::cout<<"item found!"<<std::endl;
				std::cout<<pointer->hunter->getName()<<", ";
				std::cout<<pointer->hunter->getGender()<<", ";
				std::cout<<"Age: "<<pointer->hunter->getAge()<<", ";
				std::cout<<"Attack: "<<pointer->hunter->getAttack()<<", ";
				std::cout<<"HP: "<<pointer->hunter->getHP()<<", ";
				std::cout<<"Defense: "<<pointer->hunter->getDefense()<<", ";
				std::cout<<"Sword: "<<pointer->hunter->getSword().getName()<<", ";
				std::cout<<"Equipment: "<<pointer->hunter->getEqu().getName()<<std::endl;

				return;
			}
			pointer = pointer->next;

		}
		std::cout<<"Item Not Found"<<std::endl;
	} 
}

Hunter* HunterBook::indexAccess (int index )
{
	if (index >= listSize)
	{
		std::cout<<"index out of range !"<<std::endl;
		return NULL;
	}
	else
	{
		struct Node2 *pointer = header;
		for (int i = 0; i<index; i++)
		{
			pointer = pointer->next;
		}
		return pointer->hunter;
	}
}

int HunterBook::getListSize()
{
	return listSize;
}
//test
/*
int main ()
{
	HunterBook *book = new HunterBook();
	book->add();
	book->add();
	book->add();
	//book->add();
	//book->add();
	
	std::string userIput;
	std::cin>>userIput;
	std::cout<<userIput<<std::endl;
	book->remove(userIput);
	std::cout<<"-----------"<<std::endl;
	book->display();
	book->save();
	//book->search();
	std::string userInput ;
	std::cin>>userInput;
	book->search(userInput);


	book->getMax(1);
}*/