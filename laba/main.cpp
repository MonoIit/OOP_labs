#include <iostream>
#include "Human.h"
#include "Group.h"
#include "tools.h"

using namespace std;

void menu()
{
    cout << "1. Create Human" << endl;
    cout << "2. Show Human" << endl;
    cout << "3. Download Human" << endl;
    cout << "4. Save Human" << endl;
    cout << "5. Add Human into container" << endl;
    cout << "6. Show container" << endl;
    cout << "7. Download container" << endl;
    cout << "8. Save container" << endl;
    cout << "9. Clear container" << endl;
    cout << "0. Exit" << endl;
}

int main() 
{
    Human* currentHuman = nullptr;  // Указатель на текущий объект Human
    Group group;  // Объект класса Group для хранения объектов Human
    bool flag = true;

    while (flag)
    {
        menu();
        switch (input_value<int>(0, 9))
        {
            case 1: // Создать человека
            {
                delete currentHuman; // Удаляем текущего человека
                currentHuman = new Human(); // Создаём нового человека
                currentHuman->create(); // Вводим данные нового человека
                break;
            }
            case 2: // Показать человека
            {
                // Проверка на наличие человека
                if (currentHuman) 
                {
                    cout << *currentHuman << endl;
                } 
                else 
                {
                    cout << "No human created." << endl;
                }
                break;
            }
            case 3: // Прочитать человека из файла
            {
                // Проверка на наличие человека
                if (currentHuman) 
                {
                    std::cout << "Human already created." << std::endl;
                } 
                else 
                {
                    // Объявляем нового человека
                    currentHuman = new Human();

                    // Считываем путь до файла, где прописан человек
                    cout << "Enter the file path..." << endl;
                    string filename = read_string();

                    // Открываем файл на чтение
                    ifstream ifs(filename);

                    // Проверка на открытие файла
                    if (ifs.is_open()) 
                    {
                        // Считываем данные человека из файла
                        currentHuman->download(ifs);
                        std::cout << "Human loaded from file." << std::endl;

                        // Закрываем файл
                        ifs.close();
                    } 
                    else 
                    {
                        std::cout << "Error: Could not open file." << std::endl;
                    }
                }
                break;
            }
            case 4: // Загрузить человека в файл
            {
                // Проверака на наличие человека
                if (currentHuman) {
                    // Считываем путь до файла
                    cout << "Enter the file path..." << endl;
                    string filename = read_string();

                    // Открываем файл на запись
                    std::ofstream ofs(filename);

                    // Проверка на открытие файла
                    if (ofs.is_open()) 
                    {
                        // Записываем данные человека в файл
                        currentHuman->save(ofs);
                        std::cout << "Human saved to file." << std::endl;

                        // Закрываем файл
                        ofs.close();
                    } 
                    else 
                    {
                        std::cout << "Error: Could not open file." << std::endl;
                    }
                } 
                else 
                {
                    std::cout << "No human created to save." << std::endl;
                }
                break;
            } 
            case 5: // Добавить Human в контейнер
            {  
                // Проверка на наличение человека
                if (currentHuman) 
                {
                    Human* newHuman = new Human(*currentHuman);  // Создание копии текущего Human
                    group.addMember(newHuman); // Добавление человека в группу (контейнер)
                    std::cout << "Human added to container." << std::endl;
                } 
                else 
                {
                    std::cout << "No human created to add to container." << std::endl;
                }
                break;
            }
            case 6: // Показать всех людей в группе
            {  
                group.printAll();
                break;
            }
            case 7: // Загрузить группу из файла
            {  
                // Считывание пути до файла
                cout << "Enter the file path..." << endl;
                string filename = read_string();

                // Загрузка данных из файла
                group.loadFromFile(filename);
                std::cout << "Container loaded from file." << std::endl;
                break;
            }
            case 8: // Сохранить группу в файл
            {  
                // Считывание пути до файла
                cout << "Enter the file path..." << endl;
                string filename = read_string();

                // Загрузка данных в файл
                group.saveToFile(filename);
                std::cout << "Container saved to file." << std::endl;
                break;
            }
            case 9: // Очистить контейнер 
            {  
                group.clear();
                std::cout << "Container cleared." << std::endl;
                break;
            }
            case 0: // Выход из программы
            {
                flag = false;
                break;
            }
            default: // Иные опции
            {
                cout << "Enter correct number" << endl;
                break;
            }
        }
    }

    // Удаление человека перед завершение программы
    delete currentHuman;

    return 0;
}