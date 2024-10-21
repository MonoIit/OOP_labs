#include "group.h"


template<class Archive>
void SmirnovGroup::serialize(Archive &ar, const unsigned int version) {
    ar & members;
}

// Функция записи списка в файловый поток
void SmirnovGroup::saveToFile(const QString &filename)
{
    // Открываем файл на запись
    ofstream file(filename.toStdString());

    // Проверка открытие файла
    if (file.is_open())
    {
        boost::archive::text_oarchive oa(file);

        oa << members;
    }
}

// Функция чтения списка из файлового потока
void SmirnovGroup::loadFromFile(const QString &filename)
{
    // Открываем файл на чтение
    ifstream ifs(filename.toStdString());

    // Проверка открытие файла
    if (ifs.is_open())
    {
        clear(); // Очистить текущий список перед загрузкой новых данных

        boost::archive::text_iarchive ia(ifs);

        ia >> members;
    }

}

// Функция очистки списка
void SmirnovGroup::clear()
{
    members.clear();
}
