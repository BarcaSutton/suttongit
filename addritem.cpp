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
	int n = 0;                               //���ڴ����û���ѡ�� 
	char ID[10]; 
	char Name[10];
	char occu[10]; 
	char tel[15];
	char email[30];
	
	PNode phead;
	phead = (PNode)malloc(sizeof(Node));	   //phead�������Լ�����Ŀռ� 
	if (phead == NULL)
	{
		printf("ͷ�ڵ㴴��ʧ��\n");	
		return ERROR;
	} 
	else
	{
		phead -> pnext = NULL;
	}
 	
	menu();                            //�˵����� 
    readDATA(phead);
	scanf("%d",&n);                    //�û����� 
	while(1) 
	{
		switch(n)
		{
		case 1: if (CreateList(phead, ID, Name, occu, tel, email) != OK)
            	{
                	return ERROR;
                }
                    displaycurrent(phead);            //��ʾ������ϵ���Ƿ�ɹ� 
				break;
		case 2: search(phead);
				break;
		case 3:printf("��������Ҫ�޸ĵ���ϵ��������\n");
				scanf("%s",Name);
				revise(phead,Name);
				break;
		case 4:printf("��������Ҫɾ������ϵ��������\n");
				scanf("%s",Name);
				del(phead,Name);
				break;
		case 5:sort(phead);
				break;
 	    case 6:	printf("����ͨѶ¼��ϵ����Ϣ���£�\n");
		    	display_record(phead);
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
