#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

#include "function.h"
#include "addritem.h"
 
#define OK            0
#define ERROR        -1
#define MALLOC_ERROR -2 

 //struct node *input();                               //��ϵ�˵����� 
void search();                                      //������ϵ�� 
void revise();                                      //�޸���ϵ�� 
void del(PNode phead);                       //ɾ����ϵ�� 
void sort();                                        //������ϵ�� 
void display(PNode phead);                   //��ʾ��ϵ�� 
void menu();

int main()
{ 
	int ID; 
	char Name[10];
	char occu[10]; 
	char tel[15];
	char email[30];
	
	PNode phead;
	phead = (PNode)malloc(sizeof(Node)/sizeof(char));	   //phead�������Լ�����Ŀռ� 
	if (phead == NULL)
	{
		printf("ͷ�ڵ㴴��ʧ��\n");	
		return ERROR;
	} 
	else
	{
		phead -> pnext = NULL;
	}
	int n;
	menu();                            //�˵����� 
    scanf("%d",&n);                    //�û����� 
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
			case 2: printf("��������Ҫ���ҵ���ϵ�ˣ�\n");
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
