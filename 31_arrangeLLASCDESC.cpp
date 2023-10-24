/*Write a program to arrange the list based on the
ascending or descending order of the
information field (linked list,
dynamic memory allocation techniques).*/

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
        cout << endl
             << "Enter the number to insert: ";
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
            cout << endl
                 << endl
                 << "Empty list!" << endl;
        }
        else
        {
            cout << endl
                 << "List : ";
            while (node != nullptr)
            {
                cout << node->data << "\t";
                node = node->next;
            }
        }
    }

    void Swap(int &x, int &y)
    {
        int temp = x;
        x = y;
        y = temp;
    }

    void Sort(char order)
    {

        Node *temp = start;

        while (temp != nullptr)
        {
            Node *next = temp->next;

            while (next != nullptr)
            {
                if (order == 'a')
                {

                    if (next->data < temp->data)
                    {
                        Swap(next->data, temp->data);
                    }
                }
                else
                {

                    if (next->data > temp->data)
                    {
                        Swap(next->data, temp->data);
                    }
                }

                next = next->next;
            }

            temp = temp->next;
        }

        DispLL();
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

        cout << endl
             << endl
             << "Do you want to insert another number (enter 'y' for continue): ";
        cin >> ch;
    } while (ch == 'y');

    int cho;
    while (true)
    {
        cout << endl
             << endl
             << "1.Arrange in acending order" << endl
             << "2.Arrange in decending order" << endl
             << "0.Exit" << endl
             << "Enter your choice : ";
        cin >> cho;

        switch (cho)
        {
        case 1:
            l.Sort('a');
            break;
        case 2:
            l.Sort('d');
            break;
        case 0:
            cout << endl
                 << endl
                 << "Exiting...." << endl;
            exit(0);
            break;
        }
    }
    return 0;
}
