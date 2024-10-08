#pragma once
#include <vector>
#include <memory>
#include "AthleteBukshenko.h"
#include "CoachBukshenko.h"
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/serialization/vector.hpp>


class AthleteStorageBukshenko {
private:
    std::vector<std::shared_ptr<AthleteBukshenko>> athletes; // Контейнер для хранения атлетов и тренеров

    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version) {
        ar& athletes;
    }

public:
    void addAthlete(std::shared_ptr<AthleteBukshenko> athlete); // Добавляем атлета или тренера
    void displayAthletes() const; // Вывод всех атлетов/тренеров
    void readFromFile(const std::string& filename); // Чтение из файла
    void writeToFile(const std::string& filename) const; // Запись в файл
    void clear(); // Очистка контейнера
};