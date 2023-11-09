/* Write a C++ program to insert an element in the Doubly linked list.
Menu driven program. (at beginning, end, anywhere).*/

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
    int count;

public:
    DLL()
    {
        start = nullptr;
        end = nullptr;
        count = 0;
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
        count++;
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
        cout << "NULL"
             << "count : " + to_string(count);
    }

    void DispMsg(string msg)
    {
        cout << "\n\nNode inserted at " << msg << endl;
    }

    void InsertBeg()
    {

        int x;
        cout << "Enter the element to insert : ";
        cin >> x;

        Node *newNode = new Node;
        newNode->data = x;
        newNode->prev = nullptr;
        newNode->next = start;
        start = newNode;

        count++;
        DispMsg("begining");
        DispDLL();
    }

    void InsertEnd()
    {

        int x;
        cout << "Enter the element to insert : ";
        cin >> x;

        Node *newNode = new Node;
        newNode->data = x;
        newNode->next = nullptr;
        newNode->prev = end;
        end->next = newNode;
        end = newNode;

        count++;
        DispMsg("end");
        DispDLL();
    }

    Node *SearchNode(int pos)
    {

        if (pos > 1)
        {
            int p = 1;
            Node *temp = start;
            while (p != pos)
            {
                temp = temp->next;
                p++;
            }

            return temp;
        }
        return nullptr;
    }

    void InsertPos()
    {
        int x, pos;
        cout << "Enter the element to insert : ";
        cin >> x;
        while (true)
        {
            cout << "Enter the position to insert : ";
            cin >> pos;
            if (pos < 1 || pos > (count + 1))
            {
                cout << endl
                     << endl
                     << "Invalid position...Re-Try!" << endl;
            }
            else
            {
                break;
            }
        }

        Node *temp = SearchNode(pos - 1);
        Node *newNode = new Node;
        newNode->data = x;

        if (temp == nullptr)
        {
            newNode->prev = nullptr;
            newNode->next = start;
            start->prev = newNode;
            start = newNode;
        }
        else
        {
            newNode->prev = temp;
            if (temp->next != nullptr)
            {
                newNode->next = temp->next;
                temp->next->prev = newNode;
                temp->next = newNode;
            }
            else
            {
                temp->next = newNode;
                newNode->next = nullptr;
                end = newNode;
            }
        }

        count++;
        DispMsg("at position " + to_string(pos));
        DispDLL();
    }
};

int main()
{

    DLL dll;

    dll.CreateLL();
    dll.DispDLL();
    int ch;
    while (true)
    {

        cout << endl
             << endl;
        cout << "1.Insert form begining" << endl
             << "2.Insert from end" << endl
             << "3.Insert at position" << endl
             << "0.Exit" << endl
             << "Enter your choice : ";

        cin >> ch;

        switch (ch)
        {
        case 1:
            dll.InsertBeg();
            break;
        case 2:
            dll.InsertEnd();
            break;
        case 3:
            dll.InsertPos();
            break;
        case 0:
            cout << endl
                 << endl
                 << "Exiting..." << endl;
            exit(0);
            break;

        default:
            cout << endl
                 << endl
                 << "Invalid choice..!" << endl;
        }
    }
    return 0;
}