#include<stdio.h>
#include<conio.h>
#include<string.h>

void Swap (int *A , int * B);

void main(void)
{
	int x , y;
	clrscr();
	printf("Enter first num: ");
	scanf("%d",&x);
	printf("Enter second num: ");
	scanf("%d",&y);
	Swap(&x,&y);
	printf("After Swap:\n");

	printf("First num :%d\nSecond num: %d",x,y);

	getch();
}

void Swap (int *A , int * B)
{
	int temp;
	temp = *A;
	*A = *B;
	*B = temp;
}