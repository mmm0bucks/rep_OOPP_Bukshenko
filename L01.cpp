#include <iostream>
#include "AthleteStorageBukshenko.h"

using namespace std;

void showMenu() {
    std::cout << "1. Добавить атлета\n";
    std::cout << "2. Добавить тренера\n";
    std::cout << "3. Показать список атлетов\n";
    std::cout << "4. Прочитать файл с атлетами\n";
    std::cout << "5. Записать атлетов в файл\n";
    std::cout << "6. Очистить список добавленных атлетов\n";
    std::cout << "0. Выход\n";
}

int main() {
    AthleteStorageBukshenko storage;  
    int choice;
    string filename;
    system("chcp 1251");

    do {
        showMenu();
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            system("cls");
            storage.addAthlete();  
            break;
        case 2:
            system("cls");
            storage.addCoach();  
            break;
        case 3:
            system("cls");
            storage.displayAthletes(); 
            break;
        case 4:
            system("cls");
            cout << "Введите имя файла для чтения: ";
            cin >> filename;
            storage.readFromFile(filename);
            break;
        case 5:
            system("cls");
            cout << "Введите имя файла для записи: ";
            cin >> filename;
            storage.writeToFile(filename);
            break;
        case 6:
            system("cls");
            storage.clear();
            cout << "Список атлетов очищен.\n";  
            break;
        case 0:
            system("cls");
            cout << "Выход из программы.\n";
            break;
        default:
            system("cls");
            cout << "Неверный выбор. Попробуйте снова.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}
