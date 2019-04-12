#include<stdio.h>
#include<conio.h>

void main(void)
{
 char c;

 do
 {  clrscr();
	gotoxy((80/2),(25/2)-1);
	printf("1- option1 \n");
	gotoxy(80/2,25/2);
	printf("2- option2 \n");
	gotoxy((80/2),(25/2)+1);
	printf("3- Exit \n");

	c=getch();

	if(c == '1')
	{	clrscr();
		gotoxy(80/2,25/2);
		printf("option1 \n");

	}

	else if(c == '2')
	{	clrscr();
		gotoxy(80/2,25/2);
		printf("option2 \n");

	}

	else if(c == '3')
	{
		c='4';
	}
	else
	{
		printf("invalid character");
	}


 }while(getch() == 13);

}