#include "Header.h"

//FIX ME: Добавила функции проверки

// Функция для проверки, состоит ли строка только из цифр
bool IsNumber(const std::string& str)
{
    if (str.empty())
    {
        return false;
    }

    // Разрешаем знак минус в начале для отрицательных чисел
    size_t start = 0;
    if (str[0] == '-')
    {
        if (str.length() == 1)
        {
            return false; // Только минус - не число
        }
        start = 1;
    }

    for (size_t i = start; i < str.length(); i++)
    {
        if (!isdigit(str[i]))
        {
            return false; // Если встретился не цифровой символ
        }
    }
    return true;
}

// Функция для безопасного ввода целого числа
int GetValidNumber(const std::string& prompt)
{
    std::string input;
    int value;

    while (true)
    {
        std::cout << prompt;
        std::getline(std::cin, input);

        // Проверяем, что введены только цифры (и возможно знак минус)
        if (!IsNumber(input))
        {
            std::cout << "Ошибка: введите целое число (только цифры";
            if (prompt.find("количество") == std::string::npos)
            {
                std::cout << ", можно со знаком минус";
            }
            std::cout << ")!" << std::endl;
            continue;
        }

        // Преобразуем строку в число
        try
        {
            value = std::stoi(input);

            // Для количества элементов проверяем, что оно положительное
            if (prompt.find("количество") != std::string::npos && value <= 0)
            {
                std::cout << "Ошибка: количество должно быть положительным числом!" << std::endl;
                continue;
            }

            break;
        }
        catch (...)
        {
            std::cout << "Ошибка: число слишком большое или некорректное!" << std::endl;
        }
    }

    return value;
}

// Функция для добавления элемента в очередь
void Enqueue(PQueue& Q, int value)
{
    PNode* newNode = new PNode{ value, nullptr };
    if (Q.Tail)
    {
        Q.Tail->next = newNode;
    }
    else
    {
        Q.Head = newNode; // Если очередь была пустой
    }
    Q.Tail = newNode;
}

// Функция для извлечения элемента из очереди
int Dequeue(PQueue& Q)
{
    PNode* temp = Q.Head;
    int value = temp->data;
    Q.Head = Q.Head->next;
    if (Q.Head == nullptr)
    {
        Q.Tail = nullptr; // Если очередь стала пустой
    }
    delete temp; // Освобождаем память
    return value;
}

// FIX ME: Добавила функцию для вывода очереди
void PrintQueue(const PQueue& Q)
{
    if (Q.Head == nullptr)
    {
        std::cout << "Очередь пуста" << std::endl;
        return;
    }

    std::cout << "Элементы очереди: ";
    PNode* current = Q.Head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}