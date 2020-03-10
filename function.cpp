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
	PNode pfind = (PNode)malloc(sizeof(Node));              //����һ��pfind�������ڴ� 
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

void displaycurrent(PNode Ph)                //��ʾ��ǰ�����ϵ�˴������ 
{
	if (Ph==NULL)
	{
		return;	
	}
	PNode ptemp = Ph->pnext;
	while (ptemp)
	{
		if (ptemp->pnext==NULL)
		{
			printf("��ϵ��%s �ѳɹ�������\n",ptemp->Name);
		}
		ptemp =ptemp->pnext;	
	} 	 
}
 
void search(PNode phead,char *Name)
{
	PNode p1 = phead;
	PNode p2 = NULL;
	while (p1!=NULL&&(p1->pnext)!=NULL)
	{
		p2 = p1->pnext;
		if (p2!=NULL&&strcmp(p2->Name,Name)==0)
		{
			printf("�����ҵ���ϵ����Ϣ���£�\n");
			printf("���:%d ������%s ְҵ��%s �绰��%s ���䣺%s ",p2->ID,p2->Name,p2->occu,p2->tel,p2->email);
			return;
		}
		else if (p2->pnext == NULL && strcmp(p2->Name,Name)!=0)
		{
			printf("����ͨѶ¼�޸���ϵ�ˣ�\n");
		}
		p1 = p1->pnext; 
	}
}

void del(PNode phead,char *Name)
{
	PNode p1 = phead;
	PNode p2 = NULL;
	while (p1!=NULL && (p1->pnext)!=NULL)
	{
		p2 = p1->pnext ;
		if (p2!=NULL && strcmp(p2->Name,Name)==0)
		{
			p1->pnext = p2->pnext ;
			free(p2);
			printf("����ϵ���ѳɹ�ɾ��!\n");
		}
		else if (p2->pnext==NULL && strcmp(p2->Name,Name)!=0)
		{
			printf("����ͨѶ¼�޸���ϵ�ˣ�\n");
		}
		p1=p1->pnext ;
	}
}

//��ʾ�����Ѿ���������ϵ�� 
void display_record(PNode Ph)
{
	if (Ph == NULL)
	{
		return;
	}
	PNode ptemp = Ph->pnext ;
	while (ptemp)
	{
		printf("��ţ�%d ������%s ְҵ��%s �绰��%s ���䣺%s\n",ptemp->ID ,ptemp->Name ,ptemp->occu ,ptemp->tel,ptemp->email );
		ptemp = ptemp->pnext ;
	}
}     

void revise(PNode phead,char *Name)
{
 	PNode p1 = phead;
	PNode p2 = NULL;
	while (p1!=NULL&&(p1->pnext)!=NULL)
	{
		p2 = p1->pnext;
		if (p2!=NULL&&strcmp(p2->Name,Name)==0)
		{
			printf("��Ҫ�޸ĵ���ϵ����Ϣ���£�\n");
			printf("���:%d ������%s ְҵ��%s �绰��%s ���䣺%s \n",p2->ID,p2->Name,p2->occu,p2->tel,p2->email);
		    printf("������ʼ�޸���ϵ����Ϣ��\n");
			printf ("��������ϵ�˱��:  ");
			scanf ("%d", &p2->ID);
			printf ("��������ϵ������:  ");
			scanf ("%s", p2->Name);
			printf ("��������ϵ��ְҵ: ");
			scanf ("%s", p2->occu);
			printf ("��������ϵ�˵绰: ");
			scanf ("%s", p2->tel);
			printf ("��������ϵ������: ");
			scanf ("%s", p2->email);
			printf("��ϵ��%s����Ϣ�޸ĳɹ���\n",p2->Name);
		}
		else if (p2->pnext == NULL && strcmp(p2->Name,Name)!=0)
		{
			printf("����ͨѶ¼�޸���ϵ�ˣ�\n");
		}
		p1 = p1->pnext; 
	}
}

void sort()
{
	 
}

//���ļ��ж����ݵ������� 
void readDATA(PNode phead)
{
	int count; 
	PNode pfind = phead;
	PNode padd =NULL;
	FILE *fp = NULL;                                //һ���ļ�ָ�� 
    fp = fopen("data.txt","r");                       //��ȡ�ļ�	
	if (fp == NULL)
	{
		printf("�ļ���ȡʧ��\n");
		return;	
	} 
	while (1)
	{
		padd = (PNode)malloc(sizeof(Node));	  //����һ����ָ�� 
		fscanf(fp,"��ţ�%d ������%s ְҵ��%s �绰��%s ���䣺%s",&padd ->ID,padd -> Name,padd ->occu,padd ->tel,padd ->email); 
		padd ->pnext = NULL;
		if (feof(fp))                       //�ж��ǲ��ǵ�ĩβ 
		{
		break; 
		}
	count++;
	pfind -> pnext =padd;
	pfind = pfind ->pnext;
	}
//	printf("��ǰ��%d����ϵ��,choose(0-6):",count);
	fclose(fp);
}    

//�������е�����д��data.txt�� 
void writeDATA(PNode phead)
{
 	PNode pfind = phead -> pnext;
 	FILE *fp = NULL;                                //һ���ļ�ָ�� 
	fp = fopen("data.txt","w");
	while (pfind != NULL)                      //�������� 
	{
		fprintf(fp,"��ţ�%d ������%s ְҵ��%s �绰��%s ���䣺%s",&pfind ->ID,pfind ->Name,pfind ->occu,pfind ->tel,pfind ->email) ;
		pfind = pfind -> pnext; 
	}
	fclose(fp);
	printf("ϵͳ���˳���\n");
	exit(0); 
}  
 
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
	printf("\t\t|                 6.display record               |\n");
	printf("\t\t|------------------------------------------------|\n\n");
	printf("\t\t\t  choose(0-6):\n");
}
