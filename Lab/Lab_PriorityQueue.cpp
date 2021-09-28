#include <iostream>
using namespace std;


class PriorityQueue
{
private:
    int maxItems;
    int* elements;
    int length;

    void heapifyUp(int root, int bottom)
    {
        int parent;

        if (bottom > root)
        {
            parent = (bottom - 1) / 2;
            if (elements[parent] < elements[bottom])
            {
                swap(elements[parent], elements[bottom]);
                heapifyUp(root, parent);
            }
        }
    }

    void heapifyDown(int root, int bottom)
    {
        int maxChild, rightChild = root * 2 + 2, leftChild = root * 2 + 1;
        if (leftChild <= bottom) //there is at least one child
        {
            if (leftChild == bottom) //it is the only child
                maxChild = leftChild;
            else //there are two children
            {
                if (elements[leftChild] <= elements[rightChild])
                    maxChild = rightChild;
                else
                    maxChild = leftChild;
            }
            if (elements[root] < elements[maxChild])
            {
                swap(elements[root], elements[maxChild]);
                heapifyDown(maxChild, bottom);
            }
        }
    }

public:
    PriorityQueue(int max)
    {
        maxItems = max;
        elements = new int[max];
        length = 0;
    }

    ~PriorityQueue()
    {
        delete[] elements;
    }

    void makeEmpty()
    {
        length = 0;
    }

    bool isFull()
    {
        return length == maxItems;
    }

    bool isEmpty()
    {
        return length == 0;
    }

    void enqueue(int newItem)
    {
        if (length == maxItems)
            return;
        else
        {
            length++;
            elements[length - 1] = newItem;
            heapifyUp(0, length - 1);
        }
    }

    void dequeue(int& item)
    {
        if (length == 0)
            return;
        else
        {
            item = elements[0];
            elements[0] = elements[length - 1];
            length--;
            heapifyDown(0, length - 1);
        }
    }
};

int main() {
    // Note: You are not allowed to modify the PriorityQueue class
    // Complete the following tasks

    // Ask the user for the maximum queue capacity
    cout << "Please Enter a Size For The Priority Queue " << endl;
    int size;
    cin >> size;
    // Create a priority queue with the specified capacity
    PriorityQueue p1(size);
    // Test the isEmpty() function
    cout << (p1.isEmpty() ? "The Queue is empty " : "The Queue isnt Empty") << endl;
    // Enqueue some more items (input from user) and fill half of the queue
    int input;
    int size2 = size / 2;
    while (size2--) {
        cout << "Please Give A Number to Queue" << endl;
        cin >> input;
        p1.enqueue(input);
    }
    // Test the isEmpty() function
    cout << (p1.isEmpty() ? "The Queue is empty " : "The Queue isnt Empty") << endl;
    // Test the isFull() function
    cout << (p1.isFull() ? "The Queue is Full " : "The Queue isnt Full") << endl;
    // Enqueue some more items (input from user) and fill the whole queue
    while (!p1.isFull()) {
        cout << "Please Give Some more Number to Queue" << endl;
        cin >> input;
        p1.enqueue(input);
    }
    // Test the isFull() function
    cout << (p1.isFull() ? "The Queue is Full " : "The Queue isnt Full") << endl;
    // Dequeue all the items using a loop, and print the items
    while (!p1.isEmpty()) {
        int item;
        p1.dequeue(item);
        cout << item << " ,";
    }
    cout << endl;
}