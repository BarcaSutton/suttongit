#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include "function.h"

void creatphead()
{
	phead = (struct node *)malloc(sizeof(struct node));	   //phead的类型以及分配的空间 
	if (!phead)
	{
		printf("头节点创建失败\n");	
	} 
	else
	{
		 phead->pnext = NULL;
	}
} 
 
void input(struct node *phead)
{
	 
}

void search()
{
	
}

void update()
{
	
}

void del()
{
	
}

void sort()
{
	
}

void display()
{
	
}

void menu()
{
	system("cls");
	printf("\n\n\n\n\n\n");
	printf("\t\t|---------------------通讯录---------------------|\n");
	printf("\t\t|                 0.exit                         |\n");
	printf("\t\t|                 1.input  record                |\n");
	printf("\t\t|                 2.search record                |\n");
	printf("\t\t|                 3.update record                |\n");
	printf("\t\t|                 4.del    record                |\n");
	printf("\t\t|                 5.sort   record                |\n");
	printf("\t\t|                 6.display                      |\n");
	printf("\t\t|------------------------------------------------|\n\n");
	printf("\t\t\t  choose(0-6):");
}
