#include<stdio.h>
#include<conio.h>

void main(void)
{
	int p,i,ch=0;
	clrscr();
	printf("Enter prime num :");
	scanf("%d",&p);
	if(p==1)
	{
		ch=1;
	}
	for(i=2 ; i<(p/2)+1 ; i++)
	{
		if(p%i==0)
		{
			ch=1;
			i=(p/2)+1;
		}
	}
	if(ch==1)
	{
		printf("Not Prime Number");
	}
	else
	{
		printf("prime number");
	}

	getch();
}