#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "addritem.h"
#include "function.h"

//void creatphead();
void input();                      //��ϵ�˵����� 
void search();                     //������ϵ�� 
void update();                     //�޸���ϵ�� 
void del(struct node *phead);                        //ɾ����ϵ�� 
void sort();                       //������ϵ�� 
void display();                    //��ʾ��ϵ�� 
void menu();

int main()
{ 
	struct node *phead;
	int n;
	menu();                          //�˵����� 
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
			case 4:del(phead);
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
