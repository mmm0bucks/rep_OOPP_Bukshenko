#include "AthleteStorageBukshenko.h"
#include "CoachBukshenko.h"
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/shared_ptr.hpp>

// Конструктор и деструктор
AthleteStorageBukshenko::AthleteStorageBukshenko() {}

void AthleteStorageBukshenko::addAthlete() {
    std::shared_ptr<AthleteBukshenko> newAthlete = std::make_shared<AthleteBukshenko>();
    newAthlete->inputFromConsole();
    athletes.push_back(newAthlete);
}

void AthleteStorageBukshenko::addCoach() {
    std::shared_ptr<CoachBukshenko> newCoach = std::make_shared<CoachBukshenko>();
    newCoach->inputFromConsole();
    athletes.push_back(newCoach);
}

void AthleteStorageBukshenko::displayAthletes() const {
    for (size_t i = 0; i < athletes.size(); ++i) {
        std::cout << "Объект #" << i + 1 << std::endl;
        athletes[i]->outputToConsole();
        std::cout << std::endl;
    }
}

void AthleteStorageBukshenko::readFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла для чтения." << std::endl;
        return;
    }

    try {
        boost::archive::text_iarchive ia(file);
        ia& athletes;
    }
    catch (const boost::archive::archive_exception& ex) {
        std::cerr << "Ошибка десериализации: " << ex.what() << std::endl;
    }
}

void AthleteStorageBukshenko::writeToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла для записи." << std::endl;
        return;
    }

    try {
        boost::archive::text_oarchive oa(file);
        oa& athletes;
    }
    catch (const boost::archive::archive_exception& ex) {
        std::cerr << "Ошибка сериализации: " << ex.what() << std::endl;
    }
}

void AthleteStorageBukshenko::clear() {
    athletes.clear();
}
