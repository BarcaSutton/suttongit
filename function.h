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

int CreateList(PNode Ph,int ID, char *Name, char *occu, char *tel, char *email);   //联系人的添加函数 
void search(PNode phead,char *Name);                                     //查找联系人函数 
void revise(PNode phead,char *Name);                                                       //修改联系人函数 
void del(PNode phead,char *Name);                                    //删除联系人函数 
void sort(PNode phead);                                                         //排序联系人函数 
void displaycurrent(PNode Ph);                                       //显示当前联系人函数 
void display_record(PNode Ph);                                       //显示所有已经创建的联系人 
void menu();                                                         //主菜单函数 
void readDATA(PNode phead);                                          //从文件中读取数据到链表中 
void writeDATA(PNode phead);                                         //把链表中数据写入data文本里    
#endif
