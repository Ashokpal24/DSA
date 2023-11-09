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
    void insert(Node *node, int key);
    void newNode(int key);
    void inorderTraversal(Node *node);
    Node *minNode(Node *node);
    Node *deleteNode(Node *node, int key);
};

void BST::insert(Node *node, int key)
{
    if (node->key > key)
    {
        if (node->left != NULL)
        {
            insert(node->left, key);
        }
        else
        {
            node->left = new Node(key);
        }
    }
    else
    {
        if (node->right != NULL)
        {
            insert(node->right, key);
        }
        else
        {
            node->right = new Node(key);
        }
    }
}

void BST::newNode(int key)
{
    if (root == NULL)
    {
        root = new Node(key);
        return;
    }
    insert(root, key);
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

Node *BST::deleteNode(Node *node, int key)
{
    if (node == NULL)
        return node;

    if (key < node->key)
    {
        node->left = deleteNode(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = deleteNode(node->right, key);
    }
    else
    {
        if (node->left == NULL)
        {
            Node *temp = node->right;
            free(node);
            return temp;
        }
        if (node->right == NULL)
        {
            Node *temp = node->left;
            free(node);
            return temp;
        }

        Node *temp = minNode(node->right);

        node->key = temp->key;

        node->right = deleteNode(node->right, temp->key);
    }
    return node;
}

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
    cout << "\nAfter deleting\n";
    newBST.deleteNode(newBST.root, 10);
    newBST.inorderTraversal(newBST.root);
    cout << endl;
}