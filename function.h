#ifndef _FUNCTION_H_
#define _FUNCTION_H_

typedef struct node                 
{
	int ID; 
	char Name[10];
	char occu[10]; 
	char tel[15];
	char email[30];
	struct node *pnext;
}Node;

typedef Node* PNode;

int CreateList(PNode phead,int ID, char *Name, char *occu, char *tel, char *email);   //��ϵ�˵���Ӻ��� 
void search(PNode phead,char *Name);                                     //������ϵ�˺��� 
void revise(PNode phead,char *Name);                                                       //�޸���ϵ�˺��� 
void del(PNode phead,char *Name);                                    //ɾ����ϵ�˺��� 
void sort(PNode phead);                                                         //������ϵ�˺��� 
void displaycurrent(PNode phead);                                       //��ʾ��ǰ��ϵ�˺��� 
void display_record(PNode phead);                                       //��ʾ�����Ѿ���������ϵ�� 
void menu();                                                         //���˵����� 
void readDATA(PNode phead);                                          //���ļ��ж�ȡ���ݵ������� 
void writeDATA(PNode phead);                                         //������������д��data�ı���    
#endif
