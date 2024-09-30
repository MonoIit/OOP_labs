#include "pch.h"
#include "Human.h"
#include "Student.h"

class SmirnovGroup
{
private:
    std::vector<std::shared_ptr<SmirnovHuman>> members; // Вектор указателей на объекты Human

public:
    // Деструктор для очистки памяти
    ~SmirnovGroup();

    // Функция добавления элемента
    template<typename T>
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

template <typename T>
void SmirnovGroup::addMember()
{
    std::shared_ptr<SmirnovHuman> member = std::make_shared<T>();  //Создание указателя на нового человека
    member->create(); //Создание человека
    members.push_back(member); //Добавление указателя в массив
}
