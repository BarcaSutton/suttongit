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
	int n = 0;                                    //用于储存用户的选择 
 	PNode phead;
	phead = (PNode)malloc(sizeof(Node));	       //phead的类型以及分配的空间 
 	phead = initialize();  
	menu();                                       //菜单功能 
	scanf("%d",&n);                               //用户输入 
	while(1) 
	{
		switch(n)
		{
		case 1: input(phead);
                displaycurrent(phead);            //显示创建联系人是否成功 
				break;
		case 2: search(phead);
				break;
		case 3: revise(phead);
				break;
		case 4: del(phead);
				break;
		case 5:sort(phead);
				break;
 	    case 6:	display_record(phead);
				break;
 		case 0:  
				exit(0);
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
