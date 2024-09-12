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
        std::cout << "Введите имя атлета (имя и фамилия через пробел): ";
        std::cin.ignore();
        std::getline(std::cin, inputName);
        if (!isValidName(inputName)) {
            std::cout << "Имя введено некорректно. Пожалуйста введите два слова.\n";
        }
    } while (!isValidName(inputName));

    do {
        std::cout << "Введите возраст атлета (положительное число): ";
        std::cin >> inputAge;
        if (!isValidAge(inputAge)) {
            std::cout << "Возраст не может быть отрицательным.\n";
        }
    } while (!isValidAge(inputAge));

    do {
        std::cout << "Введите кол-во медалей (Положительное число): ";
        std::cin >> inputMedals;
        if (!isValidMedals(inputMedals)) {
            std::cout << "Кол-во медалей введено некорректно.\n";
        }
    } while (!isValidMedals(inputMedals));

    name = inputName;
    age = inputAge;
    medals = inputMedals;
}

// Вывод на консоль
void AthleteBukshenko::outputToConsole() const {
    std::cout << "Имя атлета: " << name << std::endl;
    std::cout << "Возраст атлета: " << age << std::endl;
    std::cout << "Кол-во медалей атлета: " << medals << std::endl;
}

// Чтение из файла
void AthleteBukshenko::readFromFile(std::ifstream& in) {
    in >> name >> age >> medals;
}

// Запись в файл
void AthleteBukshenko::writeToFile(std::ofstream& out) const {
    out << name << " " << age << " " << medals << std::endl;
}
