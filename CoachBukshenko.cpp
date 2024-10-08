#include "CoachBukshenko.h"
#include <boost/serialization/shared_ptr.hpp>
#include <boost/serialization/vector.hpp>


void CoachBukshenko::inputFromConsole() {
    AthleteBukshenko::inputFromConsole(); // ���������� ���� �������� ������
    std::cout << "������� �������� ������� �������: ";
    std::cin.ignore();
    std::getline(std::cin, team);
    std::cout << "������� ���������� ��� ����� �������: ";
    std::cin >> experience;
}

void CoachBukshenko::outputToConsole() const {
    AthleteBukshenko::outputToConsole(); // ���������� ����� �������� ������
    std::cout << "�������: " << team << "\n����: " << experience << " ���" << std::endl;
}