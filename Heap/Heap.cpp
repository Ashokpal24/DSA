// Heap data structure is a complete binary tree that satistfies the heap property
// of max heap property or min heap property
#include <iostream>
#include <vector>

using namespace std;

class Heap
{
public:
    vector<int> heapTree;

public:
    Heap(){};
    void swap(int *a, int *b);
    void heapify(int index);
    void insertNode(int value);
    void deleteNode(int value);
    void visualize();
};

void Heap::swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

void Heap::heapify(int index)
{
    int size = heapTree.size();
    int largest = index;
    int leftIndex = 2 * index + 1;
    int rightIndex = 2 * index + 2;

    if (leftIndex < size && heapTree[leftIndex] > heapTree[largest])
    {
        largest = leftIndex;
    }

    if (rightIndex < size && heapTree[rightIndex] > heapTree[largest])
    {
        largest = rightIndex;
    }
    if (largest != index)
    {
        swap(&heapTree[index], &heapTree[largest]);
        heapify(largest);
    }
}

void Heap::insertNode(int value)
{
    int size = heapTree.size();
    if (size == 0)
    {
        heapTree.push_back(value);
    }
    else
    {
        heapTree.push_back(value);
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            heapify(i);
        }
    }
}

void Heap::deleteNode(int value)
{
    int size = heapTree.size();
    int currIndex = 0;
    if (size == 0)
    {
        cout << "No data to remove, heap empty!" << endl;
        return;
    }
    for (currIndex = 0; currIndex < size; currIndex++)
    {
        if (value == heapTree[currIndex])
            break;
    }
    swap(&heapTree[currIndex], &heapTree[size - 1]);
    heapTree.pop_back();
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(i);
    }
}

void Heap::visualize()
{
    int size = heapTree.size();
    int index = 0;
    int counter = 1;
    bool flag = true;
    cout << "Heap Structure below" << endl;
    while (flag)
    {
        for (int i = 0; i < counter; i++)
        {
            if (index >= size)
            {
                flag = false;
                break;
            };
            cout << heapTree[index] << " | ";
            index += 1;
        }
        counter = counter * 2;
        cout << endl;
    }
    cout << endl;
}

int main()
{
    Heap ht;

    ht.insertNode(3);
    ht.insertNode(4);
    ht.insertNode(9);
    ht.insertNode(5);
    ht.insertNode(2);

    ht.visualize();

    ht.deleteNode(4);

    ht.visualize();
}