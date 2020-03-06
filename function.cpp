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
	struct node *pfind = phead;
 	struct node *padd = NULL;                            //创造一个新节点 
 	padd = (struct node *)malloc(sizeof(struct node));
    while (pfind -> pnext!=NULL)                          //遍历找尾节点 
 	{
 	pfind = pfind -> pnext;
 	}	
	printf("请输入联系人姓名:\n"); 
	scanf("%s",padd -> DATA.name); 
    if (strcmp(padd->DATA.name,"0")==0) 
    { 
    printf("姓名不能为0,增加失败!\n"); 
    //return(phead); 
    } 
    else
    {
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
}

void del(struct node *phead)
{
	char delname;                                  //要删除的联系人名字 
	struct node *p1 = phead;
	struct node *p2 = phead -> pnext;             //定义指针p1和p2方便查找 
	struct node *p3 = NULL;                       //定义p3作为一个临时的指针 
	printf("请输入要删除的联系人名字:\n");
	scanf("%s",&delname);
	
	while (p2 != NULL)
	{
		if (p2 -> DATA.name ==  &delname)                  //判断删除的名字是否有匹配项 
		{
			break;
		}
		p1 = p1 -> pnext;
		p2 = p2 -> pnext; 
	 } 
	 if (p2 == NULL)
	 {
	 	printf("抱歉，无此联系人记录\n");
	 }
	 else
	 {
	 	p3 = p2 -> pnext;
	 	free(p2);
	 	p2 = NULL;
	 	p1 -> pnext = p3;
	 }
	  
}

void search()
{
	
}

void revise()
{
	
}

void sort()
{
	
}

void display(struct node *phead)
{
	struct node *pfind = phead -> pnext;
	while (pfind!=NULL)
	{
		printf("姓名：%s\t 职业：%s\t 职称：%s\t 电话：%s\t 邮箱：%s\n",pfind -> DATA.name,pfind -> DATA.occu,pfind -> DATA.prof,pfind -> DATA.tel,pfind -> DATA.email);
		pfind = pfind -> pnext;
	}
	
}

void readDATA(struct node *phead)
{
	int count; 
	struct node *pfind = phead;
	struct node *padd =NULL;
	FILE * fp = NULL;                                //一个文件指针 
    fp = fopen("data.txt","r");                       //读取文件	
	if (fp == NULL)
	{
		printf("文件读取失败\n");
		return;	
	} 
	while (1)
	{
		padd = (struct node *)malloc(sizeof(struct node));	  //建立一个新指针 
		fscanf(fp,"%s%s%s%s%s",padd -> DATA.name,padd -> DATA.occu,padd -> DATA.prof,padd -> DATA.tel,padd -> DATA.email); 
		padd -> pnext = NULL;
		if (feof(fp))                       //判断是不是到末尾 
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
 	FILE * fp = NULL;                                //一个文件指针 
	fp = fopen("data.txt","w");
	while (pfind != NULL)                      //遍历链表 
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
