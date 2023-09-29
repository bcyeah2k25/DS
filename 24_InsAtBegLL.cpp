/* Write a C++ program to Insert an element
 at the beginning of the linear linked list. */

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
        }
        else
        {
            cout << endl
                 << endl
                 << "List : ";
            while (node != nullptr)
            {
                cout << node->data << "\t";
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
    }

    void InsAtBeg()
    {

        int x;
        cout << endl
             << endl
             << "Enter the number to insert : ";
        cin >> x;

        Node *newNode = new Node;

        newNode->data = x;

        newNode->next = start;
        start = newNode;
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
             << "Do you want to insert another element (enter 'y' for continue) :";
        cin >> ch;
    } while (ch == 'y');

    while (true)
    {
        cout << endl
             << endl
             << "Do you want to insert another element at begining (enter 'y' for continue) : ";
        cin >> ch;

        if (ch != 'y')
        {
            break;
        }

        l.InsAtBeg();
        l.DispLL();
    }

    return 0;
}


//     void insertbeginning(int n) {
//         node* ptr = new node;
//         ptr->data = n;
//         ptr->next = start;
//         start = ptr;
//     }
// };

// int main() {
//     int item, n;
//     list obj;
//     cout << "Enter the limit of the list" << endl;
//     cin >> n;
//     for(int i = 0; i < n; i++) {
//         int data;
//         cout << "Enter data for item " << i + 1 << ": ";
//         cin >> data;
//         obj.create_node(data);
//     }
//     cout << "\nList before inserting" << endl;
//     obj.display();
//     cout << "\nEnter the item to be inserted at the beginning" << endl;
//     cin >> item;
//     obj.insertbeginning(item);
//     cout << "\nList after inserting" << endl;
//     obj.display();

//     return 0;
// }