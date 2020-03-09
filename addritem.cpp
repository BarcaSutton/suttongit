#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

#include "function.h"
#include "addritem.h"
 
#define OK            0
#define ERROR        -1
#define MALLOC_ERROR -2 

int main()
{ 
	int count;
	int ID; 
	char Name[10];
	char occu[10]; 
	char tel[15];
	char email[30];
	
	PNode phead;
	phead = (PNode)malloc(sizeof(Node)/sizeof(char));	   //phead的类型以及分配的空间 
	if (phead == NULL)
	{
		printf("头节点创建失败\n");	
		return ERROR;
	} 
	else
	{
		phead -> pnext = NULL;
	}
//	readDATA(phead);
//	printf("当前有%d个联系人",count);
	int n;
	menu();                            //菜单功能 
    readDATA(phead);
	printf("当前有%d个联系人,choose(0-6):",count);
	scanf("%d",&n);                    //用户输入 
	while(1) 
	{
		switch(n)
		{
		case 1: 
				if (CreateList(phead, ID, Name, occu, tel, email) != OK)
            	{
                	return ERROR;
                }
                    displaycurrent(phead);            //显示创建联系人是否成功 
				break;
		case 2: printf("请输入您要查找的联系人：\n");
				scanf("%s",Name);
				search(phead,Name);
				break;
		case 3:revise();
				break;
		case 4:printf("请输入您要删除的联系人姓名：\n");
				scanf("%s",Name);
				del(phead,Name);
				break;
		case 5:sort();
				break;
 	    case 6:printf("您的通讯录联系人信息如下：\n");
		    	display_record(phead);
 				break;
 		case 0:writeDATA(phead);
				break;
		default:
				break;
		}
		getch();
		menu();
		scanf("%d",&n);
	}
	return 0;
} 
