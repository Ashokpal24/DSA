// A FULL binary tree is a special type of binary tree in which every parent node/ internal node as either two or no children

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

bool isFullBinaryTree(Node *root)
{
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }

    if (root->left && root->right)
    {
        return (isFullBinaryTree(root->left) && isFullBinaryTree(root->right));
    }
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
    if (isFullBinaryTree(root))
        cout << "The tree is a full binary tree\n";
    else
        cout << "The tree is not a full binary tree\n";
}
