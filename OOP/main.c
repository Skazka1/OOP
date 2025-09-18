#include "stdio.h"
#include "stdlib.h"
#include "list.h"
int main() {
	struct List list;
	list.head = NULL;
	list.tail = NULL;
	struct Item* item;
	int a,b = 0;
	while (1) {
		printf("1. Add\n2. Count\n3. PrintList\n4. Insert\n5. Clear\n6. Delete\n");
		if (scanf_s("%i", &a) != 1) {
			int c;
			while ((c = getchar()) != '\n' && c != EOF); // Очистка буфера
			printf("Invalid input. Please enter a number.\n");
			continue;
		}
		switch (a) {
		case 1:
			item = (struct Item*)calloc(1, sizeof(struct Item));
			Add(&list, item);
			break;

		case 2:
			printf("\n%i\n", Count(&list));
			break;

		case 3:
			PrintList(&list);
			break;

		case 4:
			printf("what index?\n");
			scanf_s("%i", &b);
			item = (struct Item*)calloc(1, sizeof(struct Item));
			Insert(&list, item, b);
			break;
		case 5:
			Clear(&list);
			break;
		
		case 6:
			printf("what index?\n");
			scanf_s("%i", &b);
			Delete(&list, b);
		}
	}
}
