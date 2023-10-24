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
    int n = 0;

public:
    LinkedList()
    {
        start = nullptr;
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

    void CreateLL()
    {
        int x;
        n++;
        cout<<endl<<"Enter element "<<n<<" : ";
        cin>>x;
        Insert(x);

        char ch;
        cout<<"Enter 'y' to continue : ";
        cin>>ch;

        if(ch == 'y'){
            CreateLL();
        }
    }

    void Insert(int x)
    {
        Node *temp = new Node;
        temp->data = x;
        temp->next = nullptr;

        if (start == nullptr)
        {
            start = temp;
        }
        else
        {
            Node *curr = start;
            while (curr->next != nullptr)
            {
                curr = curr->next;
            }
            curr->next = temp;
        }
    }

    Node *SearchNode(int pos)
    {
        Node *curr = start;
        for (int i = 1; i < pos; i++)
        {
            curr = curr->next;
        }
        return curr;
    }

    void Interchange()
    {
        int x, y;

        cout << "Enter two positions to interchange: ";
        cin >> x >> y;

        if (x > n || y > n || x < 1 || y < 1)
        {
            cout << "\n\nInvalid positions\n\n";
            Interchange();
            return;
        }

        if (x == y)
        {
            cout << "\n\nPositions are same no interchange needed\n\n";
            return;
        }

        Node *prevX = NULL, *currX = start;
        if (x != 1)
        {
            prevX = SearchNode(x - 1);
            currX = prevX->next;
        }

        Node *prevY = NULL, *currY = start;
        if (y != 1)
        {
            prevY = SearchNode(y - 1);
            currY = prevY->next;
        }

        if (currX == NULL || currY == NULL)
        {
            cout << "\n\nNode not found, no swap done\n\n";
            return;
        }

        if (prevX != NULL)
        {
            prevX->next = currY;
        }
        else
        {
            start = currY;
        }

        if (prevY != NULL)
        {
            prevY->next = currX;
        }
        else
        {
            start = currX;
        }

        Node *temp = currX->next;
        currX->next = currY->next;
        currY->next = temp;

        cout << "\n\nNodes swapped\n\n";
        DispLL();
    }
};

int main()
{
    LinkedList list;
    list.CreateLL();
    list.DispLL();
    list.Interchange();
    return 0;
}
