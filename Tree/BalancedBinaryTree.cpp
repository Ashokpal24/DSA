// A balanced binary tree, also referred to as a height-balanced binary tree, is defined as a binary tree in which the height of the left and right subtree of any node differ by not more than 1.

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

int getHeight(Node *root)
{
    if (root == NULL)
        return 0;

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    return 1 + max(leftHeight, rightHeight);
}

bool isBalanced(Node *root)
{
    if (root == NULL)
        return true;

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    if (abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return true;

    return false;
}

int main()
{
    struct Node *root = NULL;
    root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);

    root->right = new Node(3);

    preorderTraversal(root);
    cout << endl;

    if (isBalanced(root))
    {
        cout << "The tree is balanced." << endl;
    }
    else
    {
        cout << "The tree is not balanced." << endl;
    }
}