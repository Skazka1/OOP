#include "stdio.h"
#include "stdlib.h"
#include "list.h"
void Add(struct List* list, struct Item* newElement) {
	if (list != NULL && newElement != NULL) {
		if (list->head == NULL) {
			newElement->next = NULL;
			newElement->prev = NULL;
			list->head = newElement;
			list->tail = newElement;
		}
		else {
			newElement->next = NULL;
			newElement->prev = list->tail;
			list->tail->next = newElement;
			list->tail = list->tail->next;
		}
	}
}

void Delete(struct List* list, const int number) {
	struct Item* delItem;
	if (list != NULL && number >= 0) {
		delItem = Remove(list, number);
		if (delItem != NULL) {
			free(delItem);
		}
	}
}

struct Item* GetItem(const struct List* list, const int number) {
	struct Item* currItem;
	int count = 0;
	if (list != NULL && number >= 0) {
		for (currItem = list->head; currItem != NULL; currItem = currItem->next) {
			if (count == number)
				break;
			count++;
		}
		return currItem;
	}
}

struct Item* Remove(struct List* list, const int number) {
	struct Item* item;
	if (list != NULL && number >= 0) {
		item = GetItem(list, number);
		if (item != NULL) {
			if (list->head == item) {
				if (list->head->next != NULL) {
					list->head = list->head->next;
					list->head->prev = NULL;
				}
				else {
					list->head = NULL;
					list->tail = NULL;
				}
			}
			else if (list->tail == item) {
				list->tail = list->tail->prev;
				list->tail->next = NULL;
			}
			else {
				item->next->prev = item->prev;
				item->prev->next = item->next;
				item->prev = NULL;
				item->next = NULL;
			}
		}
		return item;
	}
}
void Insert(struct List* list, struct Item* newItem, const int number) {
	struct Item* item;
	if (list != NULL && newItem != NULL && number >= 0) {
		item = GetItem(list, number);
		if (item == NULL) {
			Add(list, newItem);
		}
		else if (list->head == item) {
			list->head->prev = newItem;
			list->head->prev->next = list->head;
			list->head = list->head->prev;
			list->head->prev = NULL;

		}
		else {
			newItem->next = item;
			newItem->prev = item->prev;
			item->prev->next = newItem;
			item->prev = newItem;
		}
	}
}
void Clear(struct List* list) {
	if (list != NULL) {
		while (list->head) {
			Delete(list, 0);
		}
	}
}

int Count(const struct List* list) {
	struct Item* item;
	int count = 0;
	if (list != NULL) {
		for (item = list->head; item != NULL; item = item->next) {
			count++;
		}
	}
	return count;
}
int GetIndex(const struct List* list, const struct Item* item) {
	struct Item* currItem;
	int count = 0;
	if (list != NULL && item != NULL) {
		for (currItem = list->head; currItem != NULL; currItem = currItem->next) {
			if (currItem == item) {
				break;
			}
			count++;
		}
		if (currItem == NULL)
			return -1;
		return count;
	}
	return -1;
}

void PrintList(const struct List* list) {
	struct Item* item;
	int i = 0;
	if (list != NULL && list->head != NULL) {
		printf("#\tprev\t\t\tcurrent\t\t\tnext\n");
		for (item = list->head; item != NULL; item = item->next) {
			printf("%d\t%p\t%p\t%p\n", i, item->prev, item, item->next);
			i++;
		}
	}
	else {
		printf("nema shlyahu\n");
	}
}