#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

#include "function.h"
#include "addritem.h"
 
#define OK            0
#define ERROR        -1
#define MALLOC_ERROR -2 

 //struct node *input();                               //联系人的输入 
void search();                                      //查找联系人 
void revise();                                      //修改联系人 
void del(PNode phead);                       //删除联系人 
void sort();                                        //排序联系人 
void display(PNode phead);                   //显示联系人 
void menu();

int main()
{ 
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
	int n;
	menu();                            //菜单功能 
    scanf("%d",&n);                    //用户输入 
	while(1) 
	{
		switch(n)
		{
			case 1: if (phead)
				{
					if (CreateList(phead, ID, Name, occu, tel, email) != OK)
                    {
                     return ERROR;
                    }
                    display(phead); 
                }
			break;
			case 2: printf("请输入您要查找的联系人：\n");
					scanf("%s",Name);
					search(phead,Name);
					break;
			break;
			case 3:revise();
			break;
//			case 4:del(phead);
//			break;
//			case 5:sort();
//			break;
//			case 6:display(phead);
//			break;
//			case 0:writeDATA(phead);
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
