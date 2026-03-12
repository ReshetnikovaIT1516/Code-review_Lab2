/*
Дан циклический двусвязный линейный список и указатель первый
элемент этого списка. Необходимо удалить в списке все элементы, у которых правый и
левый сосед совпадают. Если таких элементов нет, то оставить список без изменений.
Первый и последний элементы считать соседями. В результате вернуть ссылку на
последний элемент полученного списка.
Все динамические структуры данных реализовывать через классы. Не использовать STL.
Для каждой динамической структуры должен быть предусмотрен стандартный
набор методов - добавления/удаления/вывода элементов. Во всех задачах обязательно наличие
дружественного интерфейса. Ввод данных с клавиатуры.
*/

//FIX ME: Добавила библиотеки
#include <iostream>
#include <windows.h>
#include <string>
#include <sstream>
#include <cctype>
#include <limits>
#include "Header.h"

//FIX ME: Добавила std
//FIX ME: Перенесла все скобки на новые строчки
//FIX ME: Разделила на модули
//FIX ME: Функции начинаются с заглавной буквы

//FIX ME: Функция для безопасного ввода целого числа (реализация)
int GetValidIntInput(const std::string& prompt, bool positiveOnly)
{
    std::string input;
    int value;

    while (true)
    {
        std::cout << prompt;
        std::getline(std::cin, input);

        // Проверяем на конец файла
        if (std::cin.eof())
        {
            std::cout << "Обнаружен конец файла. Выход из программы." << std::endl;
            exit(0);
        }

        // Проверяем, пустой ли ввод
        if (input.empty())
        {
            std::cout << "Ошибка! Ввод не может быть пустым." << std::endl;
            continue;
        }

        // Проверяем, есть ли в строке запятая или точка
        bool hasDecimal = false;
        for (char symbol : input)
        {
            if (symbol == '.' || symbol == ',')
            {
                hasDecimal = true;
                break;
            }
        }

        if (hasDecimal)
        {
            std::cout << "Ошибка! Введите целое число (без запятых и точек)." << std::endl;
            continue;
        }

        // Проверяем, состоит ли строка только из цифр и знака минус в начале
        bool isValid = true;
        for (size_t i = 0; i < input.length(); i++)
        {
            char currentChar = input[i];
            if (i == 0 && (currentChar == '-' || currentChar == '+'))
                continue;
            if (!isdigit(currentChar))
            {
                isValid = false;
                break;
            }
        }

        if (!isValid)
        {
            std::cout << "Ошибка! Введите целое число." << std::endl;
            continue;
        }

        // Преобразуем строку в число
        std::stringstream stringStream(input);
        stringStream >> value;

        if (stringStream.fail())
        {
            std::cout << "Ошибка! Некорректное число." << std::endl;
            continue;
        }

        // Проверяем на положительность, если требуется
        if (positiveOnly && value <= 0)
        {
            std::cout << "Ошибка! Введите положительное число." << std::endl;
            continue;
        }

        return value;
    }
}

int main()
{
    //FIX ME: Добавила наличие русского языка
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    DoubleList list;

    //FIX ME: Переименовала переменную
    //int n, value;
    int count, value;

    // Очищаем буфер ввода перед использованием getline
    std::cin.clear();

    //FIX ME: Исправила ввод 
    //std::cout << "сколько надо числе: ";
    //std::cin >> n;
    //std::cout << "вводи числа" << std::endl;
    //for (int i = 0; i < n; i++) {
    //    std::cin >> value;
    //    list.push_back(value);
    //}
    //std::cout << "нормальный список: ";
    //list.printList();
    //DoubleList::Node* tail = list.removeSides();
    //std::cout << "обработанный список: ";
    //list.printList();
    //std::cout << "последний элемент: " << tail->data << std::endl;

    // Получаем количество элементов
    count = GetValidIntInput("Сколько чисел нужно ввести: ", true);

    std::cout << "Вводите числа:" << std::endl;
    for (int i = 0; i < count; i++)
    {
        std::string prompt = "Число " + std::to_string(i + 1) + ": ";
        value = GetValidIntInput(prompt, false);  // <-- ИСПРАВЛЕНО: добавлен второй параметр false
        list.PushBack(value);
    }

    std::cout << "Исходный список: ";
    list.PrintList();

    DoubleList::Node* tail = list.RemoveSides();

    std::cout << "Обработанный список: ";
    list.PrintList();

    if (tail)
    {
        std::cout << "Последний элемент: " << tail->data << std::endl;
        std::cout << "Адрес последнего элемента: " << tail << std::endl;
    }
    else
    {
        std::cout << "Список пуст, последнего элемента нет." << std::endl;
    }

    return 0;
}