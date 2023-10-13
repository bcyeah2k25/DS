/*Write a C++ program to Insert an
element anywhere in the linear linked list.
Menu driven program and
use recursive function
(at the beginning, end and after an element)*/

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
    void DispLL()
    {

        Node *node = start;

        if (node == nullptr)
        {
            cout << endl
                 << endl
                 << "Empty list !" << endl;
        }
        else
        {
            cout << endl
                 << endl
                 << "List : ";
            while (node != nullptr)
            {
                cout << node->data;
                if (node->next != nullptr)
                {
                    cout << " --> ";
                }
                node = node->next;
            }
        }
    }

    void CreateLL()
    {

        int x;
        cout << endl
             << "Enter the number to insert : ";
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

        DispLL();
    }

    bool isContinue()
    {
        char ch;
        cout << endl
             << endl
             << "Enter 'y' to add another element : ";
        cin >> ch;

        if (ch == 'y' || ch == 'Y')
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void InsAtBeg()
    {

        int x;
        cout << endl
             << endl
             << "Enter the number to insert : ";
        cin >> x;

        Node *newNode = new Node;

        newNode->data = x;

        newNode->next = start;
        start = newNode;

        DispLL();

        if (isContinue())
        {
            InsAtBeg();
        }
        else
        {
            return;
        }
    }

    void InsAtEnd()
    {

        int x;
        cout << endl
             << endl
             << "Enter the number to insert : ";
        cin >> x;

        Node *newNode = new Node;

        newNode->data = x;
        newNode->next = nullptr;

        Node *temp = start;

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = newNode;

        DispLL();

        if (isContinue())
        {
            InsAtEnd();
        }
        else
        {
            return;
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

    void InsAftElem()
    {
        int x;
        cout << endl
             << "Enter the number to insert : ";
        cin >> x;

        int xi;
        Node *node;
        while (true)
        {

            cout << endl
                 << "After which element to insert : ";
            cin >> xi;

            node = SearchNode(xi);

            if (node != nullptr)
            {
                break;
            }
        }

        Node *newNode = new Node;
        newNode->data = x;
        newNode->next = node->next;

        node->next = newNode;

        DispLL();

        if (isContinue())
        {
            InsAftElem();
        }
        else
        {
            return;
        }
    }
};

int main()
{

    LinkedList l;
    char ch;

    cout << endl
         << "Creating an linked list......!" << endl;

    do
    {
        l.CreateLL();
    } while (l.isContinue());

    int choice;

    while (true)
    {
        cout << endl
             << endl;
        cout << "1.Insert at end" << endl
             << "2.Insert at begining" << endl
             << "3.Insert after a element" << endl
             << "0.Exit" << endl
             << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {

        case 0:
            cout << endl
                 << endl
                 << "Exiting......." << endl;
            exit(0);
            break;
        case 1:
            l.InsAtEnd();
            break;
        case 2:
            l.InsAtBeg();
            break;
        case 3:
            l.InsAftElem();
            break;
        default:
            cout << endl
                 << endl
                 << "Invalid choice..!" << endl;
        }
    }
    return 0;
}