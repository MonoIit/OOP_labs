#pragma once
#include <string>
#include <fstream>
#include <iostream>

class Human
{
private:
    std::string name; // Имя
    int age;          // Возраст
    float height;     // Рост
    float weight;     // Вес

public:
    // Функция создания человека
    void create();
    
    // Функция записи данных человека в файл
    void save(std::ofstream& ofs);

    // Функция считывания данных человека из файла
    void download(std::ifstream& ifs);

    // Оператор вывода данных о человеке
    friend std::ostream& operator << (std::ostream& out, const Human& h);
};