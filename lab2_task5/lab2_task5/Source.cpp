#include "Header.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream> 
#include <limits>  
#include <vector>
#include <algorithm>

// Функция для проверки, является ли строка целым числом
bool IsValidNumber(const std::string& str)
{
    if (str.empty())
    {
        return false;
    }

    size_t start = 0;
    if (str[0] == '-' || str[0] == '+')
    {
        if (str.length() == 1)
        {
            return false;
        }
        start = 1;
    }

    for (size_t i = start; i < str.length(); ++i)
    {
        if (!isdigit(str[i]))
        {
            return false;
        }
    }

    return true;
}

// Функция для безопасного ввода целого числа
int SafeInputInt()
{
    std::string input;
    int result;

    while (true)
    {
        std::getline(std::cin, input);

        // Проверяем, является ли введенная строка числом
        if (IsValidNumber(input))
        {
            // Преобразуем строку в число
            std::stringstream ss(input);
            ss >> result;
            return result;
        }
        else
        {
            std::cout << "Ошибка! Введите только целое число: ";
        }
    }
}

// Конструктор по умолчанию
DequeContainer::DequeContainer() {}

//FIX ME: Модифицирована для работы с DequeContainer
void FuncInsert(DequeContainer& container)
{
    //FIX ME: Переименновала переменную N на sizeMas
    size_t sizeMas = container.data.size();

    // Вычисляем индекс среднего элемента
    size_t MiddleIndex = sizeMas / 2;

    // Получаем пять средних элементов
    std::deque<int> MiddleElements;
    for (size_t i = MiddleIndex - 2; i <= MiddleIndex + 2; ++i)
    {
        MiddleElements.push_back(container.data[i]);
    }

    // Вставляем пять средних элементов в начало дека (один вызов insert)
    container.data.insert(container.data.begin(), MiddleElements.begin(), MiddleElements.end());
}

//FIX ME: Добавлена функция для вывода в прямом порядке с обычными итераторами
//FIX ME: Переименновала переменную it на iter
void PrintDequeForward(const DequeContainer& container)
{
    for (auto iter = container.data.begin(); iter != container.data.end(); ++iter)
    {
        std::cout << *iter << " ";
    }
}

//FIX ME: Добавлена функция для вывода в обратном порядке с обратными итераторами (rbegin/rend)
//FIX ME: Переименновала переменную rit на reverseIter
void PrintDequeReverse(const DequeContainer& container)
{
    for (auto reverseIter = container.data.rbegin(); reverseIter != container.data.rend(); ++reverseIter)
    {
        std::cout << *reverseIter << " ";
    }
}

//FIX ME: Модифицирована для возврата DequeContainer и использования конструктора с итераторами
DequeContainer FuncKeyboard()
{
    int count;
    std::cout << "Введите количество целых чисел (нечетное и >= 5): ";

    count = SafeInputInt();

    while (count < 5 || count % 2 == 0)
    {
        std::cout << "Количество должно быть нечетным и >= 5. Повторите ввод: ";
        count = SafeInputInt();
    }

    std::deque<int> temp;
    std::cout << "Введите " << count << " целых чисел:" << std::endl;
    for (int i = 0; i < count; ++i)
    {
        std::cout << "Число " << i + 1 << ": ";
        int number = SafeInputInt();
        temp.push_back(number);
    }

    //FIX ME: Использование конструктора с итераторами
    return DequeContainer(temp.begin(), temp.end());
}

//FIX ME: Модифицирована для возврата DequeContainer и использования конструктора с итераторами
DequeContainer FuncRandom()
{
    int count;
    std::cout << "Введите количество чисел (нечетное и >= 5): ";

    count = SafeInputInt();

    while (count < 5 || count % 2 == 0)
    {
        std::cout << "Количество должно быть нечетным и >= 5. Повторите ввод: ";
        count = SafeInputInt();
    }

    std::deque<int> temp;
    srand(static_cast<unsigned>(time(0)));

    for (int i = 0; i < count; ++i)
    {
        temp.push_back(rand() % 100);
    }

    std::cout << "Сгенерированные числа: ";
    for (auto num : temp)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    //FIX ME: Использование конструктора с итераторами
    return DequeContainer(temp.begin(), temp.end());
}

//FIX ME: Модифицирована для возврата DequeContainer и использования конструктора с итераторами
DequeContainer FuncFile()
{
    std::deque<int> temp;
    //FIX ME: Переименовала файл
    //std::ifstream infile("a.txt");
    std::ifstream infile("A.txt");
    std::string token;
    int number;
    int lineNum = 0;

    if (!infile.is_open())
    {
        throw std::runtime_error("Не удалось открыть файл 'A.txt'.");
    }

    while (infile >> token)
    {
        lineNum++;

        // Проверяем, является ли токен числом
        bool isValid = true;
        size_t start = 0;

        // Проверка на пустой токен
        if (token.empty())
        {
            isValid = false;
        }
        else
        {
            // Проверка на знак в начале
            if (token[0] == '-' || token[0] == '+')
            {
                if (token.length() == 1)
                {
                    isValid = false;
                }
                else
                {
                    start = 1;
                }
            }

            // Проверка остальных символов
            if (isValid)
            {
                for (size_t i = start; i < token.length(); ++i)
                {
                    if (!isdigit(token[i]))
                    {
                        isValid = false;
                        break;
                    }
                }
            }
        }

        if (!isValid)
        {
            throw std::invalid_argument("Обнаружен недопустимый символ в файле на позиции " +
                std::to_string(lineNum) + ": '" + token + "'");
        }

        // Преобразуем строку в число
        std::stringstream ss(token);
        ss >> number;
        temp.push_back(number);
    }

    infile.close();

    if (temp.empty())
    {
        throw std::invalid_argument("Файл пуст.");
    }

    if (temp.size() < 5 || temp.size() % 2 == 0)
    {
        throw std::invalid_argument("Количество чисел в файле должно быть нечетным и >= 5. Найдено: " +
            std::to_string(temp.size()) + " чисел.");
    }

    std::cout << "Прочитано " << temp.size() << " чисел из файла 'A.txt'." << std::endl;

    //FIX ME: Использование конструктора с итераторами
    return DequeContainer(temp.begin(), temp.end());
}