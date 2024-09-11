#pragma once
#include <string>
#include <iostream>
#include <fstream>

class AthleteBukshenko {
private:
    std::string name;
    int age;
    int medals;

    bool isValidName(const std::string& name);
    bool isValidAge(int age);
    bool isValidMedals(int medals);

public:
    AthleteBukshenko();
    AthleteBukshenko(const std::string& name, int age, int medals);

    void inputFromConsole();
    void outputToConsole() const;
    void readFromFile(std::ifstream& in);
    void writeToFile(std::ofstream& out) const;
};
