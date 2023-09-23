/*Write a program to Implementation of stack using arrays (linear stack) menu driven
program.*/

#include <iostream>
using namespace std;
#define MAX 5

class Stack
{

    int tos = 0;
    int a[MAX];
    int n;

public:
    void ReadS(int n)
    {
        this->n = n;

        cout << endl
             << "Enter the elements of the stack : ";
        for (tos; tos < n; tos++)
        {
            cin >> a[tos];
        }
        tos--;
    }

    void DispS()
    {
        if (tos < 0)
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
        for (int i = tos; i >= 0; i--)
        {
            cout << "|\t" << a[i] << "\t|\n"
                 << "|---------------|" << endl;
        }
    }

    void Push()
    {

        if (tos + 1 >= MAX)
        {
            cout << endl
                 << endl
                 << "Element cant be inserted. Stack is full! (Stack Overflow)";
            return;
        }

        int x;
        cout << endl
             << "Enter the element to push to stack : ";
        cin >> x;

        tos++;
        a[tos] = x;

        cout << endl
             << endl
             << "Element " << x << " pushed to stack!";
        DispS();
    }

    void Pop()
    {
        if (tos < 0)
        {
            cout << endl
                 << endl
                 << "Stack underflow!....Cant pop!" << endl;
            return;
        }
        int x = a[tos];
        tos--;

        cout << endl
             << endl
             << "Element " << x << " has been poped from the stack!" << endl;

        DispS();
    }
};

int main()
{

    Stack s;
    int n;
    while (true)
    {

        cout << "Enter the size of the stack : ";
        cin >> n;

        if (n > MAX || n <= 0)
        {
            cout << endl
                 << endl
                 << "The size of stack should be from 1 to " << MAX << " !" << endl;
        }
        else
        {
            break;
        }
    }

    s.ReadS(n);

    int ch;
    while (true)
    {

        cout << endl
             << endl
             << "1.Push new element" << endl
             << "2.Pop element" << endl
             << "3.Display Stack" << endl
             << "0.Exit" << endl
             << "Enter your choice : ";
        cin >> ch;

        switch (ch)
        {

        case 1:
        {
            s.Push();
            break;
        }
        case 2:
        {
            s.Pop();
            break;
        }
        case 3:
        {
            s.DispS();
            break;
        }
        case 0:
        {
            cout << endl
                 << endl
                 << "Exiting........" << endl;
            exit(0);
            break;
        }
        default:
        {
            cout << endl
                 << endl
                 << "Invalid choice!" << endl;
        }
        }
    }

    return 0;
}