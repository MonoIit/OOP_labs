#include "Group.h"

// Деструктор для очистки памяти
SmirnovGroup::~SmirnovGroup()
{
    clear(); // Освобождение всей выделенной памяти
}

// Функция добавления элемента
void SmirnovGroup::addMember()
{
    SmirnovHuman *currentHuman = new SmirnovHuman();  //Создание указателя на нового человека
    currentHuman->create(); //Создание человека
    members.push_back(currentHuman); //Добавление указателя в массив
}

// Функция вывода списка на экран
void SmirnovGroup::printAll()
{
    for (const SmirnovHuman *human : members)
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
        for (SmirnovHuman *human : members)
        {
            // Сохранение данных о человеке в файл
            human->save(file);
        }

        // Закрытие файла
        file.close();
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
        while (true)
        {
            SmirnovHuman *human = new SmirnovHuman(); // Создание указателя на новый экземпляр человека
            human->download(ifs); // Загрузка данных о человеке

            // Проверка на чтение данных
            if (ifs)
            { 
                members.push_back(human);
            }
            else
            {
                delete human;
                break;
            }
        }

        // Закрытие файла
        ifs.close();
    }
    else
    {
        std::cerr << "[!] Error: Could not open file for reading: " << filename << std::endl;
    }
}

// Функция очистки списка
void SmirnovGroup::clear()
{
    for (SmirnovHuman *human : members)
    {
        delete human; // Удаление каждого объекта Human
    }

    // Очищаем вектор указателей
    members.clear(); 
}
