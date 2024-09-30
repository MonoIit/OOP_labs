#pragma once
#include "pch.h"

class SmirnovHuman
{
private:
    friend class boost::serialization::access;

    // Функция зериализации человека
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version);

protected:
    std::string name; // Имя
    int age;          // Возраст
    float height;     // Рост
    float weight;     // Вес

    // Функция для вывода данных в поток
    virtual void print(std::ostream& out) const;

public:
    virtual ~SmirnovHuman() = default;

    // Функция создания человека
    virtual void create();

    // Оператор вывода данных
    friend std::ostream& operator << (std::ostream& out, const SmirnovHuman& h);
};