#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include "function.h"

#define OK            0
#define ERROR        -1
#define MALLOC_ERROR -2 
 
//创建联系人信息（通过尾插法创建链表） 
int CreateList(PNode Ph,int ID, char *Name, char *occu, char *tel, char *email)         
{
	if (Ph == NULL)
	{
		return ERROR;
	}
	PNode pfind = (PNode)malloc(sizeof(Node));              //定义一个pfind并分配内存 
	if (pfind == NULL)
	{
	return MALLOC_ERROR;
	}
	printf("添加联系人\n");
	printf ("请输入联系人编号:  ");
	scanf ("%d", &pfind->ID);
	printf ("请输入联系人姓名:  ");
	scanf ("%s", pfind->Name);
	printf ("请输入联系人职业: ");
	scanf ("%s", pfind->occu);
	printf ("请输入联系人电话: ");
	scanf ("%s", pfind->tel);
	printf ("请输入联系人邮箱: ");
	scanf ("%s", pfind->email);

	pfind->pnext = NULL;
	PNode ptemp = Ph;                     //定义一个临时指针ptemp 
	while (ptemp->pnext)
	{
		ptemp=ptemp->pnext;
	}
	ptemp->pnext = pfind;
	printf("联系人%s的信息已经录入\n",pfind->Name); 
	return OK;
}

void displaycurrent(PNode Ph)                //显示当前结点联系人创建情况 
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
			printf("联系人%s 已成功创建！\n",ptemp->Name);
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
			printf("您查找的联系人信息如下：\n");
			printf("编号:%d 姓名：%s 职业：%s 电话：%s 邮箱：%s ",p2->ID,p2->Name,p2->occu,p2->tel,p2->email);
			return;
		}
		else if (p2->pnext == NULL && strcmp(p2->Name,Name)!=0)
		{
			printf("您的通讯录无该联系人！\n");
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
			printf("该联系人已成功删除!\n");
		}
		else if (p2->pnext==NULL && strcmp(p2->Name,Name)!=0)
		{
			printf("您的通讯录无该联系人！\n");
		}
		p1=p1->pnext ;
	}
}

//显示所有已经创建的联系人 
void display_record(PNode Ph)
{
	if (Ph == NULL)
	{
		return;
	}
	PNode ptemp = Ph->pnext ;
	while (ptemp)
	{
		printf("编号：%d 姓名：%s 职业：%s 电话：%s 邮箱：%s\n",ptemp->ID ,ptemp->Name ,ptemp->occu ,ptemp->tel,ptemp->email );
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
			printf("您要修改的联系人信息如下：\n");
			printf("编号:%d 姓名：%s 职业：%s 电话：%s 邮箱：%s \n",p2->ID,p2->Name,p2->occu,p2->tel,p2->email);
		    printf("请您开始修改联系人信息！\n");
			printf ("请输入联系人编号:  ");
			scanf ("%d", &p2->ID);
			printf ("请输入联系人姓名:  ");
			scanf ("%s", p2->Name);
			printf ("请输入联系人职业: ");
			scanf ("%s", p2->occu);
			printf ("请输入联系人电话: ");
			scanf ("%s", p2->tel);
			printf ("请输入联系人邮箱: ");
			scanf ("%s", p2->email);
			printf("联系人%s的信息修改成功！\n",p2->Name);
		}
		else if (p2->pnext == NULL && strcmp(p2->Name,Name)!=0)
		{
			printf("您的通讯录无该联系人！\n");
		}
		p1 = p1->pnext; 
	}
}

void sort()
{
	 
}

//从文件中读数据到链表中 
void readDATA(PNode phead)
{
	int count; 
	PNode pfind = phead;
	PNode padd =NULL;
	FILE *fp = NULL;                                //一个文件指针 
    fp = fopen("data.txt","r");                       //读取文件	
	if (fp == NULL)
	{
		printf("文件读取失败\n");
		return;	
	} 
	while (1)
	{
		padd = (PNode)malloc(sizeof(Node));	  //建立一个新指针 
		fscanf(fp,"编号：%d 姓名：%s 职业：%s 电话：%s 邮箱：%s",&padd ->ID,padd -> Name,padd ->occu,padd ->tel,padd ->email); 
		padd ->pnext = NULL;
		if (feof(fp))                       //判断是不是到末尾 
		{
		break; 
		}
	count++;
	pfind -> pnext =padd;
	pfind = pfind ->pnext;
	}
//	printf("当前有%d个联系人,choose(0-6):",count);
	fclose(fp);
}    

//将链表中的数据写入data.txt中 
void writeDATA(PNode phead)
{
 	PNode pfind = phead -> pnext;
 	FILE *fp = NULL;                                //一个文件指针 
	fp = fopen("data.txt","w");
	while (pfind != NULL)                      //遍历链表 
	{
		fprintf(fp,"编号：%d 姓名：%s 职业：%s 电话：%s 邮箱：%s",&pfind ->ID,pfind ->Name,pfind ->occu,pfind ->tel,pfind ->email) ;
		pfind = pfind -> pnext; 
	}
	fclose(fp);
	printf("系统已退出！\n");
	exit(0); 
}  
 
void menu()
{
	system("cls");
	printf("\n\n\n\n\n\n");
	printf("\t\t|---------------------通讯录---------------------|\n");
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
