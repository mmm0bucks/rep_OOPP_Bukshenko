#include "CoachBukshenko.h"
#include <boost/serialization/shared_ptr.hpp>
#include <boost/serialization/vector.hpp>


void CoachBukshenko::inputFromConsole() {
    AthleteBukshenko::inputFromConsole(); // Используем ввод базового класса
    std::cout << "Введите название команды тренера: ";
    std::cin.ignore();
    std::getline(std::cin, team);
    std::cout << "Введите количество лет опыта тренера: ";
    std::cin >> experience;
}

void CoachBukshenko::outputToConsole() const {
    AthleteBukshenko::outputToConsole(); // Используем вывод базового класса
    std::cout << "Команда: " << team << "\nОпыт: " << experience << " лет" << std::endl;
}