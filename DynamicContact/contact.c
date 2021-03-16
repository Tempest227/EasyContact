#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"


//初始化通讯录
void InitContact(Contact* pc)
{
	pc->size = 0;
	pc->capacity = 3;
	pc->data = (PeoInfo*)malloc(sizeof(PeoInfo)*pc->capacity);

	if (pc->data != NULL)
	{
		printf("初始化成功\n");
	}
	else
	{
		printf("初始化失败\n");
		return;
	}
}

//增加通讯录成员
void AddContact(Contact* pc)
{
	if (pc->size == pc->capacity)
	{
		pc->capacity += 2;
		PeoInfo* ptr = (PeoInfo*)realloc(pc->data, pc->capacity*sizeof(PeoInfo));

		if (ptr == NULL)
		{
			perror("扩容失败");
			exit(-1);
		}
		pc->data = ptr;
	}
	
	printf("请输入:地址，姓名，电话，年龄\n");
	scanf("%s %s %s %d", pc->data[pc->size].addr, 
						 pc->data[pc->size].name, 
						 pc->data[pc->size].tel, 
						 &pc->data[pc->size].age);
	pc->size++;
}

//显示通讯录
void ShowContact(Contact* pc)
{
	if (pc->size == 0)
	{
		printf("通讯录为空\n");
		return;
	}
	printf("%-15s\t%-15s\t%-15s\t%-15s\n", "地址", "姓名", "电话", "年龄");
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

//删除通讯录指定成员
void DeleteContact(Contact* pc)
{
	char name[NAME_MAX];
	printf("请输入要删除的联系人姓名>...\n");
	scanf("%s", name);
	int pos = FindByName(pc, name);

	if (pos == -1)
	{
		printf("联系人不存在\n");
		return;
	}

	int i;
	for (i = pos; i < pc->size - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->size--;

	printf("删除成功\n");
}

//修改通讯录
void ModifyContact(Contact* pc)
{
	char name[NAME_MAX];
	printf("请输入要删除的联系人姓名>...\n");
	scanf("%s", name);
	int pos = FindByName(pc, name);

	if (pos == -1)
	{
		printf("联系人不存在\n");
		return;
	}
	printf("请输入修改信息:地址，姓名，电话，年龄\n");
	scanf("%s %s %s %d", pc->data[pos].addr,
						 pc->data[pos].name,
						 pc->data[pos].tel,
						&pc->data[pos].age);
}

//查找联系人
void SearchContact(Contact* pc)
{
	char name[NAME_MAX];
	printf("请输入要查找的联系人姓名>...\n");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("联系人不存在\n");
		return;
	}
	printf("%-15s\t%-15s\t%-15s\t%-15s\n", "地址", "姓名", "电话", "年龄");
	printf("%-15s\t%-15s\t%-15s\t%d\n", 
		pc->data[pos].addr,
		pc->data[pos].name,
		pc->data[pos].tel,
		pc->data[pos].age);
}
//按姓名排序
int compare(const PeoInfo *arg1, const PeoInfo *arg2)
{
	return strcmp(arg1->name, arg2->name);
}

void SortByName(Contact* pc)
{
	qsort(pc->data, pc->size, sizeof(PeoInfo), compare);
}
//销毁通讯录
void DestroyConcat(Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->capacity = 0;
	pc->size = 0;
}