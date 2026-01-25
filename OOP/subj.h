//#pragma once
//#include "list.h"
//#include "string.h"
//
//enum CarsType {
//    Legk,
//    Microbus,
//    Bus,
//    Gruz,
//    Spec
//};
//
//// Базовая структура - общие поля для всех
//struct Car {
//    struct Item* prev;
//    struct Item* next;
//    char GosNumber[10];
//    char Owner[20];
//    char Brand[20];
//    char Model[20];
//    char Color[10];
//    int Capacity;
//    enum CarsType carsType;
//};
//
//// Все остальные структуры должны начинаться с этих полей в том же порядке!
//struct Legk {
//    struct Item* prev;
//    struct Item* next;
//    char GosNumber[10];
//    char Owner[20];
//    char Brand[20];
//    char Model[20];
//    char Color[10];
//    int Capacity;
//    enum CarsType carsType;
//    char KuzovType[20];
//    char MotorType[20];
//    char DriveType[20];
//};
//
//struct Microbus {
//    struct Item* prev;
//    struct Item* next;
//    char GosNumber[10];
//    char Owner[20];
//    char Brand[20];
//    char Model[20];
//    char Color[10];
//    int Capacity;
//    enum CarsType carsType;
//    char MotorType[20];
//};
//
//struct Bus {
//    struct Item* prev;
//    struct Item* next;
//    char GosNumber[10];
//    char Owner[20];
//    char Brand[20];
//    char Model[20];
//    char Color[10];
//    int Capacity;
//    enum CarsType carsType;
//    char MotorType[20];
//    float LoadCapacity;
//};
//
//struct Gruz {
//    struct Item* prev;
//    struct Item* next;
//    char GosNumber[10];
//    char Owner[20];
//    char Brand[20];
//    char Model[20];
//    char Color[10];
//    int Capacity;
//    enum CarsType carsType;
//    char MotorType[20];
//    float LoadCapacity;
//};
//
//struct Spec {
//    struct Item* prev;
//    struct Item* next;
//    char GosNumber[10];
//    char Owner[20];
//    char Brand[20];
//    char Model[20];
//    char Color[10];
//    int Capacity;
//    enum CarsType carsType;
//    char Description[50];
//};
//
//void PrintLegk(struct Legk*);
//void PrintMicrobus(struct Microbus*);
//void PrintBus(struct Bus*);
//void PrintGruz(struct Gruz*);
//void PrintSpec(struct Spec*);
//void PrintCar(struct Car*);
//
//void InputLegk(struct Legk*);
//void InputMicrobus(struct Microbus*);
//void InputBus(struct Bus*);
//void InputGruz(struct Gruz*);
//void InputSpec(struct Spec*);
//void InputCar(struct Car*);
//
//struct Car* FindByNumber(struct List*, char*);
//struct List* FindByOwner(struct List*, char*);
//struct List* FindByColor(struct List*, char*);
//
//struct Car* Create(enum CarsType);
//void SortByCapacity(struct List*, int);
//void PrintListCars(struct List*);
//
//
