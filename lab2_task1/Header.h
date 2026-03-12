#include <iostream>
#include <string> 

class Node
{
public:
    int x;          // Значение узла
    Node* next;     // Указатель на следующий узел

    Node(int d);
};

class Stack
{
private:
    Node* top; // Указатель на вершину стека

public:
    Stack();
    //FIX ME: Лобавила леструкторр
    ~Stack();

    void push(int d);
    //FIX ME: Метод для удаления элементов
    void NumberDelete();
    //FIX ME: Улучшенная функция
 /*   void show() const
    {
        Node* current = top;
        while (current != nullptr)
        {
            cout << current->x << " ";
            current = current->next;
        }
        cout << endl;
    }*/
    void Show() const;
    void ShowAddress() const;
    //FIX ME: Улучшенный метод
    //
    //int getTopValue() const
    //{
    //    if (top != nullptr)
    //    {
    //        return top->x;
    //    }
    //    return 1;
    //}
    bool GetTopValue(int& value) const;
    bool IsEmpty() const;
};

//FIX ME: Поверка ввода - объявление функции
int GetValidNumber(const std::string& prompt);