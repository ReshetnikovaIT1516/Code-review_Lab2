#include <deque>
#include <string>

//FIX ME: Добавлен класс для дружественного интерфейса
class DequeContainer
{
private:
    std::deque<int> data;

public:
    // Конструктор по умолчанию
    DequeContainer();

    //FIX ME: Добавлен конструктор с итераторами для заполнения контейнера
    template<typename Iterator>
    DequeContainer(Iterator begin, Iterator end) : data(begin, end) {}

    //FIX ME: Добавлены дружественные функции
    friend void FuncInsert(DequeContainer& container);
    friend void PrintDequeForward(const DequeContainer& container);
    friend void PrintDequeReverse(const DequeContainer& container);
    friend DequeContainer FuncKeyboard();
    friend DequeContainer FuncRandom();
    friend DequeContainer FuncFile();
};

// Добавляем объявления функций, которые используются в main.cpp
bool IsValidNumber(const std::string& str);
int SafeInputInt();
void FuncInsert(DequeContainer& container);
void PrintDequeForward(const DequeContainer& container);
void PrintDequeReverse(const DequeContainer& container);
DequeContainer FuncKeyboard();
DequeContainer FuncRandom();
DequeContainer FuncFile();