#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

void displayMatrix(int** array, int size);
void randomAssignValue(int** array, int size);
int findMaxi(int a1, int a2, int a3, int a4);
void autoSelect(int** oriArray, int ** newArray, int size);

int main()
{
	int n = 0;
	//input from user
	do
	{
		cout<<"Please Define N of a N x N matrix (must be an even number): "<<endl;
		cin>>n;
		if(cin.fail())
		{
			cout<<"input error, program terminated"<<endl;
			return 0;
		}
		if((n>0)&&(n%2 == 0))
			break;
	}while(1);

	cout<<"N = "<<n<<endl;

	//dynamically allocate two arraies

	//N x N matrix
	int ** origMatrix = new int* [n];
	for(int i = 0; i<n; i++)
	{
		origMatrix[i] = new int[n];
	}
	//N/2 x N/2 matrix
	int ** newMatrix = new int*[n/2];
	for(int i = 0; i<n/2; i++)
	{
		newMatrix[i] = new int[n/2];
	}
	randomAssignValue(origMatrix, n);
	displayMatrix(origMatrix,n);

	autoSelect(origMatrix,newMatrix,n);
	displayMatrix(newMatrix,n/2);
}

void randomAssignValue(int** array, int size)
{
	
	for(int i = 0; i<size; i++)
	{
		for(int j=0; j<size; j++)
		{
			array[i][j] = rand()%20;
		}
		
	}
}
void displayMatrix(int** array, int size)
{
	for(int i = 0; i<size; i++)
	{
		for(int j=0; j<size; j++)
		{
			cout<<setw(3)<<array[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
}
void autoSelect(int** oriArray, int ** newArray, int size)
{
	int d = size/2;
	for(int i = 0; i<d; i++)
	{
		for(int j = 0; j<d; j++)
		{
			newArray[i][j] = findMaxi(oriArray[2*i][2*j],oriArray[2*i][2*j+1],oriArray[2*i+1][2*j],oriArray[2*i+1][2*j+1]);
		}
	}
}

int findMaxi(int a1, int a2, int a3, int a4)
{
	int data[4] = {a1,a2,a3,a4};
	int max = data[0];
	for(int i =0; i<3; i++)
	{
		for(int j=i+1; j<4; j++)
		{
			if(max<data[j])
				max = data[j];
		}
	}
	return max;

}