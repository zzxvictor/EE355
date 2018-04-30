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
		std::string newNode2Name = newNode2->hunter.getName();
		while(temp != NULL)
		{
			std::string oldNode2Name = temp->hunter.getName();
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

	}
}

int HunterBook::size()
{
	std::cout<<"number of hunters in the list: "<<listSize<<std::endl;
	return listSize;
}
void HunterBook::sort(int s)
{}

Hunter* HunterBook:: getMax(int s)
{}

void HunterBook:: remove(std::string item)
{
		//search 
	struct Node2 *pointer1 = header;
	struct Node2 *pointer2 = header->next;
	if (pointer1 == NULL)
		std::cout<<"the list is empty, nothing to remove"<<std::endl;
	else if (pointer2 == NULL)
	{
		//only one element in the list
		std::string itemName = pointer1->hunter.getName();
		if (itemName.compare(item) == 0)
		{
			delete header;
			listSize --;
			std::cout<<"item deleted"<<std::endl;
			header = NULL;

		}
		else
		{
			std::cout<<"item not found"<<std::endl;
		}
	}	
	else
	{

		std::string itemName = pointer1->hunter.getName();
		if (itemName.compare(item) == 0)
		{
			header= pointer2;
			delete pointer1;
			listSize --;
			std::cout<<"item deleted"<<std::endl;
			return ;
		}

		while (pointer2 !=NULL)
		{
			std::string itemName = pointer2->hunter.getName();
			std::cout<<"itemName: "<<itemName<<std::endl;
			if (itemName.compare(item) == 0)
			{
				//item found
				std::cout<<itemName.compare(item)<<std::endl;
				pointer1->next = pointer2->next;
				delete pointer2;
				listSize --;
				std::cout<<"item deleted"<<std::endl;
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

void HunterBook:: dispaly()
{
		//first display the list 
	struct Node2 *pointer = header;
	if (pointer == NULL)
		std::cout<<"the list is empty"<<std::endl;
	else
	{
		while (pointer!=NULL)
		{
			std::cout<<pointer->hunter.getName()<<", ";
			std::cout<<pointer->hunter.getGender()<<", ";
			std::cout<<"Age: "<<pointer->hunter.getAge()<<std::endl;
			std::cout<<"Attack: "<<pointer->hunter.getAttack()<<std::endl;
			std::cout<<"HP: "<<pointer->hunter.getHP()<<std::endl;
			std::cout<<"Defense: "<<pointer->hunter.getDefense()<<std::endl;
			
			pointer = pointer->next;
		}
	} 
}

void HunterBook:: save()
{
	std::ofstream outputFile;
	outputFile.open(HUNTERBOOKFILE);
	struct Node2 *pointer = header;
	if (pointer == NULL)
		outputFile<<"the list is empty. \n";
	else
	{
		while (pointer!=NULL)
		{
			//outputFile<<pointer->value1<<" "<<pointer->value2<<'\n';
			outputFile<<pointer->hunter.getName()<<", ";
			outputFile<<pointer->hunter.getGender()<<", ";
			outputFile<<pointer->hunter.getAge()<<", ";;
			outputFile<<"Energy: "<<pointer->hunter.getEnergy()<<",";
			outputFile<<"HP: "<<pointer->hunter.getAttack()<<",";
			outputFile<<"Defense: "<<pointer->hunter.getDefense()<<'\n';
			

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
			std::string temp = pointer->hunter.getName();
			if(temp.compare(keyword) == 0)
			{
				std::cout<<"item found!"<<std::endl;
				std::cout<<pointer->hunter.getName()<<", ";
				std::cout<<pointer->hunter.getGender()<<", ";
				std::cout<<"Age: "<<pointer->hunter.getAge()<<std::endl;
				std::cout<<"Attack: "<<pointer->hunter.getAttack()<<std::endl;
				std::cout<<"HP: "<<pointer->hunter.getHP()<<std::endl;
				std::cout<<"Defense: "<<pointer->hunter.getDefense()<<std::endl;
				return;
			}
			pointer = pointer->next;

		}
		std::cout<<"Item Not Found"<<std::endl;
	} 
}


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
	book->dispaly();
	book->save();
	//book->search();
	std::string userInput ;
	std::cin>>userInput;
	book->search(userInput);

}