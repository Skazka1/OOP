#include "subj.h"
#include <iostream>
#include <limits>
#include <string>
#include <iomanip>

// Реализация Base
Base::Base(CarsType t) : type(t) {
    Capacity = 0;
    GosNumber = '\0';
    Owner = '\0';
    Brand = '\0';
    Model = '\0';
    Color = '\0';
}
void Base::Input() {
    switch (this->type) {
    case CarsType::LEGK:
        ((Legk*)this)->Input();
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
    case CarsType::LEGK:
        ((Legk*)this)->Print();
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

// Реализация Legk
Legk::Legk() : Base(LEGK) {
    Capacity = 4;
    KuzovType[0] = '\0';
    MotorType[0] = '\0';
    DriveType[0] = '\0';
}

void Legk::Print() {
    std::cout << "Легковой автомобиль:" << std::endl;
    std::cout << "  Номер: " << GosNumber << std::endl;
    std::cout << "  Владелец: " << Owner << std::endl;
    std::cout << "  Марка: " << Brand << std::endl;
    std::cout << "  Модель: " << Model << std::endl;
    std::cout << "  Цвет: " << Color << std::endl;
    std::cout << "  Количество мест: " << Capacity << std::endl;
    std::cout << "  Тип кузова: " << KuzovType << std::endl;
    std::cout << "  Тип двигателя: " << MotorType << std::endl;
    std::cout << "  Привод: " << DriveType << std::endl;
    std::cout << std::endl;
}

void Legk::Input() {
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
    Capacity = 4;
}

// Реализация Microbus
Microbus::Microbus() : Base(MICROBUS) {
    Capacity = 8; // примерное значение
    MotorType[0] = '\0';
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
    Capacity = 20; // примерное значение
    MotorType[0] = '\0';
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
    Capacity = 3;
    MotorType[0] = '\0';
    LoadCapacity = 0.0f;
}

void Gruz::Print() {
    std::cout << "Грузовик:" << std::endl;
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
    Capacity = 3;
}

// Реализация Spec
Spec::Spec() : Base(SPEC) {
    Capacity = 2;
    Description[0] = '\0';
}

void Spec::Print() {
    std::cout << "Спецтехника:" << std::endl;
    std::cout << "  Номер: " << GosNumber << std::endl;
    std::cout << "  Владелец: " << Owner << std::endl;
    std::cout << "  Марка: " << Brand << std::endl;
    std::cout << "  Модель: " << Model << std::endl;
    std::cout << "  Цвет: " << Color << std::endl;
    std::cout << "  Количество мест: " << Capacity << std::endl;
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
    Capacity = 2;
}

// Реализация SubjList
void SubjList::Print() {
    for (Base* p = (Base*)GetHead(); p != nullptr; p = (Base*)p->GetNext()) {
        p->Print();
    }
}

void SubjList::AddCar(CarsType type) {
    Base* newCar = nullptr;

    switch (type) {
    case LEGK:
        newCar = new Legk();
        break;
    case MICROBUS:
        newCar = new Microbus();
        break;
    case BUS:
        newCar = new Bus();
        break;
    case GRUZ:
        newCar = new Gruz();
        break;
    case SPEC:
        newCar = new Spec();
        break;
    }

    if (newCar) {
        newCar->Input();
        Add((Item*)newCar);
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
                // Обмен местами
                Item* temp = Remove(j);
                Insert(temp, j + 1);
            }
        }
    }
}