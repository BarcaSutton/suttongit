#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#define LEN sizeof(struct addritem)                    //����ṹ��ĳ���//
#define DATA addrinfo[i].name,addrinfo[i].occu,addrinfo[i].tel,addrinfo[i].email,addrinfo[i].prof//����ṹ������Ԫ���еĸ�����Ա// 

 struct addritem                //����ṹ���Ա// 
{
	char name[10];
	char occu[10];
	char prof[10]; 
	char tel[15];
	char email[30];
};

void input();                      //��ϵ�˵���Ӻ��� 
void search();                     //������ϵ�˺��� 
void update();                     //�޸���ϵ�˺��� 
void del();                        //ɾ����ϵ�˺��� 
void sort();                       //������ϵ�˺��� 
void display();                    //��ʾ��ϵ�˺��� 
void menu();                       //���˵����� 

#endif
