#pragma once
#include <vector>
#include "AthleteBukshenko.h"

class AthleteStorageBukshenko {
private:
    std::vector<AthleteBukshenko*> athletes;

public:
    AthleteStorageBukshenko();
    ~AthleteStorageBukshenko();

    void addAthlete(AthleteBukshenko* athlete);
    void displayAthletes() const;
    void readFromFile(const std::string& filename);
    void writeToFile(const std::string& filename) const;
    void clear();
};
