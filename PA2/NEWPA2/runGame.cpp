#include "MyHeader.h"

void run (HunterBook * hb, Monsterbook *mb, PalicoBook *pb, ChampionBook *cb)
{
	GUI* gui = new GUI();
	bool gameFlag = true;
	while (1)
	{
		//check if game is over
		gameFlag = checkGame(hb, mb, pb, cb);
		if (gameFlag == false)
			break;
		//display 
		gui->display(hb,mb,pb,cb);
		//merge hunter and palico 
		mergeHunterPalico(hb, pb,cb);

		runFight(hb,mb,pb,cb);
		//move the rest around 
		moveAround(hb,mb,pb,cb);
	}

	cb->save(hb,pb);
	hb->save();
	mb->save();
	pb->save();

}



bool checkGame(HunterBook * hb, Monsterbook *mb, PalicoBook *pb, ChampionBook *cb)
{

	if (mb->getListSize() == 0) 
	{
		std::cout<<"Game is over, all monsters are dead "<<std::endl;
		return false;
	}
	if ((hb->getListSize() == 0)&&(cb->getListSize() == 0))
	{
		std::cout<<"Game is over, all hunters are dead "<<std::endl;
		return false;
	}

	return true;
}

void mergeHunterPalico(HunterBook * hb, PalicoBook *pb, ChampionBook *cb)
{

	if (pb->getListSize() == 0)
	{
		return ;
	}
	else
	{
		//search 
		for (int i = 0; i<hb->getListSize(); i++)
		{
			for (int j = 0; j<pb->getListSize(); j++)
			{
				int hX = hb->indexAccess(i)->getX();
				int hY = hb->indexAccess(i)->getY();
				int pX = pb->indexAccess(j)->getX();
				int pY = pb->indexAccess(j)->getY();

				if ((hX == pX)&&(hY == pY))
				{
					//test
					std::cout<<"Champion formed"<<std::endl;
					Champion * cp = new Champion(hb->indexAccess(i), pb->indexAccess(j));
					cb->add(cp);
					std::string hunterName = hb->indexAccess(i)->getName();
					hb->remove(hunterName);
					//form into a new class
					std::string palicoName = pb->indexAccess(j)->getName();
					pb->remove(palicoName);
					//remove from previous classes
					return;

				}
			}
		}
	}
}

void runFight(HunterBook * hb, Monsterbook *mb, PalicoBook *pb, ChampionBook *cb)
{
	
	hunterFightMonster(hb, mb);
	
	palicoFightMonster(pb, mb);

	ChampionFightMonster(cb, mb);

}

void moveAround(HunterBook * hb, Monsterbook *mb, PalicoBook *pb, ChampionBook *cb)
{
	
	int size = hb->getListSize();
	for (int i =0; i< size; i ++)
	{
		int addX = rand()%3 - 1;
		int addY = rand()%3 - 1;
		hb->indexAccess(i)->setXY(addX,addY);
	}
	size = mb->getListSize();
	for (int i =0; i< size; i ++)
	{
		int addX = rand()%3 - 1;
		int addY = rand()%3 - 1;
		mb->indexAccess(i)->setXY(addX,addY);
	}
	size = pb->getListSize();
	for (int i =0; i< size; i ++)
	{
		int addX = rand()%3 - 1;
		int addY = rand()%3 - 1;
		pb->indexAccess(i)->setXY(addX,addY);
	}

	size = cb->getListSize();
	for (int i =0; i< size; i ++)
	{
		int addX = rand()%3 - 1;
		int addY = rand()%3 - 1;
		cb->indexAccess(i)->setXY(addX,addY);
	}

}


void hunterFightMonster(HunterBook * hb, Monsterbook *mb)
{
	if ((hb->getListSize() == 0 )||(mb->getListSize() == 0))
		return;
	else
	{
		for (int i = 0; i<hb->getListSize(); i++)
		{
			for (int j = 0; j<mb->getListSize(); j++)
			{
				int hX = hb->indexAccess(i)->getX();
				int hY = hb->indexAccess(i)->getY();
				int mX = mb->indexAccess(j)->getX();
				int mY = mb->indexAccess(j)->getY();

				if ((hX == mX)&&(hY == mY))
				{
					//test
					while (1)
					{
						int coin = rand()%20;
						if (coin > 10)
						{
							//hunter attacks monster
							hb->indexAccess(i)->AttackMonsters(mb->indexAccess(j)); 
						}
						else
						{
							//monster attacks hunter
							hb->indexAccess(i)->DefendMonsters(mb->indexAccess(j)); 
						}

						if (hb->indexAccess(i)->getHP() < 0)
						{
							std::string name = hb->indexAccess(i)->getName();
							hb->remove(name);
							return;
						}
						if(mb->indexAccess(j)->getHP() < 0)
						{
							std::string name = mb->indexAccess(j)->getName();
							mb->remove(name);
							return;
						}

					}
					//remove from previous classes

				}
			}
		}
	}
}
void palicoFightMonster(PalicoBook *pb, Monsterbook *mb)
{
	if ((pb->getListSize() == 0 )||(mb->getListSize() == 0))
		return;
	else
	{
		for (int i = 0; i<pb->getListSize(); i++)
		{
			for (int j = 0; j<mb->getListSize(); j++)
			{
				int pX = pb->indexAccess(i)->getX();
				int pY = pb->indexAccess(i)->getY();
				int mX = mb->indexAccess(j)->getX();
				int mY = mb->indexAccess(j)->getY();

				if ((pX == mX)&&(pY == mY))
				{
					//test
					
					//remove from previous classes
					while (1)
					{
						int coin = rand()%20;
						if (coin >10)
						{
							//hunter attacks monster
							pb->indexAccess(i)->AttackMonsters(mb->indexAccess(j)); 
						}
						else
						{
							//monster attacks hunter
							mb->indexAccess(j)->AttackPalico(pb->indexAccess(i)); 
						}

						if (pb->indexAccess(i)->getHP() < 0)
						{
							std::string palicoName = pb->indexAccess(i)->getName();

							pb->remove(palicoName);
							return;
						}
						if(mb->indexAccess(j)->getHP() < 0)
						{
							std::string name = mb->indexAccess(j)->getName();
							mb->remove(name);
							return;
						}

					}

				}
			}
		}
	}
}
void ChampionFightMonster(ChampionBook *cb, Monsterbook *mb)
{
	if ((cb->getListSize() == 0 )||(mb->getListSize() == 0))
		return;
	else
	{
		for (int i = 0; i<cb->getListSize(); i++)
		{
			for (int j = 0; j<mb->getListSize(); j++)
			{
				int cX = cb->indexAccess(i)->getX();
				int cY = cb->indexAccess(i)->getY();
				int mX = mb->indexAccess(j)->getX();
				int mY = mb->indexAccess(j)->getY();

				if ((cX == mX)&&(cY == mY))
				{
					while (1)
					{
						int coin = rand()%20;
						if (coin > 10)
						{
							//hunter attacks monster
							if (cb->indexAccess(i)->getHunter()->getHP()>0)
								cb->indexAccess(i)->getHunter()->AttackMonsters(mb->indexAccess(j));
							if (cb->indexAccess(i)->getHunter()->getHP()>0)
								cb->indexAccess(i)->getPalico()->AttackMonsters(mb->indexAccess(j));
						}
						else
						{
							//monster attacks hunter
							int coin2 = rand()%20;
							if (coin2 > 10)
								mb->indexAccess(j)->AttackPalico(cb->indexAccess(i)->getPalico()); 
							else
							{
								if (cb->indexAccess(i)->getHunter()->getHP()>0)
									cb->indexAccess(i)->getHunter()->DefendMonsters(mb->indexAccess(j));
							}
								
							
						}

						if ((cb->indexAccess(i)->getHunter()->getHP()<0)&&(cb->indexAccess(i)->getHunter()->getHP()<0))
						{
							std::string name = cb->indexAccess(i)->getHunter()->getName();
							cb->remove(name);
							return;
						}
						if(mb->indexAccess(j)->getHP() < 0)
						{
							std::string name = mb->indexAccess(j)->getName();
							mb->remove(name);
							return;
						}

					}

				}
			}
		}
	}
}