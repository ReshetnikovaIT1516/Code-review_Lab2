/*Дано число D и указатель P1 на вершину непустого стека.
Добавить элемент со значением D в стек и вывести адрес P2 новой вершины стека.

Для каждой динамической структуры должен быть предусмотрен стандартный набор методов -
добавления/удаления/вывода элементов.
Во всех задачах обязательно наличие дружественного интерфейса. Ввод данных с клавиатуры.

В заданиях подгруппы структура «стек» (stack) моделируется цепочкой связанных
узлов-записей типа TNode. Поле Next последнего элемента цепочки равно nullptr. Вершиной
стека (top) считается первый элемент цепочки. Для доступа к стеку используется указатель на
его вершину (для пустого стека данный указатель полагается равным nullptr). Значением
элемента стека считается значение его поля Data*/

#include <iostream>
#include <Windows.h>

//FIX ME:Добавила бмблиотеку
#include <string> 
#include <sstream>
#include <cctype>  
#include "Header.h"

//FIX ME: Убрала глобальное использование  using namespace std;
//FIX ME: Перенесла все строки на новую строку
//FIX ME: Переименовала функции. Теперь они начинаются с заглавной буквы
//FIX ME: Разделила код на модули

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Stack stack;
    //FIX ME: Все вводы теперь через getValidNumber()
    //int N, n;
    //cout << "Сколько чисел вы хотите, чтобы было в стеке? ";
    //cin >> N;
    //for (int i = 0; i < N; i++)
    //{
    //    cout << "Введите число " << i + 1 << ": ";
    //    cin >> n;
    //    stack.push(n);
    //}

    int N = GetValidNumber("Сколько чисел вы хотите, чтобы было в стеке? ");

    for (int i = 0; i < N; i++)
    {
        int n = GetValidNumber("Введите число " + std::to_string(i + 1) + ": ");
        stack.push(n);
    }
    stack.ShowAddress();
    std::cout << "Элементы в стеке: ";
    stack.Show();
    //FIX ME: Добавила нормальный ввод
    //int D;
    //cout << "Введите значение D для добавления в стек: ";
    int D = GetValidNumber("Введите значение D для добавления в стек: ");
    stack.push(D);
    std::cout << "Элементы в новом стеке: ";
    stack.Show();
    stack.ShowAddress();
   /* if (!stack.isEmpty())
    {
        cout << "Значение новой вершины: " << stack.getTopValue() << endl;
    }
    else
    {
        cout << "Стек пуст!" << endl;
    }*/
    if (!stack.IsEmpty())
    {
        int topValue;
        stack.GetTopValue(topValue);
        std::cout << "Значение новой вершины: " << topValue << std::endl;
    }
    else
    {
        std::cout << "Стек пуст!" << std::endl;
    }
    //FIX ME: Демонстрация удаления элемента
    std::cout << "\nДемонстрация удаления элемента" << std::endl;
    stack.NumberDelete();
    std::cout << "Стек после удаления: ";
    stack.Show();

    return 0;
}
