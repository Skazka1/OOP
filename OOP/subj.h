#pragma once
#pragma once
#include "list.h"
#include <string>

enum CarsType {
    CAR,
    MICROBUS,
    BUS,
    GRUZ,
    SPEC
};
class Base : public Item {
protected:
    CarsType type;
    std::string GosNumber;
    std::string Owner;
    std::string Brand;
    std::string Model;
    std::string Color;

public:
    Base(CarsType t);
    ~Base() {};

    void Print();
    void Input();

    const int GetCapacity();
    std::string GetOwner() const { return Owner; }
    std::string GetColor() const { return Color; }
    std::string GetNumber() const { return GosNumber; }

    CarsType GetType() const { return type; }
};

class SubjList : public List {
public:
    void Print();
    void AddCar(Base* base);
    static Base* CreateCar(CarsType type);
    Base* FindByNumber(const std::string number);
    SubjList* FindByOwner(const std::string owner);
    SubjList* FindByColor(const std::string color);
    void SortByCapacity(int reverse = 0);
};
