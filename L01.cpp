#include <iostream>
#include "AthleteStorageBukshenko.h"

void showMenu() {
    std::cout << "1. Добавить атлета\n";
    std::cout << "2. Показать список атлетов\n";
    std::cout << "3. Прочитать файл с атлетами\n";
    std::cout << "4. Записать атлетов в файл\n";
    std::cout << "5. Очистить список добавленных атлетов\n";
    std::cout << "0. Выход\n";
}

int main() {
    AthleteStorageBukshenko storage;
    int choice;
    std::string filename;
    system("chcp 1251");

    do {
        showMenu();
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            AthleteBukshenko* athlete = new AthleteBukshenko();
            athlete->inputFromConsole();
            storage.addAthlete(athlete);
            break;
        }
        case 2:
            storage.displayAthletes();
            break;
        case 3:
            std::cout << "Введите файл для чтения: ";
            std::cin >> filename;
            storage.readFromFile(filename);
            break;
        case 4:
            std::cout << "Введите файл для записи: ";
            std::cin >> filename;
            storage.writeToFile(filename);
            break;
        case 5:
            storage.clear();
            std::cout << "список добавленных атлетов был очищен.\n";
            break;
        case 0:
            std::cout << "Выход из программы.\n";
            break;
        default:
            std::cout << "Некорректный выбор. Попробуйте снова.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}
