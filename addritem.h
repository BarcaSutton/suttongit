#ifndef _ADDRITEM_H_
#define _ADDRITEM_H_
//#define DATA addrinfo[i].name,addrinfo[i].occu,addrinfo[i].tel,addrinfo[i].email,addrinfo[i].prof//����ṹ������Ԫ���еĸ�����Ա//     
 
void creatphead();               //�������phead����
void input(struct node *phead);                      //��ϵ�˵����� 
void search();                     //������ϵ�� 
void update();                     //�޸���ϵ�� 
void del();                        //ɾ����ϵ�� 
void sort();                       //������ϵ�� 
void display();                    //��ʾ��ϵ�� 
void menu(); 

#endif 
