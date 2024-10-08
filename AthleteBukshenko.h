#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <boost/serialization/access.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/serialization/vector.hpp>


class AthleteBukshenko {
private:
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version) {
        ar& name& age& medals;
    }

protected:
    std::string name;
    int age;
    int medals;

public:
    AthleteBukshenko() : name("Unknown"), age(0), medals(0) {}
    AthleteBukshenko(const std::string& name, int age, int medals) : name(name), age(age), medals(medals) {}

    virtual void inputFromConsole(); // Виртуальные функции для полиморфизма
    virtual void outputToConsole() const;

    virtual ~AthleteBukshenko() = default; // Виртуальный деструктор
};
