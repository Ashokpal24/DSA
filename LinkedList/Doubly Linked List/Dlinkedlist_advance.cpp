#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    struct Node *next;
    struct Node *prev;
};

class DLinkedList
{
public:
    Node *head = NULL;
    Node *one = new Node();
    Node *two = new Node();
    Node *three = new Node();

    DLinkedList(){};

    void initiateDLinkedList();
    // passing by value
    void visualize(Node *head_ref);
    // passing by reference
    void insertAtBeginning(Node *&head_ref, int value);
    // passing by value
    void insertInBetween(Node *head_ref, int value, int afterValue);
    // passing by value
    void insertAtEnd(Node *head_ref, int value);

    void deleteAtBeginning(Node *&head_ref);

    void deleteAtPostion(Node *head_ref, int position);

    void deleteAtEnd(Node *head_ref);
};

void DLinkedList::initiateDLinkedList()
{
    one->data = 1;
    two->data = 2;
    three->data = 3;

    one->next = two;
    one->prev = NULL;

    two->next = three;
    two->prev = one;

    three->next = NULL;
    three->prev = two;

    head = one;
    cout << "Address of head: " << head << endl;
}

void DLinkedList::visualize(Node *head_ref)
{
    {
        cout << "Address of head_ref: " << head_ref << endl;
        cout << endl;

        while (head_ref != NULL)
        {
            cout << "Value: " << head_ref->data << endl;
            if (head_ref->next != NULL)
            {
                cout << "Next value: " << head_ref->next->data << endl;
            }
            else
            {
                cout << "Next value: "
                     << "No Data" << endl;
            }
            if (head_ref->prev != NULL)
            {
                cout << "Previous value: " << head_ref->prev->data << endl;
            }
            else
            {
                cout << "Previous value: "
                     << "No Data" << endl;
            }

            head_ref = head_ref->next;
            cout << endl;
        }
    }
}

void DLinkedList::insertAtBeginning(Node *&head_ref, int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head_ref;
    if (head_ref != NULL)
    {
        head_ref->prev = newNode;
    }
    head_ref = newNode;
}

void DLinkedList::insertInBetween(Node *head_ref, int value, int afterValue)
{
    Node *newNode = new Node();
    newNode->data = value;
    while (head_ref != NULL)
    {
        if (head_ref->data != afterValue)
        {
            head_ref = head_ref->next;
        }
        else
        {
            newNode->next = head_ref->next;
            newNode->next->prev = newNode;

            newNode->prev = head_ref;
            head_ref->next = newNode;
            break;
        }
    }
}

void DLinkedList::insertAtEnd(Node *head_ref, int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    while (head_ref->next != NULL)
    {
        head_ref = head_ref->next;
    }
    head_ref->next = newNode;
    newNode->prev = head_ref;
}
// add programiz implementation here
void DLinkedList::deleteAtBeginning(Node *&head_ref)
{
    Node *deleteNode = head_ref;
    if (head_ref->next != NULL)
    {
        head_ref = deleteNode->next;
        head_ref->prev = NULL;
        // moving forward
    }
    free(deleteNode);
}

void DLinkedList::deleteAtPostion(Node *head_ref, int position)
{
    Node *deleteNode = NULL;
    for (int i = 0; i != position; i++)
    {
        if (head_ref->next != NULL)
        {
            head_ref = head_ref->next;
        }
        else
        {
            cout << "Invalid position" << endl;
            cout << endl;
            return;
        }
    }
    deleteNode = head_ref;
    // correcting next node
    if (deleteNode->next != NULL)
    {
        deleteNode->next->prev = deleteNode->prev;
    }
    if (deleteNode->prev != NULL)
    {
        deleteNode->prev->next = deleteNode->next;
    }
    free(deleteNode);
}

void DLinkedList::deleteAtEnd(Node *head_ref)
{
    while (head_ref->next != NULL)
    {
        head_ref = head_ref->next;
    }
    if (head_ref->prev != NULL)
    {
        head_ref->prev->next = NULL;
    }
    free(head_ref);
}

int main()
{
    DLinkedList newObj;
    newObj.initiateDLinkedList();
    newObj.insertAtBeginning(newObj.head, 300);
    newObj.insertAtBeginning(newObj.head, 60);
    newObj.insertAtBeginning(newObj.head, 1000);
    newObj.insertAtBeginning(newObj.head, 5000);
    newObj.insertInBetween(newObj.head, 420, 1000);
    newObj.insertAtBeginning(newObj.head, 9000);
    newObj.insertAtBeginning(newObj.head, 7000);
    newObj.insertAtEnd(newObj.head, 700);
    newObj.insertAtEnd(newObj.head, 50);
    newObj.visualize(newObj.head);
    newObj.deleteAtPostion(newObj.head, 4);
    newObj.deleteAtBeginning(newObj.head);
    newObj.deleteAtEnd(newObj.head);
    newObj.visualize(newObj.head);
    newObj.deleteAtEnd(newObj.head);
    newObj.visualize(newObj.head);
}