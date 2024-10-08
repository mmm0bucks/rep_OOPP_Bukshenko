#include <iostream>
#include "AthleteStorageBukshenko.h"
#include <boost/serialization/shared_ptr.hpp>
#include <boost/serialization/vector.hpp>


void showMenu() {
    std::cout << "1. Добавить атлета\n";
    std::cout << "2. Добавить тренера\n";
    std::cout << "3. Показать список атлетов и тренеров\n";
    std::cout << "4. Прочитать файл с атлетами и тренерами\n";
    std::cout << "5. Записать атлетов и тренеров в файл\n";
    std::cout << "6. Очистить список атлетов и тренеров\n";
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
            std::shared_ptr<AthleteBukshenko> athlete = std::make_shared<AthleteBukshenko>();
            athlete->inputFromConsole();
            storage.addAthlete(athlete);
            break;
        }
        case 2: {
            std::shared_ptr<CoachBukshenko> coach = std::make_shared<CoachBukshenko>();
            coach->inputFromConsole();
            storage.addAthlete(coach);
            break;
        }
        case 3:
            storage.displayAthletes();
            break;
        case 4:
            std::cout << "Введите имя файла для чтения: ";
            std::cin >> filename;
            storage.readFromFile(filename);
            break;
        case 5:
            std::cout << "Введите имя файла для записи: ";
            std::cin >> filename;
            storage.writeToFile(filename);
            break;
        case 6:
            storage.clear();
            std::cout << "Список очищен.\n";
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
