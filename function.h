#ifndef _FUNCTION_H_
#define _FUNCTION_H_
//#define LEN sizeof(struct addritem)                    //定义结构体的长度//

struct addritem                //定义结构体成员// 
{
	char name[10];
	char occu[10];
	char prof[10]; 
	char tel[15];
	char email[30];
};

struct node
{
	addritem DATA;                                //数据域 
	struct node *pnext;                          //指针域 
};

//struct node *phead; 
//void creatphead();
void input();                                      //联系人的添加函数 
void search();                                     //查找联系人函数 
void update();                                     //修改联系人函数 
void del();                                        //删除联系人函数 
void sort();                                       //排序联系人函数 
void display();                                    //显示联系人函数 
void menu();                                       //主菜单函数 

#endif
