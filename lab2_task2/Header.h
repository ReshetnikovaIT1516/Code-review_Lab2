
#include <iostream>
#include <string>

struct PNode
{
    int data;
    PNode* next;
};

struct PQueue
{
    //FIX ME: изменила название переменных
    //PNode* front; // Указатель на начало очереди
    //PNode* last;  // Указатель на конец очереди
    PNode* Head; // Указатель на начало очереди
    PNode* Tail;  // Указатель на конец очереди
    PQueue() : Head(nullptr), Tail(nullptr) {}
};

//FIX ME: Добавила функции проверки

// Функция для проверки, состоит ли строка только из цифр
bool IsNumber(const std::string& str);

// Функция для безопасного ввода целого числа
int GetValidNumber(const std::string& prompt);

// Функция для добавления элемента в очередь
void Enqueue(PQueue& Q, int value);

// Функция для извлечения элемента из очереди
int Dequeue(PQueue& Q);

// FIX ME: Добавила функцию для вывода очереди
void PrintQueue(const PQueue& Q);
