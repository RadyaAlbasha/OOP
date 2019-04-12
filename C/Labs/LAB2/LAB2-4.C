#include<stdio.h>
#include<conio.h>
#include<string.h>

void main(void)
{
 char c ,str1[51],str2[51];
 int i=0;
 int ic;

	clrscr();

	printf("First name: ");;
	str1[i]=getche();
	ic=str1[i];
	i++;
	while(ic != 13)
	{
		str1[i]=getche();
		i++;

		ic=str1[i-1];
	}

	str1[i-1]='\0';
	printf("\nLast name: ");
	gets(str2);

	printf("%s",str1);
	printf("\n");
	printf("%s",str2);

	printf("\nFull name:\n ");
	strcat(str1," ");
	strcat(str1,str2);
	printf("%s",str1);
    getch();

}