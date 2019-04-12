#include<stdio.h>
#include<conio.h>

void main(void)
{
 int arr[5] ,min,max, i;
 clrscr();
 printf("Enter 5 integers:- ");

 for(i=0;i<5;i++)
 {
  scanf("%d",&arr[i]);
 }

 min=arr[0];
 max=arr[0];

 for(i=1;i<5;i++)
 {
  if(min>arr[i])
  {
   min=arr[i];
  }

  if(max<arr[i])
  {
   max=arr[i];
  }
 }
 printf("min: %d",min);
 printf("\n");
 printf("max: %d", max);
 getch();
}