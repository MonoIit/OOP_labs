#include "Group.h"

SmirnovGroup::~SmirnovGroup(){}

// Функция добавления элемента


// Функция вывода списка на экран
void SmirnovGroup::printAll()
{
    for (const auto& human: members)
    {
        std::cout << *human << std::endl;
    }
}

// Функция записи списка в файловый поток
void SmirnovGroup::saveToFile(const std::string &filename)
{
    // Открываем файл на запись
    std::ofstream file(filename);

    // Проверка открытие файла
    if (file.is_open())
    {
        boost::archive::text_oarchive oa(file);

        oa << members;
    }
    else
    {
        std::cerr << "[!] Error: Could not open file for writing: " << filename << std::endl;
    }
}

// Функция чтения списка из файлового потока
void SmirnovGroup::loadFromFile(const std::string &filename)
{
    // Открываем файл на чтение
    std::ifstream ifs(filename);

    // Проверка открытие файла
    if (ifs.is_open())
    {
        clear(); // Очистить текущий список перед загрузкой новых данных
        
        boost::archive::text_iarchive ia(ifs);

        ia >> members;
    }
    else
    {
        std::cerr << "[!] Error: Could not open file for reading: " << filename << std::endl;
    }
}

// Функция очистки списка
void SmirnovGroup::clear()
{
    members.clear(); 
}
