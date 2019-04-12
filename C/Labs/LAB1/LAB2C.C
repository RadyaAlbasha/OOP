#include<stdio.h>
#include<conio.h>

void main(void)
{
 char a;
 clrscr();
 printf("Please enter character :");
 scanf("%c",&a);
 printf("ASCII code for character %c is %d",a,a);
 getch();
}