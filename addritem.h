#ifndef _ADDRITEM_H_
#define _ADDRITEM_H_
#define DATA addrinfo[i].name,addrinfo[i].occu,addrinfo[i].tel,addrinfo[i].email,addrinfo[i].prof//����ṹ������Ԫ���еĸ�����Ա//     

struct addritem                //����ṹ���Ա// 
{
	char name[10];
	char occu[10];
	char prof[10]; 
	char tel[15];
	char email[30];
};

#endif 
