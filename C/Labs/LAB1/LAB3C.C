#include<stdio.h>
#include<conio.h>

void main(void)
{
 int a;
 clrscr();
 printf("Please enter number :");
 scanf("%d",&a);
 printf("HEX representation for %d is %x",a,a);
 getch();
}