#include <iostream>
#include "list.h"

int main() {
	List list;
	int a, b = 0;
	while (1) {
		std::cout<<"1. Add\n2. Count\n3. PrintList\n4. Insert\n5. Clear\n6. Delete\n";
		while (!(std::cin >> a)) {
			std::cout << "Invalid input. Please enter an integer: ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		} 
		switch (a) {
		case 1:
			list.Add(new Item());
			break;

		case 2:
			std::cout<<"\n"<<list.Count()<<"\n";
			break;

		case 3:
			list.PrintList();
			break;

		case 4:
			std::cout<<"what index?\n";
			while (!(std::cin >> b)) {
				std::cout << "Invalid input. Please enter an integer: ";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			list.Insert(new Item(), b);
			break;
		case 5:
			list.Clear();
			break;

		case 6:
			std::cout<<"what index?\n";
			while (!(std::cin >> b)) {
				std::cout << "Invalid input. Please enter an integer: ";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			list.Delete(b);
		}
	}
}