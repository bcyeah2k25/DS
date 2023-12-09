/*46. Write a C++ program to insert an
 element in the circular doubly linked list. Menu driven
program. (at beginning, end, anywhere).*/

//not complete 

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
            newNode->next = newNode->prev = newNode;
            start = end = newNode;
        }
        else
        {
            newNode->next = start;
            newNode->prev = end;
            end->next = newNode;
            end = newNode;

            start->prev = end;
        }
    }

    void Disp()
    {

        if (start == nullptr)
        {

            cout << endl
                 << endl
                 << "List is empty.." << endl;
        }
        else
        {

            Node *temp = start;
            cout << endl
                 << endl
                 << "Circular List : ";
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
    }

    Node *SearchNode(int x)
    {
        Node *temp = start;

        do
        {
            if (temp->data == x)
            {
                return temp;
            }
            temp = temp->next;

        } while (temp != start);

        return nullptr;
    }

    void InsAny()
    {

        int x;

        cout << "Enter the element to insert : ";
        cin >> x;

        Node *delNode = SearchNode(x);

        if (delNode == nullptr)
        {
            cout << "\n\nElement not found!..Re-Try!";
            Delete();
            return;
        }
        else if (delNode == start && delNode == end)
        {
            start = end = nullptr;
        }
        else
        {

            delNode->next->prev = delNode->prev;
            delNode->prev->next = delNode->next;

            if (delNode == start)
            {
                start = start->next;
            }
            else if (delNode == end)
            {
                end = end->prev;
            }

            delete delNode;
        }

        cout << "\n\nNode deleted with element " << x << "!";
    }
};

int main()
{

    CDLL list;

    list.Create();
    list.Disp();

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
            list.Create();
            list.Disp();
            break;
        case 2:
            list.Delete();
            list.Disp();
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