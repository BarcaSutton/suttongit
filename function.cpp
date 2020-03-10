#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include "function.h"

#define OK            0
#define ERROR        -1
#define MALLOC_ERROR -2 
 
//������ϵ����Ϣ��ͨ��β�巨�������� 
int CreateList(PNode phead,int ID, char *Name, char *occu, char *tel, char *email)         
{
	if (phead == NULL)
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
	PNode ptemp = phead;                          //����һ����ʱָ��ptemp 
	while (ptemp->pnext)
	{
		ptemp=ptemp->pnext;
	}
	ptemp->pnext = pfind;
	printf("��ϵ��%s����Ϣ�Ѿ�¼��\n",pfind->Name); 
	return OK;
}
//��ʾ��ǰ�����ϵ�˴������ 
void displaycurrent(PNode phead)                  
{
	if (phead==NULL)
	{
		return;	
	}
	PNode ptemp = phead->pnext;
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

//ɾ����ϵ�˺���ģ�� 
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
void display_record(PNode phead)
{
	if (phead == NULL)
	{
		printf("����ͨѶ¼Ϊ��\n"); 
		return;
	}
	PNode ptemp = phead->pnext ;
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

//��Ŀǰ���е���ϵ�˽������� 
void sort(PNode phead)
{
	PNode p1;
	PNode p2;	 
	PNode ptemp;
	ptemp = (PNode)malloc(sizeof(Node));
	p1 = phead->pnext ;
	p2 = p1->pnext ;
	while (p1!=NULL)
	{
		while (p2!=NULL)
		{
			if (strcmp (p1->Name ,p2->Name )>0)
			{
				strcpy(ptemp->Name ,p1->Name );
				strcpy(p1->Name ,p2->Name );
				strcpy(p2->Name ,ptemp->Name );
				ptemp->ID = p1->ID;
				p1->ID = p2->ID ;
				p2->ID = ptemp->ID;
				strcpy(ptemp->occu , p1->occu);
				strcpy(p1->occu ,p2->occu);
				strcpy(p2->occu , ptemp->occu);
				strcpy(ptemp->tel , p1->tel);
				strcpy(p1->tel ,p2->tel);
				strcpy(p2->tel , ptemp->tel);
				strcpy(ptemp->email , p1->email);
				strcpy(p1->email , p2->email);
				strcpy(p2->email,ptemp->email);
				}
			p2 = p2->pnext ; 
		}
		p2 = p1->pnext ;
		p1 = p1->pnext ; 
	}
	printf("�Ѿ�������������ɹ����������������\n");
}
 
//���ļ��ж����ݵ�������
void readDATA(PNode phead)
{ 
	int count;
	PNode pfind = phead;
	PNode padd =NULL;
	FILE *fp ;                                     //һ���ļ�ָ�� 
    fp = fopen("data.txt","r");                       //��ȡ�ļ�	
	if (fp == NULL)
	{
		printf("�ļ���ȡʧ��\n");
	} 
	while (!feof(fp))
	{
		padd = (PNode)malloc(sizeof(Node));	                          //����һ���ڵ� 
		fscanf(fp,"��ţ�%d ������%s ְҵ��%s �绰��%s ���䣺%s\n",&padd ->ID,padd -> Name,padd ->occu,padd ->tel,padd ->email); 
		padd ->pnext = NULL;
		pfind -> pnext =padd;
		pfind = pfind ->pnext;
		count++;
	}
	printf("��ǰ��%d����ϵ�ˣ���ѡ����:\n",count) ;
 	fclose(fp);
}  

//������������д��data�ı���  
void writeDATA(PNode phead)
{
	PNode pfind = phead -> pnext;
 	FILE *fp = NULL;                                //һ���ļ�ָ�� 
	fp = fopen("data.txt","w");
	while (pfind != NULL)                           //�������� 
	{
		fprintf(fp,"��ţ�%d ������%s ְҵ��%s �绰��%s ���䣺%s\n",pfind ->ID,pfind ->Name,pfind ->occu,pfind ->tel,pfind ->email) ;
		pfind = pfind -> pnext; 
	}
	fclose(fp);
	printf("ϵͳ���˳�����ӭʹ�ã�\n");
 	exit(0); 
}  
 
void menu()
{
	system("cls");
	printf("\n\n\n\n\n\n");
	printf("\t\t|---------------------ͨѶ¼---------------------|\n");
	printf("\t\t|                 0.���沢�˳�                   |\n");
	printf("\t\t|                 1.�����ϵ����Ϣ               |\n");
	printf("\t\t|                 2.������ϵ����Ϣ               |\n");
	printf("\t\t|                 3.�޸���ϵ����Ϣ               |\n");
	printf("\t\t|                 4.ɾ����ϵ����Ϣ               |\n");
	printf("\t\t|                 5.������ϵ����Ϣ               |\n");
	printf("\t\t|                 6.��ʾ��ϵ����Ϣ               |\n");
	printf("\t\t|------------------------------------------------|\n\n");
	printf("\t\t\t  ��ѡ����(0-6):\n");
}
