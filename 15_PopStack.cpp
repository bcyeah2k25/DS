#include <iostream>
using namespace std;
#define MAX 5
int errorCheckingVal = -99999;

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

    int Pop()
    {
        int ch;

        while (true)
        {
            cout << endl
                 << "Do you want to pop element (" << a[tos] << ") from the stack!" << endl
                 << "1.Yes" << endl
                 << "2.No" << endl
                 << "Enter your choice : ";
            cin >> ch;

            switch (ch)
            {

            case 1:
            {

                int x = a[tos];
                tos--;
                return x;
                break;
            }

            case 2:
            {
                return errorCheckingVal;
            }

            default:
            {
                cout << endl
                     << endl
                     << "Invalid choice !" << endl;
            }
            }
        }
    }
};

void menu(Stack s)
{
    int ch;
    while (true)
    {

        if (s.getTos() < 0)
        {
            cout << endl
                 << endl
                 << "Stack is empty! (Stack underflow)" << endl
                 << endl
                 << "Exiting.........!" << endl;
            exit(0);
        }

        cout << endl
             << endl;
        cout << "1.Pop from stack" << endl
             << "2.Display stack" << endl
             << "0.Exit" << endl
             << "Enter your choice : ";
        cin >> ch;

        switch (ch)
        {
        case 1:
        {
            int x = s.Pop();
            if (x != errorCheckingVal)
            {
                cout << endl
                     << endl
                     << "Element (" << x << ") has been succesfully poped from stack!" << endl;
                s.DispS();
            }
            break;
        }
        case 2:
        {
            s.DispS();
            break;
        }
        case 3:
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
}

int main()
{
    Stack s;

    s.ReadS();
    s.DispS();
    menu(s);

    return 0;
}
