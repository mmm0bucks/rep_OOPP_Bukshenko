// L01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "AthleteStorage.h"

void showMenu() {
    std::cout << "1. Добавить спортсмена\n";
    std::cout << "2. Показать всех спортсменов\n";
    std::cout << "3. Считать спортсменов из файла\n";
    std::cout << "4. Записать спортсменов в файл\n";
    std::cout << "5. Очистить список спортсменов\n";
    std::cout << "0. Выход\n";
}

int main() {
    AthleteStorage storage;
    int choice;
    std::string filename;

    do {
        showMenu();
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            storage.addAthlete();
            break;
        case 2:
            storage.displayAthletes();
            break;
        case 3:
            std::cout << "Введите имя файла для чтения: ";
            std::cin >> filename;
            storage.readFromFile(filename);
            break;
        case 4:
            std::cout << "Введите имя файла для записи: ";
            std::cin >> filename;
            storage.writeToFile(filename);
            break;
        case 5:
            storage.clear();
            std::cout << "Список спортсменов очищен.\n";
            break;
        case 0:
            std::cout << "Выход из программы.\n";
            break;
        default:
            std::cout << "Неверный выбор. Попробуйте снова.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
