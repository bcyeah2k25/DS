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
        cout << endl << "Enter the number to insert: ";
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
            cout << endl << "Empty list!" << endl;
        }
        else
        {
            cout << endl << "List : ";
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
        return nullptr;
    }

    bool isDelPossible()
    {
        if (start == nullptr || start->next == nullptr)
        {
            cout << endl << "Deletion is not possible. Empty list or single element left!" << endl;
            return false;
        }
        return true;
    }

    void DelNode()
    {
        int x;
        cout << endl << "After which element is the node to be deleted: ";
        cin >> x;

        Node *node = SearchNode(x);

        if (node == nullptr || node->next == nullptr)
        {
            cout << endl << "There is no node after this element or element not found. Re-Try." << endl;
            return;
        }

        Node *delNode = node->next;
        Node *nextNode = delNode->next;

        node->next = nextNode;

        cout << endl << "Node with element (" << delNode->data << ") has been deleted!" << endl;
        delete delNode;
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

        cout << endl << "Do you want to insert another number (enter 'y' for continue): ";
        cin >> ch;
    } while (ch == 'y');

    do
    {
        if (l.isDelPossible())
        {
            l.DelNode();
            l.DispLL();
            cout << endl << "Do you want to delete another number (enter 'y' for continue): ";
            cin >> ch;
        }
        else
        {
            break;
        }
    } while (ch == 'y');

    cout << endl << "Exiting...." << endl;

    return 0;
}

