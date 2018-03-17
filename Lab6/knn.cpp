#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

#define FILE "dataSet.txt"
#define RATIO 0.8
#define DIMENSION 2


int countLine(string fileName);
void readData(int** train, int** test, string fileName,int& trainSize, int& testSize);
void displayMatrix(int** array, int xSize, int ySize);

int main()
{
	int ** testSet;
	int ** trainSet;
	int trainSize, testSize; 
	//read data
	readData(trainSet,testSet,FILE,trainSize,testSize);
	//display
	cout<<"train size: "<<trainSize<<" test size: "<<testSize<<endl;
	cout<<"training set:";
	displayMatrix(trainSet, trainSize,DIMENSION);
	cout<<"test set:";
	displayMatrix(testSet, testSize,DIMENSION);
	//process it
}


int countLine(string fileName)
{
	string line;
	int counter = 0;
    ifstream myfile(fileName.c_str());   
    while(getline(myfile,line))
    	counter++;
    myfile.close();
    return counter;
}

void readData(int** train, int** test, string fileName,int& trainSize, int& testSize)
{
	int lineNum = countLine(fileName);
	cout<<"data size: "<<lineNum<<endl;
	//open the file for reading 
	ifstream myfile(fileName.c_str());  
	//determine sizes
	trainSize = lineNum * RATIO;
	testSize = lineNum - trainSize;
	//dynamic allocation 
	train = new int * [trainSize];
	test = new int * [testSize];
	for(int i = 0; i < trainSize; ++i) 
	{
    	train[i] = new int[DIMENSION];
	}
	for(int i = 0; i < testSize; ++i) 
	{
    	test[i] = new int[DIMENSION];
	}

	//reading 
	for(int i = 0; i < trainSize; ++i) 
	{
    	myfile>>train[i][0]>>train[i][1];
	}

	for(int i = 0; i < testSize; ++i) 
	{
    	myfile>>test[i][0]>>test[i][1];
	}
	myfile.close();

}

void displayMatrix(int** array, int xSize, int ySize)
{
	cout<<endl;
	for(int i = 0; i<xSize; i++)
	{
		for(int j=0; j<ySize; j++)
		{
			cout<<setw(5)<<array[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
}