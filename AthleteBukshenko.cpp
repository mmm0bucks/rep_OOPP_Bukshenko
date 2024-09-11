#include "AthleteBukshenko.h"
#include <sstream>

// Конструктор по умолчанию
AthleteBukshenko::AthleteBukshenko() : name("Unknown"), age(0), medals(0) {}

// Конструктор с параметрами
AthleteBukshenko::AthleteBukshenko(const std::string& name, int age, int medals)
    : name(name), age(age), medals(medals) {}

// Проверка имени
bool AthleteBukshenko::isValidName(const std::string& name) {
    std::istringstream iss(name);
    std::string firstName, lastName;
    if (!(iss >> firstName)) {
        return false;
    }
    if (iss >> lastName) {
        if (iss >> lastName) {
            return false;
        }
    }
    return true;
}

// Проверка возраста
bool AthleteBukshenko::isValidAge(int age) {
    return age >= 0;
}

// Проверка медалей
bool AthleteBukshenko::isValidMedals(int medals) {
    return medals >= 0;
}

// Чтение данных с консоли
void AthleteBukshenko::inputFromConsole() {
    std::string inputName;
    int inputAge, inputMedals;

    do {
        std::cout << "Enter athlete's name (first and last name separated by space): ";
        std::cin.ignore();
        std::getline(std::cin, inputName);
        if (!isValidName(inputName)) {
            std::cout << "Invalid name. Please enter one or two words.\n";
        }
    } while (!isValidName(inputName));

    do {
        std::cout << "Enter athlete's age (non-negative number): ";
        std::cin >> inputAge;
        if (!isValidAge(inputAge)) {
            std::cout << "Age cannot be negative.\n";
        }
    } while (!isValidAge(inputAge));

    do {
        std::cout << "Enter number of medals (non-negative number): ";
        std::cin >> inputMedals;
        if (!isValidMedals(inputMedals)) {
            std::cout << "Medals cannot be negative.\n";
        }
    } while (!isValidMedals(inputMedals));

    name = inputName;
    age = inputAge;
    medals = inputMedals;
}

// Вывод на консоль
void AthleteBukshenko::outputToConsole() const {
    std::cout << "Athlete's name: " << name << std::endl;
    std::cout << "Athlete's age: " << age << std::endl;
    std::cout << "Number of medals: " << medals << std::endl;
}

// Чтение из файла
void AthleteBukshenko::readFromFile(std::ifstream& in) {
    in >> name >> age >> medals;
}

// Запись в файл
void AthleteBukshenko::writeToFile(std::ofstream& out) const {
    out << name << " " << age << " " << medals << std::endl;
}
