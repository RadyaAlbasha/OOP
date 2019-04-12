#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<graphics.h>
#include<dos.h>

class Base
{

	public:
		Base()
		{
		   //	cout<<"Base class"<<endl;
		}
		~Base()
		{}
		void Print()
		{
			cout<<"iam Base class"<<endl;
		}

};

class Derived:public Base
{

	public:
		Derived()
		{
		   //	cout<<"Base class"<<endl;
		}
		~Derived()
		{}
		void Print()
		{
			cout<<"iam Derived class"<<endl;
		}

};



int main()
{

	clrscr();
	Base* pb=new Base();
	Base* pb2 = new Derived();
  // Derived *pd =new Base();
	Derived *pd2 = new Derived();

	cout<<"pb"<<endl;
	pb->Print();
	cout<<"pb2"<<endl;
	pb2->Print();
	cout<<"pd2"<<endl;
	pd2->Print();


	getch();

	return 0;
}