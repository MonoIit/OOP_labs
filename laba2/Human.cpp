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



template<class Archive>
void SmirnovHuman::serialize(Archive& ar, const unsigned int version)
{
    ar & name;
    ar & age;
    ar & height;
    ar & weight;
}


// Функция для вывода данных в поток
void SmirnovHuman::print(std::ostream& out) const
{
    out << "------------------------------" << std::endl;
    out << "name: " << name << std::endl;
    out << "age: " << age << std::endl;
    out << "height: " << height << std::endl;
    out << "weigth: " << weight << std::endl;
}


// Оператор вывода данных о человеке
std::ostream& operator << (std::ostream& out, const SmirnovHuman& h)
{
    h.print(out);
    return out; 
}

BOOST_CLASS_EXPORT(SmirnovHuman)