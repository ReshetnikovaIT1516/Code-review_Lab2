#include "Header.h"

//FIX ME: Проверка ввода - реализация функции
int GetValidNumber(const std::string& prompt)
{
    std::string input;
    int value;

    while (true)
    {
        std::cout << prompt;
        std::getline(std::cin, input);

        // Проверка на пустой ввод
        if (input.empty())
        {
            std::cout << "Ошибка! Ввод не может быть пустым." << std::endl;
            continue;
        }

        // Проверка, что все символы - цифры (кроме возможного минуса в начале)
        bool isValid = true;
        for (size_t i = 0; i < input.length(); i++)
        {
            if (i == 0 && input[i] == '-')
            {
                continue;  // Минус разрешен только в начале
            }
            if (!isdigit(input[i]))
            {
                std::cout << "Ошибка! Строка должна содержать только цифры. Найден символ: '" << input[i] << "'" << std::endl;
                isValid = false;
                break;
            }
        }

        if (!isValid) continue;

        // Пробуем преобразовать в число
        char* endptr;
        value = strtol(input.c_str(), &endptr, 10);

        // Проверяем, что преобразована вся строка
        if (*endptr != '\0')
        {
            std::cout << "Ошибка! Не удалось преобразовать строку в число." << std::endl;
            continue;
        }

        return value;
    }
}

// Реализация конструктора Node
Node::Node(int d) : x(d), next(nullptr) {}

// Реализация методов класса Stack
Stack::Stack() : top(nullptr) {}

//FIX ME: Добавила деструкторр
Stack::~Stack() {
    while (!IsEmpty())
    {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

void Stack::push(int d)
{
    Node* newNode = new Node(d); // Создаем новый узел
    newNode->next = top; // Новый узел указывает на старую вершину
    top = newNode; // Новый узел становится вершиной стека
}

//FIX ME: Метод для удаления элементов
void Stack::NumberDelete()
{
    if (IsEmpty())
    {
        std::cout << "Стек пуст! Невозможно удалить элемент." << std::endl;
        return;
    }
    Node* temp = top;
    int value = top->x;
    top = top->next;
    delete temp;
    std::cout << "Элемент " << value << " удален из стека" << std::endl;
}

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
void Stack::Show() const
{
    if (IsEmpty())
    {
        std::cout << "Стек пуст!" << std::endl;
        return;
    }

    std::cout << "Элементы стека (от вершины к низу): ";
    Node* current = top;
    while (current != nullptr)
    {
        std::cout << current->x << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void Stack::ShowAddress() const
{
    std::cout << "Адрес вершины стека: " << top << std::endl;
}

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
bool Stack::GetTopValue(int& value) const
{
    if (top != nullptr)
    {
        value = top->x;
        return true;
    }
    return false;
}

bool Stack::IsEmpty() const
{
    return top == nullptr;
}