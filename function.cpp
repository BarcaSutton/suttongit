#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include "function.h"

#define OK            0
#define ERROR        -1
#define MALLOC_ERROR -2 
 
//������ϵ����Ϣ��ͨ��β�巨�������� 
int CreateList(PNode Ph,int ID, char *Name, char *occu, char *tel, char *email)         
{
	if (Ph == NULL)
	{
		return ERROR;
	}
	PNode pfind = (PNode)malloc(sizeof(Node)/sizeof(char));              //����һ��pfind�������ڴ� 
	if (pfind == NULL)
	{
	return MALLOC_ERROR;
	}
	printf("�����ϵ��\n");
	printf ("��������ϵ�˱��:  ");
	scanf ("%d", &pfind->ID);
	printf ("��������ϵ������:  ");
	scanf ("%s", pfind->Name);
	printf ("��������ϵ��ְҵ: ");
	scanf ("%s", pfind->occu);
	printf ("��������ϵ�˵绰: ");
	scanf ("%s", pfind->tel);
	printf ("��������ϵ������: ");
	scanf ("%s", pfind->email);

	pfind->pnext = NULL;
	PNode ptemp = Ph;                     //����һ����ʱָ��ptemp 
	while (ptemp->pnext)
	{
		ptemp=ptemp->pnext;
	}
	ptemp->pnext = pfind;
	printf("��ϵ��%s����Ϣ�Ѿ�¼��\n",pfind->Name); 
	return OK;
}
 
/*void del(PNode phead)
{
	char delname[10];                                  //Ҫɾ������ϵ������ 
	PNode p1 = phead;
	PNode p2 = phead -> pnext;             //����ָ��p1��p2������� 
	PNode p3 = NULL;                       //����p3��Ϊһ����ʱ��ָ�� 
	printf("������Ҫɾ������ϵ������:\n");
	scanf("%s",delname);
	
	while (p2 != NULL)
	{
		if (strcmp(p2 -> DATA.name,delname)==0)                  //�ж�ɾ���������Ƿ���ƥ���� 
		{
			break;
		}
		p1 = p1 -> pnext;
		p2 = p2 -> pnext; 
	 } 
	 if (p2 == NULL)
	 {
	 	printf("��Ǹ���޴���ϵ�˼�¼\n");
	 }
	 else
	 {
	 	p3 = p2 -> pnext;
	 	free(p2);
	 	p2 = NULL;
	 	p1 -> pnext = p3;
	 }
	  
}*/

void search()
{
	
}

void revise()
{
	
}

void sort()
{
	
}

/*void display(PNode phead)
{
	 
}*/

/*void readDATA(PNode phead)
{
	int count; 
	PNode pfind = phead;
	PNode padd =NULL;
	FILE * fp = NULL;                                //һ���ļ�ָ�� 
    fp = fopen("data.txt","r");                       //��ȡ�ļ�	
	if (fp == NULL)
	{
		printf("�ļ���ȡʧ��\n");
		return;	
	} 
	while (1)
	{
		padd = (PNode)malloc(sizeof(Node)/sizeof(char));	  //����һ����ָ�� 
		fscanf(fp,"%d%s%s%s%s",&padd ->ID,padd -> name,padd ->occu,padd ->tel,padd ->email); 
		padd ->pnext = NULL;
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

void writeDATA(PNode phead)
{
 	PNode pfind = phead -> pnext;
 	FILE * fp = NULL;                                //һ���ļ�ָ�� 
	fp = fopen("data.txt","w");
	while (pfind != NULL)                      //�������� 
	{
		fprintf(fp,"%d%s%s%s%s",&pfind ->ID,pfind ->name,pfind ->occu,pfind ->tel,pfind ->email) ;
		pfind = pfind -> pnext; 
	}
	fclose(fp);
} */
 
void menu()
{
	system("cls");
	printf("\n\n\n\n\n\n");
	printf("\t\t|---------------------ͨѶ¼---------------------|\n");
	printf("\t\t|                 0.preserve & exit              |\n");
	printf("\t\t|                 1.input  record                |\n");
	printf("\t\t|                 2.search record                |\n");
	printf("\t\t|                 3.revise record                |\n");
	printf("\t\t|                 4.del    record                |\n");
	printf("\t\t|                 5.sort   record                |\n");
	printf("\t\t|                 6.display                      |\n");
	printf("\t\t|------------------------------------------------|\n\n");
	printf("\t\t\t  choose(0-6):");
}
