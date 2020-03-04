#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "function.h"
#include "addritem.h"

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
