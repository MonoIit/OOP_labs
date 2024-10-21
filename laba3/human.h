#ifndef HUMAN_H
#define HUMAN_H

#include "pch.h"

class SmirnovHuman
{
private:
    friend class boost::serialization::access;

    // Функция зериализации человека
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version);

public:
    QString name; // Имя
    int age;          // Возраст
    float height;     // Рост
    float weight;     // Вес

    // Функция для вывода данных в поток
    // virtual void print(std::ostream& out) const;

    SmirnovHuman() = default;
    SmirnovHuman(const QString& name, int age, int height, int weight);

    virtual ~SmirnovHuman() = default;

    virtual QString getType() const { return "Human"; }
};

#endif // HUMAN_H
