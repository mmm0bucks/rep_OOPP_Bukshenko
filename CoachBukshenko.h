#pragma once
#include "AthleteBukshenko.h"
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/serialization/vector.hpp>


class CoachBukshenko : public AthleteBukshenko {
private:
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version) {
        ar& boost::serialization::base_object<AthleteBukshenko>(*this); // ������������ �������� ������
        ar& team& experience;
    }

    std::string team;
    int experience; // ���������� ��� �����

public:
    CoachBukshenko() : AthleteBukshenko(), team("Unknown"), experience(0) {}
    CoachBukshenko(const std::string& name, int age, int medals, const std::string& team, int experience)
        : AthleteBukshenko(name, age, medals), team(team), experience(experience) {}

    void inputFromConsole() override; // ���������������� ����������� �������
    void outputToConsole() const override;
};