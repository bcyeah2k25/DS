/*Write a program to create a linked list
and count number of node in it?*/

#include <iostream>
using namespace std;

class LinkedList
{

    class Node
    {
    public:
        int data;
        Node *next;
        Node(int value)
        {
            data = value;
        }
    };

    Node *start;
    int count;

public:
    LinkedList()
    {
        start = nullptr;
        count = 0;
    }

    void CreateLL()
    {

        int x;
        cout << endl
             << "Enter the number to insert : ";
        cin >> x;

        Node *newnode = new Node(x);
        newnode->next = nullptr;

        if (start == nullptr)
        {
            start = newnode;
        }
        else
        {
            Node *temp = start;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }

        count++;
        DispLL();
    }

    void DispLL()
    {
        cout << endl
             << "List : ";
        if (start == nullptr)
        {
            cout << endl
                 << endl
                 << "Empty list!";
            return;
        }

        Node *temp = start;
        while (temp != nullptr)
        {
            cout << temp->data << "\t";
            temp = temp->next;
        }
    }

    void NodeCount()
    {
        cout << endl
             << endl
             << "\tThere are " << count << " nodes !" << endl;
    }
};

int main()
{

    LinkedList l;
    char ch;
    while (true)
    {

        l.CreateLL();
        l.NodeCount();

        cout << endl
             << "Enter 'y' to continue : ";
        cin >> ch;

        if (ch != 'y' && ch != 'Y')
        {
            break;
        }
    }

    cout<<endl<<endl<<"Exiting..."<<endl;

    return 0;
}