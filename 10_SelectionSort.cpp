/*Write a program to sort a list of numbers using selection sort method using class
and user defined function and pass parameters*/

#include <iostream>
using namespace std;
#define MAX 5

class Array
{

    int a[MAX];

public:
    void ReadA(int &n)
    {

        cout << endl
             << "Enter the elemets of the array :-" << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
    }

    void DisplayA(int &n)
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

    void Swap(int &x, int &y)
    {
        int temp = x;
        x = y;
        y = temp;
    }

    void SelectionSort(int &n)
    {
        int minIndex, i;
        for (i = 0; i < n - 1; i++)
        {
            minIndex = i;

            for (int j = i + 1; j < n; j++)
            {

                if (a[j] < a[minIndex])
                {
                    minIndex = j;
                }
            }

            if (minIndex != i)
            {
                Swap(a[i], a[minIndex]);
            }
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
    a.DisplayA(n);

    a.SelectionSort(n);
    cout << endl
         << endl
         << "Array after sorting:- ";
    a.DisplayA(n);
}