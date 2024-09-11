#include "Athlete.h"
#include <sstream>

// Конструктор по умолчанию
Athlete::Athlete() : name("Unknown"), age(0), medals(0) {}

// Конструктор с параметрами
Athlete::Athlete(const std::string& name, int age, int medals)
    : name(name), age(age), medals(medals) {}

// Проверка имени (одно или два слова через пробел)
bool Athlete::isValidName(const std::string& name) {
    std::istringstream iss(name);
    std::string firstName, lastName;
    if (!(iss >> firstName)) {
        return false; // Если первое имя отсутствует, имя некорректно
    }
    if (iss >> lastName) {
        if (iss >> lastName) {
            return false; // Если более двух слов, имя некорректно
        }
    }
    return true;
}

// Проверка возраста (не может быть отрицательным)
bool Athlete::isValidAge(int age) {
    return age >= 0;
}

// Проверка количества медалей (не может быть отрицательным)
bool Athlete::isValidMedals(int medals) {
    return medals >= 0;
}

// Чтение атрибутов с консоли с проверками
void Athlete::inputFromConsole() {
    std::string inputName;
    int inputAge, inputMedals;

    // Ввод имени с проверкой
    do {
        std::cout << "Enter athlete's name (you can use first and last name separated by space): ";
        std::cin.ignore(); // Очищаем буфер ввода
        std::getline(std::cin, inputName);
        if (!isValidName(inputName)) {
            std::cout << "Invalid name. Please enter one or two words separated by space.\n";
        }
    } while (!isValidName(inputName));

    // Ввод возраста с проверкой
    do {
        std::cout << "Enter athlete's age (non-negative number): ";
        std::cin >> inputAge;
        if (!isValidAge(inputAge)) {
            std::cout << "Age cannot be negative. Please enter a valid age.\n";
        }
    } while (!isValidAge(inputAge));

    // Ввод количества медалей с проверкой
    do {
        std::cout << "Enter number of medals (non-negative number): ";
        std::cin >> inputMedals;
        if (!isValidMedals(inputMedals)) {
            std::cout << "Medals cannot be negative. Please enter a valid number.\n";
        }
    } while (!isValidMedals(inputMedals));

    // Устанавливаем значения атрибутов, если все проверки пройдены
    name = inputName;
    age = inputAge;
    medals = inputMedals;
}

// Вывод атрибутов на консоль
void Athlete::outputToConsole() const {
    std::cout << "Athlete's name: " << name << std::endl;
    std::cout << "Athlete's age: " << age << std::endl;
    std::cout << "Number of medals: " << medals << std::endl;
}

// Чтение из файла
void Athlete::readFromFile(std::ifstream& in) {
    in >> name >> age >> medals;
}

// Запись в файл
void Athlete::writeToFile(std::ofstream& out) const {
    out << name << " " << age << " " << medals << std::endl;
}
