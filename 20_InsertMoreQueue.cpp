/* Write a program to insert more than one element into a queue.*/

#include <iostream>
using namespace std;
#define MAX 5

class Queue
{

    int f = 0;
    int r = 0;
    int n;
    int q[MAX];

public:
    void ReadQ()
    {

        while (true)
        {

            cout << endl
                 << "Enter the size of the queue : ";
            cin >> n;

            if (n < 0 || n > MAX)
            {
                cout << endl
                     << endl
                     << "Invalid size..Size from 1 to 5!" << endl
                     << endl;
            }
            else
            {
                break;
            }
        }

        cout << endl
             << "Enter the elements of the queue : ";
        for (; r < n; r++)
        {
            cin >> q[r];
        }
        r--;
        DispQ();
    }

    void DispQ()
    {

        cout << endl
             << endl
             << "Queue : ";

        for (int i = 0; i <= r; i++)
        {
            cout << q[i] << "\t";
        }
    }

    void InsQ()
    {

        r++;
        cout << endl
             << endl
             << "Enter the element to insert : ";
        cin >> q[r];
        cout << endl
             << endl
             << "Element " << q[r] << " is inserted to queue!" << endl;
        DispQ();

        if (r == MAX - 1)
        {
            cout << endl
                 << endl
                 << "Queue is full !....Exiting..!" << endl;
            exit(0);
        }
        Choice();
    }

    void Choice()
    {

        string ch;
        cout << endl
             << "Do you want to insert another element ? (yes/no): ";
        cin >> ch;

        if (ch == "yes")
        {
            InsQ();
        }
        else if (ch == "no")
        {
            exit(0);
        }
        else
        {

            cout << endl
                 << endl
                 << "Invalid choice ! " << endl;
            Choice();
        }
    }
};

int main()
{

    Queue q;

    q.ReadQ();
    q.Choice();

    return 0;
}