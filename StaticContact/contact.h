
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

//��ʼ��ͨѶ¼
void InitContact(Contact* pc);
//����ͨѶ¼��Ա
void AddContact(Contact* pc);
//��ʾͨѶ¼
void ShowContact(Contact* pc);
//ɾ��ͨѶ¼
void DeleteContact(Contact* pc);
//�޸�ͨѶ¼
void ModifyContact(Contact* pc);
//������ϵ��
void SearchContact(Contact* pc);
//����������
void SortByName(Contact* pc);