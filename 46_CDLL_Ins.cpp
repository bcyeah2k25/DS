/*46. Write a C++ program to insert an
 element in the circular doubly linked list. Menu driven
program. (at beginning, end, anywhere).*/

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
    int count;

public:
    CDLL()
    {
        start = end = nullptr;
        count = 0;
    }

    void Create()
    {

        int x;
        char ch;

        while (true)
        {

            cout << "\nEnter the element to insert: ";
            cin >> x;

            InsertEnd(x);

            cout << "\nEnter 'y' to insert next: ";
            cin >> ch;

            if (ch != 'y')
            {
                break;
            }
        }
    }

    void InsertEnd(int x)
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

        count++;
        cout << "\n\nNode inserted with element " << x << "!";
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

    Node *SearchNode(int pos)
    {
        Node *temp = start;
        int p = 1;

        while (p != pos)
        {
            temp = temp->next;
            p++;
        }

        return temp;
    }

    void InsPos(int x)
    {

        int pos;

        while (true)
        {

            cout << "Enter the position to insert : ";
            cin >> pos;

            if (pos < 1 || pos > (count + 1))
            {
                cout << "\n\nInvalid position..Re-Try!";
            }
            else
            {
                break;
            }
        }

        if (pos == 1)
        {
            InsBeg(x);
        }
        else if (pos == (count + 1))
        {
            InsertEnd(x);
        }
        else
        {

            Node *temp = SearchNode(pos);

            Node *newNode = new Node;
            newNode->data = x;

            newNode->next = temp;
            newNode->prev = temp->prev;
            temp->prev->next = newNode;
            temp->prev = newNode;

            count++;
            cout << "\n\nNode inserted with element " << x << "!";
        }
    }

    void InsBeg(int x)
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

            newNode->prev = start->prev;
            newNode->next = start;
            start->prev = newNode;
            start = newNode;
            end->next = newNode;
        }

        count++;
        cout << "\n\nNode inserted with element " << x << "!";
    }
};

int main()
{

    CDLL list;
    int x;

    list.Create();
    list.Disp();

    int ch;

    while (true)
    {

        cout << "\n\n1.Insert at beg" << endl
             << "2.Insert at end" << endl
             << "3.Insert at position" << endl
             << "Enter your choice : ";
        cin >> ch;

        switch (ch)
        {

        case 1:
            cout<<"Enter the element to insert : ";
            cin>>x;
            list.InsBeg(x);
            list.Disp();
            break;
        case 2:
            cout<<"Enter the element to insert : ";
            cin>>x;
            list.InsertEnd(x);
            list.Disp();
            break;
        case 3 : 
            cout<<"Enter the element to insert : ";
            cin>>x;
            list.InsPos(x);
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