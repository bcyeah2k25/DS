/*Write a C++ program to concatenate two linked lists*/

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
    int n;

public:
    LinkedList()
    {
        start = nullptr;
    }

    void CreateLL()
    {
        int x;
        n++;
        cout << endl
             << "Enter element " << n << " : ";
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
            cout << "List : ";
            while (node != nullptr)
            {
                cout << node->data << " --> ";
                node = node->next;
            }
            cout << "NULL";
        }
    }

    LinkedList ConCat(LinkedList li)
    {

        LinkedList temp;
        temp.start = start;

        Node *lastNode = temp.start;

        while (lastNode->next != nullptr)
        {
            lastNode = lastNode->next;
        }

        lastNode->next = li.start;

        return temp;
    }
};

int main()
{
    LinkedList a, b, c;

    cout << endl
         << "Creating List 1 ...." << endl;
    a.CreateLL();
    cout << endl
         << endl
         << "Creating List 2 ...." << endl;
    b.CreateLL();

    cout << endl
         << endl
         << "1ST ";
    a.DispLL();

    cout << endl
         << endl
         << "2ND ";
    b.DispLL();

    c = a.ConCat(b);

    cout << endl
         << endl
         << "The combined ";
    c.DispLL();
    return 0;
}
