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
    Car* clone() override;
    Car();
    void Print() override;
    void Input() override;
    const int GetCapacity() const override { return 5; };
    const CarsType GetType() const override { return CAR; };
};

class Microbus : public Base {
private:
    int Capacity = 0;
    std::string MotorType;

public:
    Microbus* clone() override;
    Microbus();
    void Print() override;
    void Input() override;
    const int GetCapacity() const override { return Capacity; };
    const CarsType GetType() const override { return MICROBUS; };
};

class Bus : public Base {
private:
    int Capacity = 0;
    std::string MotorType;
    float LoadCapacity = 0;

public:
    Bus* clone() override;
    Bus();
    void Print() override;
    void Input() override;
    const int GetCapacity() const override { return Capacity; };
    const CarsType GetType() const override { return BUS; };
};

class Gruz : public Base {
private:
    std::string MotorType;
    float LoadCapacity = 0;

public:
    Gruz* clone() override;
    Gruz();
    void Print() override;
    void Input() override;
    const int GetCapacity() const override { return 2; };
    const CarsType GetType() const override { return GRUZ; };
};

class Spec : public Base {
private:
    std::string Description;

public:
    Spec* clone() override;
    Spec();
    void Print() override;
    void Input() override;
    const int GetCapacity() const override { return 1; };
    const CarsType GetType() const override { return SPEC; };
};

Car* Car::clone() {
    Car* newObj = new Car();
    newObj->GosNumber = this->GosNumber;
    newObj->Owner = this->Owner;
    newObj->Brand = this->Brand;
    newObj->Model = this->Model;
    newObj->Color = this->Color;
    newObj->KuzovType = this->KuzovType;
    newObj->MotorType = this->MotorType;
    newObj->DriveType = this->DriveType;
    return newObj;
}
Microbus* Microbus::clone() {
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
    newObj->Description = this->Description;
    return newObj;
}
Base::Base(){
    GosNumber = "";
    Owner = "";
    Brand = "";
    Model = "";
    Color = "";
}

Car::Car() : Base() {
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
    std::cout << "  Количество мест: " << GetCapacity() << std::endl;
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
Microbus::Microbus() : Base() {
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
Bus::Bus() : Base() {
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
Gruz::Gruz() : Base() {
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
    std::cout << "  Количество мест: " << GetCapacity() << std::endl;
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
Spec::Spec() : Base() {
    Description = "";
}

void Spec::Print() {
    std::cout << "Спецтехника:" << std::endl;
    std::cout << "  Номер: " << GosNumber << std::endl;
    std::cout << "  Владелец: " << Owner << std::endl;
    std::cout << "  Марка: " << Brand << std::endl;
    std::cout << "  Модель: " << Model << std::endl;
    std::cout << "  Цвет: " << Color << std::endl;
    std::cout << "  Количество мест: " << GetCapacity() << std::endl;
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
            Base* newObj = p->clone();
            result->Add((Item*)newObj);
        }
    }

    return result;
}

SubjList* SubjList::FindByColor(const std::string color) {
    SubjList* result = new SubjList();

    for (Base* p = (Base*)GetHead(); p != nullptr; p = (Base*)p->GetNext()) {
        if (p->GetColor() == color) {
            Base* newObj = p->clone();
            result->Add((Item*)newObj);
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
                Item* temp = Remove(j);
                Insert(temp, j + 1);
            }
        }
    }
}