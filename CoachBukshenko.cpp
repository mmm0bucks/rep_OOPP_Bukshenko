#include "CoachBukshenko.h"
#include <boost/serialization/export.hpp>

// Конструктор по умолчанию
CoachBukshenko::CoachBukshenko() : AthleteBukshenko(), coachName("Unknown"), experience(0) {}  

// Конструктор с параметрами
CoachBukshenko::CoachBukshenko(const std::string& athleteName, int athleteYear, double athleteSalary, const std::string& coachName, int experience)
    : AthleteBukshenko(athleteName, athleteYear, athleteSalary), coachName(coachName), experience(experience) {} 

// Чтение атрибутов с консоли
void CoachBukshenko::inputFromConsole() {
    AthleteBukshenko::inputFromConsole();  // Чтение данных атлета
    std::cout << "Введите имя тренера: ";  
    std::cin >> coachName;  
    std::cout << "Введите стаж тренера: ";  
    std::cin >> experience;
}

// Вывод атрибутов на консоль
void CoachBukshenko::outputToConsole() const {
    AthleteBukshenko::outputToConsole();  
    std::cout << "Имя тренера: " << coachName << std::endl; 
    std::cout << "Стаж тренера: " << experience << " лет" << std::endl;  
}

// Регистрация производного класса для сериализации
BOOST_CLASS_EXPORT(CoachBukshenko)  
