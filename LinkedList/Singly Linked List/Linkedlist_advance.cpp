#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node *next;
};
// passing pointer as value normally
void visualize(Node *head_ref) {
  cout << "current address of head:" << head_ref << endl;

  int counter = 0;
  while (head_ref != NULL) {
    cout << counter << ": [ Address :" << head_ref
         << " | value : " << head_ref->data << " ]" << endl;
    head_ref = head_ref->next;
    counter += 1;
  }

  cout << endl;
  cout << endl;
}

// passing pointer as reference
void insertAtBeginning(Node *&head_ref, int value) {
  Node *newNode = new Node();
  newNode->data = value;
  newNode->next = head_ref;
  head_ref = newNode;
}

void insertAtEnd(Node *temp, int value) {

  Node *newNode = new Node();
  newNode->data = value;
  newNode->next = NULL;

  while (temp->next != NULL) {
    temp = temp->next;
  }

  temp->next = newNode;
}

void insertAtPosition(Node *temp, int value, int position) {
  // cout << "Enter the position at which you wnat to add data" << endl;
  // visualize(head_ref);
  // string pos;
  // cin >> pos;

  Node *newNode = new Node();
  newNode->data = value;

  for (int i = 0; i < position - 1; i++) {
    if (temp->next != NULL) {
      temp = temp->next;
    } else {
      cout << "The position is not valid for insertion" << endl;
      cout << endl;
      return;
    }
  }

  newNode->next = temp->next;
  temp->next = newNode;
}

void deleteAtPosition(Node *&head_ref, int position) {
  Node *temp = head_ref;
  Node *prev = NULL;

  for (int i = 0; i < position; i++) {
    if (temp->next != NULL) {
      prev = temp;
      temp = temp->next;
    } else {
      cout << "The position is not valid for deletion" << endl;
      cout << endl;
      return;
    }
  }
  prev->next = temp->next;
  free(temp);
}

void deleteAtValue(Node *&head_ref, int Value) {
  // cout << Value << endl;
  Node *temp = head_ref;
  Node *prev = NULL;

  while (temp != NULL && temp->data != Value) {
    prev = temp;
    temp = temp->next;
  }
  cout << temp << endl;
  if (temp == NULL) {
    cout << "Invalid value for deletion" << endl;
    cout << endl;
    return;
  }
  prev->next = temp->next;
  free(temp);
}

bool searchNode(Node *temp, int value) {
  while (temp != NULL) {
    if (temp->data == value)
      return true;
    temp = temp->next;
  }
  return false;
}

void sortLinkedList(Node *&head_ref) {
  Node *current = head_ref;
  Node *index = NULL;
  int temp;

  if (head_ref == NULL) {
    cout << "No data to sort.." << endl;
    return;
  } else {
    while (current != NULL) {
      index = current->next;
      while (index != NULL) {
        if (current->data > index->data) {
          cout << "current" << current->data << endl;
          cout << "index:" << index->data << endl;
          temp = current->data;
          current->data = index->data;
          index->data = temp;
        } else {
          break;
        }
        // visualize(head_ref);

        index = index->next;
      }

      current = current->next;
    }
  }
}

int main() {
  Node *head = NULL;
  Node *one = new Node();
  Node *two = new Node();
  Node *three = new Node();

  one->data = 1;
  one->next = two;

  two->data = 2;
  two->next = three;

  three->data = 3;
  three->next = NULL;

  head = one;

  cout << head << endl;
  // visualize(head);
  insertAtBeginning(head, 100);
  // visualize(head);
  insertAtEnd(head, 200);
  // visualize(head);
  insertAtPosition(head, 300, 4);
  // visualize(head);
  insertAtPosition(head, 1000, 4);
  insertAtPosition(head, 1000, 8); // invalid
  // visualize(head);
  deleteAtPosition(head, 2);
  deleteAtPosition(head, 100); // invalid
  // visualize(head);
  deleteAtValue(head, 3);
  // visualize(head);
  deleteAtValue(head, 3);   // invalid
  deleteAtValue(head, 400); // invalid
  visualize(head);
  cout << searchNode(head, 1) << endl;
  cout << searchNode(head, 400) << endl;
  sortLinkedList(head);
  visualize(head);
}