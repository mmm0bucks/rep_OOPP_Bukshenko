#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/base_object.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

class AthleteBukshenko {
private:
    std::string name;
    int year;
    double salary;  

    friend class boost::serialization::access; // Для доступа к приватным полям в процессе сериализации
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version) {
        ar& name;
        ar& year;
        ar& salary;  
    }

public:
    AthleteBukshenko();  
    AthleteBukshenko(const std::string& name, int year, double salary);  

    // Виртуальные функции для ввода/вывода
    virtual void inputFromConsole();
    virtual void outputToConsole() const;

    virtual ~AthleteBukshenko() = default; // Виртуальный деструктор для корректного удаления объектов наследников
};

// Регистрация базового класса для сериализации
//BOOST_CLASS_EXPORT(AthleteBukshenko)
