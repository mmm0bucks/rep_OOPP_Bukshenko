#include "AthleteStorage.h"
#include <iostream>
#include <fstream>

// Конструктор и деструктор
AthleteStorage::AthleteStorage() {}

AthleteStorage::~AthleteStorage() {
    clear();
}

// Добавление спортсмена
void AthleteStorage::addAthlete() {
    std::string name;
    int age, medals;

    // Запросим у пользователя данные перед созданием объекта Athlete
    std::cout << "Enter athlete's name (you can use first and last name separated by space): ";
    std::cin.ignore(); // Очищаем буфер ввода
    std::getline(std::cin, name);

    std::cout << "Enter athlete's age (non-negative number): ";
    std::cin >> age;

    std::cout << "Enter number of medals (non-negative number): ";
    std::cin >> medals;

    // Создаем объект Athlete с параметрами
    Athlete* newAthlete = new Athlete(name, age, medals);
    athletes.push_back(newAthlete);
}

// Вывод списка спортсменов на экран
void AthleteStorage::displayAthletes() const {
    if (athletes.empty()) {
        std::cout << "No athletes in the list.\n";
        return;
    }

    for (size_t i = 0; i < athletes.size(); ++i) {
        std::cout << "Athlete #" << i + 1 << std::endl;
        athletes[i]->outputToConsole();
        std::cout << std::endl;
    }
}

// Чтение списка спортсменов из файла с выводом в консоль
void AthleteStorage::readFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file for reading." << std::endl;
        return;
    }

    clear(); // Очистка текущего списка

    // Чтение данных о спортсменах
    while (!file.eof()) {
        Athlete* newAthlete = new Athlete();
        newAthlete->readFromFile(file);

        // Если чтение успешно, добавляем в список и выводим на экран
        if (file) {
            athletes.push_back(newAthlete);
            newAthlete->outputToConsole();
            std::cout << std::endl;
        }
        else {
            delete newAthlete;
        }
    }

    file.close();
}

// Запись списка спортсменов в файл
void AthleteStorage::writeToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file for writing." << std::endl;
        return;
    }

    for (const auto& athlete : athletes) {
        athlete->writeToFile(file);
    }

    file.close();
}

// Очистка списка спортсменов
void AthleteStorage::clear() {
    for (auto& athlete : athletes) {
        delete athlete;
    }
    athletes.clear();
}
