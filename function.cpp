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
	struct node *pfind = phead;
 	struct node *padd = NULL;                            //����һ���½ڵ� 
 	padd = (struct node *)malloc(sizeof(struct node));
    while (pfind -> pnext!=NULL)                          //������β�ڵ� 
 	{
 	pfind = pfind -> pnext;
 	}	
	printf("��������ϵ������:\n"); 
	scanf("%s",padd -> DATA.name); 
    if (strcmp(padd->DATA.name,"0")==0) 
    { 
    printf("��������Ϊ0,����ʧ��!\n"); 
    //return(phead); 
    } 
    else
    {
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
}

void del()
{
	
}

void search()
{
	
}

void update()
{
	
}

void sort()
{
	
}

void display()
{
	
}

void readDATA(struct node *phead)
{
	int count; 
	struct node *pfind = phead;
	struct node *padd =NULL;
	FILE * fp = NULL;                                //һ���ļ�ָ�� 
    fp = fopen("data.txt","r");                       //��ȡ�ļ�	
	if (fp == NULL)
	{
		printf("�ļ���ȡʧ��\n");
		return;	
	} 
	while (1)
	{
		padd = (struct node *)malloc(sizeof(struct node));	  //����һ����ָ�� 
		fscanf(fp,"%s%s%s%s%s",padd -> DATA.name,padd -> DATA.occu,padd -> DATA.prof,padd -> DATA.tel,padd -> DATA.email); 
		padd -> pnext = NULL;
		if (feof(fp))                       //�ж��ǲ��ǵ�ĩβ 
		{
		break; 
		}
	count++;
	pfind -> pnext =padd;
	pfind = pfind ->pnext;
	}
	fclose(fp);
}    

void writeDATA(struct node *phead)
{
 	struct node *pfind = phead -> pnext;
 	FILE * fp = NULL;                                //һ���ļ�ָ�� 
	fp = fopen("data.txt","w");
	while (pfind != NULL)                      //�������� 
	{
		fprintf(fp,"%s%s%s%s%s",pfind -> DATA.name,pfind -> DATA.occu,pfind -> DATA.prof,pfind -> DATA.tel,pfind -> DATA.email) ;
		pfind = pfind -> pnext; 
	}
	fclose(fp);
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
