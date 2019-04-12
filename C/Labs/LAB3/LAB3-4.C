#include<stdio.h>
#include<conio.h>
#include<string.h>

const int Esize=2;

struct Employee
{
	int Code;
	char Name[51];
	float Salary;
	float Bonus;
	float Deduction;

};

int StartPage(struct Employee emp[],int size);
struct Employee EnterEmp(void);
void DisplayEmp(struct Employee emp[],int size);
void DisplayEmp_byIndex(struct Employee emp[],int index);
int search(struct Employee emp[],int size,int code);

void main(void)
{

	int Ecount;
	struct Employee emp[2];
	int i;
	Ecount = StartPage(emp,Esize);
	//getch();
}


struct Employee EnterEmp(void)
{
	struct Employee emp ;
	int scan;

	clrscr();

	gotoxy((80/3),(25/2)-2);
	printf("Code: ");

	gotoxy((80/3)+25,(25/2)-2);
	printf("Name: ");;

	gotoxy((80/3),(25/2));
	printf("Salary: ");

	gotoxy((80/3)+25,(25/2));
	printf("Bonus: ");

	gotoxy((80/3),(25/2)+2);
	printf("Deduction: ");

	//--------take inputs---------
	gotoxy((80/3)+6,(25/2)-2);
	do
	{
		scan = scanf("%d", &emp.Code);
		flushall();
		gotoxy((80/3)+31,(25/2)-2);

	}while(scan == 0);

	gets(emp.Name);
	flushall();
	gotoxy((80/3)+8,(25/2));
	do
	{
		scan = scanf("%f", &emp.Salary);
		flushall();
		gotoxy((80/3)+32,(25/2));
	}while(scan == 0);
	do
	{
		scan = scanf("%f",&emp.Bonus);
		flushall();
		gotoxy((80/3)+11,(25/2)+2);

	}while(scan == 0);
	do
	{
		scan = scanf("%f",&emp.Deduction);
		flushall();
	}while(scan == 0);

	return emp;

}

void DisplayEmp(struct Employee emp[],int size)
{
	float NetSalary;
	int i;
	clrscr();

	gotoxy((80/3),(25/2)-3);
	printf("code");
	gotoxy((80/3)+15,(25/2)-3);
	printf("Name");
	gotoxy((80/3)+30,(25/2)-3);
	printf("Net Salary");


	for(i=0 ; i<size ; i++)
	{
		gotoxy((80/3),(25/2)+(i-1));
		printf("%d",emp[i].Code);


		gotoxy((80/3)+15,(25/2)+(i-1));
		printf("%s",emp[i].Name);


		gotoxy((80/3)+30,(25/2)+(i-1));
		NetSalary = (emp[i].Salary+emp[i].Bonus-emp[i].Deduction);
		printf("%f",NetSalary);
	}


}
void DisplayEmp_byIndex(struct Employee emp[],int index)
{
	float NetSalary;
	clrscr();

	gotoxy((80/3),(25/2)-3);
	printf("code");
	gotoxy((80/3)+15,(25/2)-3);
	printf("Name");
	gotoxy((80/3)+30,(25/2)-3);
	printf("Net Salary");


		gotoxy((80/3),(25/2)-1);
		printf("%d",emp[index].Code);


		gotoxy((80/3)+15,(25/2)-1);
		printf("%s",emp[index].Name);


		gotoxy((80/3)+30,(25/2)-1);
		NetSalary = (emp[index].Salary+emp[index].Bonus-emp[index].Deduction);
		printf("%f",NetSalary);



}

int StartPage(struct Employee emp[],int size)
{	char c;
	int count=0,out=0,code,index;

	 do
	 {  clrscr();
		gotoxy((80/3)+2,(25/2)-1);
		printf("1- Enter Employee\n");
		gotoxy((80/3)+2,25/2);
		printf("2- Display Employee\n");
		gotoxy((80/3)+2,(25/2)+1);
		printf("3- Display All Employees \n");
		gotoxy((80/3)+2,(25/2)+2);
		printf("4- Exit \n");

		c=getch();

		if(c == '1')
		{
			if(count<size)
			{
				emp[count]=EnterEmp();
				count++;

			}
			else
			{   do
				{
					gotoxy((80/3),(25/2)+3);
					printf("* Array is full\n");
					c=getch();
					if(c == '2')
					{
						gotoxy((80/3)+23,25/2);
						printf("Enter code: ");
						gotoxy((80/3)+36,25/2);
						scanf("%d",&code);
						index= search(emp,count,code);
						DisplayEmp_byIndex(emp,index);
					}

					else if(c == '3')
					{
						DisplayEmp(emp,count);
					}
					else if(c == '4')
					{
						out=1;
					}
					else
					{
						if(c != '1')
						{
						   //	gotoxy((80/3),(25/2)+3);
							printf("* invalid character");
						}
					}
				}while(c == '1');

			}

		}

		else if(c == '2')
		{   gotoxy((80/3)+23,25/2);
			printf("Enter code: ");
			gotoxy((80/3)+36,25/2);
			scanf("%d",&code);
			index= search(emp,count,code);
			DisplayEmp_byIndex(emp,index);
		}
		else if(c == '3')
		{
			DisplayEmp(emp,count);
		}

		else if(c == '4')
		{
		   out=1;
		}
		else
		{
		   //	gotoxy((80/3),(25/2)+3);
			printf("* invalid character");
		}

	 }while((out==0) && getch() == 13);

	 return count;

}


int search(struct Employee emp[],int size,int code)
{
	int i;
	for(i=0 ; i<size ; i++)
	{
		if(emp[i].Code == code)
			return i;
	}
	return 0;
}