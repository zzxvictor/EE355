#include "MyHeader.h"

#define HUNTERNUM 10
#define MONSTERNUM 10
#define PALICONUM 10
#define DIMENSION 2

int main()
{
	//create  objects 
	srand(time(0));
	int autoGenerate = 0;
	std::cout<<"Auto-generate the names and ages? 0 for yes, 1 for no"<<std::endl;
	std::cin>>autoGenerate;
	if ((std::cin.fail())||((autoGenerate != 1)&&(autoGenerate != 0)))
	{
		std::cout<<"input error, session aborted"<<std::endl;
		return 0;
	}

	HunterBook *hb = new HunterBook();
	Monsterbook *mb = new Monsterbook();
	PalicoBook *pb = new PalicoBook();
	ChampionBook *cb = new ChampionBook();

	//add 3 Hunters
	if (autoGenerate == 0)
	{
		int x = 1;
		for (int i = 0; i < HUNTERNUM; i++)
			hb->add(x);
		for (int i = 0; i < MONSTERNUM; i++)
			mb->add(x);
		for (int i = 0; i < PALICONUM; i++)
			pb->add(x);
	}
	else 
	{
		for (int i = 0; i < HUNTERNUM; i++)
			hb->add();
		for (int i = 0; i < MONSTERNUM; i++)
			mb->add();
		for (int i = 0; i < PALICONUM; i++)
			pb->add();
	}
	hb->display();
	mb->display();
	pb->display();

	std::cout<<"----------------"<<std::endl;
	run(hb,mb,pb,cb);
	std::cout<<"----------------"<<std::endl;

}
														


