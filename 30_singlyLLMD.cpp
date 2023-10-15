/*Write a program to implement singly linked list.
Menu driven program.*/

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

    void insert(int value)
    {

        Node *newNode = new Node;
        newNode->data = value;
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

    void display()
    {
        Node *temp = start;
        if (temp == nullptr)
        {
            cout << "\n\nEmpty List!" << endl;
        }
        else
        {
            cout << "\n\nList: ";
            while (temp != nullptr)
            {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }

    Node *SearchNode(int x)
    {
        Node *temp = start;
        Node *prev = nullptr;

        while (temp != nullptr)
        {
            if (temp->data == x)
            {
                return prev;
            }
            prev = temp;
            temp = temp->next;
        }

        cout << "\n\nElement not found!..Re-Try..!" << endl;
        return nullptr;
    }

    void deleteNode(int value)
    {

        if (start == nullptr)
        {
            cout << "\n\nEmpty List!" << endl;
            return;
        }

        Node *preNode = SearchNode(value);

        if (preNode == nullptr && start->data == value)
        {

            Node *del = start;
            start = start->next;
            cout << "\n\nNode with element " << del->data << " has been deleted successfully!" << endl;
            delete del;
        }
        else if (preNode != nullptr)
        {
            Node *del = preNode->next;
            preNode->next = del->next;
            cout << "\n\nNode with element " << del->data << " has been deleted successfully!" << endl;
            delete del;
        }
        display();
    }
};

int main()
{
    LinkedList list;
    int choice, value;

    while (true)
    {
        cout << "\n\n1. Insert into list\n"
             << "2. Delete from list\n"
             << "3. Display list\n"
             << "0. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the value to insert: ";
            cin >> value;
            list.insert(value);
            list.display();
            break;
        case 2:
            cout << "Enter the value to delete: ";
            cin >> value;
            list.deleteNode(value);
            break;
        case 3:
            list.display();
            break;
        case 0:
            cout << "\n\nExiting..." << endl;
            exit(0);
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
