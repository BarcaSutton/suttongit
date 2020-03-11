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

void insert(PNode p);                                                                     //尾插法创建一个新的结点 
void emptynode(PNode p );                                                                 // 将传入的结点进行初始化处理 
PNode initialize();                                                                       //初始化链表函数  
void judge_empty(PNode p);                                                               //判断传入的指针是否为空  
  
void input(PNode phead);                                         					    //联系人的添加函数 
void search(PNode phead);                                                               //查找联系人函数 
void revise(PNode phead );                                                              //修改联系人函数 
void del(PNode phead );                                                                 //删除联系人函数 
void sort(PNode phead);                                                                 //排序联系人函数 
void displaycurrent(PNode phead);                                                       //显示当前联系人函数 
void display_record(PNode phead);                                                       //显示所有已经创建的联系人 
void menu();                                                                             //主菜单函数 
#endif
