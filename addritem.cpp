#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "function.h"
#include "addritem.h"

//struct addritem addrinfo[100];
void input();                      //联系人的输入 
void search();                     //查找联系人 
void update();                     //修改联系人 
void del();                        //删除联系人 
void sort();                       //排序联系人 
void display();                    //显示联系人 

int main()
{ 
	int n;
	menu();                         //菜单功能 
	scanf("%d",&n);                 //用户输入 
	while(n)
	{
		switch(n)
		{
			case 1:input();
			break;
			case 2:search();
			break;
			case 3:update();
			break;
			case 4:del();
			break;
			case 5:sort();
			break;
			case 6:display();
			break;
			default:
			break;
		}
		getch();
		menu();
		scanf("%d",&n);
	}
} 
