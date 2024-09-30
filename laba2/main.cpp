#include "pch.h"
#include "Group.h"
#include "tools.h"

void menu()
{
    cout << "1. Add Human into container" << endl;
    cout << "2. Add Student into container" << endl;
    cout << "3. Show container" << endl;
    cout << "4. Download container" << endl;
    cout << "5. Save container" << endl;
    cout << "6. Clear container" << endl;
    cout << "0. Exit" << endl;
}

int main() 
{
    SmirnovGroup group;  // Объект класса Group для хранения объектов Human
    bool flag = true;

    while (flag)
    {
        menu();
        switch (input_value<int>(0, 6))
        {
            case 1: // Добавить Human в контейнер
            {  
                group.addMember<SmirnovHuman>(); // Добавление человека в группу (контейнер)
                std::cout << "Human added to container." << std::endl;
                break;
            }
            case 2:
            {
                group.addMember<SmirnovStudent>(); // Добавление студента в группу (контейнер)
                std::cout << "Human added to container." << std::endl;
                break;
            }
            case 3: // Показать всех людей в группе
            {  
                group.printAll();
                break;
            }
            case 4: // Загрузить группу из файла
            {  
                // Считывание пути до файла
                cout << "Enter the file path..." << endl;
                string filename = read_string();

                // Загрузка данных из файла
                group.loadFromFile(filename);
                std::cout << "Container loaded from file." << std::endl;
                break;
            }
            case 5: // Сохранить группу в файл
            {  
                // Считывание пути до файла
                cout << "Enter the file path..." << endl;
                string filename = read_string();

                // Загрузка данных в файл
                group.saveToFile(filename);
                std::cout << "Container saved to file." << std::endl;
                break;
            }
            case 6: // Очистить контейнер 
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