#ifndef _ADDRITEM_H_
#define _ADDRITEM_H_

int CreateList(PNode phead,int ID, char *Name, char *occu, char *tel, char *email);   //������ϵ�� 
void search(PNode phead,char *Name);                                               //������ϵ�� 
void revise(PNode phead,char *Name);                                               //�޸���ϵ�� 
void del(PNode phead);                                                     //ɾ����ϵ�� 
void sort(PNode phead);                                                               //������ϵ�� 
void displaycurrent(PNode phead);                                             //�жϵ�ǰ������ϵ���Ƿ�ɹ� 
void display_record(PNode phead);                                             //��ʾ�����Ѿ���������ϵ�� 
void menu(); 
void readDATA(PNode phead); 
void writeDATA(PNode phead);
#endif 
