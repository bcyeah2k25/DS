/*Write a program to search an element using binary searching*/

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
                     << "Number of elements should be from 1 to " << MAX << " !....Re-Enter!" << endl;
            }
            else
            {
                break;
            }
        }

        cout << endl
             << "Enter the elements of the array :-" << endl;
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

    
    void Swap(int& a,int& b){
        int temp = a;
        a = b;
        b = temp;
    } 

   void Sort()
  {

        for (int i = 0; i < n; i++)
        {

            for (int j = i + 1; j < n; j++)
            {

                if (values[j] < values[i])
                {
                    Swap(values[j], values[i]);
                }
            }
        }
    }

    bool SearchItem(int &x)
    {

        Sort();

        int beg = 0;
        int end = n - 1;

        while (beg <= end)
        {

            int mid = (beg + end) / 2;

            if (x == values[mid])
            {
                return true;
            }
            else if (x < values[mid])
            {
                end = mid - 1;
            }
            else
            {
                beg = mid + 1;
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