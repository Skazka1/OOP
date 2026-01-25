#include <iostream>
#include "list.h"

int main() {
	List list = *(new List());
	int a, b = 0;
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
			list.Add(new Item());
			break;

		case 2:
			printf("\n%i\n",  list.Count());
			break;

		case 3:
			list.PrintList();
			break;

		case 4:
			printf("what index?\n");
			std::cin >> b;
			list.Insert(new Item(), b);
			break;
		case 5:
			list.Clear();
			break;

		case 6:
			printf("what index?\n");
			std::cin >> b;
			list.Delete(b);
		}
	}
}