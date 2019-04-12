#include<stdlib.h>
#include<conio.h>
#include<iostream.h>

class Stack
{
	private:
		int tos,size;
		int* stk;
		static int Counter;
	public:
		Stack();
		Stack(int size);
		Stack(Stack&s);
		~Stack();
		int IsFull();
		int IsEmpty();
		int Push(int data);
		int Pop(int &data);
		void PrintStack();
		friend void ViewContent_Ref(Stack&s);
		friend void ViewContent(Stack s);
		static int GetCounter()
		{
			return Counter;
		}

};

int Stack::Counter=0;

Stack::Stack()
{
	size=10;
	tos=0;
	stk=new int[size];
	Counter++;
	cout<<"\n Defoult Constructor";
}
Stack::Stack(int size)
{
	this->size=size;
	tos=0;
	stk=new int[size];
	Counter++;
	cout<<"\nConstructor with one param";
}
Stack::Stack(Stack&s)
{
	Counter++;
	tos=s.tos;
	size=s.size;
	stk=new int[size];
	for(int i=0; i<tos ; i++)
	{
		stk[i]=s.stk[i];
	}
	cout<<"\nCopy Constructor";
}
Stack::~Stack()
{
	delete[] stk;
	Counter--;
	cout<<"\n Destructor";
}
int Stack::IsFull()
{
	return tos==size;
}
int Stack::IsEmpty()
{
	return tos==0;
}
int Stack::Push(int data)
{
	if(IsFull())
		return 0;
	stk[tos]=data;
	tos++;
	return 1;
}
int Stack::Pop(int &data)
{
	if(IsEmpty())
		return 0;
	tos--;
	data=stk[tos];
	return 1;
}
void Stack::PrintStack()
{
	int i;
	for(i=0 ; i<tos;i++)
	{
		cout<<"\n"<<stk[i];
	}

}

void ViewContent_Ref(Stack & s)
{
	int i;
	for(i=0 ; i<s.tos;i++)
	{
		cout<<"\n"<<s.stk[i];
	}

}
void ViewContent(Stack s)
{
	int i;
	for(i=0 ; i<s.tos;i++)
	{
		cout<<"\n"<<s.stk[i];
	}

}


void main()
{
	int x;
	clrscr();

	Stack s;
	s.Push(10);
	s.Push(15);
	s.Push(12);
	s.Push(3);
	s.Pop(x);

	cout<<"\nBy Ref";
	ViewContent_Ref(s);
	cout<<"\nBy Value";
	ViewContent(s);

	getch();
}