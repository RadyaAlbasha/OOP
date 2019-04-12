#include<stdio.h>
#include<conio.h>
#include<string.h>


void main(void)
{
	int size,i,ch;
	int * arr;
	arr=(int*)malloc(size * sizeof(int));
	do
	{   clrscr();
		printf("Enter size of array: ");
		ch = scanf("%d",&size);
		flushall();
	}while((ch == 0) || (size < 0));

	for(i=0 ; i<size ; i++)
	{
		printf("Element %d: ",(i+1));
		scanf("%d",arr+i);
	}
	printf("Array: ");
	for(i=0 ; i<size ; i++)
	{
	   printf("%d ",arr[i]);

	}

	getch();
}
