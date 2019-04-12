#include<stdlib.h>
#include<conio.h>
#include<iostream.h>

void Swap_Address (int *A , int *B);
void Swap_Value (int A , int B);
void Swap_Ref (int &A , int &B);

void main()
{
	int x , y;
	clrscr();
	cout<<"Enter first num: ";
	cin>>x;
	cout<<"Enter second num: ";
	cin>>y;;

	Swap_Address(&x,&y);
	cout<<"After Swap_Addres:\n";

	cout<<"First num :"<<x<<"\nSecond num:"<<y<<endl;


	Swap_Value(x,y);
	cout<<"After Swap_Value:\n";

	cout<<"First num :"<<x<<"\nSecond num:"<<y<<endl;

	Swap_Ref(x,y);
	cout<<"After Swap_Ref:\n";

	cout<<"First num :"<<x<<"\nSecond num:"<<y<<endl;

	getch();

}

void Swap_Address (int *A , int * B)
{
	int temp;
	temp = *A;
	*A = *B;
	*B = temp;
}

void Swap_Value (int A , int B)
{
	int temp;
	temp = A;
	A = B;
	B = temp;
}

void Swap_Ref (int &A , int &B)
{
	int temp;
	temp = A;
	A = B;
	B = temp;
}