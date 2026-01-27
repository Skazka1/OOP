#include "subj.h"
#include <iostream>
#include <limits>
#include <string>
#include <iomanip>

class Car : public Base {
private:
    std::string KuzovType;
    std::string MotorType;
    std::string DriveType;

public:
    Car();
    void Print();
    void Input();
};

class Microbus : public Base {
private:
    int Capacity;
    std::string MotorType;

public:
    int GetCapacity() const { return Capacity; }
    Microbus();
    void Print();
    void Input();
};

class Bus : public Base {
private:
    int Capacity;
    std::string MotorType;
    float LoadCapacity;

public:
    int GetCapacity() const { return Capacity; }
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

Base::Base(CarsType t) : type(t) {
    GosNumber = "";
    Owner = "";
    Brand = "";
    Model = "";
    Color = "";
}

void Base::Input() {
    switch (this->type) {
    case CarsType::CAR:
        ((Car*)this)->Input();
        break;
    case CarsType::MICROBUS:
        ((Microbus*)this)->Input();
        break;
    case CarsType::BUS:
        ((Bus*)this)->Input();
        break;
    case CarsType::GRUZ:
        ((Gruz*)this)->Input();
        break;
    case CarsType::SPEC:
        ((Spec*)this)->Input();
        break;
    }
}

void Base::Print() {
    switch (this->type) {
    case CarsType::CAR:
        ((Car*)this)->Print();
        break;
    case CarsType::MICROBUS:
        ((Microbus*)this)->Print();
        break;
    case CarsType::BUS:
        ((Bus*)this)->Print();
        break;
    case CarsType::GRUZ:
        ((Gruz*)this)->Print();
        break;
    case CarsType::SPEC:
        ((Spec*)this)->Print();
        break;
    }
}

Car::Car() : Base(CAR) {
    KuzovType = "";
    MotorType = "";
    DriveType = "";
}

void Car::Print() {
    std::cout << "Легковой автомобиль:" << std::endl;
    std::cout << "  Номер: " << GosNumber << std::endl;
    std::cout << "  Владелец: " << Owner << std::endl;
    std::cout << "  Марка: " << Brand << std::endl;
    std::cout << "  Модель: " << Model << std::endl;
    std::cout << "  Цвет: " << Color << std::endl;
    std::cout << "  Количество мест: " << ((Base*)this)->GetCapacity() << std::endl;
    std::cout << "  Тип кузова: " << KuzovType << std::endl;
    std::cout << "  Тип двигателя: " << MotorType << std::endl;
    std::cout << "  Привод: " << DriveType << std::endl;
    std::cout << std::endl;
}

void Car::Input() {
    std::cout << "Введите госномер: ";
    std::cin >> GosNumber;
    std::cout << "Введите ФИО владельца: ";
    std::cin >> Owner;
    std::cout << "Введите марку: ";
    std::cin >> Brand;
    std::cout << "Введите модель: ";
    std::cin >> Model;
    std::cout << "Введите цвет: ";
    std::cin >> Color;
    std::cout << "Введите тип кузова: ";
    std::cin >> KuzovType;
    std::cout << "Введите тип двигателя: ";
    std::cin >> MotorType;
    std::cout << "Введите тип привода: ";
    std::cin >> DriveType;
}

// Реализация Microbus
Microbus::Microbus() : Base(MICROBUS) {
    MotorType = "";
}

void Microbus::Print() {
    std::cout << "Микроавтобус:" << std::endl;
    std::cout << "  Номер: " << GosNumber << std::endl;
    std::cout << "  Владелец: " << Owner << std::endl;
    std::cout << "  Марка: " << Brand << std::endl;
    std::cout << "  Модель: " << Model << std::endl;
    std::cout << "  Цвет: " << Color << std::endl;
    std::cout << "  Количество мест: " << Capacity << std::endl;
    std::cout << "  Тип двигателя: " << MotorType << std::endl;
    std::cout << std::endl;
}

void Microbus::Input() {
    std::cout << "Введите госномер: ";
    std::cin >> GosNumber;
    std::cout << "Введите ФИО владельца: ";
    std::cin >> Owner;
    std::cout << "Введите марку: ";
    std::cin >> Brand;
    std::cout << "Введите модель: ";
    std::cin >> Model;
    std::cout << "Введите цвет: ";
    std::cin >> Color;
    std::cout << "Введите тип двигателя: ";
    std::cin >> MotorType;
    std::cout << "Введите вместимость: ";
    std::cin >> Capacity;
}

// Реализация Bus
Bus::Bus() : Base(BUS) {
    MotorType = "";
    LoadCapacity = 0.0f;
}

void Bus::Print() {
    std::cout << "Автобус:" << std::endl;
    std::cout << "  Номер: " << GosNumber << std::endl;
    std::cout << "  Владелец: " << Owner << std::endl;
    std::cout << "  Марка: " << Brand << std::endl;
    std::cout << "  Модель: " << Model << std::endl;
    std::cout << "  Цвет: " << Color << std::endl;
    std::cout << "  Количество мест: " << Capacity << std::endl;
    std::cout << "  Тип двигателя: " << MotorType << std::endl;
    std::cout << "  Грузоподъемность: " << std::fixed << std::setprecision(2) << LoadCapacity << " т" << std::endl;
    std::cout << std::endl;
}

void Bus::Input() {
    std::cout << "Введите госномер: ";
    std::cin >> GosNumber;
    std::cout << "Введите ФИО владельца: ";
    std::cin >> Owner;
    std::cout << "Введите марку: ";
    std::cin >> Brand;
    std::cout << "Введите модель: ";
    std::cin >> Model;
    std::cout << "Введите цвет: ";
    std::cin >> Color;
    std::cout << "Введите тип двигателя: ";
    std::cin >> MotorType;
    std::cout << "Введите вместимость: ";
    std::cin >> Capacity;
    std::cout << "Введите грузоподъемность: ";
    std::cin >> LoadCapacity;
}

// Реализация Gruz
Gruz::Gruz() : Base(GRUZ) {
    MotorType = "";
    LoadCapacity = 0.0f;
}

void Gruz::Print() {
    std::cout << "Грузовик:" << std::endl;
    std::cout << "  Номер: " << GosNumber << std::endl;
    std::cout << "  Владелец: " << Owner << std::endl;
    std::cout << "  Марка: " << Brand << std::endl;
    std::cout << "  Модель: " << Model << std::endl;
    std::cout << "  Цвет: " << Color << std::endl;
    std::cout << "  Количество мест: " << ((Base*)this)->GetCapacity() << std::endl;
    std::cout << "  Тип двигателя: " << MotorType << std::endl;
    std::cout << "  Грузоподъемность: " << std::fixed << std::setprecision(2) << LoadCapacity << " т" << std::endl;
    std::cout << std::endl;
}

void Gruz::Input() {
    std::cout << "Введите госномер: ";
    std::cin >> GosNumber;
    std::cout << "Введите ФИО владельца: ";
    std::cin >> Owner;
    std::cout << "Введите марку: ";
    std::cin >> Brand;
    std::cout << "Введите модель: ";
    std::cin >> Model;
    std::cout << "Введите цвет: ";
    std::cin >> Color;
    std::cout << "Введите тип двигателя: ";
    std::cin >> MotorType;
    std::cout << "Введите грузоподъемность: ";
    std::cin >> LoadCapacity;
}

// Реализация Spec
Spec::Spec() : Base(SPEC) {
    Description = "";
}

void Spec::Print() {
    std::cout << "Спецтехника:" << std::endl;
    std::cout << "  Номер: " << GosNumber << std::endl;
    std::cout << "  Владелец: " << Owner << std::endl;
    std::cout << "  Марка: " << Brand << std::endl;
    std::cout << "  Модель: " << Model << std::endl;
    std::cout << "  Цвет: " << Color << std::endl;
    std::cout << "  Количество мест: " << ((Base*)this)->GetCapacity() << std::endl;
    std::cout << "  Описание: " << Description << std::endl;
    std::cout << std::endl;
}

void Spec::Input() {
    std::cout << "Введите госномер: ";
    std::cin >> GosNumber;
    std::cout << "Введите ФИО владельца: ";
    std::cin >> Owner;
    std::cout << "Введите марку: ";
    std::cin >> Brand;
    std::cout << "Введите модель: ";
    std::cin >> Model;
    std::cout << "Введите цвет: ";
    std::cin >> Color;
    std::cout << "Введите описание: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, Description);
}

// Реализация SubjList
void SubjList::Print() {
    for (Base* p = (Base*)GetHead(); p != nullptr; p = (Base*)p->GetNext()) {
        p->Print();
    }
}
Base* SubjList::CreateCar(CarsType type){

    switch (type) {
    case CAR:
        return ((Base*)new Car());
        break;
    case MICROBUS:
        return ((Base*)new Microbus());
        break;
    case BUS:
        return ((Base*)new Bus());
        break;
    case GRUZ:
        return ((Base*)new Gruz());
        break;
    case SPEC:
        return ((Base*)new Spec());
        break;
    }
    return nullptr;
}

void SubjList::AddCar(Base* base) {
    if (base) {
        Add((Item*)base);
    }
}


Base* SubjList::FindByNumber(const std::string number) {
    for (Base* p = (Base*)GetHead(); p != nullptr; p = (Base*)p->GetNext()) {
        if (p->GetNumber() == number) {
            return p;
        }
    }
    return nullptr;
}

SubjList* SubjList::FindByOwner(const std::string owner) {
    SubjList* result = new SubjList();

    for (Base* p = (Base*)GetHead(); p != nullptr; p = (Base*)p->GetNext()) {
        if (p->GetOwner() == owner) {
            result->Add((Item*)p);
        }
    }

    return result;
}

SubjList* SubjList::FindByColor(const std::string color) {
    SubjList* result = new SubjList();

    for (Base* p = (Base*)GetHead(); p != nullptr; p = (Base*)p->GetNext()) {
        if (p->GetColor() == color) {
            result->Add((Item*)p);
        }
    }

    return result;
}

const int Base::GetCapacity() {
    switch (this->type)
    {
    case CAR:
        return 5;
    case GRUZ:
        return 2;
    case SPEC:
        return 1;
    case MICROBUS:
        return ((Microbus*)this)->GetCapacity();
    case BUS:
        return ((Bus*)this)->GetCapacity();
    }
    return 0;
}

void SubjList::SortByCapacity(int reverse) {
    int len = Count();

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - 1; j++) {
            Base* p1 = (Base*)GetItem(j);
            Base* p2 = (Base*)GetItem(j + 1);

            bool shouldSwap = false;
            if (reverse) {
                shouldSwap = p1->GetCapacity() < p2->GetCapacity();
            }
            else {
                shouldSwap = p1->GetCapacity() > p2->GetCapacity();
            }

            if (shouldSwap) {
                Item* temp = Remove(j);
                Insert(temp, j + 1);
            }
        }
    }
}