/*Write a C++ program to create and count
number of nodes in the Doubly linked list.*/

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

class DLL
{

    Node *start;
    Node *end;

public:
    DLL()
    {
        start = nullptr;
        end = nullptr;
    }

    void CreateLL()
    {
        int x;
        cout << endl
             << "Enter element to insert: ";
        cin >> x;
        Insert(x);

        char ch;
        cout << "Enter 'y' to continue : ";
        cin >> ch;

        if (ch == 'y')
        {
            CreateLL();
        }
    }

    void Insert(int x)
    {

        Node *newNode = new Node;
        newNode->data = x;
        newNode->next = nullptr;

        if (start == nullptr)
        {
            newNode->prev = nullptr;
            start = newNode;
            end = newNode;
        }
        else
        {
            end->next = newNode;
            newNode->prev = end;
            end = newNode;
        }
    }

    void DispDLL()
    {

        if (start == nullptr)
        {

            cout << endl
                 << endl
                 << "List is empty.." << endl;
            exit(0);
        }

        Node *temp = start;
        cout << endl
             << endl;
        while (temp != nullptr)
        {
            cout << temp->data << " --> ";
            temp = temp->next;
        }
        cout << "NULL";
    }

    int NodeCount()
    {

        Node *temp = start;
        int count = 0;

        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }

        return count;
    }
};

int main()
{

    DLL dll;

    dll.CreateLL();
    dll.DispDLL();

    cout << endl
         << endl
         << "There are " << dll.NodeCount() << " nodes in the list" << endl;

    return 0;
}