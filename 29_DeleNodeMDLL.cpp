/*Write a C++ program to Delete an element anywhere
from the linear linked list. Menu driven
program (at the beginning, end and after an element).*/


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
    void DispLL()
    {

        Node *node = start;

        if (node == nullptr)
        {
            cout << endl
                 << endl
                 << "Empty list !" << endl;
            cout << endl
                 << endl
                 << "Exiting...." << endl;
            exit(0);
        }
        else
        {
            cout << endl
                 << endl
                 << "List : ";
            while (node != nullptr)
            {
                cout << node->data;
                if (node->next != nullptr)
                {
                    cout << " --> ";
                }
                node = node->next;
            }
        }
    }

    void CreateLL()
    {

        int x;
        cout << endl
             << "Enter the number to insert : ";
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

        DispLL();
    }

    Node *SearchNode(int x)
    {
        Node *temp = start;

        while (temp != nullptr)
        {
            if (temp->data == x)
            {
                return temp;
            }
            else
            {
                temp = temp->next;
            }
        }

        cout << endl
             << "Element not found!..Re-Try..!" << endl;
        return nullptr;
    }

    void DispDeleted(int x)
    {
        cout << endl
             << endl
             << "Node with element " << x << " has been deleted successfully!" << endl;
    }

    void DelAtBeg()
    {
        Node *temp = start;
        start = start->next;
        DispDeleted(temp->data);
        delete temp;

        DispLL();
    }

    void DelAtEnd()
    {
        if (start->next == nullptr)
        {
            DispDeleted(start->data);
            delete start;
            start = nullptr;
            DispLL();
            return;
        }

        Node *temp = start;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }

        Node *del = temp->next;
        temp->next = nullptr;
        DispDeleted(del->data);
        delete del;
        DispLL();
    }

    void DelAftElem()
    {
        if (isSingleElem())
        {
            return;
        }
        else
        {
            int xi;
            Node *node;
            while (true)
            {
                cout << "After which element to delete: ";
                cin >> xi;
                node = SearchNode(xi);
                if (node != nullptr)
                {
                    break;
                }
            }

            if (node->next != nullptr)
            {
                Node *temp = node->next;
                node->next = temp->next;
                DispDeleted(temp->data);
                delete temp;
                DispLL();
            }
            else
            {
                cout << "No element to delete after " << xi << endl;
            }
        }
    }

    bool isSingleElem()
    {

        if (start->next == nullptr)
        {
            cout << endl
                 << endl
                 << "Deletion after a element not possible single element left!" << endl;
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{

    LinkedList l;
    char ch;

    cout << endl
         << "Creating an linked list......!" << endl;
    do
    {

        l.CreateLL();

        cout << endl
             << endl
             << "Enter 'y' to add another element :";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    int choice;

    while (true)
    {
        cout << endl
             << endl;
        cout << "1.Delete from end" << endl
             << "2.Delete from begining" << endl
             << "3.Delete after a element" << endl
             << "0.Exit" << endl
             << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {

        case 0:
            cout << endl
                 << endl
                 << "Exiting......." << endl;
            exit(0);
            break;
        case 1:
            l.DelAtEnd();
            break;
        case 2:
            l.DelAtBeg();
            break;
        case 3:
            l.DelAftElem();
            break;
        default:
            cout << endl
                 << endl
                 << "Invalid choice..!" << endl;
        }
    }
    return 0;
}
