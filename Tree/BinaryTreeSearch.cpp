// The properties that separate a binary search tree from a regular binary tree is
// ->All nodes of left subtree are less than the root node
// ->All nodes of right subtree are more than the root node

#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    Node *left, *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

class BST
{

public:
    Node *root = NULL;

    BST() {}
    void newNode(int key);
    void inorderTraversal(Node *node);
    Node *minNode(Node *node);
};

void BST::newNode(int key)
{
    if (root == NULL)
    {
        root = new Node(key);
        return;
    }
    Node *newNode = root;

    if (key < newNode->key)
    {
        while (newNode->left != NULL)
        {
            newNode = newNode->left;
        }
        newNode->left = new Node(key);
    }
    else
    {
        while (newNode->right != NULL)
        {
            newNode = newNode->right;
        }
        newNode->right = new Node(key);
    }
}

void BST::inorderTraversal(Node *node)
{
    if (node == NULL)
        return;

    inorderTraversal(node->left);
    cout << node->key << "->";
    inorderTraversal(node->right);
}

Node *BST::minNode(Node *node)
{
    Node *curr = node;
    while (node && node->left)
    {
        node = node->left;
        if (node->key < curr->key)
        {
            curr = node;
        }
    }
    return curr;
}

// 18
// l->1
// 1
// r->10
// 10
// l->9
// 9
// l->2

// r-98
int main()
{
    BST newBST;
    newBST.newNode(18);
    newBST.newNode(1);
    newBST.newNode(10);
    newBST.newNode(98);
    newBST.newNode(9);
    newBST.newNode(2);

    newBST.inorderTraversal(newBST.root);
    cout << endl;

    cout << "Min Value: " << newBST.minNode(newBST.root)->key << endl;
}