#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include "function.h"

/*void creatphead()
{
	phead = (struct node *)malloc(sizeof(struct node));	   //phead�������Լ�����Ŀռ� 
	if (!phead)
	{
		printf("ͷ�ڵ㴴��ʧ��\n");	
	} 
	else
	{
		 phead->pnext = NULL;
	}
}*/
 
void input()
{
	struct node *phead;                                    // ͷ��� 
	phead = (struct node *)malloc(sizeof(struct node));	   //phead�������Լ�����Ŀռ� 
	if (!phead)
	{
		printf("ͷ��㴴��ʧ��\n");	
	} 
	else
	{
		phead->pnext = NULL;
	}    
	struct node * pfind = phead;
 	struct node * padd = NULL;                         //����һ���½ڵ� 
 	padd = (struct node *)malloc(sizeof(struct node));
 	while (pfind -> pnext!=NULL)                       //������β�ڵ� 
 	{
 	pfind = pfind -> pnext;
 	}
 	 	printf("��������ϵ��������\n");
 		scanf("%s",padd -> DATA.name); 
 		printf("��������ϵ��ְҵ��\n");
 		scanf("%s",padd -> DATA.occu); 
 		printf("��������ϵ��ְ�ƣ�\n");
		scanf("%s",padd -> DATA.prof); 
 		printf("��������ϵ�˵绰��\n");
 		scanf("%s",padd -> DATA.tel); 
 		printf("��������ϵ�����䣺\n");
 		scanf("%s",padd -> DATA.email); 
 		padd -> pnext = NULL;                       //��padd���뵽β�ڵ�ǰ�� 
 		pfind -> pnext = padd;
 		printf("��ϵ��%s����Ϣ�Ѿ�¼��\n",padd -> DATA.name); 
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
	printf("\t\t|---------------------ͨѶ¼---------------------|\n");
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
