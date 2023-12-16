/*Write a program to arrange the list based on the
ascending or descending order of the
information field (linked list,
dynamic memory allocation techniques).*/

//Swapping nodes...!

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
        n = 0;
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
        n++;
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
                        Interchange(next, temp);
                        temp = next;
                    }
                }
                else
                {

                    if (next->data > temp->data)
                    {
                        Interchange(next, temp);
                        temp = next;
                    }
                }

                next = next->next;
            }

            temp = temp->next;
        }
    }

    Node *SearchPrevNode(Node *curr)
    {
        Node *temp = start;

        if (curr == start)
        {
            return nullptr;
        }

        while (temp->next != curr)
        {
            temp = temp->next;
        }

        return temp;
    }

    void Interchange(Node *node1, Node *node2)
    {
        Node *prevX = SearchPrevNode(node1), *currX = node1;
        Node *prevY = SearchPrevNode(node2), *currY = node2;

        if (prevX != nullptr)
            prevX->next = currY;
        else
            start = currY;

        if (prevY != nullptr)
            prevY->next = currX;
        else
            start = currX;

        Node *temp = currX->next;
        currX->next = currY->next;
        currY->next = temp;
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
            l.DispLL();
            break;
        case 2:
            l.Sort('d');
            l.DispLL();
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
