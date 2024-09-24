#include <iostream>
#include "Human.h"
#include "Group.h"
#include "tools.h"

using namespace std;

void menu()
{
    cout << "1. Add Human into container" << endl;
    cout << "2. Show container" << endl;
    cout << "3. Download container" << endl;
    cout << "4. Save container" << endl;
    cout << "5. Clear container" << endl;
    cout << "0. Exit" << endl;
}

int main() 
{
    SmirnovGroup group;  // Объект класса Group для хранения объектов Human
    bool flag = true;

    while (flag)
    {
        menu();
        switch (input_value<int>(0, 5))
        {
            case 1: // Добавить Human в контейнер
            {  
                
                group.addMember(); // Добавление человека в группу (контейнер)
                std::cout << "Human added to container." << std::endl;
                break;
            }
            case 2: // Показать всех людей в группе
            {  
                group.printAll();
                break;
            }
            case 3: // Загрузить группу из файла
            {  
                // Считывание пути до файла
                cout << "Enter the file path..." << endl;
                string filename = read_string();

                // Загрузка данных из файла
                group.loadFromFile(filename);
                std::cout << "Container loaded from file." << std::endl;
                break;
            }
            case 4: // Сохранить группу в файл
            {  
                // Считывание пути до файла
                cout << "Enter the file path..." << endl;
                string filename = read_string();

                // Загрузка данных в файл
                group.saveToFile(filename);
                std::cout << "Container saved to file." << std::endl;
                break;
            }
            case 5: // Очистить контейнер 
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

    return 0;
}