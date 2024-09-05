#pragma once
#include <string>
#include <iostream>
#include <fstream>

class Athlete {
private:
    std::string name;
    int age;
    int medals;

public:
    Athlete();
    Athlete(const std::string& name, int age, int medals);

    // Функции для работы с объектом
    void inputFromConsole();
    void outputToConsole() const;
    void readFromFile(std::ifstream& in);
    void writeToFile(std::ofstream& out) const;
};



