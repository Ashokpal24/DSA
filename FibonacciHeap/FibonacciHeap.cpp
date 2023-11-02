// A Fibonacci Heap is a particular implementation of the heap data structure that has a collection of trees that follows either min-heap or max-heap properties

// ->In the Fibonacci heap, there is a pointer that keep tracker of minimum value in the heap.
// ->The smallest value is the root of the tree
// ->All the tree roots in the heap are connected using  a circular doubly linked list

// operations
// 1.Insertion
// 2.Union
// 3.Extracting min
// 4.Decrease Key
// 5.Deletion

#include <iostream>
#include <vector>

using namespace std;
struct Node
{
    int key;
    int degree;
    bool marked;
    Node *parent;
    Node *child;
    Node *next;
    Node *prev;
    Node(int k) : key(k), degree(0), marked(false), parent(nullptr), child(NULL), next(this), prev(this) {}
};
class FibonacciHeap
{
public:
    Node *minNode;
    int numNodes;
    FibonacciHeap() : minNode(nullptr), numNodes(0) {}
    void insert(int key)
    {
        Node *newNode = new Node(key);
        if (minNode == nullptr)
        {
            minNode = newNode; // 1
        }
        else
        {
            newNode->next = minNode->next; 
            // 2 next = 1 next (.i.e 1) | 3 next = 1 next (i.e 2)
            newNode->prev = minNode;       
            // 2 prev = 1 | 3 prev = 1
            minNode->next->prev = newNode; 
            // 1 next (.i.e 1) prev (.i.e 1) = 2 | 1 next 2 prev = 3
            minNode->next = newNode;       
            // 1 next = 2 | 1 next 3
            if (key < minNode->key)
            {
                minNode = newNode;
            }
        }
        numNodes++;
    }

    void visualize()
    {
        Node *tempNode = minNode;
        do
        {
            cout << "Value->" << tempNode->key << endl;
            cout << "current address->" << tempNode << endl;
            cout << "Previous->" << tempNode->prev << endl;
            cout << "Next->" << tempNode->next << endl;
            cout << endl;
            tempNode = tempNode->next;
        } while (tempNode != minNode);
    }
};
int main()
{
    FibonacciHeap fibHeap;

    fibHeap.insert(5);
    fibHeap.insert(3);
    fibHeap.insert(8);
    fibHeap.visualize();
    return 0;
}
