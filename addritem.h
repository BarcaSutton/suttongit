#ifndef _ADDRITEM_H_
#define _ADDRITEM_H_
//#define DATA addrinfo[i].name,addrinfo[i].occu,addrinfo[i].tel,addrinfo[i].email,addrinfo[i].prof//代表结构体数组元素中的各个成员//     
 
void creatphead();               //将链表的phead创建
void input(struct node *phead);                      //联系人的输入 
void search();                     //查找联系人 
void update();                     //修改联系人 
void del();                        //删除联系人 
void sort();                       //排序联系人 
void display();                    //显示联系人 
void menu(); 

#endif 
