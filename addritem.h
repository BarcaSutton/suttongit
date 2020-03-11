#ifndef _ADDRITEM_H_
#define _ADDRITEM_H_

PNode initialize();                                                                      //尾插法创建链表 
void input(PNode phead);                                                                 //创建联系人 
void search(PNode phead);                                                                //查找联系人 
void revise(PNode phead );                                                               //修改联系人 
void del(PNode phead );                                                                  //删除联系人 
void sort(PNode phead);                                                                  //排序联系人 
void displaycurrent(PNode phead);                                                        //判断当前创建联系人是否成功 
void display_record(PNode phead);                                                        //显示所有已经创建的联系人 
void menu(); 
#endif 
