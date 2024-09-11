#include "AthleteStorageBukshenko.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>

// Конструктор и деструктор
AthleteStorageBukshenko::AthleteStorageBukshenko() {}

AthleteStorageBukshenko::~AthleteStorageBukshenko() {
    clear();
}

// Добавление спортсмена
void AthleteStorageBukshenko::addAthlete(AthleteBukshenko* athlete) {
    athletes.push_back(athlete);
}

// Вывод списка спортсменов на экран
void AthleteStorageBukshenko::displayAthletes() const {
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

// Чтение списка спортсменов из файла построчно
void AthleteStorageBukshenko::readFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file for reading: " << filename << std::endl;
        return;
    }

    std::cout << "File opened successfully: " << filename << std::endl;

    // Проверка на пустоту файла
    if (file.peek() == std::ifstream::traits_type::eof()) {
        std::cout << "The file is empty, nothing to read." << std::endl;
        file.close();
        return;
    }

    clear();  // Очистка текущего списка

    std::string line;
    std::regex regex_pattern(R"(^(.*)\s+(\d+)\s+(\d+)$)");
    std::smatch match;

    while (std::getline(file, line)) {
        // Используем регулярное выражение для поиска имени, возраста и медалей
        if (std::regex_match(line, match, regex_pattern)) {
            std::string name = match[1];
            int age = std::stoi(match[2]);
            int medals = std::stoi(match[3]);

            // Отладочное сообщение о считанных данных
            std::cout << "Read athlete: " << name << ", age: " << age << ", medals: " << medals << std::endl;

            // Создание и добавление нового спортсмена
            AthleteBukshenko* newAthlete = new AthleteBukshenko(name, age, medals);
            athletes.push_back(newAthlete);
        }
        else {
            std::cerr << "Error reading line: " << line << std::endl;
        }
    }

    file.close();

    // Проверка, если спортсмены были считаны, выводим их на экран
    if (athletes.empty()) {
        std::cout << "No athletes were read from the file." << std::endl;
    }
    else {
        displayAthletes();
    }
}

// Запись списка спортсменов в файл
void AthleteStorageBukshenko::writeToFile(const std::string& filename) const {
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
void AthleteStorageBukshenko::clear() {
    for (auto& athlete : athletes) {
        delete athlete;
    }
    athletes.clear();
}
