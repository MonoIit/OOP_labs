#pragma once
#include "pch.h"
#include "Human.h"

class SmirnovStudent: public SmirnovHuman
{
private:
    friend class boost::serialization::access;

    // Функция зериализации студента
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version);

protected:
    std::string university;
    int pass;

    // Функция для вывода данных в поток
    void print(std::ostream& out) const override;

public:
    // Функция создания студента
    void create() override;
};