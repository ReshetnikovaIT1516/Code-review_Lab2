#include <iostream>
//FIX ME: Добаввила необходимые библиотеки
#include <Windows.h>
#include <limits>
#include <string>
#include <sstream>
#include <cctype>  // Добавлено для isdigit
#include "Header.h"

//FIX ME: Перенесла все скобки на новую строку
//FIX ME: Убрала глобальное использование using namespace std;
//FIX ME: Разделила на модули
//FIX ME: Переименовала функции. Теперь они начинаются с заглавной буквы

// Реализация конструктора Node
Node::Node(int value) : data(value), next(nullptr) {}

// Реализация конструктора LinkedList
LinkedList::LinkedList() : head(nullptr) {}

//FIX ME: Деструктор для автоматической очистки памяти
LinkedList::~LinkedList()
{
    ClearList();
}

void LinkedList::Add(int value)
{
    Node* newNode = new Node(value);
    if (head == nullptr)
    {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

//FIX ME: Исправленный метод вставки перед каждым вторым элементом
// 
//// Метод для вставки значения M перед каждым вторым элементом
//void InsertBeforeEverySecond(int M) 
//{
//    Node* current = head;
//    int count = 1;                  // Счетчик для отслеживания позиции
//
//    while (current != nullptr && current->next != nullptr) 
//    {
//        //FIX ME: не правильная вставка элемента
//        //if (count % 2 == 1)
//        if (count % 2 == 0)
//        {       // Если текущий элемент — первый в паре
//            Node* newNode = new Node(M); // Создаем новый узел со значением M
//            newNode->next = current->next; // Новый узел указывает на следующий элемент
//            current->next = newNode; // Текущий узел указывает на новый узел
//            current = newNode->next; // Переходим к следующему элементу
//        }
//        else
//        {
//            current = current->next;
//        }
//        count++;
//    }
//}

void LinkedList::InsertBeforeEverySecond(int M)
{
    if (head == nullptr) return;  // Пустой список

    Node* current = head;
    Node* prev = nullptr;
    int position = 1;  // Счетчик позиций

    while (current != nullptr)
    {
        // Вставляем перед вторым, четвертым, шестым и т.д. элементами
        if (position % 2 == 0)  // Если это четный элемент (2-й, 4-й, 6-й...)
        {
            Node* newNode = new Node(M);
            newNode->next = current;

            if (prev != nullptr)
            {
                prev->next = newNode;
            }
            else
            {
                head = newNode;  // Вставка в начало списка
            }

            prev = newNode;  // prev теперь указывает на вставленный узел
            // current не меняем, так как мы вставили перед ним
        }
        else
        {
            prev = current;
        }

        current = current->next;
        position++;
    }

    // Проверка на нечетное количество элементов
    // Если в исходном списке было нечетное количество, 
    // то последний элемент останется без изменений
}

void LinkedList::Print()
{
    Node* current = head;           // Начинаем с головы списка
    while (current != nullptr)
    {    // Пока не дойдем до конца списка
        std::cout << current->data << " "; // Выводим данные текущего узла
        current = current->next;    // Переходим к следующему узлу
    }
    std::cout << std::endl;         // Переход на новую строку после вывода
}

// Метод для получения указателя на последний элемент списка
Node* LinkedList::GetLastNode()
{
    if (head == nullptr) return nullptr;  // Добавлена проверка на пустой список

    Node* current = head;           // Начинаем с головы списка
    while (current != nullptr && current->next != nullptr) { // Идем до последнего узла
        current = current->next;
    }
    return current;                 // Возвращаем указатель на последний узел
}

void LinkedList::ClearList()
{
    while (head != nullptr)
    {       // Пока список не пуст
        Node* temp = head;          // Сохраняем текущую голову
        head = head->next;          // Перемещаем голову на следующий узел
        delete temp;                // Удаляем узел
    }
    std::cout << "Список очищен." << std::endl;
}

void InsertBeforeEverySecond(LinkedList& list, int M)
{
    list.InsertBeforeEverySecond(M);
}

//FIX ME: Функция для безопасного ввода целого числа
// Аргумент по умолчанию УБРАН из определения (оставлен только в объявлении)
int getValidIntInput(const std::string& prompt, bool positiveOnly)
{
    std::string input;
    int value;

    while (true)
    {
        std::cout << prompt;
        std::getline(std::cin, input);

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
            char c = input[i];
            if (i == 0 && (c == '-' || c == '+'))
                continue;
            if (!isdigit(c))
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
        std::stringstream ss(input);
        ss >> value;

        if (ss.fail())
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