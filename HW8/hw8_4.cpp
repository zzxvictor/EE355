#include <iostream>
#include <iomanip>
using namespace std;
#define ROW 3
#define COL 4

int main()
{
	int **array = new int * [ROW];
	for(int i = 0; i<ROW; i++)
	{
		array[i] = new int [COL];
	}
	// assign
	for(int i = 0; i<ROW; i++)
	{
		for(int j = 0; j<COL; j++)
		{
			array[i][j] = j+65;
		}
	}
	//display
	for(int i = 0; i<ROW; i++)
	{
		for(int j = 0; j<COL; j++)
		{
			cout<<setw(5)<<array[i][j];
		}
		cout<<endl;
	}
}