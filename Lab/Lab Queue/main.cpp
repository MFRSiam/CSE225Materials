#include <iostream>
#include "quetype.h"
#include "quetype.cpp"

template <typename G>
void isEmptyCheck(QueType<G> X) {
    if (X.IsEmpty())
    {
        std::cout << "Queue is Empty" << std::endl;
    }
    else
    {
        std::cout << "Queue is Not Empty" << std::endl;
    }
}

void generateBinary(int n) {
    QueType<std::string> bi;
    bi.Enqueue("1");
    while (n--) {
        std::string temp;
        bi.Dequeue(temp);
        std::cout << temp << std::endl;
        temp.append("0");
        bi.Enqueue(temp);
        temp.append("1");
        bi.Enqueue(temp);
    }
}


int main()
{
    QueType<int> Q1(5);
    isEmptyCheck(Q1);
    Q1.Enqueue(5);
    Q1.Enqueue(7);
    Q1.Enqueue(4);
    Q1.Enqueue(2);
    isEmptyCheck(Q1);
    Q1.Enqueue(6);
    QueType<int> Q2 = Q1;
    int size = 5;
    try
    {
        while (!(Q2.IsEmpty()))
        {
            int temp;
            Q2.Dequeue(temp);
            std::cout << temp << " ";
        }
    }
    catch (...)
    {
    }
    std::cout << std::endl;
    try
    {
        Q1.Enqueue(8);
    }
    catch (...)
    {
        std::cout << "Queue Overflow" << std::endl;
    }
    int garbage;
    Q1.Dequeue(garbage);
    Q1.Dequeue(garbage);
    try
    {
        while (!(Q1.IsEmpty()))
        {
            int temp;
            Q1.Dequeue(temp);
            std::cout << temp << " ";
        }
    }
    catch (...)
    {
    }
    isEmptyCheck(Q1);
    try {
        int temp2;
        Q1.Dequeue(temp2);
    }
    catch (...) {
        std::cout << "Underflow" << std::endl;
    }
    int n;
    std::cin >> n;
    generateBinary(n);
    return 0;
}