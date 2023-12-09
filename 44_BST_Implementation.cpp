/*44. Write a C++ program to Implementation of
Insertion and deletion of nodes in the binary
search trees.*/

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

    void Delete()
    {
        int key;
        cout << "\nEnter the element to delete : ";
        cin >> key;
        root = DeleteNode(root, key);
    }

    Node *DeleteNode(Node *node, int key)
    {
        if (node == nullptr)
        {
            return node;
        }

        if (key < node->data)
        {
            node->left = DeleteNode(node->left, key);
        }
        else if (key > node->data)
        {
            node->right = DeleteNode(node->right, key);
        }
        else
        {
            // Node with only one child or no child
            if (node->left == nullptr)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children
            Node *temp = FindMin(node->right);
            node->data = temp->data;
            node->right = DeleteNode(node->right, temp->data);
        }

        return node;
    }

    Node *FindMin(Node *node)
    {
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }

    void Disp()
    {
        if (root == nullptr)
        {
            cout << "\n\nEmpty Tree!\n";
            return;
        }

        cout << "\n\nInOrder traversal : ";
        InOrder(root);
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
};

int main()
{

    BST b;
    b.Create();
    b.Disp();

    int ch;

    while (true)
    {

        cout << "\n\n1.Insert" << endl
             << "2.Delete" << endl
             << "0.Exit" << endl
             << "Enter your choice : ";
        cin >> ch;

        switch (ch)
        {

        case 1:
            b.Create();
            b.Disp();
            break;
        case 2:
            b.Delete();
            b.Disp();
            break;
        case 0:
            cout << "\n\nExiting....\n\n";
            exit(0);
            break;
        default:
            cout << "\n\nInvalid choice...Re-Try..\n";
        }
    }

    return 0;
}
