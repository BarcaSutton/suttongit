#ifndef _FUNCTION_H_
#define _FUNCTION_H_
//#define LEN sizeof(struct addritem)                    //����ṹ��ĳ���//

struct addritem                //����ṹ���Ա// 
{
	char name[10];
	char occu[10];
	char prof[10]; 
	char tel[15];
	char email[30];
};

struct node
{
	addritem DATA;                                //������ 
	struct node *pnext;                          //ָ���� 
};

//void creatphead();
void input();                                      //��ϵ�˵���Ӻ��� 
void search();                                     //������ϵ�˺��� 
void update();                                     //�޸���ϵ�˺��� 
void del();                                        //ɾ����ϵ�˺��� 
void sort();                                       //������ϵ�˺��� 
void display();                                    //��ʾ��ϵ�˺��� 
void menu();                                       //���˵����� 
void readDATA();                                  //���ļ��ж�ȡ���ݵ������� 
#endif
