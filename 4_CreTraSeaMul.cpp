/*Write a program to implementation of array menu driven
program - create, traverse, search, multiply with a constant value*/

#include <iostream>
using namespace std;
#define MAX 5

class Array
{

    int a[MAX], size;
    bool arrayCreated = false;

public:
    void Create()
    {

        while (true)
        {
            cout << endl
                 << "Enter the size of the array : ";
            cin >> size;
            if (size > MAX || size < 2)
            {
                cout << endl
                     << "Size should be from 2 to " << MAX << "!..Re-Try!";
            }
            else
            {
                break;
            }
        }

        cout << "Enter the elements of the array :-" << endl;
        for (int i = 0; i < size; i++)
        {
            cin >> a[i];
        }

        cout << endl
             << endl
             << "Array created succefully...!" << endl;
        arrayCreated = true;
    }

    void Display()
    {

        if (arrayCreated)
        {

            cout << endl;
            cout << "Array : [ ";
            for (int i = 0; i < size; i++)
            {
                cout << a[i];
                if (i < size - 1)
                {
                    cout << ", ";
                }
            }
            cout << " ]";
        }
        else
        {
            cout << endl
                 << endl
                 << "Create array first!" << endl;
        }
    }

    void Search()
    {

        if (arrayCreated)
        {

            int x;
            cout << "Enter the element to be searched : ";
            cin >> x;

            bool found = false;
            for (int i = 0; i < size; i++)
            {
                if (a[i] == x)
                {
                    cout << endl
                         << endl
                         << "Element (" << x << ") has been found at position (" << ++i << ")!";
                    found = true;
                }
            }

            if (!found)
            {
                cout << endl
                     << endl
                     << "Element (" << x << ") is not found in this array!";
            }
        }
        else
        {
            cout << endl
                 << endl
                 << "Create array first!" << endl;
        }
    }

    void MulConst()
    {

        if (arrayCreated)
        {

            int c;
            cout << "Enter the constant to multiply : ";
            cin >> c;

            for (int i = 0; i < size; i++)
            {
                a[i] = a[i] * c;
            }

            cout << endl
                 << endl
                 << "Constant (" << c << ") succefully multiplied with array elements!" << endl;
        }
        else
        {
            cout << endl
                 << endl
                 << "Create array first!" << endl;
        }
    }
};

int main()
{

    Array A;
    int choice;

    do
    {

        cout << endl
             << endl;
        cout << "....Array Operations....." << endl
             << "1. Create" << endl
             << "2. Display" << endl
             << "3. Search element" << endl
             << "4. Multiply with a constant" << endl
             << "0. Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {

        case 0:
            cout << endl
                 << endl
                 << "Exiting............" << endl;
            exit(0);
            break;

        case 1:
            A.Create();
            break;

        case 2:
            A.Display();
            break;

        case 3:
            A.Search();
            break;

        case 4:
            A.MulConst();
            break;

        default:
            cout << endl
                 << "Invalid choice.....Re-Try...!" << endl;
        }

    } while (choice != 0);
}