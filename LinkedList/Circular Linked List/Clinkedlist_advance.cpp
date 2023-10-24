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
    
    // debugging print
    cout << "NEW Adding at beginning"
         << ": [ Address :" << head_ref
         << " | value : " << head_ref->data
         << " | next value :" << head_ref->next->data << "]" << endl;

    cout << endl;

    Node *tempNode = head_ref->next;

    do
    {
        tempNode = tempNode->next;
    } while (tempNode->next != head_ref->next);
    // when reached the end Node,point the next field to head node i.e newNode
    tempNode->next = newNode;
}

void insertAtEnd(Node *head_ref, int value)
{
    Node *startNode = head_ref;
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = startNode;

    // debugging print
    cout << "NEW Adding at end"
         << ": [ Address :" << newNode
         << " | value : " << newNode->data
         << " | next value :" << newNode->next->data << "]" << endl;

    cout << endl;

    do
    {
        head_ref = head_ref->next;

    } while (head_ref->next != startNode);
    head_ref->next = newNode;
}

void insertAtPosition(Node *&head_ref, int value, int position)
{
    // create a variable to store the head node
    // create a new Node to be added
    Node *tempNode = head_ref;
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
        for (int i = 0; i < position - 1; i++)
        {
            // if the next field points to head node stop.
            if (tempNode->next != head_ref)
            {
                tempNode = tempNode->next;
            }
            else
            {
                cout << "The position is not valid for insertion" << endl;
                cout << endl;
                return;
            }
        }
        newNode->next = tempNode->next;
        tempNode->next = newNode;
    }
}

void deleteAtPosition(Node *head_ref, int position)
{
    Node *startNode = head_ref;
    Node *prev = NULL;

    for (int i = 0; i < position; i++)
    {
        if (head_ref != startNode)
        {
            prev = head_ref;
            head_ref = head_ref->next;
        }
        else
        {
            cout << "The position is not valid for deletion" << endl;
            cout << endl;
            return;
        }
    }
    prev->next = head_ref->next;
    free(head_ref);
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
    // deleteAtPosition(head, 2);

    // insertAtPosition(head, 1000, 8); // invalid
    // visualize(head);
    // deleteAtPosition(head, 2);
    // deleteAtPosition(head, 100); // invalid
    // // visualize(head);
    // deleteAtValue(head, 3);
    // // visualize(head);
    // deleteAtValue(head, 3);   // invalid
    // deleteAtValue(head, 400); // invalid
    // cout << searchNode(head, 1) << endl;
    // cout << searchNode(head, 400) << endl;
    // sortLinkedList(head);
    // visualize(head);
}