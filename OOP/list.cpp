#include "list.h"
Item::Item() {
	this->prev = nullptr;
	this->next = nullptr;
};
Item::Item(List* list):Item() {
	this->list = list;
};
//Item::~Item() {
//	list->Remove(list->GetIndex(this));
//};
Item* Item::GetNext() {
	return this->next;
};
Item* Item::GetPrev() {
	return this->prev;
};
void Item::SetPrev(Item* prev) {
	this->prev = prev;
};
void Item::SetNext(Item* next) {
	this->next = next;
};
List::List() {
	this->head = nullptr;
	this->tail = nullptr;
};
List::~List() {
	Clear();
};
Item* List::GetHead() {
	return this->head;
};
Item* List::GetTail() {
	return this->tail;
};
void List::SetHead(Item* head) {
	this->head;
};
void List::SetTail(Item* tail) {
	this->tail;
};
void List::Add(Item* newElement) {
	if (newElement != nullptr) {
		if (this->head == nullptr) {
			newElement->SetNext(nullptr);
			newElement->SetPrev(nullptr);
			this->head = newElement;
			this->tail = newElement;
		}
		else {
			newElement->SetNext(nullptr);
			newElement->SetPrev(this->tail);
			this->tail->SetNext(newElement);
			this->tail = this->tail->GetNext();
		}
	}
}

void List::Delete(const int number) {
	Item* delItem;
	if (number >= 0) {
		delItem = Remove(number);
		if (delItem != nullptr) {
			delete delItem;
		}
	}
}

Item* List::GetItem(const int number) const {
	Item* currItem;
	int count = 0;
	if (number >= 0) {
		for (currItem = this->head; currItem != nullptr; currItem = currItem->GetNext()) {
			if (count == number)
				break;
			count++;
		}
		return currItem;
	}
	return nullptr;
}

Item* List::Remove(const int number) {
	Item* item;
	if (number >= 0) {
		item = GetItem(number);
		if (item != nullptr) {
			if (this->head == item) {
				if (this->head->GetNext() != nullptr) {
					this->head = this->head->GetNext();
					this->head->SetPrev(nullptr);
				}
				else {
					this->head = nullptr;
					this->tail = nullptr;
				}
			}
			else if (this->tail == item) {
				this->tail = this->tail->GetPrev();
				this->tail->SetNext(nullptr);
			}
			else {
				item->GetNext()->SetPrev(item->GetPrev());
				item->GetPrev()->SetNext(item->GetNext());
				item->SetPrev(nullptr);
				item->SetNext(nullptr);
			}
		}
		return item;
	}
}
void List::Insert(Item* newItem, const int number) {
	Item* item;
	if (newItem != nullptr && number >= 0) {
		item = GetItem(number);
		if (item == NULL) {
			Add(newItem);
		}
		else if (this->head == item) {
			this->head->SetPrev(newItem);
			this->head->GetPrev()->SetNext(this->head);
			this->head = this->head->GetPrev();
			this->head->prev = nullptr;

		}
		else {
			newItem->SetNext(item);
			newItem->SetPrev(item->GetPrev());
			item->GetPrev()->SetNext(newItem);
			item->SetPrev(newItem);
		}
	}
}
void List::Clear() {
	while (this->head) {
		Delete(0);		
	}
}

int List::Count() const {
	Item* item;
	int count = 0;
		for (item = this->head; item != nullptr; item = item->GetNext()) {
			count++;
		}
	return count;
}
int List::GetIndex(const Item* item) {
	Item* currItem;
	int count = 0;
	if (item != NULL) {
		for (currItem = this->head; currItem != nullptr; currItem = currItem->GetNext()) {
			if (currItem == item) {
				break;
			}
			count++;
		}
		if (currItem == nullptr)
			return -1;
		return count;
	}
	return -1;
}

void List::PrintList() {
	Item* item;
	int i = 0;
	if (this != NULL && this->head != NULL) {
		printf("#\tprev\t\t\tcurrent\t\t\tnext\n");
		for (item = this->head; item != nullptr; item = item->GetNext()) {
			printf("%d\t%p\t%p\t%p\n", i, item->GetPrev(), item, item->GetNext());
			i++;
		}
	}
	else {
		printf("nema shlyahu\n");
	}
}
