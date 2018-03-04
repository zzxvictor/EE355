#include <iostream>

using namespace std;

int main()
{ 
	int balance=100;
	int target=1000;
	float rate = 0.1;
	int year = 0;
	do
	{
		float interest = balance * rate;
		balance = balance + interest;
		year++;
	} while ( balance >= target );
	cout << year << "No. of years to achieve target balance.\n";
	return 0;
}
