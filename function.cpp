#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include "function.h"

/*void creatphead()
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
}*/
 
void input()
{
	struct node *phead;                                    // 头结点 
	phead = (struct node *)malloc(sizeof(struct node));	   //phead的类型以及分配的空间 
	if (!phead)
	{
		printf("头结点创建失败\n");	
	} 
	else
	{
		phead->pnext = NULL;
	}    
	struct node * pfind = phead;
 	struct node * padd = NULL;                         //创造一个新节点 
 	padd = (struct node *)malloc(sizeof(struct node));
 	while (pfind -> pnext!=NULL)                       //遍历找尾节点 
 	{
 	pfind = pfind -> pnext;
 	}
 	 	printf("请输入联系人姓名：\n");
 		scanf("%s",padd -> DATA.name); 
 		printf("请输入联系人职业：\n");
 		scanf("%s",padd -> DATA.occu); 
 		printf("请输入联系人职称：\n");
		scanf("%s",padd -> DATA.prof); 
 		printf("请输入联系人电话：\n");
 		scanf("%s",padd -> DATA.tel); 
 		printf("请输入联系人邮箱：\n");
 		scanf("%s",padd -> DATA.email); 
 		padd -> pnext = NULL;                       //将padd插入到尾节点前面 
 		pfind -> pnext = padd;
 		printf("联系人%s的信息已经录入\n",padd -> DATA.name); 
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
