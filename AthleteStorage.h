#pragma once
#include <vector>
#include "Athlete.h"

class AthleteStorage {
private:
    std::vector<Athlete*> athletes;

public:
    AthleteStorage();
    ~AthleteStorage();

    // Функции управления списком спортсменов
    void addAthlete();
    void displayAthletes() const;
    void readFromFile(const std::string& filename);
    void writeToFile(const std::string& filename) const;
    void clear();
};
