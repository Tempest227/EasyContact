#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"


//��ʼ��ͨѶ¼
void InitContact(Contact* pc)
{
	memset(pc->data, 0, sizeof(pc->data));
	pc->size = 0;
}

//����ͨѶ¼��Ա
void AddContact(Contact* pc)
{
	if (pc->size == PEO_MAX)
	{
		printf("ͨѶ¼����\n");
		return;
	}
	printf("������:��ַ���������绰������\n");
	scanf("%s %s %s %d", pc->data[pc->size].addr, 
						 pc->data[pc->size].name, 
						 pc->data[pc->size].tel, 
						 &pc->data[pc->size].age);
	pc->size++;
}

//��ʾͨѶ¼
void ShowContact(Contact* pc)
{
	if (pc->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
		return;
	}
	printf("%-15s\t%-15s\t%-15s\t%-15s\n", "��ַ", "����", "�绰", "����");
	int i;
	for (i = 0; i < pc->size; i++)
	{
		printf("%-15s\t%-15s\t%-15s\t%d\n", pc->data[i].addr,
										  pc->data[i].name,
										  pc->data[i].tel,
										  pc->data[i].age);
	}
}

static int FindByName(Contact* pc, char* name)
{
	int i;

	for (i = 0; i < pc->size; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}

//ɾ��ͨѶ¼
void DeleteContact(Contact* pc)
{
	char name[NAME_MAX];
	printf("������Ҫɾ������ϵ������>...\n");
	scanf("%s", name);
	int pos = FindByName(pc, name);

	if (pos == -1)
	{
		printf("��ϵ�˲�����\n");
		return;
	}

	int i;
	for (i = pos; i < pc->size - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->size--;

	printf("ɾ���ɹ�\n");
}

//�޸�ͨѶ¼
void ModifyContact(Contact* pc)
{
	char name[NAME_MAX];
	printf("������Ҫɾ������ϵ������>...\n");
	scanf("%s", name);
	int pos = FindByName(pc, name);

	if (pos == -1)
	{
		printf("��ϵ�˲�����\n");
		return;
	}
	printf("�������޸���Ϣ:��ַ���������绰������\n");
	scanf("%s %s %s %d", pc->data[pos].addr,
						 pc->data[pos].name,
						 pc->data[pos].tel,
						&pc->data[pos].age);
}

//������ϵ��
void SearchContact(Contact* pc)
{
	char name[NAME_MAX];
	printf("������Ҫ���ҵ���ϵ������>...\n");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("��ϵ�˲�����\n");
		return;
	}
	printf("%-15s\t%-15s\t%-15s\t%-15s\n", "��ַ", "����", "�绰", "����");
	printf("%-15s\t%-15s\t%-15s\t%d\n", 
		pc->data[pos].addr,
		pc->data[pos].name,
		pc->data[pos].tel,
		pc->data[pos].age);
}
//����������
int compare(const PeoInfo *arg1, const PeoInfo *arg2)
{
	return strcmp(arg1->name, arg2->name);
}

void SortByName(Contact* pc)
{
	qsort(pc->data, pc->size, sizeof(PeoInfo), compare);
}