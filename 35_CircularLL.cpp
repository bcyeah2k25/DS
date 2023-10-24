/*Write a C++ program to create and
insert an element anywhere in the circular list.*/

//not complete


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
            if(node != start){
                cout<< " --> ";
            }
        } while (node != start);
    }

    void CreateLL()
    {
        cout << "Enter number of elements: ";
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int x;
            cout << "Enter element " << i + 1 << ": ";
            cin >> x;
            Insert(x);
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
    }
};

int main()
{
    CircularLinkedList list;
    list.CreateLL();
    list.DispLL();
    return 0;
}
