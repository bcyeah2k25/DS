/*Write a program to insert an element into a stack*/

#include <iostream>
using namespace std;
#define MAX 5

class Stack
{

    int tos = 0;
    int a[MAX];
    int n;

public:
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

    void Push()
    {

        if (tos + 1 >= MAX)
        {
            cout << endl
                 << endl
                 << "Element cant be inserted. Stack is full! (Stack Overflow)";
            exit(0);
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
};

int main()
{

    Stack s;

    s.ReadS();
    s.DispS();
    s.Push();

    return 0;
}