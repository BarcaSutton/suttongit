#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "function.h"
#include "addritem.h"

//struct addritem addrinfo[100];
void input();                      //��ϵ�˵����� 
void search();                     //������ϵ�� 
void update();                     //�޸���ϵ�� 
void del();                        //ɾ����ϵ�� 
void sort();                       //������ϵ�� 
void display();                    //��ʾ��ϵ�� 

int main()
{ 
	int n;
	menu();                         //�˵����� 
	scanf("%d",&n);                 //�û����� 
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
