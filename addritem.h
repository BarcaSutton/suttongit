#ifndef _ADDRITEM_H_
#define _ADDRITEM_H_

int CreateList(PNode Ph,int ID, char *Name, char *occu, char *tel, char *email);   //联系人的输入 
void search(PNode phead,char *Name);                                           //查找联系人 
void revise();                                           //修改联系人 
void del(PNode phead);                                   //删除联系人 
void sort();                                             //排序联系人 
void display(PNode phead);                               //显示联系人 
void menu(); 
void readDATA(PNode phead); 
void writeDATA(PNode phead);
#endif 
