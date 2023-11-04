// A Fibonacci Heap is a particular implementation of the heap data structure that has a collection of trees that follows either min-heap or max-heap properties

// ->In the Fibonacci heap, there is a pointer that keep tracker of minimum value in the heap.
// ->The smallest value is the root of the tree
// ->All the tree roots in the heap are connected using  a circular doubly linked list

// operations
// 1.Insertion
// 2.Extracting min
// 3.Union
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
public:
    Node *minNode;

    FibonacciHeap() : minNode(nullptr), numNodes(0) {}
    void insert(int key);
    Node *extractMin();
    void unionFibonacciHeap(FibonacciHeap &other);
    void decreaseKey(Node *node, int newkey);
    void deleteNode(Node *node);
    void visualize(Node *tempNode);

private:
    int numNodes;
    void consolidate();
    void link(Node *y, Node *x);
    void cut(Node *x_child, Node *y_parent);
    void cascadingCut(Node *y_parent);
    void printChild(Node *tempNode);
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

void FibonacciHeap::unionFibonacciHeap(FibonacciHeap &other)
{
    if (other.minNode == nullptr)
        return;
    if (minNode == nullptr)
    {
        minNode = other.minNode;
    }
    else
    {
        Node *thisMin = minNode;
        Node *otherMin = other.minNode;

        Node *thisNext = thisMin->next;
        Node *otherPrev = otherMin->prev;

        // a->next=b
        // b->prev=a
        thisMin->next = otherMin;
        otherMin->prev = thisMin;

        // a->next->prev=b->prev
        // b->prev->next=a->next
        thisNext->prev = otherPrev;
        otherPrev->next = thisNext;

        // a<->c  b<->d
        // a<->b<->d<->c

        if (otherMin->key < minNode->key)
        {
            minNode = otherMin;
        }
        numNodes += other.numNodes;
        other.numNodes = 0;
        other.minNode = nullptr;
    }
}

void FibonacciHeap::decreaseKey(Node *node, int newkey)
{
    if (newkey > node->key)
    {
        cerr << "New key is greater than the current key." << endl;
        return;
    }
    node->key = newkey;
    Node *parent = node->parent;

    if (parent != nullptr && node->key < parent->key)
    {
        cut(node, parent);
        cascadingCut(parent);
    }

    if (node->key < minNode->key)
    {
        minNode = node;
    }
}

void FibonacciHeap::deleteNode(Node *node)
{
    decreaseKey(node, numeric_limits<int>::min());
    extractMin();
}
// Consolidate the heap to ensure there is at most one tree of each degree
void FibonacciHeap::consolidate()
{
    // Calculate the maximum degree in the heap
    int maxDegree = static_cast<int>(log2(numNodes));
    vector<Node *> degreeTable(maxDegree + 1, nullptr);

    Node *currentNode = minNode;

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
        currentNode = currentNode->next;

    } while (flag);

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
    y->parent = x;

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

void FibonacciHeap::cut(Node *x_child, Node *y_parent)
{
    if (x_child == x_child)
    {
        y_parent->child = nullptr;
    }
    else
    {
        x_child->next->prev = x_child->prev;
        x_child->prev->next = x_child->next;
        if (y_parent->child == x_child)
        {
            y_parent->child = x_child->next;
        }
    }

    y_parent->degree--;

    // make the child a part of root list
    x_child->prev = minNode;
    x_child->next = minNode->next;
    minNode->next->prev = x_child;
    minNode->next = x_child;
    x_child->parent = nullptr;
    x_child->marked = false;
}

void FibonacciHeap::cascadingCut(Node *y_parent)
{
    Node *tempNode = y_parent->parent;
    if (tempNode != nullptr)
    {
        if (!tempNode->marked)
        {
            tempNode->marked = true;
        }
        else
        {
            cut(y_parent, tempNode);
            cascadingCut(tempNode);
        }
    }
}

// TODO update the visual logic
//  current child are not being printed, need a recursive

void FibonacciHeap::visualize(Node *tempNode = nullptr)

{
    if (tempNode == nullptr)
        tempNode = minNode;

    if (minNode != nullptr)
    {
        cout << "Main Node are as follows" << endl;

        do
        {
            cout << "Value->" << tempNode->key << endl;
            cout << "current address->" << tempNode << endl;
            cout << "Previous->" << tempNode->prev->key << endl;
            cout << "Next->" << tempNode->next->key << endl;
            cout << endl;
            if (tempNode->child != nullptr)
                printChild(tempNode->child);
            tempNode = tempNode->next;
        } while (tempNode != minNode);
    }
    else
    {
        cout << "empty" << endl;
    }
}

void FibonacciHeap::printChild(Node *tempNode)

{
    Node *startNode = tempNode;
    cout << "Child are as follows" << endl;
    do
    {
        cout << "Value->" << tempNode->key << endl;
        cout << "current address->" << tempNode << endl;
        cout << "Previous->" << tempNode->prev->key << endl;
        cout << "Next->" << tempNode->next->key << endl;
        cout << endl;
        if (tempNode->child != nullptr)
            printChild(tempNode->child);
        tempNode = tempNode->next;
    } while (tempNode != startNode);
}

int main()
{
    FibonacciHeap fibHeap1;
    FibonacciHeap fibHeap2;

    fibHeap1.insert(5);
    fibHeap1.insert(3);
    fibHeap1.insert(8);
    fibHeap1.insert(49);
    fibHeap1.insert(79);
    fibHeap1.insert(15);
    fibHeap1.insert(33);
    fibHeap1.insert(84);
    fibHeap1.insert(1);
    fibHeap1.insert(790);
    Node *minN = fibHeap1.extractMin();
    if (minN != nullptr)
    {
        cout << "Min: " << minN->key << endl;
        delete minN;
    }
    cout << endl;
    fibHeap1.visualize();

    fibHeap2.insert(10);
    fibHeap2.insert(7);
    fibHeap2.insert(310);
    fibHeap2.insert(90);
    fibHeap2.insert(90);

    minN = fibHeap2.extractMin();
    if (minN != nullptr)
    {
        cout << "Min: " << minN->key << endl;
        delete minN;
    }
    cout << endl;

    fibHeap1.unionFibonacciHeap(fibHeap2);
    // fibHeap1.visualize();

    Node *nodeToDecrease = fibHeap1.minNode->next->child;
    if (nodeToDecrease != nullptr)
    {
        cout << endl;
        cout << "Before decrease Key: " << nodeToDecrease->key << endl;
        fibHeap1.decreaseKey(nodeToDecrease, 2);
        cout << "Decreased Key: " << nodeToDecrease->key << endl;
    }

    // Test Deletion
    Node *nodeToDelete = fibHeap1.minNode;
    if (nodeToDelete != nullptr)
    {
        cout << endl;
        cout << "Before delete Key: " << nodeToDelete->key << endl;
        fibHeap1.deleteNode(nodeToDelete);
        cout << "Deleted Node: " << nodeToDelete->key << endl;
        delete nodeToDelete;
    }

    // Extract the minimum node after deletion
    Node *minNode = fibHeap1.extractMin();
    if (minNode != nullptr)
    {
        cout << "New Min Node: " << minNode->key << endl;
        delete minNode;
    }

    return 0;
}
