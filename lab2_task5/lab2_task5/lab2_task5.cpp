/* Элементами контейнеров являются целые числа. Для
заполнения контейнера использовать итератор и конструктор соответствующего контейнера,
для вывода элементов использовать итератор (для вывода элементов в обратном порядке
использовать обратные итераторы, возвращаемые функциями-членами rbegin и rend)
Обязательно наличие дружественного интерфейса. Ввод данных организовать
разными способами (с клавиатуры, рандом, из файла)

 Дан дек D с нечетным количеством элементов N (≥ 5). Добавить в начало дека пять
его средних элементов в исходном порядке. Использовать один вызов функции-члена insert. */
#include <iostream>
#include <deque>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iterator>
//FIX ME: Добавила необходимые библиотеки
#include <windows.h>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream> 
#include <limits>  
#include "Header.h"
//FIX ME: Убрала глобальное использование using namespace std;
//FIX ME: Перенесла скобки на новые строки
//FIX ME: Все функции с заглавной буквы
//FIX ME: Разделила на модули


int main()
{
    //FIX ME: Добавила наличие русского языка
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice;
    //FIX ME: Изменила ввод 
    //std::cout << "Выберите метод ввода данных: 1.Ввод с клавиатуры  2.Случайные числа  3.Чтение из файла" << std::endl;
    //std::cin >> choice;   
    std::cout << "Выберите метод ввода данных: \n";
    std::cout << "1. Ввод с клавиатуры\n";
    std::cout << "2. Случайные числа\n";
    std::cout << "3. Чтение из файла\n";
    std::cout << "Ваш выбор: ";

    choice = SafeInputInt();

    while (choice < 1 || choice > 3)
    {
        std::cout << "Ошибка! Введите число 1, 2 или 3: ";
        choice = SafeInputInt();
    }

    //FIX ME: Изменен тип на DequeContainer
    DequeContainer D;

    try
    {
        switch (choice)
        {
        case 1:
            D = FuncKeyboard();
            break;
        case 2:
            D = FuncRandom();
            break;
        case 3:
            D = FuncFile();
            break;
        default:
            std::cout << "Некорректный выбор." << std::endl;
            return 1;
        }

        //FIX ME: Использование функции с обычными итераторами для вывода
        std::cout << "Исходный дек (прямой порядок): ";
        PrintDequeForward(D);
        std::cout << std::endl;

        //FIX ME: Использование функции с обратными итераторами (rbegin/rend) для вывода
        std::cout << "Исходный дек (обратный порядок): ";
        PrintDequeReverse(D);
        std::cout << std::endl;

        FuncInsert(D);

        //FIX ME: Использование функции с обычными итераторами для вывода
        std::cout << "Дек после вставки (прямой порядок): ";
        PrintDequeForward(D);
        std::cout << std::endl;

        //FIX ME: Использование функции с обратными итераторами (rbegin/rend) для вывода
        std::cout << "Дек после вставки (обратный порядок): ";
        PrintDequeReverse(D);
        std::cout << std::endl;

    }
    catch (const std::exception& e)
    {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }
    return 0;
}