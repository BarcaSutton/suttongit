#ifndef _ADDRITEM_H_
#define _ADDRITEM_H_
#define DATA addrinfo[i].name,addrinfo[i].occu,addrinfo[i].tel,addrinfo[i].email,addrinfo[i].prof//代表结构体数组元素中的各个成员//     

struct addritem                //定义结构体成员// 
{
	char name[10];
	char occu[10];
	char prof[10]; 
	char tel[15];
	char email[30];
};

#endif 
