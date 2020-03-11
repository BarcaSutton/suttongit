#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include "function.h"

#define OK            0
#define ERROR        -1
#define MALLOC_ERROR -2 

//�жϴ����ָ���Ƿ�Ϊ�� 
void judge_empty(PNode p) 
{
	if (p == NULL)
	{
		printf("ָ��Ϊ�գ�");
		exit(0); 
	}
}

//������Ľ����г�ʼ������ 
void emptynode(PNode p )            
{     
	strcpy(p ->ID ,"0");
    strcpy(p ->Name ,"0");
    strcpy(p ->occu ,"0");
    strcpy(p ->tel ,"0");
    strcpy(p ->email ,"0");
    p ->pnext = NULL;
}  

//β�巨����һ���µĽ�� 
void insert(PNode p)    
{   
	PNode p1;                                                      
	p1 = (PNode)malloc(sizeof(Node));                                      //����һ��P1�������ڴ� 
	if(p1 == NULL)                                                         //�жϷ����ڴ��Ƿ�ɹ� 
    {
    	printf("����p1ʧ��\n");
    	exit(1);	 
    }
	emptynode(p1);                                                         //��p1��ʼ������ 
	p-> pnext=p1;
	p1->pnext=NULL;
}

//��ʼ������ 
PNode initialize()                                  
{    
	PNode phead;                                                          //����ͷ����p2��� 
	PNode p2;
	phead = (PNode)malloc(sizeof(Node));                                     
	p2 = phead;                                                            //��p2ָ��phead 
	if(phead == NULL)                                                         
    {
    	printf("�ռ����ʧ��\n");
    	exit(-1);	 
    }
    phead-> pnext = NULL;
    emptynode(phead);                                                      //��phead ��ʼ������ 
	
	insert(p2);
 	if(p2==NULL)                                                          //ͨ������p2�����������һ����� 
	{
	return NULL;
	}
	else
	{
	p2 = p2->pnext; 
	}
	return phead;
}

//������β�������ϵ�˹��� 
void input(PNode phead)                        
{   
	judge_empty(phead);
	PNode ptemp;
	ptemp=phead;
	while(ptemp->pnext)
    {
		if(ptemp==NULL)                                                      //����ptemp������һ����� 
		{
			exit(0); 
		}
		else
		{
			ptemp=ptemp->pnext; 
		}
	} 
	insert(ptemp);
	if(ptemp==NULL)                                                          //����ptemp������һ����� 
	{
			exit(0); 
	}
	else
	{
		ptemp=ptemp->pnext; 
	}
	printf("�����ϵ��\n");                                                  //�������ϵ����Ϣ 
	printf ("��������ϵ�˱��:  ");
	scanf ("%s", ptemp->ID);
	printf ("��������ϵ������:  ");
	scanf ("%s", ptemp->Name);
	printf ("��������ϵ��ְҵ: ");
	scanf ("%s", ptemp->occu);
	printf ("��������ϵ�˵绰: ");
	scanf ("%s", ptemp->tel);
	printf ("��������ϵ������: ");
	scanf ("%s", ptemp->email);     
}


//��ʾ��ǰ�����ϵ�˴������ 
void displaycurrent(PNode phead)                  
{
	judge_empty(phead);
	PNode ptemp; 
	if (phead ==NULL)
	{
		return;	
	}
	ptemp = phead ->pnext;  
	while (ptemp)                                                        //�ж���ϵ���Ƿ񴴽��ɹ� 
	{
		if (ptemp->pnext==NULL)
		{
			printf("��ϵ��%s �ѳɹ�������\n",ptemp->Name);
		}
		ptemp =ptemp->pnext;	
	} 	 
}

//ʵ�ַ��������ϵ�� 
void search(PNode phead)
{
	judge_empty(phead);
	int m = 0;
	int n = 0; 
	PNode p1 = phead;                                                             //p1ָ��ͷ��� 
	PNode p2 = NULL;
	printf("\t\t��-------------------------------------��\n");                    //��ѯ��ʽ�˵� 
	printf("\t\t��          ��ѡ���ѯ��ʽ:            ��\n");
	printf("\t\t��     1.ͨ�����      2.ͨ������      ��\n");
	printf("\t\t��     3.ͨ��ְҵ      4.ͨ���绰��    ��\n");
	printf("\t\t��     5.ͨ������      6.����          ��\n");
	printf("\t\t��-------------------------------------��\n");
	scanf("\t\t%d",&m);                                                           //ѡ���ѯ��ʽ 
	do
	{
		n = 0;
		if (m!=1&&m!=2&&m!=3&&m!=4&&m!=5&&m!=6)                                   //�ж����������Ƿ�����0-6 
		{
			n = 1;
			printf("��ѯ��ʽ�������������루0-6����");
			scanf("%d",&m);           
		} 
    }while(n);
		
if(m==1)                                                           
{   
	char ID[10];                                                              //����Ҫ����ı�� 
	printf("��������Ҫ���ҵ���ϵ�˱�ţ�\n");
	scanf("%s",ID);
	while (p1!=NULL&&(p1->pnext)!=NULL)                                    
	{
		p2 = p1->pnext;
		if (p2!=NULL&&strcmp(p2->ID,ID)==0)
		{
			printf("�����ҵ���ϵ����Ϣ���£�\n");
			printf("���:%s ������%s ְҵ��%s �绰��%s ���䣺%s ",p2->ID,p2->Name,p2->occu,p2->tel,p2->email);
			return;
		}
		else if (p2->pnext == NULL && strcmp(p2->ID,ID)!=0)
		{
			printf("����ͨѶ¼�޸���ϵ�ˣ�\n");
			return;
		}
		p1 = p1->pnext; 
	}
}	

if(m==2)
{   
	char Name[10];
	printf("��������Ҫ���ҵ���ϵ��������\n");
	scanf("%s",Name);
	while (p1!=NULL&&(p1->pnext)!=NULL)
	{
		p2 = p1->pnext;
		if (p2!=NULL&&strcmp(p2->Name,Name)==0)
		{
			printf("�����ҵ���ϵ����Ϣ���£�\n");
			printf("���:%s ������%s ְҵ��%s �绰��%s ���䣺%s ",p2->ID,p2->Name,p2->occu,p2->tel,p2->email);
			return;
		}
		else if (p2->pnext == NULL && strcmp(p2->Name,Name)!=0)
		{
			printf("����ͨѶ¼�޸���ϵ�ˣ�\n");
		}
		p1 = p1->pnext; 
	}
}

if(m==3)
{   
	char occu[10];
	printf("��������Ҫ���ҵ���ϵ��ְҵ��\n");
	scanf("%s",occu);
	while (p1!=NULL&&(p1->pnext)!=NULL)
	{
		p2 = p1->pnext;
		if (p2!=NULL&&strcmp(p2->occu,occu)==0)
		{
			printf("�����ҵ���ϵ����Ϣ���£�\n");
			printf("���:%s ������%s ְҵ��%s �绰��%s ���䣺%s ",p2->ID,p2->Name,p2->occu,p2->tel,p2->email);
			return;
		}
		else if (p2->pnext == NULL && strcmp(p2->occu,occu)!=0)
		{
			printf("����ͨѶ¼�޸���ϵ�ˣ�\n");
		}
		p1 = p1->pnext; 
	}
}

if(m==4)
{   
	char tel[15];
	printf("��������Ҫ���ҵ���ϵ�˵绰��\n");
	scanf("%s",tel);
	while (p1!=NULL&&(p1->pnext)!=NULL)
	{
		p2 = p1->pnext;
		if (p2!=NULL&&strcmp(p2->tel,tel)==0)
		{
			printf("�����ҵ���ϵ����Ϣ���£�\n");
			printf("���:%s ������%s ְҵ��%s �绰��%s ���䣺%s ",p2->ID,p2->Name,p2->occu,p2->tel,p2->email);
			return;
		}
		else if (p2->pnext == NULL && strcmp(p2->tel,tel)!=0)
		{
			printf("����ͨѶ¼�޸���ϵ�ˣ�\n");
		}
		p1 = p1->pnext; 
	}
}

if(m==5)
{   
	char email[30];
	printf("��������Ҫ���ҵ���ϵ�����䣺\n");
	scanf("%s",email);
	while (p1!=NULL&&(p1->pnext)!=NULL)
	{
		p2 = p1->pnext;
		if (p2!=NULL&&strcmp(p2->email,email)==0)
		{
			printf("�����ҵ���ϵ����Ϣ���£�\n");
			printf("���:%s ������%s ְҵ��%s �绰��%s ���䣺%s ",p2->ID,p2->Name,p2->occu,p2->tel,p2->email);
			return;
		}
		else if (p2->pnext == NULL && strcmp(p2->email,email)!=0)
		{
			printf("����ͨѶ¼�޸���ϵ�ˣ�\n");
		}
		p1 = p1->pnext; 
	}
}

if (m==6)                                         //����ѡ�� 
{
	return;
}
}
  

//ɾ����ϵ�˺���ģ�� 
void del(PNode phead)
{	
	judge_empty(phead);
	char Name[10]; 
	printf("��������Ҫɾ������ϵ��������\n");                
	scanf("%s",Name);
	PNode p1 = phead; 
	PNode p2 = NULL;
	while (p1!=NULL && (p1->pnext)!=NULL)                                                 
	{
		p2 = p1->pnext ;
		if (p2!=NULL && strcmp(p2->Name,Name)==0)                          //��Ҫɾ���������������е���Ϣ���бȶ� 
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
	if (phead->pnext ==NULL)                                                 //�ж�ͨѶ¼�Ƿ�Ϊ�� 
	{
		printf("����ͨѶ¼Ϊ��,�뷵�ز������ϵ��\n"); 
		return;
	}
	printf("����ͨѶ¼��ϵ����Ϣ���£��������������\n");
	PNode ptemp = phead ->pnext ;                 
	while (ptemp)                                                              //�������������ϵ����Ϣ 
	{
		printf("��ţ�%s ������%s ְҵ��%s �绰��%s ���䣺%s\n",ptemp->ID ,ptemp->Name ,ptemp->occu ,ptemp->tel,ptemp->email );
		ptemp = ptemp->pnext ;
	}
}     

//�޸���ϵ�˺��� 
void revise(PNode phead)
{
 	judge_empty(phead);
	char Name[10]; 
	printf("��������Ҫ�޸ĵ���ϵ��������\n");
	scanf("%s",Name);
	PNode p1 = phead;
	PNode p2 = NULL;
	while (p1!=NULL&&(p1->pnext)!=NULL)                                 //��������       
	{
		p2 = p1->pnext;
		if (p2!=NULL&&strcmp(p2->Name,Name)==0)                         //�жϺ��û�����������Ƿ���ͬ 
		{
			printf("��Ҫ�޸ĵ���ϵ����Ϣ���£�\n");                     //��ӡ��ϵ����Ϣ 
			printf("���:%s ������%s ְҵ��%s �绰��%s ���䣺%s \n",p2->ID,p2->Name,p2->occu,p2->tel,p2->email);
		    printf("������ʼ�޸���ϵ����Ϣ��\n");
			printf ("�������µ���ϵ�˱��:  ");
			scanf ("%s", p2->ID);
			printf ("�������µ���ϵ������:  ");
			scanf ("%s", p2->Name);
			printf ("�������µ���ϵ��ְҵ: ");
			scanf ("%s", p2->occu);
			printf ("�������µ���ϵ�˵绰: ");
			scanf ("%s", p2->tel);
			printf ("�������µ���ϵ������: ");
			scanf ("%s", p2->email);
			printf("��ϵ��%s����Ϣ�޸ĳɹ���\n",p2->Name);
		}
		else if (p2->pnext == NULL && strcmp(p2->Name,Name)!=0)                //û��ƥ�����ϵ�˵���� 
		{
			printf("����ͨѶ¼�޸���ϵ�ˣ�\n");
		}
		p1 = p1->pnext; 
	}
}

//��Ŀǰ���е���ϵ�˽������� 
void sort(PNode phead)
{
	judge_empty(phead);                
	PNode p1;
	PNode p2;	 
	PNode ptemp;                                                      //����ptemp��Ϊ�м��������p1��p2����ֵ���� 
	ptemp = (PNode)malloc(sizeof(Node));
	p1 = phead->pnext ;                                      
	p2 = p1->pnext ;
	while (p1!=NULL)                                                  //������������ 
	{
		while (p2!=NULL)
		{
			if (strcmp (p1->Name ,p2->Name )>0)                        //������ĸ�����ж� 
			{
				strcpy(ptemp->Name ,p1->Name );                        //���н����Ĳ��� 
				strcpy(p1->Name ,p2->Name );
				strcpy(p2->Name ,ptemp->Name );
				strcpy(ptemp->ID ,p1->ID);
				strcpy(p1->ID ,p2->ID);
				strcpy(p2->ID ,ptemp->ID);
				strcpy(ptemp->occu,p1->occu);
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
	printf("�Ѿ�����������������ɹ����������������\n");
}
  
//�˵�ҳ�溯�� 
void menu()
 {
	system("cls");
	printf("\n\n\n\n\n\n");
	printf("\t\t|---------------------ͨѶ¼---------------------|\n");
	printf("\t\t|                 0. �˳�ͨѶ¼                  |\n");
	printf("\t\t|                 1.�����ϵ����Ϣ               |\n");
	printf("\t\t|                 2.������ϵ����Ϣ               |\n");
	printf("\t\t|                 3.�޸���ϵ����Ϣ               |\n");
	printf("\t\t|                 4.ɾ����ϵ����Ϣ               |\n");
	printf("\t\t|                 5.������ϵ����Ϣ               |\n");
	printf("\t\t|                 6.��ʾ��ϵ����Ϣ               |\n");
	printf("\t\t|------------------------------------------------|\n\n");
	printf("\t\t\t  ��ѡ����(0-6):\n");
 }
