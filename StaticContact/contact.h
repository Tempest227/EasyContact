
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_MAX 12
#define TEL_MAX 20
#define ADDR_MAX 40
#define PEO_MAX 1000

typedef struct PeoInfo
{
	char name[NAME_MAX];
	char tel[TEL_MAX];
	char addr[ADDR_MAX];

	int age;
} PeoInfo;

typedef struct Contact
{
	int size;

	PeoInfo data[PEO_MAX];
}Contact;

//初始化通讯录
void InitContact(Contact* pc);
//增加通讯录成员
void AddContact(Contact* pc);
//显示通讯录
void ShowContact(Contact* pc);
//删除通讯录
void DeleteContact(Contact* pc);
//修改通讯录
void ModifyContact(Contact* pc);
//查找联系人
void SearchContact(Contact* pc);
//按姓名排序
void SortByName(Contact* pc);