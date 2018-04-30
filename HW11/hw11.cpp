#include <iostream>
using namespace std;

class baseClass
{
	private:
		int baseAttribute1;
		string baseAttribute2;
	public :
		baseClass(int a, string b):baseAttribute1(a),baseAttribute2(b)
		{
			baseAttribute1 = a;
			baseAttribute2 = b;
		}
		void printBase()
		{
			cout<<"baseAttribute1: "<<baseAttribute1<<endl;
			cout<<"baseAttribute2: "<<baseAttribute2<<endl; 
		}
};


class derivedClass : public baseClass
{
	private:
		int derivedAttribute1;
		string derivedAttribute2;
	public:
		derivedClass(int a, string b):baseClass(a,b)
		{
			derivedAttribute1 = 1;
			derivedAttribute2 = "derived";
		}
		void printDerive()
		{
			cout<<"derivedAttribute1: "<<derivedAttribute1<<endl;
			cout<<"derivedAttribute2: "<<derivedAttribute2<<endl; 
			printBase();
		}
};


int main()
{
	derivedClass*d = new derivedClass (0,"base");
	d->printDerive();
}