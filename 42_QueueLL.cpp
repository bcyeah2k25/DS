/*42. Write a C++ program to Implementation of 
queue using linked list. Menu driven program.*/

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Queue
{

    Node *r,*f;

public:
    Queue()
    {
        r = f = nullptr;
    }

    void Create()
    {

        int x;
        char ch;

        while (true)
        {

            cout << "\nEnter the element to insert: ";
            cin >> x;

            Insert(x);

            cout << "\nEnter 'y' to insert next: ";
            cin >> ch;

            if (ch != 'y')
            {
                break;
            }
        }
    }

    void Insert(int x)
    {

        Node *newNode = new Node;
        newNode->data = x;
        newNode->next = nullptr;
        
        if(r == nullptr){
            r = f = newNode;
        }else{
            r->next = newNode;
            r = newNode;
        }

        DispMsg(x," inserted to");
    }

    void Delete()
    {

        if (f == nullptr)
        {
            cout << "\n\nQueue is empty!";
            return;
        }

        Node *delNode = f;
        f = f->next;
        

        DispMsg(delNode->data," deleted from");
        delete delNode;
    }

    void DispMsg(int x , string msg){
        cout<<"\nElement "<<x<<msg<<" Queue!\n";
    }

    void Disp()
    {
        if (f == nullptr)
        {
            cout << endl
                 << endl
                 << "Queue is empty!" << endl;
            return;
        }

        cout << endl
             << endl
             << "Queue is :-" << endl
             << endl;

        Node *temp = f;
        while (temp != nullptr)
        {
            cout << temp->data <<"\t";
            temp = temp->next;
        }
    }
};

int main()
{

    Queue Queue;
    int choice, value;

    do
    {
        cout << "\n\n1. Insert\n";
        cout << "2. Delete\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            Queue.Create();
            Queue.Disp();
            break;

        case 2:
            Queue.Delete();
            Queue.Disp();
            break;

        case 0:
            cout << "Exiting.....\n";
            exit(0);
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}