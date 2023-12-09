/*41. Write a C++ program to Implementation of
stack using of linked list. Menu driven program.*/

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Stack
{

    Node *top;

public:
    Stack()
    {
        top = nullptr;
    }

    void Create()
    {

        int x;
        char ch;

        while (true)
        {

            cout << "\nEnter the element to insert: ";
            cin >> x;

            Push(x);

            cout << "\nEnter 'y' to insert next: ";
            cin >> ch;

            if (ch != 'y')
            {
                break;
            }
        }
    }

    void Push(int x)
    {

        Node *newNode = new Node;
        newNode->data = x;
        newNode->next = top;
        top = newNode;

        DispMsg(x," pushed to");
    }

    void Pop()
    {

        if (top == nullptr)
        {
            cout << "\n\nStack is empty!";
            return;
        }

        Node *delNode = top;
        top = top->next;
        

        DispMsg(delNode->data," popped from");
        delete delNode;
    }

    void DispMsg(int x , string msg){
        cout<<"\nElement "<<x<<msg<<" stack!\n";
    }

    void Disp()
    {
        if (top == nullptr)
        {
            cout << endl
                 << endl
                 << "Stack is empty!" << endl;
            return;
        }

        cout << endl
             << endl
             << "Stack is :-" << endl
             << endl;

        Node *temp = top;
        while (temp != nullptr)
        {
            cout << "|\t" << temp->data << "\t|\n"
                 << "|---------------|" << endl;
            temp = temp->next;
        }
    }
};

int main()
{

    Stack stack;
    int choice, value;

    do
    {
        cout << "\n\n1. Push\n";
        cout << "2. Pop\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            stack.Create();
            stack.Disp();
            break;

        case 2:
            stack.Pop();
            stack.Disp();
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