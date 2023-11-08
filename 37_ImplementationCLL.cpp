/*Write a C++ program to
Implementation of circular list.*/

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class CircularLinkedList
{
private:
    Node *start;
    int n;

public:
    CircularLinkedList()
    {
        start = nullptr;
        n = 0;
    }

    void DispLL()
    {
        if (start == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node *node = start;
        cout << "\nList: ";
        do
        {
            cout << node->data;
            node = node->next;
            if (node != start)
            {
                cout << " --> ";
            }
        } while (node != start);
    }

    void CreateLL()
    {
        int x;
        cout << endl
             << "Enter element " << (n + 1) << " : ";
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
        Node *temp = new Node;
        temp->data = x;

        if (start == nullptr)
        {
            start = temp;
            temp->next = start;
        }
        else
        {
            Node *curr = start;
            while (curr->next != start)
            {
                curr = curr->next;
            }
            curr->next = temp;
            temp->next = start;
        }
        n++;
    }

    Node *SearchNode(int pos)
    {
        Node *curr = start;
        for (int i = 0; i < pos; i++)
        {
            curr = curr->next;
        }
        return curr;
    }

    void InsertAtPos()
    {

        int pos, x;
        cout << endl
             << "Enter the element to insert : ";
        cin >> x;
        while (true)
        {
            cout << endl
                 << "Enter the position you want to enter : ";
            cin >> pos;
            pos--;
            if (pos < 0 || pos > n)
            {
                cout << endl
                     << endl
                     << "Invalid position...Re-Enter!" << endl;
            }
            else
            {
                break;
            }
        }

        if (pos == 0)
        {
            Node *newNode = new Node;
            Node *temp = start;

            while (temp->next != start)
            {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->next = start;
            start = newNode;
            newNode->data = x;
        }
        else
        {
            Node *newNode = new Node;
            Node *prevNode = SearchNode(pos - 1);

            newNode->data = x;
            newNode->next = prevNode->next;
            prevNode->next = newNode;
        }
        n++;
        cout << endl
             << endl
             << "Element (" << x << ") has been inserted at position (" << (pos + 1) << ")" << endl;

        DispLL();
    }
    void DispDeleted(int x, int pos)
    {
        cout << endl
             << endl
             << "Node with element " << x << " at position " << (pos + 1) << " has been deleted successfully!" << endl;
    }
    void DelAtPos()
    {

        int pos;
        while (true)
        {
            cout << endl
                 << "Enter position : ";
            cin >> pos;
            pos--;
            if (pos >= n || pos < 0)
            {
                cout << endl
                     << endl
                     << "Invalid postion...Re-Try..!" << endl;
            }
            else
            {
                break;
            }
        }

        if (pos == 0)
        {
            if (start->next == start)
            {
                DispDeleted(start->data, pos);
                start = nullptr;
            }
            else
            {
                Node *delNode = start;
                Node *lastNode = start;

                while (lastNode->next != start)
                {
                    lastNode = lastNode->next;
                }
                start = delNode->next;
                lastNode->next = start;
                DispDeleted(delNode->data, pos);
                delete delNode;
            }
        }
        else
        {

            Node *prev = SearchNode(pos - 1);
            Node *delNode = prev->next;

            prev->next = delNode->next;
            DispDeleted(delNode->data, pos);
            delete delNode;
        }

        DispLL();
    }
};

int main()
{
    int choice;
    CircularLinkedList list;
    list.CreateLL();
    list.DispLL();

    while (true)
    {

        cout << endl
             << endl;
        cout << "1.Insert" << endl
             << "2.Delete" << endl
             << "0.Exit" << endl
             << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << endl
                 << endl
                 << "Exiting...." << endl;
            exit(0);
            break;
        case 1:
            list.InsertAtPos();
            break;
        case 2:
            list.DelAtPos();
            break;

        default:
            cout << endl
                 << endl
                 << "Invalid choice !" << endl;
            break;
        }
    }
    return 0;
}
