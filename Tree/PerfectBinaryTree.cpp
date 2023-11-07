// A Perfect binary tree is a type of binary tree in which every internal node has exact 2 child nodes and leaf nodes are at same level

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

int depth(Node *node)
{
    int d = 0;
    while (node != NULL)
    {
        d++;
        node = node->left;
    }
    return d;
}

bool isPerfectCheck(Node *root, int d, int level = 0)
{
    if (root == NULL)
        return true;

    if (root->left == NULL && root->right == NULL)
        return (d == level + 1);

    if (root->left == NULL || root->right == NULL)
        return false;

    return (isPerfectCheck(root->left, d, level + 1) && isPerfectCheck(root->right, d, level + 1));
}

int main()
{
    struct Node *root = NULL;
    root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    preorderTraversal(root);
    cout << endl;

    if (isPerfectCheck(root, depth(root)))
        cout << "The tree is a perfect binary tree\n";
    else
        cout << "The tree is not a perfect binary tree\n";
}