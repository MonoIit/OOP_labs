#include "Human.h"
#include "tools.h"


// Функция создания человека
void SmirnovHuman::create()
{
    std::cout << "Enter human name" << std::endl;
    name = read_string();
    std::cout << "Enter age" << std::endl;
    age = input_value<int>(0, 100);
    std::cout << "Enter height" << std::endl;
    height = input_value<float>(0, 240);
    std::cout << "Enter weight" << std::endl;
    weight = input_value<float>(2, 400);
}


// Функция записи данных человека в файл
void SmirnovHuman::save(std::ofstream& ofs)
{
    ofs << name << std::endl;
    ofs << age << std::endl;
    ofs << height << std::endl;
    ofs << weight << std::endl;
}


// Функция считывания данных человека из файла
void SmirnovHuman::download(std::ifstream& ifs)
{
    // считываем данные в поток
    getline(ifs, name); 
    ifs >> age >> height >> weight;

    // Пропускаем символ новой строки после считывания
    ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
}


// Оператор вывода данных о человеке
std::ostream& operator << (std::ostream& out, const SmirnovHuman& h)
{
    out << "------------------------------" << std::endl;
    out << "Your Human:" << std::endl;
    out << "name: " << h.name << std::endl;
    out << "age: " << h.age << std::endl;
    out << "height: " << h.height << std::endl;
    out << "weigth: " << h.weight << std::endl;
    out << "------------------------------" << std::endl;
    return out;
}
