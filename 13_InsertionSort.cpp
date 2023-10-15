/*Write a program to sort a list of elements using insertion sort*/

#include <iostream>
using namespace std;
#define MAX 5

class Array
{
    int a[MAX];
    int n;

public:
    void ReadA(int n)
    {
        this->n = n;
        cout << endl
             << "Enter the elements of the array :-" << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
    }

    void DisplayA()
    {
        cout << endl;
        cout << "Array : [ ";
        for (int i = 0; i < n; i++)
        {
            cout << a[i];
            if (i < n - 1)
            {
                cout << ", ";
            }
        }
        cout << " ]";
    }

    void InsertionSort()
    {
        for (int i = 1; i < n; i++)
        {
            int cur = a[i];
            int pre = i - 1;

            while (a[pre] > cur && pre >= 0)
            {

                a[pre + 1] = a[pre];
                pre--;
            }
            a[pre + 1] = cur;
        }
    }
};

int main()
{
    Array a;
    int n;

    while (true)
    {
        cout << "Enter the number of elements : ";
        cin >> n;
        if ((n < 1) || (n > MAX))
        {
            cout << endl
                 << endl
                 << "Number of elements should be from 1 to " << MAX << " !....Re-Enter!" << endl;
        }
        else
        {
            break;
        }
    }

    a.ReadA(n);
    cout << endl
         << endl
         << "Array before sorting:-";
    a.DisplayA();

    a.InsertionSort();
    cout << endl
         << endl
         << "Array after sorting:- ";
    a.DisplayA();

    return 0;
}
