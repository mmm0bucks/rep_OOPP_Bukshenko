#pragma once
#include <vector>
#include <memory>  // Для shared_ptr
#include <boost/serialization/vector.hpp>
#include "AthleteBukshenko.h"

class AthleteStorageBukshenko {
private:
    std::vector<std::shared_ptr<AthleteBukshenko>> athletes;  

    friend class boost::serialization::access;

    // Шаблонная функция для сериализации
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version) {
        ar& athletes; 
    }

public:
    AthleteStorageBukshenko();
    ~AthleteStorageBukshenko() = default;

    void addAthlete();  
    void addCoach();    
    void displayAthletes() const; 
    void readFromFile(const std::string& filename);
    void writeToFile(const std::string& filename) const;
    void clear();
};
