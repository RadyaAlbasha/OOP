#include<stdlib.h>
#include<conio.h>
#include<iostream.h>

template <class T>
class Stack
{
	private:
		int tos,size;
		T* stk;
		static int Counter;
	public:
		Stack();
		Stack(int size);
		Stack(Stack&s);
		~Stack();
		int IsFull();
		int IsEmpty();
		int Push(T data);
		int Pop(T &data);
		void PrintStack();
		friend void ViewContent_Ref(Stack&s);
		friend void ViewContent(Stack s);
		static int GetCounter()
		{
			return Counter;
		}

		Stack& operator =(Stack &s);

};

template <class T>
int Stack<T>::Counter=0;

template <class T>
Stack<T>::Stack()
{
	size=10;
	tos=0;
	stk=new T[size];
	Counter++;
	cout<<"\n Defoult Constructor";
}

template <class T>
Stack<T>::Stack(int size)
{
	this->size=size;
	tos=0;
	stk=new T[size];
	Counter++;
	cout<<"\nConstructor with one param";
}

template <class T>
Stack<T>::Stack(Stack<T>&s)
{
	Counter++;
	tos=s.tos;
	size=s.size;
	stk=new T[size];
	for(int i=0; i<tos ; i++)
	{
		stk[i]=s.stk[i];
	}
	cout<<"\nCopy Constructor";

}

template <class T>
Stack<T>::~Stack()
{
	delete[] stk;
	Counter--;
	cout<<"\n Destructor";
}

template <class T>
int Stack<T>::IsFull()
{
	return tos==size;
}

template <class T>
int Stack<T>::IsEmpty()
{
	return tos==0;
}

template <class T>
int Stack<T>::Push(T data)
{
	if(IsFull())
		return 0;
	stk[tos]=data;
	tos++;
	return 1;
}

template <class T>
int Stack<T>::Pop(T &data)
{
	if(IsEmpty())
		return 0;
	tos--;
	data=stk[tos];
	return 1;
}

template <class T>
void Stack<T>::PrintStack()
{
	int i;
	for(i=0 ; i<tos;i++)
	{
		cout<<"\n"<<stk[i];
	}

}

template <class T>
void ViewContent_Ref(Stack<T> & s)
{
	int i;
	for(i=0 ; i<s.tos;i++)
	{
		cout<<"\n"<<s.stk[i];
	}

}

template <class T>
void ViewContent(Stack<T> s)
{
	int i;
	for(i=0 ; i<s.tos;i++)
	{
		cout<<"\n"<<s.stk[i];
	}

}

template <class T>
Stack<T>& Stack<T>::operator =(Stack<T> &s)
{
   this->tos=s.tos;
   size=s.size;
   delete[] stk;
   stk=new T[size];
   for(int i=0 ; i<tos ; i++)
   {
	stk[i]=s.stk[i];
   }
   return *this;
}
void main()
{
	Stack<int>s1,s2(50),s3(13);
	Stack<float> s4(20);
	clrscr();
	cout<<"int: "<<s1.GetCounter()<<endl;
	cout<<"float: "<<Stack<float>::GetCounter()<<endl;
   //	cout<<"char: "<<Stack<char>::GetCounter()<<endl;






	getch();
}