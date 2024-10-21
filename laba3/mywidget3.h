#pragma once

#include <QWidget>
#include <QTableWidget>
#include "pch.h"
#include "human.h"
#include "student.h"


class MyWidget3 : public QWidget
{
    Q_OBJECT



public:
    QTableWidget *tableWidget;

    template<class Archive>
    void serialize(Archive &ar, const unsigned int version);
    vector<std::shared_ptr<SmirnovHuman>> members;

    explicit MyWidget3(QWidget *parent = nullptr);
    ~MyWidget3();

    // Функция добавления элемента
    // void addMember();

    // Функция вывода списка на экран
    // void printAll();

    // Функция записи списка в файловый поток
    void saveToFile(const QString &filename);

    // Функция чтения списка из файлового потока
    void loadFromFile(const QString &filename);

    // Функция очистки списка
    void clean();

    void setupTable();
    void populateTable();

signals:
};
