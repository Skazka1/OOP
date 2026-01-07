#include "subj.h"
#include <iostream>
#include <limits>
#include <string>
#include <iomanip>

// Реализация Base
Base::Base(CarsType t){
    Capacity = 0;
    GosNumber = '\0';
    Owner = '\0';
    Brand = '\0';
    Model = '\0';
    Color = '\0';
}
bool Base::operator>(const Base& other) const {
    return this->Capacity > other.Capacity;
}
bool Base::operator==(const std::string& value) const {
    return this->Owner == value;
}
Base& SubjList::operator[](int index) {
    Item* item = GetItem(index); 
    if (item == nullptr) {
        throw std::out_of_range("Index out of range");
    }
    return *(Base*)item;
}

const Base& SubjList::operator[](int index) const {
    Item* item = GetItem(index);
    if (item == nullptr) {
        throw std::out_of_range("Index out of range"); 
    }
    return *(Base*)item;
}
Base* Base::clone() {
    return nullptr;
}
Legk* Legk::clone()  {
    Legk* newObj = new Legk();
    // Просто присваиваем - std::string сам скопируется
    newObj->GosNumber = this->GosNumber;
    newObj->Owner = this->Owner;
    newObj->Brand = this->Brand;
    newObj->Model = this->Model;
    newObj->Color = this->Color;
    newObj->Capacity = this->Capacity;
    newObj->KuzovType = this->KuzovType;
    newObj->MotorType = this->MotorType;
    newObj->DriveType = this->DriveType;
    return newObj;
}

Microbus* Microbus::clone()  {
    Microbus* newObj = new Microbus();
    newObj->GosNumber = this->GosNumber;
    newObj->Owner = this->Owner;
    newObj->Brand = this->Brand;
    newObj->Model = this->Model;
    newObj->Color = this->Color;
    newObj->Capacity = this->Capacity;
    newObj->MotorType = this->MotorType;
    return newObj;
}
Bus* Bus::clone() {
    Bus* newObj = new Bus();
    newObj->GosNumber = this->GosNumber;
    newObj->Owner = this->Owner;
    newObj->Brand = this->Brand;
    newObj->Model = this->Model;
    newObj->Color = this->Color;
    newObj->Capacity = this->Capacity;
    newObj->MotorType = this->MotorType;
    newObj->LoadCapacity = this->LoadCapacity;
    return newObj;
}

Gruz* Gruz::clone() {
    Gruz* newObj = new Gruz();
    newObj->GosNumber = this->GosNumber;
    newObj->Owner = this->Owner;
    newObj->Brand = this->Brand;
    newObj->Model = this->Model;
    newObj->Color = this->Color;
    newObj->Capacity = this->Capacity;
    newObj->MotorType = this->MotorType;
    newObj->LoadCapacity = this->LoadCapacity;
    return newObj;
}

Spec* Spec::clone() {
    Spec* newObj = new Spec();
    newObj->GosNumber = this->GosNumber;
    newObj->Owner = this->Owner;
    newObj->Brand = this->Brand;
    newObj->Model = this->Model;
    newObj->Color = this->Color;
    newObj->Capacity = this->Capacity;
    newObj->Description = this->Description;
    return newObj;
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

    int n = Count();
    for (int i = 0; i < n; i++) {
        if ((*this)[i] == owner) {
            Base* newObj = (*this)[i].clone();
            if (newObj) {
                result->Add((Item*)newObj);
            }
        }
    }

    return result;
}

SubjList* SubjList::FindByColor(const std::string color) {
    SubjList* result = new SubjList();

    for (Base* p = (Base*)GetHead(); p != nullptr; p = (Base*)p->GetNext()) {
        if (p->GetColor() == color) {
            Base* newObj = p->clone();
            if (newObj) {
                result->Add((Item*)newObj);
            }
        }

        return result;
    }
}

void SubjList::SortByCapacityUsingOperator() {
    int n = Count();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            // Используем перегруженный оператор >
            if ((*this)[i] > (*this)[j]) {
                Item* temp = Remove(j);
                Insert(temp, i);
            }
        }
    }
}