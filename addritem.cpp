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
	int count;
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
//	readDATA(phead);
//	printf("��ǰ��%d����ϵ��",count);
	int n;
	menu();                            //�˵����� 
    readDATA(phead);
	printf("��ǰ��%d����ϵ��,choose(0-6):",count);
	scanf("%d",&n);                    //�û����� 
	while(1) 
	{
		switch(n)
		{
		case 1: 
				if (CreateList(phead, ID, Name, occu, tel, email) != OK)
            	{
                	return ERROR;
                }
                    displaycurrent(phead);            //��ʾ������ϵ���Ƿ�ɹ� 
				break;
		case 2: printf("��������Ҫ���ҵ���ϵ�ˣ�\n");
				scanf("%s",Name);
				search(phead,Name);
				break;
		case 3:revise();
				break;
		case 4:printf("��������Ҫɾ������ϵ��������\n");
				scanf("%s",Name);
				del(phead,Name);
				break;
		case 5:sort();
				break;
 	    case 6:printf("����ͨѶ¼��ϵ����Ϣ���£�\n");
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
