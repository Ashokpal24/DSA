#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node *next; // stores address
};

// passing pointer as pointer
void visualize(Node **head_ref) { // parameters
  cout << (head_ref) << endl;
  cout << (*head_ref) << endl;
  while (*head_ref != NULL) {
    cout << "Current value:\n" << (**head_ref).data << endl;
    cout << "Current address:\n" << (**head_ref).next << endl;
    *head_ref = (**head_ref).next;
    cout << endl;
  }
}

// passing pointer as reference
void visualize(Node *&head_ref) { // parameters
  cout << (head_ref) << endl;
  while (head_ref != NULL) {
    cout << "Current value:\n" << (*head_ref).data << endl;
    cout << "Current address:\n" << (*head_ref).next << endl;
    head_ref = (*head_ref).next;
    cout << endl;
  }
}

int main() {
  Node *head = NULL;
  Node *one = new Node();
  Node *two = new Node();
  Node *three = new Node();

  (*one).data = 1;
  (*two).data = 2;
  (*three).data = 3;

  (*one).next = two;
  (*two).next = three;
  (*three).next = NULL;

  head = one;
  cout << head << endl;

  while (head != NULL) {
    cout << "Current value:\n" << (*head).data << endl;
    cout << "Current address:\n" << (*head).next << endl;
    head = (*head).next;
    cout << endl;
  }

  head = one;
  visualize(head); // argument
  return 0;
}