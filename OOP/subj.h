#pragma once
#include "list.h"
#include "string.h"

enum CarsType {
    Car,
    Microbus,
    Bus,
    Gruz,
    Spec
};

// TODO: Изменить имя базовой структуры на Base
// И везде, где используется Car заменить на Base

// Базовая структура - общие поля для всех
struct Base {
    struct Item* prev;
    struct Item* next;
    char GosNumber[10];
    char Owner[20];
    char Brand[20];
    char Model[20];
    char Color[10];
    enum CarsType carsType;
};

// TODO: Изменить имя структуры легкового автоа на Car
// И везде, где используется Legk заменить на Car

// Все остальные структуры должны начинаться с этих полей в том же порядке!

void PrintBase(struct Base*);
void InputBase(struct Base*);

struct Base* FindByNumber(struct List*, char*);
struct List* FindByOwner(struct List*, char*);
struct List* FindByColor(struct List*, char*);

struct Base* Create(enum CarsType);
void SortByCapacity(struct List*, int);
void PrintListCars(struct List*);


