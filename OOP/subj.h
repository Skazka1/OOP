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
    std::string GosNumber;
    std::string Owner;
    std::string Brand;
    std::string Model;
    std::string Color;

public:
    Base();
    virtual ~Base() {};
    virtual Base* clone() = 0;
    virtual void Print() = 0;
    virtual void Input() = 0;

    virtual const int GetCapacity() const = 0;
    std::string GetOwner() const { return Owner; }
    std::string GetColor() const { return Color; }
    std::string GetNumber() const { return GosNumber; }

    virtual const CarsType GetType() const = 0;
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
