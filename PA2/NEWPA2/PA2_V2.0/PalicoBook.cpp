#include "MyHeader.h"

int sortingIndicator = 1;
PalicoBook::PalicoBook()
{
	listSize = 0;

}


void PalicoBook::add()
{
	cleanHeap();
	Palico *palico = new Palico ();
	std::vector <Palico*>::iterator it;
	for (it = rawInput.begin(); it != rawInput.end(); it++)
	{
		std::string name = (*it)->getName();
		if(name.compare(palico->getName()) == 0)
		{
			std::cout<<"item already exists, error"<<std::endl;
			return;
		}
	}
	rawInput.push_back(palico);
	listSize ++;
	for (int i = 0; i<rawInput.size(); i++)
	{
		palicoQueue.push(rawInput.at(i));
	}

	
}

void PalicoBook::add(int x)
{
		cleanHeap();
	Palico *palico = new Palico (1);
	std::vector <Palico*>::iterator it;
	for (it = rawInput.begin(); it != rawInput.end(); it++)
	{
		std::string name = (*it)->getName();
		if(name.compare(palico->getName()) == 0)
		{
			std::cout<<"item already exists, error"<<std::endl;
			return;
		}
	}
	rawInput.push_back(palico);
	listSize ++;
	for (int i = 0; i<rawInput.size(); i++)
	{
		palicoQueue.push(rawInput.at(i));
	}

}

void PalicoBook::externalAdd(Palico * p)
{
	cleanHeap();
	Palico *palico = p;
	std::vector <Palico*>::iterator it;
	for (it = rawInput.begin(); it != rawInput.end(); it++)
	{
		std::string name = (*it)->getName();
		if(name.compare(palico->getName()) == 0)
		{
			std::cout<<"item already exists, error"<<std::endl;
			return;
		}
	}
	rawInput.push_back(palico);
	listSize ++;
	for (int i = 0; i<rawInput.size(); i++)
	{
		palicoQueue.push(rawInput.at(i));
	}
}



void PalicoBook::changeMode(int Indicator)
{
	if (Indicator == sortingIndicator)
		return;
	else if (Indicator == 0)
	{
		//change to max heap of hp 
		sortingIndicator = Indicator;
		cleanHeap();
		for (int i = 0; i<rawInput.size(); i++)
		{
			palicoQueue.push(rawInput.at(i));
		}
		return;
	}
	else
	{
		//change to max heap of attack
		sortingIndicator = Indicator;
		cleanHeap();
		for (int i = 0; i<rawInput.size(); i++)
		{
			palicoQueue.push(rawInput.at(i));
		}
		return;
	}
}



Palico* PalicoBook::max(int Indicator )
{
	if (Indicator == sortingIndicator)
	{
		;
	}
	else if (Indicator == 1)
	{
		//change to max heap of hp 
		changeMode(1);
		sortingIndicator = Indicator;
	}
	else
	{
		//change to max heap of attack
		changeMode(0);
		sortingIndicator = Indicator;
		
	}

		return palicoQueue.top();
}


void PalicoBook::remove(std::string userInput)
{
	std::cout<<"palico remove start"<<std::endl;
	for (int i = 0; i <rawInput.size(); i++)
	{
		//std::cout<<rawInput.at(3)->getName()<<std::endl;
		if (userInput.compare(rawInput.at(i)->getName()) == 0)
		{
			rawInput.erase(rawInput.begin() + i);
			listSize--;
			cleanHeap();
			for (int i = 0; i<rawInput.size(); i++)
			{
				palicoQueue.push(rawInput.at(i));
			}
			std::cout<<"palico remove end"<<std::endl;
			return;
		}
	}
	std::cout<<"Item not found! "<<std::endl;

}


void PalicoBook::search(std::string userInput)
{
	for (int i = 0; i < rawInput.size(); i++)
	{
		if (userInput.compare(rawInput.at(i)->getName()) == 0)
		{
			std::cout<<rawInput.at(i)->getName()<<", ";
			std::cout<<rawInput.at(i)->getGender()<<", ";
			std::cout<<rawInput.at(i)->getAge()<<", ";
			std::cout<<rawInput.at(i)->getAttack()<<", ";
			std::cout<<rawInput.at(i)->getSword().getName()<<std::endl;

		}
	}
}


void PalicoBook::save()
{
	std::ofstream outputFile;
	outputFile.open(PALICOBOOKFILE);
	if (rawInput.size() == 0)
	{
		outputFile<<"the list is empty. \n";
		return ;
	}
	else
	{
		for (int i = 0; i<rawInput.size(); i++)
		{
			//outputFile<<pointer->value1<<" "<<pointer->value2<<'\n';
			outputFile<<rawInput.at(i)->getName()<<", ";
			outputFile<<rawInput.at(i)->getGender()<<", ";
			outputFile<<rawInput.at(i)->getAge()<<", ";;
			outputFile<<"HP: "<<rawInput.at(i)->getAttack()<<", ";
			outputFile<<"Sword: "<<rawInput.at(i)->getSword().getAttack()<<"\n";
		}
	} 
	outputFile.close();
	std::cout<<"file saved!"<<std::endl;
}

void PalicoBook::cleanHeap()
{
	while (palicoQueue.size() != 0)
	{
		palicoQueue.pop();
	}
}
void PalicoBook::display()
{
	std::cout<<"size of the max heap: " <<palicoQueue.size()<<std::endl;
	std::cout<<"displayed in a descending order"<<std::endl;
	while (palicoQueue.size() != 0)
	{
		std::cout<<palicoQueue.top()->getName()<<std::endl;
		palicoQueue.pop();
	}

	//for (auto i : palicoQueue) std::cout << i << ' ';

}


Palico* PalicoBook::indexAccess(int index)
{
	std::priority_queue <Palico*, std::vector<Palico*>, compare >  tempQue = palicoQueue;
	if (index < listSize)
	{
		for (int i = 0; i<index; i++)
			tempQue.pop();
		return tempQue.top();
	}
	else
		return NULL;

}

int PalicoBook::getListSize()
{
	return listSize;
}


bool compare::operator() (  Palico* lhs,   Palico* rhs) 
{
	if (sortingIndicator == 0)
	{
		//compare HP
		//if(lhs->getHP() < rhs->getHP()) 
		if(lhs->getAge() < rhs->getAge()) 
			return true;
   		else 
   			return false;

	}
	else
	{
		//compare attack
		//
		if(lhs->getAttack() < rhs->getAttack()) 
			return true;
   		else 
   			return false;
	}
}

//test
/*
int main()
{
	PalicoBook *pb = new PalicoBook();
	pb->add();
	pb->add();
	pb->add();
	pb->add();
	std::string name = pb->indexAccess(1)->getName();
	pb->remove(name);
	pb->display();
}
*/