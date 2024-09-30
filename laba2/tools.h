#include "pch.h"


inline std::string read_string()
{
    // Функция для считыванияя строки
    std::string name;
    std::cin >> std::ws;
    std::getline(std::cin, name);
    std::cerr << name << std::endl;
    return name;
}

template <typename T>
T input_value(T min = std::numeric_limits<T>::min(), T max = std::numeric_limits<T>::max())
{
    // Функция для считывания значений (int, float, double)
    // с указание диапозонов доступных значений
    T value;
    std::cin >> value;
    while (std::cin.fail() || std::cin.peek() != '\n' || value < min || value > max)
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "try again" << std::endl;
        std::cin >> value;
    }
    std::cerr << value << std::endl;
    return value;
}