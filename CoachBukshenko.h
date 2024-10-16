#pragma once
#include "AthleteBukshenko.h"
#include <boost/serialization/access.hpp>
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/export.hpp>

class CoachBukshenko : public AthleteBukshenko {  
private:
    std::string coachName;  
    int experience;

    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version) {
        ar& boost::serialization::base_object<AthleteBukshenko>(*this); 
        ar& coachName;  
        ar& experience;
    }

public:
    CoachBukshenko();  
    CoachBukshenko(const std::string& athleteName, int athleteYear, double athleteSalary, const std::string& coachName, int experience);  

    // Переопределение виртуальных функций
    void inputFromConsole() override;
    void outputToConsole() const override;

};

// Регистрация производного класса для сериализации
//BOOST_CLASS_EXPORT(CoachBukshenko)  
