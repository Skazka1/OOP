#pragma once
#include "list.h"
#include <string>

enum CarsType {
    LEGK,
    MICROBUS,
    BUS,
    GRUZ,
    SPEC
};

// Базовый класс для всех автомобилей
class Base : public Item {
protected:
    CarsType type;
    std::string GosNumber;
    std::string Owner;
    std::string Brand;
    std::string Model;
    std::string Color;
    int Capacity;

public:
    Base(CarsType t);
    ~Base() {};

    void Print();
    void Input();

    int GetCapacity() const { return Capacity; }
    std::string GetOwner() const { return Owner; }
    std::string GetColor() const { return Color; }
    std::string GetNumber() const { return GosNumber; }

    CarsType GetType() const { return type; }
};


class Legk : public Base {
private:
    std::string KuzovType;
    std::string MotorType;
    std::string DriveType;

public:
    Legk();
    void Print();
    void Input();
};

class Microbus : public Base {
private:
    std::string MotorType;

public:
    Microbus();
    void Print();
    void Input();
};

class Bus : public Base {
private:
    std::string MotorType;
    float LoadCapacity;

public:
    Bus();
    void Print();
    void Input();
};

class Gruz : public Base {
private:
    std::string MotorType;
    float LoadCapacity;

public:
    Gruz();
    void Print();
    void Input();
};

class Spec : public Base {
private:
    std::string Description;

public:
    Spec();
    void Print();
    void Input();
};

class SubjList : public List {
public:
    void Print();
    void AddCar(CarsType type);
    Base* FindByNumber(const std::string number);
    SubjList* FindByOwner(const std::string owner);
    SubjList* FindByColor(const std::string color);
    void SortByCapacity(int reverse = 0);
};