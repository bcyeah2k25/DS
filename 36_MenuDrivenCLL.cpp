/*Write a C++ program to delete an element in
the circular list. Menu driven program. (at
beginning, end, anywhere).*/

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

    void DispDeleted(int x)
    {
        cout << endl
             << endl
             << "Node with element " << x << " has been deleted successfully!" << endl;
    }

    void DispLL()
    {
        if (start == nullptr)
        {
            cout << endl
                 << endl
                 << "List is empty.....Exiting.." << endl;
            exit(0);
        }

        Node *node = start;
        cout << endl
             << endl
             << "List: ";
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
    void DelEnd()
    {

        if (start->next == start)
        {
            DispDeleted(start->data);
            start = nullptr;
        }
        else
        {
            Node *delNode = start, *prev;

            while (delNode->next != start)
            {
                prev = delNode;
                delNode = delNode->next;
            }

            prev->next = start;
            DispDeleted(delNode->data);
            delete delNode;
        }
        n--;
        DispLL();
    }
    void DelBeg()
    {

        if (start->next == start)
        {
            DispDeleted(start->data);
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
            DispDeleted(delNode->data);
            delete delNode;
        }

        n--;
        DispLL();
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
            if (pos > n || pos < 0)
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
            DelBeg();
        }
        else
        {

            Node *prev = SearchNode(pos - 1);
            Node *delNode = prev->next;

            prev->next = delNode->next;
            DispDeleted(delNode->data);
            delete delNode;
            DispLL();
        }
    }
};

int main()
{
    char ch;
    CircularLinkedList list;
    list.CreateLL();
    list.DispLL();

    int choice;

    while (true)
    {

        cout << endl
             << endl;
        cout << "1.Delete from begning" << endl
             << "2.Delete from end" << endl
             << "3.Delete from position" << endl
             << "0.Exit" << endl
             << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << endl
                 << endl
                 << "Exiting...." << endl;
            break;

        case 1:
            list.DelBeg();
            break;
        case 2:
            list.DelEnd();
            break;
        case 3:
            list.DelAtPos();
            break;

        default:
            cout << endl
                 << "Invalid choice! " << endl;
            break;
        }
    }
    return 0;
}