#include <vector>
#include <iostream>
#include <fstream>
#include "Human.h"

class SmirnovGroup
{
private:
    std::vector<SmirnovHuman *> members; // Вектор указателей на объекты Human

public:
    // Деструктор для очистки памяти
    ~SmirnovGroup();

    // Функция добавления элемента
    void addMember();

    // Функция вывода списка на экран
    void printAll();

    // Функция записи списка в файловый поток
    void saveToFile(const std::string &filename);

    // Функция чтения списка из файлового потока
    void loadFromFile(const std::string &filename);

    // Функция очистки списка
    void clear();
};
