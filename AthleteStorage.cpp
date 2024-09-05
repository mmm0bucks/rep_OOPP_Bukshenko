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
    Athlete* newAthlete = new Athlete();
    newAthlete->inputFromConsole();
    athletes.push_back(newAthlete);
}

// Вывод списка спортсменов на экран
void AthleteStorage::displayAthletes() const {
    for (size_t i = 0; i < athletes.size(); ++i) {
        std::cout << "Спортсмен #" << i + 1 << std::endl;
        athletes[i]->outputToConsole();
        std::cout << std::endl;
    }
}

// Чтение списка спортсменов из файла
void AthleteStorage::readFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла для чтения." << std::endl;
        return;
    }

    clear(); // Очистка текущего списка

    while (!file.eof()) {
        Athlete* newAthlete = new Athlete();
        newAthlete->readFromFile(file);
        if (file) {
            athletes.push_back(newAthlete);
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
        std::cerr << "Ошибка открытия файла для записи." << std::endl;
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
