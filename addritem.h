#ifndef _ADDRITEM_H_
#define _ADDRITEM_H_

int CreateList(PNode Ph,int ID, char *Name, char *occu, char *tel, char *email);   //������ϵ�� 
void search(PNode phead,char *Name);                                               //������ϵ�� 
void revise();                                                             //�޸���ϵ�� 
void del(PNode phead);                                                     //ɾ����ϵ�� 
void sort();                                                               //������ϵ�� 
void displaycurrent(PNode Ph);                                             //�жϵ�ǰ������ϵ���Ƿ�ɹ� 
void display_record(PNode Ph);                                             //��ʾ�����Ѿ���������ϵ�� 
void menu(); 
void readDATA(PNode phead); 
void writeDATA(PNode phead);
#endif 
