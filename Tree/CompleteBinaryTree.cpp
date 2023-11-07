// A complete binary tree is a binray tree in which all leavs are completely filled except the lowest one, which if is filled from left

// int must lean towards left

// the last leaf might not have a right sibling

#include <iostream>
using namespace std;

struct Node
{
    int key;
    struct Node *left, *right;
    Node(int k)
    {
        this->key = k;
        left = right = NULL;
    }
};

void preorderTraversal(Node *root)
{
    if (root == NULL)
        return;
    cout << root->key << "->";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int countNumNodes(Node *root)
{
    if (root == NULL)
        return 0;
    return (1 + countNumNodes(root->left) + countNumNodes(root->right));
}

bool checkComplete(Node *root, int index, int numberNodes)
{
    if (root == NULL)
        return true;

    if (index >= numberNodes)
        return false;

    return (checkComplete(root->left, 2 * index + 1, numberNodes) &&
            checkComplete(root->right, 2 * index + 2, numberNodes));
}

int main()
{
    struct Node *root = NULL;
    root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    // root->right->left = new Node(40);
    root->right->right = new Node(50);

    preorderTraversal(root);
    cout << endl;
    if (checkComplete(root, 0, countNumNodes(root)))
        cout << "The tree is a complete binary tree\n";
    else
        cout << "The tree is not a complete binary tree\n";
}