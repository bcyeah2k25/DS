/*Write a C++ program to delete an element
 after a node the linear linked list. ( hint : not an
element).*/

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class LinkedList
{
    Node *start;

public:
    LinkedList()
    {
        start = nullptr;
    }

    void CreateLL()
    {
        int x;
        cout << endl
             << "Enter the number to insert: ";
        cin >> x;

        Node *newNode = new Node;
        newNode->data = x;
        newNode->next = nullptr;

        if (start == nullptr)
        {
            start = newNode;
        }
        else
        {
            Node *temp = start;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void DispLL()
    {
        Node *node = start;
        if (node == nullptr)
        {
            cout << endl
                 << endl
                 << "Empty list!" << endl;
        }
        else
        {
            cout << endl
                 << "List : ";
            while (node != nullptr)
            {
                cout << node->data << "\t";
                node = node->next;
            }
        }
    }

    Node *SearchNode(int x)
    {
        Node *temp = start;

        while (temp != nullptr)
        {
            if (temp->data == x)
            {
                return temp;
            }
            else
            {
                temp = temp->next;
            }
        }

        cout << endl
             << "Element not found!..Re-Try..!" << endl;
        return nullptr;
    }

    void DelNode()
    {

        if (start == nullptr)
        {
            cout << endl
                 << endl
                 << "Deletion is not possible..Empty list!" << endl;
            cout << endl
                 << endl
                 << "Exiting..." << endl;
            exit(0);
        }

        int x;
        cout << endl
             << endl
             << "After which element is the node to be deleted :  ";
        cin >> x;

        Node *node = SearchNode(x);

        if (node == nullptr)
        {
            DelNode();
        }

        if (node->next == nullptr)
        {
            cout << endl
                 << endl
                 << "There is no node after this element!..Re-Try!" << endl;
            DelNode();
        }

        Node *delNode = node->next;
        Node *nextNode = delNode->next;

        node->next = nextNode;

        cout << endl
             << endl
             << "Node with element (" << delNode->data << ") has been deleted!" << endl;

        delete delNode;

        DispLL();
    }
};

int main()
{
    LinkedList l;
    char ch;

    do
    {
        l.CreateLL();
        l.DispLL();

        cout << endl
             << endl
             << "Do you want to insert another number (enter 'y' for continue): ";
        cin >> ch;
    } while (ch == 'y');

    l.DelNode();

    cout << endl
         << "Exiting...." << endl;

    return 0;
}
