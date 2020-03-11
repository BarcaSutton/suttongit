#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include "function.h"

#define OK            0
#define ERROR        -1
#define MALLOC_ERROR -2 

//判断传入的指针是否为空 
void judge_empty(PNode p) 
{
	if (p == NULL)
	{
		printf("指针为空！");
		exit(0); 
	}
}

//将传入的结点进行初始化处理 
void emptynode(PNode p )            
{     
	strcpy(p ->ID ,"0");
    strcpy(p ->Name ,"0");
    strcpy(p ->occu ,"0");
    strcpy(p ->tel ,"0");
    strcpy(p ->email ,"0");
    p ->pnext = NULL;
}  

//尾插法创建一个新的结点 
void insert(PNode p)    
{   
	PNode p1;                                                      
	p1 = (PNode)malloc(sizeof(Node));                                      //定义一个P1并分配内存 
	if(p1 == NULL)                                                         //判断分配内存是否成功 
    {
    	printf("创建p1失败\n");
    	exit(1);	 
    }
	emptynode(p1);                                                         //将p1初始化处理 
	p-> pnext=p1;
	p1->pnext=NULL;
}

//初始化链表 
PNode initialize()                                  
{    
	PNode phead;                                                          //创建头结点和p2结点 
	PNode p2;
	phead = (PNode)malloc(sizeof(Node));                                     
	p2 = phead;                                                            //将p2指向phead 
	if(phead == NULL)                                                         
    {
    	printf("空间分配失败\n");
    	exit(-1);	 
    }
    phead-> pnext = NULL;
    emptynode(phead);                                                      //将phead 初始化处理 
	
	insert(p2);
 	if(p2==NULL)                                                          //通过传入p2结点来传出下一个结点 
	{
	return NULL;
	}
	else
	{
	p2 = p2->pnext; 
	}
	return phead;
}

//在链表尾部添加联系人功能 
void input(PNode phead)                        
{   
	judge_empty(phead);
	PNode ptemp;
	ptemp=phead;
	while(ptemp->pnext)
    {
		if(ptemp==NULL)                                                      //传出ptemp结点的下一个结点 
		{
			exit(0); 
		}
		else
		{
			ptemp=ptemp->pnext; 
		}
	} 
	insert(ptemp);
	if(ptemp==NULL)                                                          //传出ptemp结点的下一个结点 
	{
			exit(0); 
	}
	else
	{
		ptemp=ptemp->pnext; 
	}
	printf("添加联系人\n");                                                  //逐步添加联系人信息 
	printf ("请输入联系人编号:  ");
	scanf ("%s", ptemp->ID);
	printf ("请输入联系人姓名:  ");
	scanf ("%s", ptemp->Name);
	printf ("请输入联系人职业: ");
	scanf ("%s", ptemp->occu);
	printf ("请输入联系人电话: ");
	scanf ("%s", ptemp->tel);
	printf ("请输入联系人邮箱: ");
	scanf ("%s", ptemp->email);     
}


//显示当前结点联系人创建情况 
void displaycurrent(PNode phead)                  
{
	judge_empty(phead);
	PNode ptemp; 
	if (phead ==NULL)
	{
		return;	
	}
	ptemp = phead ->pnext;  
	while (ptemp)                                                        //判断联系人是否创建成功 
	{
		if (ptemp->pnext==NULL)
		{
			printf("联系人%s 已成功创建！\n",ptemp->Name);
		}
		ptemp =ptemp->pnext;	
	} 	 
}

//实现分类查找联系人 
void search(PNode phead)
{
	judge_empty(phead);
	int m = 0;
	int n = 0; 
	PNode p1 = phead;                                                             //p1指向头结点 
	PNode p2 = NULL;
	printf("\t\t┌-------------------------------------┐\n");                    //查询方式菜单 
	printf("\t\t│          请选择查询方式:            │\n");
	printf("\t\t│     1.通过编号      2.通过姓名      │\n");
	printf("\t\t│     3.通过职业      4.通过电话号    │\n");
	printf("\t\t│     5.通过邮箱      6.返回          │\n");
	printf("\t\t└-------------------------------------┘\n");
	scanf("\t\t%d",&m);                                                           //选择查询方式 
	do
	{
		n = 0;
		if (m!=1&&m!=2&&m!=3&&m!=4&&m!=5&&m!=6)                                   //判断输入数字是否属于0-6 
		{
			n = 1;
			printf("查询方式错误，请重新输入（0-6）：");
			scanf("%d",&m);           
		} 
    }while(n);
		
if(m==1)                                                           
{   
	char ID[10];                                                              //定义要输入的编号 
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
			return;
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
	printf("请输入您要查找的联系人邮箱：\n");
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

if (m==6)                                         //返回选项 
{
	return;
}
}
  

//删除联系人函数模块 
void del(PNode phead)
{	
	judge_empty(phead);
	char Name[10]; 
	printf("请输入您要删除的联系人姓名：\n");                
	scanf("%s",Name);
	PNode p1 = phead; 
	PNode p2 = NULL;
	while (p1!=NULL && (p1->pnext)!=NULL)                                                 
	{
		p2 = p1->pnext ;
		if (p2!=NULL && strcmp(p2->Name,Name)==0)                          //将要删除的名字与链表中的信息进行比对 
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
	if (phead->pnext ==NULL)                                                 //判断通讯录是否为空 
	{
		printf("您的通讯录为空,请返回并添加联系人\n"); 
		return;
	}
	printf("您的通讯录联系人信息如下，按任意键继续：\n");
	PNode ptemp = phead ->pnext ;                 
	while (ptemp)                                                              //遍历链表输出联系人信息 
	{
		printf("编号：%s 姓名：%s 职业：%s 电话：%s 邮箱：%s\n",ptemp->ID ,ptemp->Name ,ptemp->occu ,ptemp->tel,ptemp->email );
		ptemp = ptemp->pnext ;
	}
}     

//修改联系人函数 
void revise(PNode phead)
{
 	judge_empty(phead);
	char Name[10]; 
	printf("请输入您要修改的联系人姓名：\n");
	scanf("%s",Name);
	PNode p1 = phead;
	PNode p2 = NULL;
	while (p1!=NULL&&(p1->pnext)!=NULL)                                 //遍历链表       
	{
		p2 = p1->pnext;
		if (p2!=NULL&&strcmp(p2->Name,Name)==0)                         //判断和用户输入的名字是否相同 
		{
			printf("您要修改的联系人信息如下：\n");                     //打印联系人信息 
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
		else if (p2->pnext == NULL && strcmp(p2->Name,Name)!=0)                //没有匹配的联系人的情况 
		{
			printf("您的通讯录无该联系人！\n");
		}
		p1 = p1->pnext; 
	}
}

//将目前已有的联系人进行排序 
void sort(PNode phead)
{
	judge_empty(phead);                
	PNode p1;
	PNode p2;	 
	PNode ptemp;                                                      //定义ptemp作为中间桥梁完成p1和p2的数值交换 
	ptemp = (PNode)malloc(sizeof(Node));
	p1 = phead->pnext ;                                      
	p2 = p1->pnext ;
	while (p1!=NULL)                                                  //遍历整个链表 
	{
		while (p2!=NULL)
		{
			if (strcmp (p1->Name ,p2->Name )>0)                        //对首字母进行判断 
			{
				strcpy(ptemp->Name ,p1->Name );                        //进行交换的操作 
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
  
//菜单页面函数 
void menu()
 {
	system("cls");
	printf("\n\n\n\n\n\n");
	printf("\t\t|---------------------通讯录---------------------|\n");
	printf("\t\t|                 0. 退出通讯录                  |\n");
	printf("\t\t|                 1.添加联系人信息               |\n");
	printf("\t\t|                 2.查找联系人信息               |\n");
	printf("\t\t|                 3.修改联系人信息               |\n");
	printf("\t\t|                 4.删除联系人信息               |\n");
	printf("\t\t|                 5.排序联系人信息               |\n");
	printf("\t\t|                 6.显示联系人信息               |\n");
	printf("\t\t|------------------------------------------------|\n\n");
	printf("\t\t\t  请选择功能(0-6):\n");
 }
