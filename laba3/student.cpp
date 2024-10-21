#include "student.h"



SmirnovStudent::SmirnovStudent(const QString& name, int age, int height, int weight, const QString& university, int pass) {
    this->name = name;
    this->age = age;
    this->height = height;
    this->weight = weight;
    this->university = university;
    this->pass = pass;
}


template<class Archive>
void SmirnovStudent::serialize(Archive& ar, const unsigned int version)
{
    ar & boost::serialization::base_object<SmirnovHuman>(*this);

    ar & university;
    ar & pass;
}


BOOST_CLASS_EXPORT(SmirnovStudent)
