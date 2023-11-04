/*Write a program to implementation of
circular queue using arrays (linear queue ) menu driven program*/

#include <iostream>
#define MAX 5
using namespace std;

class CQueue
{
    int q[MAX];
    int f;
    int r;
    int n;

public:
    void viewData(string N)
    {
        cout << endl
             << endl;
        cout << "\t" << N << endl;
        cout << "\t| R : " << r << "|" << endl
             << "\t| F : " << f << "|" << endl;
    }
    CQueue()
    {
        f = r = -1;
    }

    bool isFull()
    {
        return (r + 1) % MAX == f;
    }

    bool isEmpty()
    {
        return f == -1;
    }

    void DispCQ()
    {

        viewData("Before Displaying");
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue: ";
        if (r >= f)
        {
            int i = f;
            do
            {
                cout << q[i] << "\t";
                i = (i + 1) % MAX;
            } while (i != (r + 1) % MAX);
            cout << endl;
        }
        else
        {

            for (int i = 0; i <= r; i++)
            {
                cout << q[i] << "\t";
            }

            for (int i = f; i < MAX; i++)
            {
                cout << q[i] << "\t";
            }
        }
    }

    void ReadCQ()
    {
        while (true)
        {
            cout << "Enter the size of the circular queue: ";
            cin >> n;

            if (n < 1 || n > MAX)
            {
                cout << "Invalid size!" << endl;
            }
            else
            {
                break;
            }
        }

        cout << endl
             << "Enter " << n << " elements for the queue: ";
        for (int i = 0; i < n; i++)
        {
            r = (r + 1) % MAX;
            cin >> q[r];
        }
        f = 0;
        viewData("After reading");
        DispCQ();
    }
    void InsCQ()
    {
        viewData("Before inserting");
        if (isFull())
        {
            cout << endl
                 << endl
                 << "Queue is full!" << endl;
            return;
        }

        int x;
        cout << "Enter the element to insert: ";
        cin >> x;

        if (isEmpty())
        {
            f = 0;
        }

        r = (r + 1) % MAX;
        q[r] = x;
        viewData("After inserting");
        DispCQ();
    }

    void DelCQ()
    {
        viewData("Before deleting");
        if (isEmpty())
        {
            cout << endl
                 << endl
                 << "Queue is empty!" << endl;
            return;
        }

        int x = q[f];
        q[f] = 0;
        if (f == r)
        {
            f = r = -1;
        }
        else
        {
            f = (f + 1) % MAX;
        }

        cout << "Element " << x << " deleted successfully!" << endl;
        viewData("after deleting");
        DispCQ();
    }
};

int main()
{
    CQueue q;
    q.ReadCQ();

    while (true)
    {
        int choice;
        cout << endl
             << "1. Insert" << endl
             << "2. Delete" << endl
             << "0. Exit" << endl
             << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            q.InsCQ();
            break;
        case 2:
            q.DelCQ();
            break;
        case 0:
            cout << endl
                 << endl
                 << "Exiting....";
            exit(0);
        default:
            cout << "Invalid choice !" << endl;
        }
    }

    return 0;
}
