#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    struct Node *next;
    struct Node *prev;
};

class DLinkedlist_basic
{
public:
    Node *head = NULL;
    Node *one = new Node();
    Node *two = new Node();
    Node *three = new Node();

    DLinkedlist_basic() {}
    // pass by value
    void visualize(Node *head_ref);

    // pass by pointer
    void visualize(Node **head_ref);

    void initiateDLinkedList();
};

void DLinkedlist_basic::visualize(Node *head_ref)
{
    {
        cout << "Address of head_ref" << head_ref << endl;
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

void DLinkedlist_basic::visualize(Node **head_ref)
{
    cout << "Address of head_ref: " << head_ref << endl;

    {
        while ((*head_ref) != NULL)
        {
            cout << "Value: " << (*head_ref)->data << endl;
            if ((*head_ref)->next != NULL)
            {
                cout << "Next value: " << (*head_ref)->next->data << endl;
            }
            else
            {
                cout << "Next value: "
                     << "No Data" << endl;
            }
            if ((*head_ref)->prev != NULL)
            {
                cout << "Previous value: " << (*head_ref)->prev->data << endl;
            }
            else
            {
                cout << "Previous value: "
                     << "No Data" << endl;
            }

            *head_ref = (*head_ref)->next;
            cout << "Address of head: " << *head_ref << endl;
            cout << endl;
        }
    }
}

void DLinkedlist_basic::initiateDLinkedList()
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
    visualize(&head);
    cout << "Address of head: " << head << endl;
}

int main()
{
    DLinkedlist_basic new_obj;
    new_obj.initiateDLinkedList();
}