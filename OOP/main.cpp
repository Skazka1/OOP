#include "subj.h"
#include <iostream>
#include <windows.h>
#include <limits>
#include <string>
#include <iomanip>

int main() {
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    SubjList list;
    int choice;
    std::string searchStr;

    while (true) {
        std::cout << "\n========== МЕНЮ УПРАВЛЕНИЯ АВТОПАРКОМ ==========" << std::endl;
        std::cout << "1. Добавить автомобиль" << std::endl;
        std::cout << "2. Показать все автомобили" << std::endl;
        std::cout << "3. Поиск по государственному номеру" << std::endl;
        std::cout << "4. Поиск по владельцу" << std::endl;
        std::cout << "5. Поиск по цвету" << std::endl;
        std::cout << "6. Сортировка по количеству мест" << std::endl;
        std::cout << "7. Удалить автомобиль по индексу" << std::endl;
        std::cout << "8. Очистить весь список" << std::endl;
        std::cout << "9. Выйти из программы" << std::endl;
        std::cout << "Выберите действие: ";

        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
            std::cout << "Ошибка ввода! Введите число от 1 до 9." << std::endl;
            continue;
        }

        switch (choice) {
        case 1: {
            int carType;
            std::cout << "\nВыберите тип автомобиля:" << std::endl;
            std::cout << "1. Легковой автомобиль" << std::endl;
            std::cout << "2. Микроавтобус" << std::endl;
            std::cout << "3. Автобус" << std::endl;
            std::cout << "4. Грузовик" << std::endl;
            std::cout << "5. Спецтехника" << std::endl;
            std::cout << "Введите номер типа (1-5): ";

            std::cin >> carType;
            if (std::cin.fail() || carType < 1 || carType > 5) {
                std::cout << "Неверный тип автомобиля!" << std::endl;
                std::cin.clear();
                std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
                break;
            }

            list.AddCar((CarsType)(carType - 1));
            std::cout << "Автомобиль успешно добавлен!" << std::endl;
            break;
        }

        case 2: {
            std::cout << "\n========== СПИСОК ВСЕХ АВТОМОБИЛЕЙ ==========" << std::endl;
            if (list.Count() == 0) {
                std::cout << "Список пуст." << std::endl;
            }
            else {
                list.Print();
            }
            break;
        }

        case 3: {
            std::cout << "Введите государственный номер для поиска: ";
            std::cin >> searchStr;
            Base* found = list.FindByNumber(searchStr);
            if (found) {
                std::cout << "\nНайден автомобиль:" << std::endl;
                found->Print();
            }
            else {
                std::cout << "Автомобиль с номером '" << searchStr << "' не найден." << std::endl;
            }
            break;
        }

        case 4: {
            std::cout << "Введите ФИО владельца для поиска: ";
            std::cin >> searchStr;
            SubjList* results = list.FindByOwner(searchStr);
            if (results->Count() > 0) {
                std::cout << "\nНайдено " << results->Count() << " автомобилей владельца '" << searchStr << "':" << std::endl;
                results->Print();
            }
            else {
                std::cout << "Автомобили владельца '" << searchStr << "' не найдены." << std::endl;
            }
            delete results;
            break;
        }

        case 5: {
            std::cout << "Введите цвет для поиска: ";
            std::cin >> searchStr;
            SubjList* results = list.FindByColor(searchStr);
            if (results->Count() > 0) {
                std::cout << "\nНайдено " << results->Count() << " автомобилей цвета '" << searchStr << "':" << std::endl;
                results->Print();
            }
            else {
                std::cout << "Автомобили цвета '" << searchStr << "' не найдены." << std::endl;
            }
            delete results;
            break;
        }

        case 6: {
            int reverse;
            std::cout << "Выберите порядок сортировки:" << std::endl;
            std::cout << "0 - по возрастанию (от меньшего к большему)" << std::endl;
            std::cout << "1 - по убыванию (от большего к меньшему)" << std::endl;
            std::cout << "Введите 0 или 1: ";

            std::cin >> reverse;
            if (std::cin.fail() || (reverse != 0 && reverse != 1)) {
                std::cout << "Неверный выбор!" << std::endl;
                std::cin.clear();
                std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
                break;
            }

            list.SortByCapacity(reverse);
            std::cout << "Сортировка выполнена успешно!" << std::endl;
            break;
        }

        case 7: {
            int index;
            std::cout << "Текущее количество автомобилей: " << list.Count() << std::endl;
            if (list.Count() == 0) {
                std::cout << "Список пуст, удалять нечего." << std::endl;
                break;
            }

            std::cout << "Введите индекс для удаления (0-" << list.Count() - 1 << "): ";
            std::cin >> index;
            if (std::cin.fail() || index < 0 || index >= list.Count()) {
                std::cout << "Неверный индекс!" << std::endl;
                std::cin.clear();
                std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
                break;
            }

            list.Delete(index);
            std::cout << "Автомобиль удален успешно!" << std::endl;
            break;
        }

        case 8: {
            list.Clear();
            std::cout << "Список очищен." << std::endl;
            break;
        }

        case 9: {
            list.Clear();
            std::cout << "Программа завершена." << std::endl;
            return 0;
        }

        default:
            std::cout << "Неверный выбор! Введите число от 1 до 9." << std::endl;
            std::cin.clear();
            std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
        }
    }

    return 0;
}