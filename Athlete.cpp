#include <iostream>
#include "Athlete.h"

// Конструктор по умолчанию
Athlete::Athlete() : name("Unknown"), age(0), medals(0) {}

// Конструктор с параметрами
Athlete::Athlete(const std::string& name, int age, int medals)
    : name(name), age(age), medals(medals) {}

// Чтение атрибутов с консоли
void Athlete::inputFromConsole() {
    std::cout << "Enter sportsman name: ";
    std::cin >> name;
    std::cout << "Enter sportsman age: ";
    std::cin >> age;
    std::cout << "Enter count of medals of the sportsman: ";
    std::cin >> medals;
}

// Вывод атрибутов на консоль
void Athlete::outputToConsole() const {
    std::cout << "Sportsman name: " << name << std::endl;
    std::cout << "Sportsman age: " << age << std::endl;
    std::cout << "Count of sportman medals:" << medals << std::endl;
}

// Чтение из файла
void Athlete::readFromFile(std::ifstream& in) {
    in >> name >> age >> medals;
}

// Запись в файл
void Athlete::writeToFile(std::ofstream& out) const {
    out << name << " " << age << " " << medals << std::endl;
}