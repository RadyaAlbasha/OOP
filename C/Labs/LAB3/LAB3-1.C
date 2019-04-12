#include<stdio.h>
#include<conio.h>
#include<string.h>

struct Employee
{
	int Code;
	char Name[51];
	float Salary;
	float Bonus;
	float Deduction;

};

struct Employee EnterEmp(void);
void DisplayEmp(struct Employee emp);

void main(void)
{
	struct Employee emp ;
   //clrscr();
	emp=EnterEmp();
	DisplayEmp(emp);

	getch();
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

void DisplayEmp(struct Employee emp)
{
	float NetSalary;
	clrscr();

	gotoxy((80/3),(25/2)-2);
	printf("code");
	gotoxy((80/3),(25/2));
	printf("%d",emp.Code);

	gotoxy((80/3)+15,(25/2)-2);
	printf("Name",emp.Name);
	gotoxy((80/3)+15,(25/2));
	printf("%s",emp.Name);

	gotoxy((80/3)+30,(25/2)-2);
	NetSalary = (emp.Salary+emp.Bonus-emp.Deduction);
	printf("Net Salary",NetSalary);
	gotoxy((80/3)+30,(25/2));
	printf("%f",NetSalary);

}