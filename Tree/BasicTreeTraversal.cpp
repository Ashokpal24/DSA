// Node-> entity that contains a key or value and pointers to its child node
// Edge-> link between 2 nodes
// Root-> topmost node of a tree
// Height-> longest path from the node to a leaf node
// Depth-> number of edges from root to th node
// Height of three->height of root node
// Degree-> total number of branches of node
// Forest-> A collection of disjoint trees is called a forest

// Types of traversal

// ->Preorder traversal
// -->root->left subtree->right subtree

// ->Inorder traversal
// -->left subtree->root->right subtree

// ->Postorder traversal
// -->left subtree->right subtree->root

#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void preorderTraversal(struct Node *node)
{
    if (node == NULL)
        return;
    cout << node->data << "->";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

void inorderTraversal(struct Node *node)
{
    if (node == NULL)
        return;

    inorderTraversal(node->left);
    cout << node->data << "->";
    inorderTraversal(node->right);
}

void postorderTraversal(struct Node *node)
{
    if (node == NULL)
        return;

    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout << node->data << "->";
}

int main()
{
    struct Node *root = new Node(34);
    root->left = new Node(78);
    root->left->left = new Node(278);
    root->left->right = new Node(89);

    root->right = new Node(400);
    root->right->left = new Node(69);
    root->right->right = new Node(892);

    cout << "Inorder traversal ";
    inorderTraversal(root);
    cout << endl;

    cout << "Preorder traversal ";
    preorderTraversal(root);
    cout << endl;

    cout << "Postorder traversal ";
    postorderTraversal(root);
    cout << endl;
}