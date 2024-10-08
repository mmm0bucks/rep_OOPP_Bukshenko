#include "AthleteBukshenko.h"
#include <sstream>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/serialization/vector.hpp>

void AthleteBukshenko::inputFromConsole() {
    std::cout << "Введите имя атлета: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "Введите возраст атлета: ";
    std::cin >> age;
    std::cout << "Введите количество медалей: ";
    std::cin >> medals;
}

void AthleteBukshenko::outputToConsole() const {
    std::cout << "Имя: " << name << "\nВозраст: " << age << "\nМедали: " << medals << std::endl;
}