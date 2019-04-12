#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<alloc.h>


void main(void)
{
	int rows,cols,i,j,chR,chC,sum=0;
	int ** arr;

		do
	{   clrscr();
		printf("Enter num of rows: ");
		chR= scanf("%d",&rows);
		flushall();
	}while((chR == 0) || (rows < 0));

	printf("Enter num of cols: ");

	do
	{
		gotoxy(20,2);
		chC= scanf("%d",&cols);
		flushall();
	}while((chC == 0)||(cols == 0));

	arr=(int **)malloc(rows * sizeof(int*));
	for(i=0 ; i<rows ; i++)
	{
		arr[i]=(int *)malloc(cols * sizeof(int));
		for(j=0 ; j<cols ; j++)
		{
			printf("Enter Element [%d][%d]: ",i,j);
			scanf("%d",&arr[i][j]);
			flushall();
		   //	printf("\n");
		}

	}

	printf("\n");
	for(i=0 ; i<rows ; i++)
	{
		 sum=0;

		for(j=0 ; j<cols ; j++)
		{
			sum=sum+arr[i][j];
			if(j == 0)
			{
				printf("	%d ",arr[i][j]);
			}
			else
				printf("    		%d ",arr[i][j]);

			if(j == (cols-1))
			{
				printf("	sum: %d",sum);
			}
		}
		 printf("\n");

	}

	printf("avg: ");
	for(i=0 ; i<cols ; i++)
	{
		sum=0;

		for(j=0 ; j<rows ; j++)
		{
			sum=sum+arr[j][i];

			if(j == (rows-1))
			{
				printf("	%f",(sum/(float)rows));
			}
		}

	}


	getch();
}
