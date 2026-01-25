#include "stdio.h"
#include "stdlib.h"
#include "list.h"
#include "subj.h"
#include <windows.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    struct List list;
    list.head = NULL;
    list.tail = NULL;
    struct Base* car;
    int choice, index, reverse;
    char searchStr[100];

    while (1) {
        printf("\n========== МЕНЮ УПРАВЛЕНИЯ АВТОПАРКОМ ==========\n");
        printf("1. Добавить автомобиль\n");
        printf("2. Показать все автомобили\n");
        printf("3. Поиск по государственному номеру\n");
        printf("4. Поиск по владельцу\n");
        printf("5. Поиск по цвету\n");
        printf("6. Сортировка по количеству мест\n");
        printf("7. Удалить автомобиль по индексу\n");
        printf("8. Очистить весь список\n");
        printf("9. Выйти из программы\n");
        printf("Выберите действие: ");

        if (scanf_s("%d", &choice) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Ошибка ввода! Введите число от 1 до 9.\n");
            continue;
        }

        switch (choice) {
        case 1: { // Добавить автомобиль
            int carType;
            printf("\nВыберите тип автомобиля:\n");
            printf("1. Легковой автомобиль\n");
            printf("2. Микроавтобус\n");
            printf("3. Автобус\n");
            printf("4. Грузовик\n");
            printf("5. Спецтехника\n");
            printf("Введите номер типа (1-5): ");

            if (scanf_s("%d", &carType) != 1 || carType < 1 || carType > 5) {
                printf("Неверный тип автомобиля!\n");
                break;
            }

            car = Create((enum CarsType)(carType - 1));
            if (car) {
                InputBase(car);
                Add(&list, (struct Item*)car);
                printf("Автомобиль успешно добавлен!\n");
            }
            break;
        }

        case 2: { // Показать все автомобили
            printf("\n========== СПИСОК ВСЕХ АВТОМОБИЛЕЙ ==========\n");
            if (Count(&list) == 0) {
                printf("Список пуст.\n");
            }
            else {
                PrintListCars(&list);
            }
            break;
        }

        case 3: { // Поиск по номеру
            printf("Введите государственный номер для поиска: ");
            scanf_s("%s", searchStr, (unsigned int)sizeof(searchStr));
            struct Base* found = FindByNumber(&list, searchStr);
            if (found) {
                printf("\nНайден автомобиль:\n");
                PrintBase(found);
            }
            else {
                printf("Автомобиль с номером '%s' не найден.\n", searchStr);
            }
            break;
        }

        case 4: { // Поиск по владельцу
            printf("Введите ФИО владельца для поиска: ");
            scanf_s("%s", searchStr, (unsigned int)sizeof(searchStr));
            struct List* results = FindByOwner(&list, searchStr);
            if (Count(results) > 0) {
                printf("\nНайдено %d автомобилей владельца '%s':\n", Count(results), searchStr);
                PrintListCars(results);
            }
            else {
                printf("Автомобили владельца '%s' не найдены.\n", searchStr);
            }
            free(results);
            break;
        }

        case 5: { // Поиск по цвету
            printf("Введите цвет для поиска: ");
            scanf_s("%s", searchStr, (unsigned int)sizeof(searchStr));
            struct List* results = FindByColor(&list, searchStr);
            if (Count(results) > 0) {
                printf("\nНайдено %d автомобилей цвета '%s':\n", Count(results), searchStr);
                PrintListCars(results);
            }
            else {
                printf("Автомобили цвета '%s' не найдены.\n", searchStr);
            }
            free(results);
            break;
        }

        case 6: { // Сортировка по количеству мест
            printf("Выберите порядок сортировки:\n");
            printf("0 - по возрастанию (от меньшего к большему)\n");
            printf("1 - по убыванию (от большего к меньшему)\n");
            printf("Введите 0 или 1: ");

            if (scanf_s("%d", &reverse) != 1 || (reverse != 0 && reverse != 1)) {
                printf("Неверный выбор!\n");
                break;
            }

            SortByCapacity(&list, reverse);
            printf("Сортировка выполнена успешно!\n");
            break;
        }

        case 7: { // Удалить автомобиль
            printf("Текущее количество автомобилей: %d\n", Count(&list));
            if (Count(&list) == 0) {
                printf("Список пуст, удалять нечего.\n");
                break;
            }

            printf("Введите индекс для удаления (0-%d): ", Count(&list) - 1);
            if (scanf_s("%d", &index) != 1 || index < 0 || index >= Count(&list)) {
                printf("Неверный индекс!\n");
                break;
            }

            Delete(&list, index);
            printf("Автомобиль удален успешно!\n");
            break;
        }

        case 8: { // Очистить список
            Clear(&list);
            printf("Список очищен.\n");
            break;
        }

        case 9: { // Выход
            Clear(&list);
            printf("Программа завершена. Память освобождена.\n");
            return 0;
        }

        default:
            printf("Неверный выбор! Введите число от 1 до 9.\n");
        }
    }
}