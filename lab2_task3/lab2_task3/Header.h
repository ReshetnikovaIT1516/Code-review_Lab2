#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>

class Node
{
public:
    int data;
    Node* next;
    Node(int value);
};

class LinkedList
{
private:
    Node* head;

public:

    LinkedList();
    //FIX ME: Деструктор для автоматической очистки памяти
    ~LinkedList();

    void Add(int value);
    void InsertBeforeEverySecond(int M);
    void Print();
    // Метод для получения указателя на последний элемент списка
    Node* GetLastNode();
    void ClearList();

    friend void InsertBeforeEverySecond(LinkedList& list, int M);
};

// Дружественная функция (объявление)
void InsertBeforeEverySecond(LinkedList& list, int M);

//FIX ME: Функция для безопасного ввода целого числа
// Аргумент по умолчанию указан ТОЛЬКО ЗДЕСЬ, в объявлении
int getValidIntInput(const std::string& prompt, bool positiveOnly = false);

#endif // HEADER_H