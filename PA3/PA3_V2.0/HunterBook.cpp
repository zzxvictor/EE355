#include "MyHeader.h"

HunterBook::HunterBook()
{

}
bool compare0 (Hunter* h1, Hunter* h2)
{
	if (h1->getEnergy() < h2->getEnergy())
		return true;
	else
		return false;
}
bool compare1 (Hunter* h1, Hunter* h2)
{
	if (h1->getHP() < h2->getHP())
		return true;
	else
		return false;
}

bool compare2 (Hunter* h1, Hunter* h2)
{
	if (h1->getAttack() < h2->getAttack())
		return true;
	else
		return false;
}

bool compare3 (Hunter* h1, Hunter* h2)
{
	if (h1->getDefense() < h2->getDefense())
		return true;
	else
		return false;
}

bool compare4 (Hunter* h1, Hunter* h2)
{
	if (h1->getAge() < h2->getAge())
		return true;
	else
		return false;
}

bool checkName(Hunter* h1, Hunter* h2)
{
	if (h1->getName() == h2->getName())
		return true;
	else
		return false;
}


void HunterBook::add()
{
	Hunter * p = new Hunter();
	hb.push_front(p);
}


void HunterBook::add(int x)
{
	Hunter * p = new Hunter(1);
	hb.push_front(p);
	hb.unique(checkName);
}


void HunterBook::externalAdd(Hunter* hp)
{
	Hunter * p = hp;
	hb.push_front(p);
	hb.unique(checkName);
}


void HunterBook::sort(int s)
{
	if (s == 0)
	{
		hb.sort(compare0);
	}
	else if (s == 1)
	{
		hb.sort(compare1);
	}
	else if (s == 2)
	{
		hb.sort(compare2);
	}
	else if (s == 3)
	{
		hb.sort(compare3);
	}
	else
	{
		hb.sort(compare4);
	}

}

Hunter * HunterBook::getMax(int s)
{
	if (s == 0)
	{
		int max = 0; 
		Hunter* temp = NULL;
		for (auto it = hb.begin(); it != hb.end(); ++it)
		{
			if (max < (*it)->getEnergy())
			{
				max = (*it)->getEnergy();
				temp = (*it);
			}
		} 
		return temp;
	}
	else if (s == 1)
	{
		int max = 0; 
		Hunter* temp = NULL;
		for (auto it = hb.begin(); it != hb.end(); ++it)
		{
			if (max < (*it)->getHP())
			{
				max = (*it)->getHP();
				temp = (*it);
			}
		} 
		return temp;
	}
	else if (s == 2)
	{
		int max = 0; 
		Hunter* temp = NULL;
		for (auto it = hb.begin(); it != hb.end(); ++it)
		{
			if (max < (*it)->getAttack())
			{
				max = (*it)->getAttack();
				temp = (*it);
			}
		} 
		return temp;
	}
	else if (s == 3)
	{
		int max = 0; 
		Hunter* temp = NULL;
		for (auto it = hb.begin(); it != hb.end(); ++it)
		{
			if (max < (*it)->getDefense())
			{
				max = (*it)->getDefense();
				temp = (*it);
			}
		} 
		return temp;
	}
	else
	{
		//corner case, get the oldest one
		int max = 0; 
		Hunter* temp = NULL;
		for (auto it = hb.begin(); it != hb.end(); ++it)
		{
			if (max < (*it)->getAge())
			{
				max = (*it)->getAge();
				temp = (*it);
			}
		} 
		return temp;
	}

	
}


Hunter * HunterBook::indexAccess (int index )
{
	if ((index >= getListSize())||(index < 0))
		return NULL;
	else
	{
		int counter = 0;
		for (auto it = hb.begin(); it != hb.end(); ++it)
		{
			if (counter == index)
			{
				return *it;
			}
			counter ++;
		}
	}
}


void HunterBook::remove(std::string keyword)
{
	Hunter * temp = search (keyword,1);
	if (temp != NULL)
	{
		hb.remove(temp);
	}
	
}


void HunterBook::display()
{
	for (auto it = hb.begin(); it != hb.end(); ++it)
	{
		std::cout<<((*it)->getName())<<", ";
		std::cout<<((*it)->getAge())<<std::endl;
	}
}
void HunterBook::save()
{
	std::ofstream outputFile;
	//sort(1);//sort elements before save
	sort(4);
	outputFile.open(HUNTERBOOKFILE);
	if (getListSize() == 0)
		outputFile<<"the list is empty. \n";
	else
	{
		for (auto it = hb.begin(); it != hb.end(); ++it)
		{	//outputFile<<pointer->value1<<" "<<pointer->value2<<'\n';
			outputFile<<(*it)->getName()<<", ";
			outputFile<<(*it)->getGender()<<", ";
			outputFile<<(*it)->getAge()<<", ";
			outputFile<<"HP: "<<(*it)->getHP()<<",";
			outputFile<<"Energy: "<<(*it)->getEnergy()<<",";
			outputFile<<"HP: "<<(*it)->getAttack()<<",";
			outputFile<<"Defense: "<<(*it)->getDefense()<<", ";
			outputFile<<"Sword: "<<(*it)->getSword().getName()<<", ";
			outputFile<<"Equipment: "<<(*it)->getEqu().getName()<<'\n';
		}
		
	} 
	outputFile.close();
	std::cout<<"filed saved!"<<std::endl;
}
void HunterBook::search(std::string keyword)
{
	for (auto it = hb.begin(); it != hb.end(); ++it)
	{
		std::string name = (*it)->getName() ; 
		if (name.compare(keyword) == 0)
		{
			std::cout<<"Name: "<<(*it)->getName()<<", ";
			std::cout<<"Energy: "<<(*it)->getEnergy()<<", ";
			std::cout<<"Age: "<<(*it)->getAge()<<", ";
			std::cout<<"Gender: "<<(*it)->getGender()<<", ";
			std::cout<<"Attack: "<<(*it)->getAttack()<<", ";
			std::cout<<"Defense: "<<(*it)->getDefense()<<", ";
			std::cout<<"Sword: "<<(*it)->getSword().getName()<<", ";
			std::cout<<"Equipement: "<<(*it)->getEqu().getName()<<std::endl;
			return;
		}
	}
	std::cout<<"search failure: item not found,"<<std::endl;
}

Hunter * HunterBook::search(std::string keyword, int x)
{
	for (auto it = hb.begin(); it != hb.end(); ++it)
	{
		std::string name = (*it)->getName() ; 
		if (name.compare(keyword) == 0)
		{
			return *it;
		}
	}
	std::cout<<"search failure: item not found,"<<std::endl;
	return NULL;
}


int HunterBook::getListSize()
{
	int counter = 0;
	for (auto it = hb.begin(); it != hb.end(); ++it)
	{
		counter++;
	}
	return counter;
}
/*
int main ()
{
	srand(time(0));
	HunterBook *hb = new HunterBook();
	for (int i = 0; i<10; i++)
		hb->add(1);
	for (int i = 0; i< 10; i++)
	{
		Hunter *p = new Hunter (1);
		hb->externalAdd(p);
	}

	hb->display();
	hb->sort(4);
	std::cout<<"-----------"<<std::endl;
	hb->display();
	std::cout<<"numbers of hunters: "<<hb->getListSize()<<std::endl;
	Hunter * max = hb->getMax(4);
	std::cout<<"oldest guy "<<max->getName()<<std::endl;
	hb->search(max->getName());
	hb->remove(max->getName());
	std::cout<<"-----------"<<std::endl;
	hb->display();
	std::cout<<"numbers of hunters: "<<hb->getListSize()<<std::endl;
	std::cout<<hb->indexAccess(5)->getName();
	hb->save();
}*/