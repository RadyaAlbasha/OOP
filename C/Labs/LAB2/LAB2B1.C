#include<stdio.h>
#include<conio.h>

void main(void)
{
	int f,i ;
	long int fact=1;

	clrscr();

	printf("Enter factorial num :");
	scanf("%d",&f);

	for(i=f ; i>1 ; i--)
	{
		fact*=i;
	}

	printf("\nfainal fact %ld",fact);

	getch();
}