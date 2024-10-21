#ifndef STUDENT_H
#define STUDENT_H

#include "pch.h"
#include "human.h"

class SmirnovStudent: public SmirnovHuman
{
private:
    friend class boost::serialization::access;

    // Функция зериализации студента
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version);

public:
    QString university;
    int pass;

    SmirnovStudent() = default;
    SmirnovStudent(const QString& name, int age, int height, int weight, const QString& university, int pass);

    QString getType() const override { return "Human"; }
};

#endif // STUDENT_H
