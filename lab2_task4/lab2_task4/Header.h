

#include <iostream>
#include <string>

//FIX ME: Добавила библиотеки
//FIX ME: Добавила std
//FIX ME: Перенесла все скобки на новые строчки
//FIX ME: Разделила на модули
//FIX ME: Функции начинаются с заглавной буквы

class DoubleList
{
public:
    struct Node
    {
        int data;
        Node* next;
        Node* prev;

        //FIX ME: Переименовала переменную
        //Node(int val)
        Node(int value);
    };

private:
    Node* head;

public:
    DoubleList();
    ~DoubleList();

    void PushBack(int value);
    void PrintList();
    Node* DeleteNode(Node* node);
    Node* RemoveSides();

    // Геттер для head (на случай, если понадобится доступ извне)
    Node* GetHead() const { return head; }
}; // <-- ЗДЕСЬ НУЖНА ТОЧКА С ЗАПЯТОЙ

//FIX ME: Функция для безопасного ввода целого числа (объявление)
int GetValidIntInput(const std::string& prompt, bool positiveOnly = false);

