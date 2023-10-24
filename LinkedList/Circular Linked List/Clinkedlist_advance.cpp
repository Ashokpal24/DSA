// circular linked list same as single linked list with end pointing to start
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

// passing pointer as value normally
void visualize(Node *head_ref)
{
    if (head_ref == NULL)
    {
        cout << "Empty circular Linked list" << endl;
        return;
    }
    cout << "current address of head:" << head_ref << endl;
    Node *startNode = head_ref;
    int counter = 0;
    do
    {

        cout << counter
             << ": [ Address :" << head_ref
             << " | value : " << head_ref->data
             << " | next value :" << head_ref->next->data << "]" << endl;
        head_ref = head_ref->next;
        counter += 1;

    } while (head_ref != startNode);

    cout << endl;
    cout << endl;
}

int getLength(Node *head_ref)
{
    if (head_ref == NULL)
        return 0;

    int count = 0;
    Node *startNode = head_ref;
    do
    {
        head_ref = head_ref->next;
        count += 1;

    } while (head_ref->next != startNode);
    return count;
}

// passing pointer as reference
void insertAtBeginning(Node *&head_ref, int value)
{

    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = head_ref;
    head_ref = newNode;

    Node *tempNode = NULL;
    // debugging print
    cout << "brr" << endl;
    if (newNode->next != NULL)
    {
        cout << "NEW Adding at beginning"
             << ": [ Address :" << head_ref
             << " | value : " << head_ref->data
             << " | next value :" << head_ref->next->data << "]" << endl;

        cout << endl;
        tempNode = head_ref->next;

        do
        {
            tempNode = tempNode->next;
        } while (tempNode->next != head_ref->next);

        tempNode->next = newNode;
    }
    else
    {
        head_ref->next = newNode;
    }
}

void insertAtEnd(Node *&head_ref, int value)
{
    if (head_ref != NULL)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = head_ref;

        // debugging print
        cout << "NEW Adding at end"
             << ": [ Address :" << newNode
             << " | value : " << newNode->data
             << " | next value :" << newNode->next->data << "]" << endl;

        cout << endl;

        Node *tempNode = head_ref;

        do
        {
            tempNode = tempNode->next;

        } while (tempNode->next != head_ref);

        tempNode->next = newNode;
    }
    else
    {
        insertAtBeginning(head_ref, value);
    }
}

void insertAtPosition(Node *&head_ref, int value, int position)
{
    if (position > getLength(head_ref))
    {
        cout << "The position is not valid for insertion" << endl;
        cout << endl;
        return;
    }

    Node *newNode = new Node();
    newNode->data = value;

    // debugging print
    cout << "Position: " << position << endl;
    cout << "NEW Adding at above position"
         << ": [ Address :" << newNode
         << " | value : " << newNode->data << endl;
    cout << endl;

    if (position == 0)
    {
        insertAtBeginning(head_ref, value);
    }
    else if (getLength(head_ref) + 1 == position)
    {
        insertAtEnd(head_ref, value);
    }
    else
    {
        Node *tempNode = head_ref;

        for (int i = 0; i < position - 1; i++)
        {

            tempNode = tempNode->next;
        }

        newNode->next = tempNode->next;
        tempNode->next = newNode;
    }
}

void deleteAtBeginning(Node *&head_ref)
{
    if (head_ref == NULL)
    {
        cout << "Empty circular Linked list" << endl;
        return;
    }
    cout << "Deletion at beginning" << endl;

    Node *delNode = head_ref;
    Node *tempNode = head_ref;
    head_ref = head_ref->next;
    if (getLength(head_ref) != 1)
    {
        do
        {
            tempNode = tempNode->next;
        } while (tempNode->next != delNode);

        tempNode->next = head_ref;
        free(delNode);
    }
    else
    {
        head_ref = NULL;
        free(delNode);
    }
}

void deleteAtEnd(Node *&head_ref)
{
    if (head_ref == NULL)
    {
        cout << "Empty circular Linked list" << endl;
        return;
    }

    cout << "Deletion at end" << endl;

    Node *tempNode = head_ref;
    Node *delNode = NULL;

    if (getLength(head_ref) != 1)
    {
        do
        {
            tempNode = tempNode->next;

        } while (tempNode->next->next != head_ref);
        delNode = tempNode->next;
        tempNode->next = head_ref;
        free(delNode);
    }
    else
    {
        delNode = head_ref;
        head_ref = NULL;
        free(delNode);
    }
}

void deleteAtPosition(Node *&head_ref, int position)
{
    if (head_ref == NULL)
    {
        cout << "Empty circular Linked list" << endl;
        return;
    }
    if (position > getLength(head_ref))
    {
        cout << "The position is not valid for deletion" << endl;
        cout << endl;
        return;
    }

    if (position == 0)
    {
        deleteAtBeginning(head_ref);
    }
    else if (getLength(head_ref) + 1 == position)
    {
        deleteAtEnd(head_ref);
    }
    else
    {

        Node *tempNode = head_ref;
        for (int i = 0; i < position - 1; i++)
        {
            tempNode = tempNode->next;
        }
        Node *delNode = tempNode->next;
        tempNode->next = tempNode->next->next;
        free(delNode);
    }
}

void deleteAtValue(Node *head_ref, int Value)
{
    // cout << Value << endl;
    Node *startNode = head_ref;
    Node *currNode = NULL;
    bool flag = true;
    while (flag)
    {
        if (head_ref->next != startNode)
        {
            if (head_ref->data != Value)
            {
                currNode = head_ref;
                head_ref = head_ref->next;
            }
            else
                flag = false;
        }
        else
        {
            cout << "Invalid value for deletion" << endl;
            cout << endl;
            flag = false;
            return;
        }
    }
    currNode->next = head_ref->next;
    free(head_ref);
}

int main()
{
    Node *head = NULL;
    Node *one = new Node();
    Node *two = new Node();
    Node *three = new Node();

    one->data = 1;
    one->next = two;

    two->data = 2;
    two->next = three;

    three->data = 3;
    three->next = one;

    head = one;

    cout << head << endl;
    visualize(head);
    insertAtBeginning(head, 100);
    insertAtEnd(head, 200);
    insertAtPosition(head, 300, 4);
    insertAtPosition(head, 1000, 0);
    visualize(head);
    deleteAtEnd(head);
    deleteAtBeginning(head);
    deleteAtPosition(head, 2);
    visualize(head);
    deleteAtPosition(head, 0);
    deleteAtPosition(head, 1);
    visualize(head);
    deleteAtPosition(head, 0);
    deleteAtPosition(head, 0);
    visualize(head);
    insertAtPosition(head, 1000, 0);
    insertAtBeginning(head, 70);
    insertAtBeginning(head, 69);
    visualize(head);
}