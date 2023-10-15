/*Write a program to delete more than one element form the stack*/

#include <iostream>
using namespace std;
#define MAX 5

class Stack
{
    int tos = 0;
    int a[MAX];
    int n;

public:
    int getTos() { return tos; }
    void ReadS()
    {
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

    int getElement()
    {
        return a[tos];
    }

    int Pop()
    {
        int x = a[tos];
        tos--;
        return x;
    }
};

int main()
{
    Stack s;

    s.ReadS();

    int ch;

    while (true)
    {
        if (s.getTos() < 0)
        {
            cout << endl
                 << endl
                 << "Stack is empty (Stack Underflow) !" << endl;
            cout << endl
                 << endl
                 << "Exiting......." << endl;
            exit(0);
        }

        s.DispS();
        int z = s.getElement();

        cout << endl
             << endl;
        cout << "1.Pop element ( " << z << " ) from stack" << endl
             << "0.Exit" << endl
             << "Enter your choice : ";
        cin >> ch;

        switch (ch)
        {
        case 1:
        {
            int y = s.Pop();
            cout << endl
                 << endl
                 << "Element (" << y << ") has been succefully poped from stack !" << endl;
            break;
        }
        case 0:
        {
            cout << endl
                 << endl
                 << "Exiting....." << endl;
            exit(0);
            break;
        }
        default:
            cout << endl
                 << endl
                 << "Invalid choice !" << endl;
        }
    }

    return 0;
}
