#include "MyHeader.h"
using namespace std;
int main ()
{
	srand((unsigned)time(0)); 
	Monster connie;
	cout<<connie.getHP()<<endl;
	cout<<connie.getName()<<endl;

	Monster me;
	cout<<me.getHP()<<endl;
	cout<<me.getName()<<endl;

	Palico Connie2;
	cout<<Connie2.getAttack()<<endl;
	cout<<Connie2.getName()<<endl;

	Hunter Victor;
	cout<<Victor.getAttack()<<endl;
	cout<<Victor.getDefense()<<endl;
	cout<<Victor.getName()<<endl;

	Hunter *vic = new Hunter();
	me.attackHunter(vic);
}
