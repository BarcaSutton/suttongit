#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "addritem.h"
#include "function.h"

//void creatphead();
void input();                      //��ϵ�˵����� 
void search();                     //������ϵ�� 
void revise();                     //�޸���ϵ�� 
void del(struct node *phead);                        //ɾ����ϵ�� 
void sort();                       //������ϵ�� 
void display(struct node *phead);                    //��ʾ��ϵ�� 
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
			case 3:revise();
			break;
			case 4:del(phead);
			break;
			case 5:sort();
			break;
			case 6:display(phead);
			break;
			case 7:writeDATA(phead);
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
