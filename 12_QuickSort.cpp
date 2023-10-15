/*Write a program to sort a list of elements using quick sort*/
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

    int partition(int p, int q)
    {
        int piv = a[q];
        int i = p - 1;

        for (int j = p; j <= q - 1; j++)
        {
            if (a[j] <= piv)
            {
                i++;
                swap(a[i], a[j]);
            }
        }

        swap(a[i + 1], a[q]);
        return (i + 1);
    }

    void QuickSort(int p, int q)
    {
        if (p < q)
        {
            int piv = partition(p, q);

            QuickSort(p, piv - 1);
            QuickSort(piv + 1, q);
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

    a.QuickSort(0, n - 1);
    cout << endl
         << endl
         << "Array after sorting:- ";
    a.DisplayA();

    return 0;
}
