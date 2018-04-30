#include "MyHeader.h"



Monsterbook::Monsterbook()
{
	header = NULL;
	listSize = 0;
}

void Monsterbook::add()
{
	struct Node *newNode = new struct Node;
	std::string input;
	std::cout<<"value1"<<std::endl;
	std::cin>>input;
	newNode->value1 = input;
	std::cout<<"value2"<<std::endl;
	std::cin>>input;
	newNode->value2 = input;
	bool flag = true;
	struct Node *insertPlace = findPosition(newNode,flag);
	//insert
	if (flag == false)
		;
	else
	{
		if ((insertPlace == header)&&(listSize == 0))
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
		listSize++;
		std::cout<<"item added!"<<std::endl;
	}


	Monsterbook::dispaly();
	std::cout<<"---------"<<std::endl;

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
			if (pointer->value1.compare(item) == 0)
			{
				//remove
				if (listSize == 1)
				{
					delete header;
					header = NULL;
					listSize --;
					break;
				}
				else if (pointer->next == NULL)
				{
					//last item
					struct Node *temp = pointer->previous;
					delete pointer;
					temp->next = NULL;
					listSize --;
					break;
				}
				else if(pointer->previous == NULL)
				{
					//first item 
					header = pointer->next;
					pointer->next->previous = NULL;
					delete pointer;
					listSize --;
					break;

				}
				else
				{
					pointer->next->previous = pointer->previous;
					pointer->previous->next = pointer->next;
					delete pointer;
					listSize --;
					break;
				}

			}
			else
				pointer = pointer->next;
		}
	} 

}


void Monsterbook::dispaly()
{
	//first display the list 
	struct Node *pointer = header;
	if (pointer == NULL)
		std::cout<<"the list is empty"<<std::endl;
	else
	{
		while (pointer!=NULL)
		{
			std::cout<<pointer->value1<<" "<<pointer->value2<<std::endl;
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
			std::string temp = pointer->value1;
			if(temp.compare(keyword) == 0)
			{
				std::cout<<"item found!"<<std::endl;
				std::cout<<pointer->value1<<" "<<pointer->value2<<std::endl;
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
	outputFile.open(OUTPUTFILE);
	struct Node *pointer = header;
	if (pointer == NULL)
		outputFile<<"the list is empty. \n";
	else
	{
		while (pointer!=NULL)
		{
			outputFile<<pointer->value1<<" "<<pointer->value2<<'\n';
			pointer = pointer->next;
		}
	} 
	outputFile.close();
	std::cout<<"filed saved!"<<std::endl;

}
Node* Monsterbook::findPosition(struct Node * item, bool& flag)
{
	struct Node * temp = header;
	std::string inputValue = item->value1 + item->value2;
	std::cout<<"new node value:"<<inputValue<<std::endl;

	if (listSize == 0)
		//no element in the list
		return header;
	while (temp != NULL)
	{
		std::string nodeValue = temp->value1 + temp->value2;
		std::cout<<"previous node value: "<<nodeValue<<std::endl;
		int result = nodeValue.compare(inputValue);
		std::cout<<"compare results: "<<result<<std::endl;
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
	book->dispaly();
	book->save();
	//book->search();
	std::string userInput ;
	std::cin>>userInput;
	book->search(userInput);

}