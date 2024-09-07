#include <vector>
#include <iostream>
#include <fstream>
#include "Human.h"

class Group
{
private:
    std::vector<Human *> members; // Вектор указателей на объекты Human

public:
    // Деструктор для очистки памяти
    ~Group();

    // Функция добавления элемента
    void addMember(Human *human);

    // Функция вывода списка на экран
    void printAll() const;

    // Функция записи списка в файловый поток
    void saveToFile(const std::string &filename) const;

    // Функция чтения списка из файлового потока
    void loadFromFile(const std::string &filename);

    // Функция очистки списка
    void clear();
};
