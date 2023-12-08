/* Write a C++ program to delete an element in the Doubly linked list.
Menu driven program.(at beginning, end, anywhere). */

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
    int count;
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
        cout << "NULL";
    }

    void DispMsg(string msg)
    {
        cout << "\n\nNode Deleted from " << msg << endl;
    }

    void DeleteBeg()
    {

        Node *delNode = start;
        if (start->next != nullptr)
        {
            start = delNode->next;
            start->prev = nullptr;
            delete delNode;
        }
        else
        {
            start = end = nullptr;
        }

        count--;
        DispMsg("begining");
        DispDLL();
    }

    void DeleteEnd()
    {

        Node *delNode = end;

        if (end != start)
        {
            end = delNode->prev;
            end->next = nullptr;
        }
        else
        {
            end = start = nullptr;
        }

        count--;
        DispMsg("end");
        DispDLL();
    }

    Node *SearchNode(int pos)
    {

        if (pos >= 1)
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

    void DeletePos()
    {
        int pos;
        while (true)
        {
            cout << "Enter the position to Delete : ";
            cin >> pos;
            if (pos < 1 || pos >= (count + 1))
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

        if (pos == 1)
        {
            DeleteBeg();
        }
        else if (pos == count)
        {
            DeleteEnd();
        }
        else
        {

            Node *delNode = SearchNode(pos);

            delNode->next->prev = delNode->prev;
            delNode->prev->next = delNode->next;

            delete delNode;
            count--;
        }

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
        cout << "1.Delete form begining" << endl
             << "2.Delete from end" << endl
             << "3.Delete at position (MAX count : " << dll.count << ")" << endl
             << "0.Exit" << endl
             << "Enter your choice : ";

        cin >> ch;

        switch (ch)
        {
        case 1:
            dll.DeleteBeg();
            break;
        case 2:
            dll.DeleteEnd();
            break;
        case 3:
            dll.DeletePos();
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