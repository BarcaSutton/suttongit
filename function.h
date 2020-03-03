#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#define LEN sizeof(struct addritem)                    //定义结构体的长度//
#define DATA addrinfo[i].name,addrinfo[i].occu,addrinfo[i].tel,addrinfo[i].email,addrinfo[i].prof//代表结构体数组元素中的各个成员// 


void input();                      //联系人的添加函数 
void search();                     //查找联系人函数 
void update();                     //修改联系人函数 
void del();                        //删除联系人函数 
void sort();                       //排序联系人函数 
void display();                    //显示联系人函数 
void menu();                       //主菜单函数 

#endif
