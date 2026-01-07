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
    std::string GosNumber;
    std::string Owner;
    std::string Brand;
    std::string Model;
    std::string Color;
    int Capacity;

public:
    Base(CarsType t);
    ~Base() {};
    virtual Base* clone();
    virtual void Print() {};
    virtual void Input() {};

    int GetCapacity() const { return Capacity; }
    std::string GetOwner() const { return Owner; }
    std::string GetColor() const { return Color; }
    std::string GetNumber() const { return GosNumber; }

    virtual CarsType GetType() const = 0;
};


class Legk : public Base {
private:
    std::string KuzovType;
    std::string MotorType;
    std::string DriveType;

public:
    Legk* clone() override ;
    Legk();
    void Print() override;
    void Input() override;
    CarsType GetType() const override { return CarsType::LEGK; };
};

class Microbus : public Base {
private:
    std::string MotorType;

public:
    Microbus* clone() override;
    Microbus();
    void Print() override;
    void Input() override;
    CarsType GetType() const override { return CarsType::MICROBUS; };
};

class Bus : public Base {
private:
    std::string MotorType;
    float LoadCapacity;

public:
    Bus* clone() override;
    Bus();
    void Print() override;
    void Input() override;
    CarsType GetType() const override { return CarsType::BUS; };
};

class Gruz : public Base {
private:
    std::string MotorType;
    float LoadCapacity;

public:
    Gruz* clone() override;
    Gruz();
    void Print() override;
    void Input() override;
    CarsType GetType() const override { return CarsType::GRUZ; };
};

class Spec : public Base {
private:
    std::string Description;

public:
    Spec* clone() override;
    Spec();
    void Print() override;
    void Input() override;
    CarsType GetType() const override { return CarsType::SPEC; };
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