#ifndef _ADDRITEM_H_
#define _ADDRITEM_H_

//struct node *creatphead();
struct node *input();                      //联系人的输入 
void search();                     //查找联系人 
void revise();                     //修改联系人 
void del(struct node *phead);                        //删除联系人 
void sort();                       //排序联系人 
void display(struct node *phead);                    //显示联系人 
void menu(); 
void readDATA(struct node *phead); 
void writeDATA(struct node *phead);
#endif 
