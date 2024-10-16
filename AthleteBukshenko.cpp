#include "AthleteBukshenko.h"

using namespace std;

// Конструкторы
AthleteBukshenko::AthleteBukshenko() : name("Unknown"), year(0), salary(0.0) {}  

AthleteBukshenko::AthleteBukshenko(const string& name, int year, double salary)
    : name(name), year(year), salary(salary) {}  

// Чтение атрибутов с консоли
void AthleteBukshenko::inputFromConsole() {
    cout << "Введите имя спортсмена: ";  
    cin >> name;
    cout << "Введите год рождения: ";  
    cin >> year;
    cout << "Введите зарплату спортсмена: ";  
    cin >> salary;  
}

// Вывод атрибутов на консоль
void AthleteBukshenko::outputToConsole() const {
    cout << "Имя спортсмена: " << name << endl;  
    cout << "Год рождения: " << year << endl; 
    cout << "Зарплата: " << salary << endl;  
}

