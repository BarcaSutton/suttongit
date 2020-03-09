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
	PNode pfind = (PNode)malloc(sizeof(Node)/sizeof(char));              //定义一个pfind并分配内存 
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
 
/*void del(PNode phead)
{
	char delname[10];                                  //要删除的联系人名字 
	PNode p1 = phead;
	PNode p2 = phead -> pnext;             //定义指针p1和p2方便查找 
	PNode p3 = NULL;                       //定义p3作为一个临时的指针 
	printf("请输入要删除的联系人名字:\n");
	scanf("%s",delname);
	
	while (p2 != NULL)
	{
		if (strcmp(p2 -> DATA.name,delname)==0)                  //判断删除的名字是否有匹配项 
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
	FILE * fp = NULL;                                //一个文件指针 
    fp = fopen("data.txt","r");                       //读取文件	
	if (fp == NULL)
	{
		printf("文件读取失败\n");
		return;	
	} 
	while (1)
	{
		padd = (PNode)malloc(sizeof(Node)/sizeof(char));	  //建立一个新指针 
		fscanf(fp,"%d%s%s%s%s",&padd ->ID,padd -> name,padd ->occu,padd ->tel,padd ->email); 
		padd ->pnext = NULL;
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

void writeDATA(PNode phead)
{
 	PNode pfind = phead -> pnext;
 	FILE * fp = NULL;                                //一个文件指针 
	fp = fopen("data.txt","w");
	while (pfind != NULL)                      //遍历链表 
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
	printf("\t\t|---------------------通讯录---------------------|\n");
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
