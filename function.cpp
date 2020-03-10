#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include "function.h"

#define OK            0
#define ERROR        -1
#define MALLOC_ERROR -2 
 
//创建联系人信息（通过尾插法创建链表） 
int CreateList(PNode phead,char *ID, char *Name, char *occu, char *tel, char *email)         
{
	if (phead == NULL)                                      //判断头指针是否为空 
	{
		return ERROR;                                        
	}
	PNode pfind = (PNode)malloc(sizeof(Node));              //定义一个pfind并分配内存 
	if (pfind == NULL)
	{
	return MALLOC_ERROR;
	} 
	printf("添加联系人\n");                                    //逐步添加联系人信息 
	printf ("请输入联系人编号:  ");
	scanf ("%s", pfind->ID);
	printf ("请输入联系人姓名:  ");
	scanf ("%s", pfind->Name);
	printf ("请输入联系人职业: ");
	scanf ("%s", pfind->occu);
	printf ("请输入联系人电话: ");
	scanf ("%s", pfind->tel);
	printf ("请输入联系人邮箱: ");
	scanf ("%s", pfind->email);

	pfind->pnext = NULL;
	PNode ptemp = phead;                          //定义一个临时指针ptemp 
	while (ptemp->pnext)
	{
		ptemp=ptemp->pnext;
	}
	ptemp->pnext = pfind;
	printf("联系人%s的信息已经录入\n",pfind->Name); 
	return OK;
}
//显示当前结点联系人创建情况 
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
			printf("联系人%s 已成功创建！\n",ptemp->Name);
		}
		ptemp =ptemp->pnext;	
	} 	 
}

//分类查找联系人 
void search(PNode phead)
{
	int m = 0;
	int n = 0; 
	PNode p1 = phead;
	PNode p2 = NULL;
	printf("\t\t┌-------------------------------------┐\n");
	printf("\t\t│          请选择查询方式:            │\n");
	printf("\t\t│     1.通过编号      2.通过姓名      │\n");
	printf("\t\t│     3.通过职业      4.通过电话号    │\n");
	printf("\t\t│     5.通过邮箱      6.                │\n");
	printf("\t\t└-------------------------------------┘\n");
	scanf("\t\t%d",&m);                              //选择查询方式 
	do
	{
		n = 0;
		if (m!=1&&m!=2&&m!=3&&m!=4&&m!=5&&m!=6)
		{
			n = 1;
			printf("查询方式错误，请重新输入（0-6）：");
			scanf("%d",&m);           
		} 
    }while(n);
		
	if(m==1)
{   
	char ID[10];
	printf("请输入您要查找的联系人编号：\n");
	scanf("%s",ID);
	while (p1!=NULL&&(p1->pnext)!=NULL)
	{
		p2 = p1->pnext;
		if (p2!=NULL&&strcmp(p2->ID,ID)==0)
		{
			printf("您查找的联系人信息如下：\n");
			printf("编号:%s 姓名：%s 职业：%s 电话：%s 邮箱：%s ",p2->ID,p2->Name,p2->occu,p2->tel,p2->email);
			return;
		}
		else if (p2->pnext == NULL && strcmp(p2->ID,ID)!=0)
		{
			printf("您的通讯录无该联系人！\n");
		}
		p1 = p1->pnext; 
	}
}	
	if(m==2)
{   
	char Name[10];
	printf("请输入您要查找的联系人姓名：\n");
	scanf("%s",Name);
	while (p1!=NULL&&(p1->pnext)!=NULL)
	{
		p2 = p1->pnext;
		if (p2!=NULL&&strcmp(p2->Name,Name)==0)
		{
			printf("您查找的联系人信息如下：\n");
			printf("编号:%s 姓名：%s 职业：%s 电话：%s 邮箱：%s ",p2->ID,p2->Name,p2->occu,p2->tel,p2->email);
			return;
		}
		else if (p2->pnext == NULL && strcmp(p2->Name,Name)!=0)
		{
			printf("您的通讯录无该联系人！\n");
		}
		p1 = p1->pnext; 
	}
}

if(m==3)
{   
	char occu[10];
	printf("请输入您要查找的联系人职业：\n");
	scanf("%s",occu);
	while (p1!=NULL&&(p1->pnext)!=NULL)
	{
		p2 = p1->pnext;
		if (p2!=NULL&&strcmp(p2->occu,occu)==0)
		{
			printf("您查找的联系人信息如下：\n");
			printf("编号:%s 姓名：%s 职业：%s 电话：%s 邮箱：%s ",p2->ID,p2->Name,p2->occu,p2->tel,p2->email);
			return;
		}
		else if (p2->pnext == NULL && strcmp(p2->occu,occu)!=0)
		{
			printf("您的通讯录无该联系人！\n");
		}
		p1 = p1->pnext; 
	}
}

if(m==4)
{   
	char tel[15];
	printf("请输入您要查找的联系人电话：\n");
	scanf("%s",tel);
	while (p1!=NULL&&(p1->pnext)!=NULL)
	{
		p2 = p1->pnext;
		if (p2!=NULL&&strcmp(p2->tel,tel)==0)
		{
			printf("您查找的联系人信息如下：\n");
			printf("编号:%s 姓名：%s 职业：%s 电话：%s 邮箱：%s ",p2->ID,p2->Name,p2->occu,p2->tel,p2->email);
			return;
		}
		else if (p2->pnext == NULL && strcmp(p2->tel,tel)!=0)
		{
			printf("您的通讯录无该联系人！\n");
		}
		p1 = p1->pnext; 
	}
}

if(m==5)
{   
	char email[30];
	printf("请输入您要查找的联系人电话：\n");
	scanf("%s",email);
	while (p1!=NULL&&(p1->pnext)!=NULL)
	{
		p2 = p1->pnext;
		if (p2!=NULL&&strcmp(p2->email,email)==0)
		{
			printf("您查找的联系人信息如下：\n");
			printf("编号:%s 姓名：%s 职业：%s 电话：%s 邮箱：%s ",p2->ID,p2->Name,p2->occu,p2->tel,p2->email);
			return;
		}
		else if (p2->pnext == NULL && strcmp(p2->email,email)!=0)
		{
			printf("您的通讯录无该联系人！\n");
		}
		p1 = p1->pnext; 
	}
}

if (m==6)
{
	return;
}
}
  

//删除联系人函数模块 
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
void display_record(PNode phead)
{
	if (phead == NULL)
	{
		printf("您的通讯录为空\n"); 
		return;
	}
	PNode ptemp = phead->pnext ;
	while (ptemp)
	{
		printf("编号：%s 姓名：%s 职业：%s 电话：%s 邮箱：%s\n",ptemp->ID ,ptemp->Name ,ptemp->occu ,ptemp->tel,ptemp->email );
		ptemp = ptemp->pnext ;
	}
}     
//修改联系人函数 
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
			printf("编号:%s 姓名：%s 职业：%s 电话：%s 邮箱：%s \n",p2->ID,p2->Name,p2->occu,p2->tel,p2->email);
		    printf("请您开始修改联系人信息！\n");
			printf ("请输入新的联系人编号:  ");
			scanf ("%s", p2->ID);
			printf ("请输入新的联系人姓名:  ");
			scanf ("%s", p2->Name);
			printf ("请输入新的联系人职业: ");
			scanf ("%s", p2->occu);
			printf ("请输入新的联系人电话: ");
			scanf ("%s", p2->tel);
			printf ("请输入新的联系人邮箱: ");
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

//将目前已有的联系人进行排序 
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
	printf("已经按照姓氏升降排序成功！按任意键继续！\n");
}
 
//从文件中读数据到链表中
void readDATA(PNode phead)
{ 
	int count;
	PNode pfind = phead;
	PNode padd =NULL;
	FILE *fp ;                                     //一个文件指针 
    fp = fopen("data.txt","r");                       //读取文件	
	if (fp == NULL)
	{
		printf("文件读取失败\n");
	} 
	while (!feof(fp))
	{
		padd = (PNode)malloc(sizeof(Node));	                          //建立一个节点 
		fscanf(fp,"编号：%s 姓名：%s 职业：%s 电话：%s 邮箱：%s\n",padd ->ID,padd -> Name,padd ->occu,padd ->tel,padd ->email); 
		padd ->pnext = NULL;
		pfind -> pnext =padd;
		pfind = pfind ->pnext;
		count++;
	}
	printf("当前有%d个联系人，请选择功能:\n",count) ;
 	fclose(fp);
}  

//把链表中数据写入data文本里  
void writeDATA(PNode phead)
{
	PNode pfind = phead -> pnext;
 	FILE *fp = NULL;                                //一个文件指针 
	fp = fopen("data.txt","w");
	while (pfind != NULL)                           //遍历链表 
	{
		fprintf(fp,"编号：%s 姓名：%s 职业：%s 电话：%s 邮箱：%s\n",pfind ->ID,pfind ->Name,pfind ->occu,pfind ->tel,pfind ->email) ;
		pfind = pfind -> pnext; 
	}
	fclose(fp);
	printf("系统已退出！欢迎使用！\n");
 	exit(0); 
}  
 
void menu()
 {
	system("cls");
	printf("\n\n\n\n\n\n");
	printf("\t\t|---------------------通讯录---------------------|\n");
	printf("\t\t|                 0.保存并退出                   |\n");
	printf("\t\t|                 1.添加联系人信息               |\n");
	printf("\t\t|                 2.查找联系人信息               |\n");
	printf("\t\t|                 3.修改联系人信息               |\n");
	printf("\t\t|                 4.删除联系人信息               |\n");
	printf("\t\t|                 5.排序联系人信息               |\n");
	printf("\t\t|                 6.显示联系人信息               |\n");
	printf("\t\t|------------------------------------------------|\n\n");
	printf("\t\t\t  请选择功能(0-6):\n");
 }
