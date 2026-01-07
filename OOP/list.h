#pragma once
#include "stdio.h"
#include "stdlib.h"
class Item
{
	friend class List;
private:
	Item* prev;
	Item* next;
	List* list;
public:
	virtual ~Item() {};
	Item();
	Item(List*);
	Item* GetPrev();
	Item* GetNext();
	void SetPrev(Item*);
	void SetNext(Item*);
};
class List
{
private:
	Item* tail;
	Item* head;
public:
	Item* GetHead();
	Item* GetTail();
	void SetHead(Item*);
	void SetTail(Item*);
	~List();
	List();

	void Add(Item*);
	void Delete(const int);
	Item* GetItem(const int) const;
	Item* Remove(const int);
	void Insert(Item*, const int);
	int Count() const;
	void Clear();
	int GetIndex(const Item*);
	void PrintList();

};
