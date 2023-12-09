/*45. Write a C++ program to create circular doubly linked list.*/

#include <iostream>
using namespace std;

struct Node
{

    int data;
    Node *prev;
    Node *next;
};

class CDLL
{

    Node *start;
    Node *end;

public:
    CDLL()
    {
        start = end = nullptr;
    }

    void Create()
    {

        int x;
        char ch;

        while (true)
        {

            cout << "\nEnter the element to insert: ";
            cin >> x;

            Insert(x);

            cout << "\nEnter 'y' to insert next: ";
            cin >> ch;

            if (ch != 'y')
            {
                break;
            }
        }
    }

    void Insert(int x)
    {

        Node *newNode = new Node;
        newNode->data = x;

        if (start == nullptr)
        {
            newNode->next = nullptr;
            newNode->prev = nullptr;
            start = end = newNode;
        }
        else
        {
            newNode->next = start;
            newNode->prev = end;
            end->next = newNode;
            end = newNode;
        }
    }

    void Disp()
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
             << endl
             << "Circular List is : ";
        do
        {
            cout << temp->data;
            if (temp != end)
            {
                cout << " <--> ";
            }
            temp = temp->next;

        } while (temp != start);
    }
};

int main()
{

    CDLL list;

    list.Create();
    list.Disp();

    return 0;
}