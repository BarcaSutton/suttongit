#ifndef _FUNCTION_H_
#define _FUNCTION_H_

typedef struct node                 
{
	char ID[10]; 
	char Name[10];
	char occu[10]; 
	char tel[15];
	char email[30];
	struct node *pnext;
}Node;

typedef Node* PNode;

void insert(PNode p);                                                                     //β�巨����һ���µĽ�� 
void emptynode(PNode p );                                                                 // ������Ľ����г�ʼ������ 
PNode initialize();                                                                       //��ʼ��������  
void judge_empty(PNode p);                                                               //�жϴ����ָ���Ƿ�Ϊ��  
  
void input(PNode phead);                                         					    //��ϵ�˵���Ӻ��� 
void search(PNode phead);                                                               //������ϵ�˺��� 
void revise(PNode phead );                                                              //�޸���ϵ�˺��� 
void del(PNode phead );                                                                 //ɾ����ϵ�˺��� 
void sort(PNode phead);                                                                 //������ϵ�˺��� 
void displaycurrent(PNode phead);                                                       //��ʾ��ǰ��ϵ�˺��� 
void display_record(PNode phead);                                                       //��ʾ�����Ѿ���������ϵ�� 
void menu();                                                                             //���˵����� 
#endif
