#pragma once
#include "stdio.h"
#include "stdlib.h"
struct Item
{
	struct Item* prev;
	struct Item* next;
};
struct List
{
	struct Item* tail;
	struct Item* head;
};

void Add(struct List*, struct Item*);
void Delete(struct List*, const int);
struct Item* GetItem(const struct List*, const int);
struct Item* Remove(struct List*, const int);
void Insert(struct List*, struct Item*, const int);
int Count(const struct List*);
void Clear(struct List*);
int GetIndex(const struct List*, const struct Item*);
void PrintList(const struct List*);
