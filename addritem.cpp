#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "addritem.h"
#include "function.h"

void input();                      //��ϵ�˵����� 
void search();                     //������ϵ�� 
void update();                     //�޸���ϵ�� 
void del();                        //ɾ����ϵ�� 
void sort();                       //������ϵ�� 
void display();                    //��ʾ��ϵ�� 
void menu();

int main()
{ 
	int n;
	menu();                          //�˵����� 
   // creatphead();
	scanf("%d",&n);                    //�û����� 
	while(1)
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
	return 0;
} 
