#include "human.h"




// Функция создания человека
SmirnovHuman::SmirnovHuman(const QString &name, int age, int height, int weight) {
    this->name = name;
    this->age = age;
    this->height = height;
    this->weight = weight;
}



template<class Archive>
void SmirnovHuman::serialize(Archive& ar, const unsigned int version)
{
    ar & name;
    ar & age;
    ar & height;
    ar & weight;
}


BOOST_CLASS_EXPORT(SmirnovHuman)
