#ifndef _ADDRITEM_H_
#define _ADDRITEM_H_

//struct node *creatphead();
struct node *input();                      //��ϵ�˵����� 
void search();                     //������ϵ�� 
void revise();                     //�޸���ϵ�� 
void del(struct node *phead);                        //ɾ����ϵ�� 
void sort();                       //������ϵ�� 
void display(struct node *phead);                    //��ʾ��ϵ�� 
void menu(); 
void readDATA(struct node *phead); 
void writeDATA(struct node *phead);
#endif 
