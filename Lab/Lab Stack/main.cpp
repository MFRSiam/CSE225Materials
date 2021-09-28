#include <iostream>
#include "stacktype.h"
#include "stacktype.cpp"

int main()
{
    StackType<int> Q1;
    if (Q1.IsEmpty())
    {
        std::cout << "Its Empty" << std::endl;
    }
    else
    {
        std::cout << "Its not empty" << std::endl;
    }
    Q1.Push(5);
    Q1.Push(7);
    Q1.Push(4);
    Q1.Push(2);
    if (Q1.IsFull())
    {
        std::cout << "Stack is full" << std::endl;
    }
    else
    {
        std::cout << "Stack is not full" << std::endl;
    }
    StackType<int> Q2 = Q1;
    int length{ 0 };
    int arr[5];
    while (!Q2.IsEmpty())
    {
        int temp = Q2.Top();
        Q2.Pop();
        arr[length] = temp;
        length++;
    }
    while (length--) {
        std::cout << arr[length] << " ";
    }
    std::cout << std::endl;
    Q1.Push(3);
    Q2 = Q1;
    length = 0;
    int arr2[5];
    while (!Q2.IsEmpty())
    {
        int temp = Q2.Top();
        Q2.Pop();
        arr[length] = temp;
        length++;
    }
    while (length--) {
        std::cout << arr[length] << " ";
    }
    std::cout << std::endl;
    Q1.Pop();
    Q1.Pop();
    std::cout << Q1.Top() << std::endl;
    std::string x;
    StackType<char> Q3;
    std::cout << "Input the Pharenthesis " << std::endl;
    std::cin >> x;
    bool error = false;
    try
    {
        for (char i : x)
        {
            if (i == '(')
            {
                Q3.Push(i);
            }
            else if (i == ')')
            {
                Q3.Pop();
            }
        }
    }
    catch (...) {
        error = true;
    }
    if (Q3.IsEmpty() and error == false)
    {
        std::cout << "It is Balanced " << std::endl;
    }
    else {
        std::cout << "Its not balanced" << std::endl;
    }
}