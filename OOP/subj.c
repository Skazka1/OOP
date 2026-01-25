#include "subj.h"
struct Car {
	struct Item* prev;
	struct Item* next;
	char GosNumber[10];
	char Owner[20];
	char Brand[20];
	char Model[20];
	char Color[10];
	enum CarsType carsType;
	char KuzovType[20];
	char MotorType[20];
	char DriveType[20];
};

struct Microbus {
	struct Item* prev;
	struct Item* next;
	char GosNumber[10];
	char Owner[20];
	char Brand[20];
	char Model[20];
	char Color[10];
	enum CarsType carsType;
	int Capacity;
	char MotorType[20];
};

struct Bus {
	struct Item* prev;
	struct Item* next;
	char GosNumber[10];
	char Owner[20];
	char Brand[20];
	char Model[20];
	char Color[10];
	enum CarsType carsType;
	int Capacity;
	char MotorType[20];
	float LoadCapacity;
};

struct Gruz {
	struct Item* prev;
	struct Item* next;
	char GosNumber[10];
	char Owner[20];
	char Brand[20];
	char Model[20];
	char Color[10];
	enum CarsType carsType;
	char MotorType[20];
	float LoadCapacity;
};

struct Spec {
	struct Item* prev;
	struct Item* next;
	char GosNumber[10];
	char Owner[20];
	char Brand[20];
	char Model[20];
	char Color[10];
	enum CarsType carsType;
	char Description[50];
};

void PrintCar(struct Car* car) {
	printf("Легковой автомобиль:\n");
	printf("  Номер: %s\n", car->GosNumber);
	printf("  Владелец: %s\n", car->Owner);
	printf("  Марка: %s\n", car->Brand);
	printf("  Модель: %s\n", car->Model);
	printf("  Цвет: %s\n", car->Color);
	printf("  Тип кузова: %s\n", car->KuzovType);
	printf("  Тип двигателя: %s\n", car->MotorType);
	printf("  Привод: %s\n", car->DriveType);
	printf("  Вместимость: %d чел.\n", GetCapacity(car));
	printf("\n");
}
void PrintMicrobus(struct Microbus* microbus) {
	printf("Микроавтобус:\n");
	printf("  Номер: %s\n", microbus->GosNumber);
	printf("  Владелец: %s\n", microbus->Owner);
	printf("  Марка: %s\n", microbus->Brand);
	printf("  Модель: %s\n", microbus->Model);
	printf("  Цвет: %s\n", microbus->Color);
	printf("  Тип двигателя: %s\n", microbus->MotorType);
	printf("  Вместимость: %d чел.\n", GetCapacity(microbus));
	printf("\n");
}
void PrintBus(struct Bus* bus) {
	printf("Автобус:\n");
	printf("  Номер: %s\n", bus->GosNumber);
	printf("  Владелец: %s\n", bus->Owner);
	printf("  Марка: %s\n", bus->Brand);
	printf("  Модель: %s\n", bus->Model);
	printf("  Цвет: %s\n", bus->Color);
	printf("  Тип двигателя: %s\n", bus->MotorType);
	printf("  Вместимость: %d чел.\n", GetCapacity(bus));
	printf("  Грузоподъемность: %.2f т\n", bus->LoadCapacity);
	printf("\n");
}
void PrintGruz(struct Gruz* gruz) {
	printf("Грузовик:\n");
	printf("  Номер: %s\n", gruz->GosNumber);
	printf("  Владелец: %s\n", gruz->Owner);
	printf("  Марка: %s\n", gruz->Brand);
	printf("  Модель: %s\n", gruz->Model);
	printf("  Цвет: %s\n", gruz->Color);
	printf("  Тип двигателя: %s\n", gruz->MotorType);
	printf("  Грузоподъемность: %.2f т\n", gruz->LoadCapacity);
	printf("  Вместимость: %d чел.\n", GetCapacity(gruz));
	printf("\n");
}
void PrintSpec(struct Spec* spec) {
	printf("Спецтехника:\n");
	printf("  Номер: %s\n", spec->GosNumber);
	printf("  Владелец: %s\n", spec->Owner);
	printf("  Марка: %s\n", spec->Brand);
	printf("  Модель: %s\n", spec->Model);
	printf("  Цвет: %s\n", spec->Color);
	printf("  Описание: %s\n", spec->Description);
	printf("  Вместимость: %d чел.\n", GetCapacity(spec));
	printf("\n");
}
void PrintBase(struct Base* car) {
	if (!car) return;

	switch (car->carsType) {
	case Car:
		PrintCar((struct Car*)car);
		break;
	case Microbus:
		PrintMicrobus((struct Microbus*)car);
		break;
	case Bus:
		PrintBus((struct Bus*)car);
		break;
	case Gruz:
		PrintGruz((struct Gruz*)car);
		break;
	case Spec:
		PrintSpec((struct Spec*)car);
		break;
	}
}


void InputCar(struct Car* car) {
	printf("введите госномер: ");
	scanf_s("%s", car->GosNumber, 10);
	printf("введите фио владельца: ");
	scanf_s("%s", car->Owner, 20);
	printf("введите марку машины: ");
	scanf_s("%s", car->Brand, 20);
	printf("введите модель: ");
	scanf_s("%s", car->Model, 20);
	printf("введите цвет: ");
	scanf_s("%s", car->Color, 10);
	printf("введите тип кузова: ");
	scanf_s("%s", car->KuzovType, 20);
	printf("введите тип двигателя: ");
	scanf_s("%s", car->MotorType, 20);
	printf("введите тип привода: ");
	scanf_s("%s", car->DriveType, 20);
}
void InputMicrobus(struct Microbus* car) {
	printf("введите госномер ");
	scanf_s("%s", car->GosNumber, 10);
	printf("введите фио владельца ");
	scanf_s("%s", car->Owner, 20);
	printf("введите марку машины ");
	scanf_s("%s", car->Brand, 20);
	printf("введите модель ");
	scanf_s("%s", car->Model, 20);
	printf("введите цвет ");
	scanf_s("%s", car->Color, 10);
	printf("введите тип двигателя ");
	scanf_s("%s", car->MotorType, 20);
	printf("введите вмещаемость ");
	scanf_s("%d", &(car->Capacity));

}
void InputBus(struct Bus* car) {
	printf("введите госномер ");
	scanf_s("%s", car->GosNumber, 10);
	printf("введите фио владельца ");
	scanf_s("%s", car->Owner, 20);
	printf("введите марку машины ");
	scanf_s("%s", car->Brand, 20);
	printf("введите модель ");
	scanf_s("%s", car->Model, 20);
	printf("введите цвет");
	scanf_s("%s", car->Color, 10);
	printf("введите тип двигателя ");
	scanf_s("%s", car->MotorType, 29);
	printf("введите вмещаемость ");
	scanf_s("%d", &(car->Capacity));
	printf("введите грузоподъемность ");
	scanf_s("%f", &(car->LoadCapacity));
}
void InputGruz(struct Gruz* car) {
	printf("введите госномер ");
	scanf_s("%s", car->GosNumber, 10);
	printf("введите фио владельца ");
	scanf_s("%s", car->Owner, 20);
	printf("введите марку машины ");
	scanf_s("%s", car->Brand, 20);
	printf("введите модель ");
	scanf_s("%s", car->Model, 20);
	printf("введите цвет ");
	scanf_s("%s", car->Color, 10);
}
void InputSpec(struct Spec* car) {
	printf("введите госномер ");
	scanf_s("%s", car->GosNumber, 10);
	printf("введите фио владельца ");
	scanf_s("%s", car->Owner, 20);
	printf("введите марку машины ");
	scanf_s("%s", car->Brand, 20);
	printf("введите модель ");
	scanf_s("%s", car->Model, 20);
	printf("введите цвет ");
	scanf_s("%s", car->Color, 10);
	printf("введите короткое описание ");
	scanf_s("%s", car->Description, 50);
}
void InputBase(struct Base* base) {
	if (!base) return;

	switch (base->carsType) {
	case Car:
		InputCar((struct Car*)base);
		break;
	case Microbus:
		InputMicrobus((struct Microbus*)base);
		break;
	case Bus:
		InputBus((struct Bus*)base);
		break;
	case Gruz:
		InputGruz((struct Gruz*)base);
		break;
	case Spec:
		InputSpec((struct Spec*)base);
		break;
	}
}


struct Base* FindByNumber(struct List* list, char* number) {
	for (struct Item* i = list->head; i != NULL; i = i->next) {
		if (strcmp(((struct Base*)i)->GosNumber, number) == 0) {
			return (struct Base*)i;
		}
	}
	return NULL;
}
struct List* FindByOwner(struct List* list, char* owner) {
	struct List* result = (struct List*)malloc(sizeof(struct List));
	result->head = NULL;
	result->tail = NULL;
	for (struct Item* i = list->head; i != NULL; i = i->next) {
		if (strcmp(((struct Base*)i)->Owner, owner) == 0) {
			Add(result, i);
		}
	}
	return result;
}
struct List* FindByColor(struct List* list, char* color) {
	struct List* result = (struct List*)malloc(sizeof(struct List));
	result->head = NULL;
	result->tail = NULL;
	for (struct Item* i = list->head; i != NULL; i = i->next) {
		if (strcmp(((struct Base*)i)->Color, color) == 0) {
			Add(result, i);
		}
	}
	return result;
}

struct Base* Create(enum CarsType createTypeCar) {
	struct Base* item = NULL;
	switch (createTypeCar) {
	case Car:
		item = (struct Base*)calloc(1, sizeof(struct Car));
		break;
	case Microbus:
		item = (struct Base*)calloc(1, sizeof(struct Microbus));
		break;
	case Bus:
		item = (struct Base*)calloc(1, sizeof(struct Bus));
		break;
	case Gruz:
		item = (struct Base*)calloc(1, sizeof(struct Gruz));
		break;
	case Spec:
		item = (struct Base*)calloc(1, sizeof(struct Spec));
		break;
	}
	if (item != NULL)
		item->carsType = createTypeCar;
	return item;
}
void Swap(struct List* list, int j) {
	struct Item* a = Remove(list, j);
	Insert(list, a, j + 1);
}

void SortByCapacity(struct List* list, int reverse) {
	int i, j, len = Count(list);
	struct Base* p1, * p2;

	for (i = 0; i < len; i++) {
		for (j = 0; j < len - 1; j++) {
			p1 = (struct Base*)GetItem(list, j);
			p2 = (struct Base*)GetItem(list, j + 1);

			int shouldSwap = 0;
			if (reverse) {

				shouldSwap = GetCapacity(p1) < GetCapacity(p2);
			}
			else {

				shouldSwap = GetCapacity(p1) > GetCapacity(p2);
			}

			if (shouldSwap) {
				Swap(list, j);
			}
		}
	}
}
void PrintListCars(struct List* list) {
	struct Item* item;
	for (item = list->head; item != NULL; item = item->next) {
		PrintBase((struct Base*)item);
	}
}

const int GetCapacity(struct Base* base) {
	if (!base) return;
	switch(base->carsType)
	{
	case Car:
		return 5;
	case Gruz:
		return 2;
	case Spec:
		return 1;
	case Microbus:
		return ((struct Microbus*)base)->Capacity;
	case Bus:
		return ((struct Bus*)base)->Capacity;
	}
}
