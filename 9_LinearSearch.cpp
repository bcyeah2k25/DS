/*Write a program to search an element using linear search.
Using user defined functions and pass parameters*/

#include <iostream>
using namespace std;
#define MAX 5

class Array
{

    int values[MAX];
    int n;

public:
    void ReadA()
    {

        while (true)
        {
            cout << "Enter the number of elements : ";
            cin >> n;
            if ((n < 1) || (n > MAX))
            {
                cout << endl
                     << endl
                     << "Number of elements should be from 1 to "<<MAX<<" !....Re-Enter!" << endl;
            }
            else
            {
                break;
            }
        }

        cout << endl
             << "Enter the elemets of the array :-" << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> values[i];
        }
    }

    void DisplayA()
    {

        cout << endl;
        cout << "Array : [ ";
        for (int i = 0; i < n; i++)
        {
            cout << values[i];
            if (i < n - 1)
            {
                cout << ", ";
            }
        }
        cout << " ]";
    }

    bool SearchItem(int &item)
    {

        for (int i = 0; i < n; i++)
        {

            if (values[i] == item)
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{

    Array a;

    a.ReadA();
    a.DisplayA();

    int x;
    cout << endl
         << endl
         << "Enter the item to be searched : ";
    cin >> x;

    if (a.SearchItem(x))
    {
        cout << endl
             << endl
             << "Item " << x << " is found !" << endl;
    }
    else
    {
        cout << endl
             << endl
             << "Item " << x << " is not found !" << endl;
    }

    return 0;
}