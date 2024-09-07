#include "Group.h"

// Деструктор для очистки памяти
Group::~Group()
{
    clear(); // Освобождение всей выделенной памяти
}

// Функция добавления элемента
void Group::addMember(Human *human)
{
    members.push_back(human);
}

// Функция вывода списка на экран
void Group::printAll() const
{
    for (const Human *human : members)
    {
        std::cout << *human << std::endl;
    }
}

// Функция записи списка в файловый поток
void Group::saveToFile(const std::string &filename) const
{
    // Открываем файл на запись
    std::ofstream file(filename);

    // Проверка открытие файла
    if (file.is_open())
    {
        for (Human *human : members)
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
void Group::loadFromFile(const std::string &filename)
{
    // Открываем файл на чтение
    std::ifstream ifs(filename);

    // Проверка открытие файла
    if (ifs.is_open())
    {
        clear(); // Очистить текущий список перед загрузкой новых данных
        while (true)
        {
            Human *human = new Human(); // Создание нового экземпляра человека
            human->download(ifs); // Загрузка данных о человеке

            // Проверка на чтение данных
            if (ifs)
            { 
                addMember(human); // Добавление указателя в список
            }
            else
            {
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
void Group::clear()
{
    for (Human *human : members)
    {
        delete human; // Удаление каждого объекта Human
    }

    // Очищаем вектор указателей
    members.clear(); 
}
