/*Write a C++ program to interchange
any two nodes in a list.*/

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
        int n;
        cout << "Enter the number of elements: ";
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int x;
            cout << "Enter element " << (i + 1) << ": ";
            cin >> x;
            Insert(x);
        }
    }

    void Insert(int x)
    {
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
        cout << "\nList: ";
        while (node != nullptr)
        {
            cout << node->data << " --> ";
            node = node->next;
        }
        cout << "NULL" << endl
             << endl;
    }

    Node *SearchNode(int x)
    {
        int count = 0;
        Node *temp = start;

        while (count != x)
        {

            if (temp == nullptr)
            {
                return nullptr;
            }

            temp = temp->next;
            count++;
        }

        return temp;
    }

    void Interchange()
    {

        int x, y;
        cout << "Enter two positions to interchange: ";
        cin >> x >> y;

        x--;
        y--;

        if (x == y)
        {
            cout << "\n\nPositions are the same, no interchange needed." << endl;
            return;
        }

        Node *node1 = SearchNode(x);
        Node *node2 = SearchNode(y);

        if (node1 && node2)
        {
            swap(node1->data, node2->data);
            DispLL();
        }
        else
        {
            cout << "\n\nInvalid positions.Re-Try..!\n" << endl;
            Interchange();
        }
    }
};

int main()
{
    LinkedList a;

    cout << "Creating List...." << endl;
    a.CreateLL();
    a.DispLL();

    a.Interchange();

    return 0;
}
