#ifndef GROUP_H
#define GROUP_H

#include "pch.h"
#include "human.h"
#include "student.h"

class SmirnovGroup
{
private:
    template<class Archive>
    void serialize(Archive &ar, const unsigned int version);

public:
    QVector<std::shared_ptr<SmirnovHuman>> members;

    // Функция добавления элемента
    template<typename T>
    void addMember();

    // Функция вывода списка на экран
    // void printAll();

    // Функция записи списка в файловый поток
    void saveToFile(const QString &filename);

    // Функция чтения списка из файлового потока
    void loadFromFile(const QString &filename);

    // Функция очистки списка
    void clear();
};

template <typename T>
void SmirnovGroup::addMember()
{
    std::shared_ptr<SmirnovHuman> member = std::make_shared<T>();  //Создание указателя на нового человека
    member->create(); //Создание человека
    members.push_back(member); //Добавление указателя в массив
}


#endif // GROUP_H
