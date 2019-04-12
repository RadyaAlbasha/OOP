#include<stdio.h>
#include<conio.h>

void main(void)
{
 int col , row , n , i;
 clrscr();
 printf("Enter magicbox size: ");
 scanf("%d",&n);
 row=0;
 col=n/2;
 gotoxy((col+1)*(80/(n+1)),(row+2)*(25/(n+1)));
 printf("1");
 for(i=1;i<(n*n);i++)
 {
  if(i%n != 0)
  {
   row--;
   if(row<0)
   {
	row=n-1;
   }
   col--;
   if(col<0)
   {
	col=n-1;
   }
  }
  else
  {
   row++;
   if(row>(n-1))
   {
	row=0;
   }
  }
  gotoxy((col+1)*(80/(n+1)),(row+2)*(25/(n+1)));
  printf("%d",i+1);
 }
 getch();
}