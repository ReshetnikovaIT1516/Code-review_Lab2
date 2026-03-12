#include <iostream>
#include <windows.h>
#include <string>
#include <sstream>
#include <cctype>
#include <limits>
#include "Header.h"

//FIX ME: Добавила библиотеки
//FIX ME: Добавила std
//FIX ME: Перенесла все скобки на новые строчки
//FIX ME: Разделила на модули
//FIX ME: Функции начинаются с заглавной буквы

// Реализация конструктора Node
DoubleList::Node::Node(int value)
{
    data = value;
    next = nullptr;
    prev = nullptr;
}

// Реализация конструктора DoubleList
DoubleList::DoubleList()
{
    head = nullptr;
}

// Реализация деструктора DoubleList
DoubleList::~DoubleList()
{
    if (!head)
    {
        return;
    }
    //FIX ME: Переименовала переменную
    // Node* curr = head;
    Node* current = head;
    while (true)
    {
        Node* tmp = current;
        current = current->next;
        delete tmp;
        if (current == head)
        {
            break;
        }
    }
}

void DoubleList::PushBack(int value)
{
    Node* newNode = new Node(value);
    if (!head)
    {
        head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    }
    else
    {
        Node* tail = head->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
    }
}

void DoubleList::PrintList()
{
    if (!head)
    {
        std::cout << "Список пуст" << std::endl;
        return;
    }

    Node* curr = head;
    while (true)
    {
        std::cout << curr->data << " ";
        curr = curr->next;
        if (curr == head)
        {
            break;
        }
    }
    std::cout << std::endl;
}

DoubleList::Node* DoubleList::DeleteNode(Node* node)
{
    if (!node)
        return nullptr;

    if (node->next == node && node->prev == node)
    {
        if (node == head)
            head = nullptr;
        delete node;
        return nullptr;
    }

    Node* nextNode = node->next;
    node->prev->next = node->next;
    node->next->prev = node->prev;

    if (node == head)
    {
        head = nextNode;
    }

    delete node;
    return nextNode;
}
//FIX ME: ИСПРАВЛЕННЫЙ МЕТОД RemoveSides
//DoubleList::Node* DoubleList::RemoveSides()
//{
//    if (!head) return nullptr;
//
//    bool anyDeletion = false;
//    bool deletedSomething = false;
//
//    while (true)
//    {
//        anyDeletion = false;
//
//        if (!head || head->next == head)
//        {
//            break;
//        }
//
//        Node* start = head;
//        Node* current = head;
//        bool completedCycle = false;
//
//        while (!completedCycle)
//        {
//            int leftData = current->prev->data;
//            int rightData = current->next->data;
//
//            if (leftData == rightData)
//            {
//                anyDeletion = true;
//                deletedSomething = true;
//                Node* nextNode = current->next;
//
//                if (current == head)
//                {
//                    head = nextNode;
//                }
//
//                current = DeleteNode(current);
//
//                if (!current)
//                {
//                    return nullptr;
//                }
//
//                start = head;
//                continue;
//            }
//            else
//            {
//                current = current->next;
//            }
//
//            if (current == start)
//            {
//                completedCycle = true;
//            }
//        }
//
//        if (!anyDeletion)
//        {
//            break;
//        }
//    }
//
//    if (!head)
//    {
//        return nullptr;
//    }
//
//    Node* tail = head->prev;
//    return tail;
//}


// ИСПРАВЛЕННЫЙ МЕТОД RemoveSides
DoubleList::Node* DoubleList::RemoveSides()
{
    if (!head) return nullptr;

    // Если в списке только один элемент
    if (head->next == head) return head;

    // Считаем количество элементов в списке
    int size = 0;
    Node* temp = head;
    do {
        size++;
        temp = temp->next;
    } while (temp != head);

    // Создаем массив для хранения элементов, которые нужно удалить
    Node** toDelete = new Node * [size];
    int deleteCount = 0;

    // Первый проход: отмечаем элементы для удаления
    Node* current = head;
    for (int i = 0; i < size; i++)
    {
        int leftData = current->prev->data;
        int rightData = current->next->data;

        if (leftData == rightData)
        {
            toDelete[deleteCount++] = current;
        }

        current = current->next;
    }

    // Второй проход: удаляем отмеченные элементы
    for (int i = 0; i < deleteCount; i++)
    {
        Node* nodeToDelete = toDelete[i];

        if (nodeToDelete == head)
        {
            head = (nodeToDelete->next != nodeToDelete) ? nodeToDelete->next : nullptr;
        }

        // Отвязываем узел от списка
        nodeToDelete->prev->next = nodeToDelete->next;
        nodeToDelete->next->prev = nodeToDelete->prev;

        delete nodeToDelete;
    }

    delete[] toDelete;

    // Возвращаем последний элемент
    return head ? head->prev : nullptr;
}