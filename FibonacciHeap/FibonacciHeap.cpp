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
#include <bits/stdc++.h>

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
    Node(int k) : key(k), degree(0), marked(false), parent(nullptr), child(nullptr), next(this), prev(this) {}
};
class FibonacciHeap
{
private:
    Node *minNode;
    int numNodes;

public:
    FibonacciHeap() : minNode(nullptr), numNodes(0) {}
    void insert(int key);
    Node *extractMin();
    void consolidate();
    void link(Node *y, Node *x);
    void visualize();
};

void FibonacciHeap::insert(int key)
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

Node *FibonacciHeap::extractMin()
{
    Node *rmMin = minNode;
    if (rmMin != nullptr)
    {
        if (rmMin->next == rmMin)
        {
            minNode = nullptr;
        }
        else
        {
            rmMin->next->prev = rmMin->prev;
            rmMin->prev->next = rmMin->next;
            minNode = rmMin->next;
        }

        if (rmMin->child != nullptr)
        {
            Node *child = rmMin->child;
            Node *originalChild = child;
            do
            {
                Node *nextChild = child->next;
                child->prev = minNode;
                child->next = minNode->next;
                minNode->next->prev = child;
                minNode->next = child;
                child->marked = false;
                child->parent = nullptr;
                child = nextChild;

            } while (child != originalChild);
        }
        consolidate();
        numNodes--;
    }
    return rmMin;
}

// Consolidate the heap to ensure there is at most one tree of each degree
void FibonacciHeap::consolidate()
{
    // Calculate the maximum degree in the heap
    int maxDegree = static_cast<int>(log2(numNodes));
    vector<Node *> degreeTable(maxDegree + 1, nullptr);

    Node *currentNode = minNode;
    vector<Node *> toRemove;

    bool flag = true;

    do
    {
        Node *x = currentNode;
        int degree = x->degree;

        while (degreeTable[degree] != nullptr)
        {
            Node *y = degreeTable[degree];
            if (x != y)
            {
                if (x->key > y->key)
                {
                    swap(x, y);
                }

                // make y the child of x

                link(y, x);
                degreeTable[degree] = nullptr;
                degree++;
            }
            else
            {
                flag = false;
                degreeTable[degree] = nullptr;
            }
        }

        degreeTable[degree] = x;
        toRemove.push_back(currentNode);
        currentNode = currentNode->next;

    } while (flag);

    for (Node *node : toRemove)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    minNode = nullptr;
    for (Node *node : degreeTable)
    {
        if (node != nullptr)
        {
            if (minNode == nullptr || node->key < minNode->key)
            {
                minNode = node;
            }
        }
    }
}

void FibonacciHeap::link(Node *y, Node *x)
{
    y->prev->next = y->next;
    y->next->prev = y->prev;

    y->prev = y;
    y->next = y;

    if (x->child == nullptr)
    {
        x->child = y;
    }
    else
    {
        y->next = x->child->next;
        y->prev = x->child;
        x->child->next->prev = y;
        x->child->next = y;
    }
    x->degree++;
    y->marked = false;
}

void FibonacciHeap::visualize()
{
    Node *tempNode = minNode;
    if (minNode != nullptr)
    {
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
    else
    {
        cout << "empty" << endl;
    }
}

int main()
{
    FibonacciHeap fibHeap;

    fibHeap.insert(5);
    fibHeap.insert(3);
    fibHeap.insert(8);
    fibHeap.insert(49);
    fibHeap.insert(79);

    fibHeap.visualize();

    Node *minN = fibHeap.extractMin();
    if (minN != nullptr)
    {
        cout << "Min: " << minN->key << endl;
        delete minN;
    }

    fibHeap.visualize();

    return 0;
}
