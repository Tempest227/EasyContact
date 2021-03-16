#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

enum Option
{
	EXIT,
	ADD,
	DELETE,
	MODIFY,
	SEARCH,
	SHOW,
	SORT,
	CLEAR
};

void menu()
{
	printf("***1.add              2.delete***\n");
	printf("***3.modify           4.search***\n");
	printf("***5.show             6.sort  ***\n");
	printf("***7.clear                    ***\n");
	printf("***         0.exit            ***\n");
}

int main()
{
	int input = 0;
	Contact con;
	InitContact(&con);

	do
	{
		menu();
		printf("ÇëÊäÈëÑ¡Ïî>...\n");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DELETE:
			DeleteContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			SortByName(&con);
			break;
		case CLEAR:
			Clear(&con);
		}
	} while (input);

	return 0;
}