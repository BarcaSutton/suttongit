#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "addritem.h"
#include "function.h"

//struct node *creatphead();
struct node *input();                      //联系人的输入 
void search();                     //查找联系人 
void revise();                     //修改联系人 
void del(struct node *phead);                        //删除联系人 
void sort();                       //排序联系人 
void display(struct node *phead);                    //显示联系人 
void menu();

int main()
{ 
	struct node *phead = NULL;
//	creatphead();
	int n;
	menu();                            //菜单功能 
    scanf("%d",&n);                    //用户输入 
	while(1) 
	{
		switch(n)
		{
			case 1:input();
			break;
			case 2:search();
			break;
			case 3:revise();
			break;
			case 4:del(phead);
			break;
			case 5:sort();
			break;
			case 6:display(phead);
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
