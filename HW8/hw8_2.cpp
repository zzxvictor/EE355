#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	string output ;
	char add; 
	while(1)
	{
		add = getchar();
		if((add>=48)&&(add<=57))
			output += add;
		else if (add == '\n')
			break;
		else
			;
		
	}
	cout<<output<<endl;
	
	
	
}