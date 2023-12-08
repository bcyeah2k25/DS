/*43. Write a C++ program to Creation of binary search trees.
Tree traversals. Recursive function for traversals.*/

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class BST
{

    Node *root;

public:
    BST()
    {
        root = nullptr;
    }

    void Create()
    {

        int x;
        char ch;

        while (true)
        {

            cout << "\nEnter the element to insert: ";
            cin >> x;

            root = Insert(root, x);

            cout << "\nEnter 'y' to insert next: ";
            cin >> ch;

            if (ch != 'y')
            {
                break;
            }
        }
    }

    Node *Insert(Node *node, int x)
    {

        if (node == nullptr)
        {
            Node *newNode = new Node;
            newNode->data = x;
            newNode->left = nullptr;
            newNode->right = nullptr;
            return newNode;
        }
        else
        {

            if (x <= node->data)
            {
                node->left = Insert(node->left, x);
            }
            else
            {
                node->right = Insert(node->right, x);
            }

            return node;
        }
    }

    void Disp()
    {
        cout << "\n\nTree Traversals :- \n\n";
        cout << "\n\nPreOrder traversal : ";
        PreOrder(root);
        cout << "\n\nInOrder traversal : ";
        InOrder(root);
        cout << "\n\nPostOrder traversal : ";
        PostOrder(root);
    }

    void PreOrder(Node *node)
    {
        if (node != nullptr)
        {
            cout << node->data << " ";
            PreOrder(node->left);
            PreOrder(node->right);
        }
    }

    void InOrder(Node *node)
    {
        if (node != nullptr)
        {
            InOrder(node->left);
            cout << node->data << " ";
            InOrder(node->right);
        }
    }

    void PostOrder(Node *node)
    {
        if (node != nullptr)
        {
            PostOrder(node->left);
            PostOrder(node->right);
            cout << node->data << " ";
        }
    }
};

int main()
{

    BST b;
    b.Create();
    b.Disp();

    return 0;
}
