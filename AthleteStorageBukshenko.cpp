#include "AthleteStorageBukshenko.h"
#include <iostream>
#include <fstream>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/serialization/vector.hpp>


void AthleteStorageBukshenko::addAthlete(std::shared_ptr<AthleteBukshenko> athlete) {
    athletes.push_back(athlete); // Добавляем атлета или тренера в контейнер
}

void AthleteStorageBukshenko::displayAthletes() const {
    for (const auto& athlete : athletes) {
        athlete->outputToConsole(); // Вызываем полиморфную функцию для вывода
    }
}

void AthleteStorageBukshenko::readFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Ошибка: Не удалось открыть файл для чтения.\n";
        return;
    }
    boost::archive::text_iarchive ia(file);
    ia >> *this;
}

void AthleteStorageBukshenko::writeToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Ошибка: Не удалось открыть файл для записи.\n";
        return;
    }
    boost::archive::text_oarchive oa(file);
    oa << *this;
}

void AthleteStorageBukshenko::clear() {
    athletes.clear();
}