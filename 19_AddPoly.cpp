/*Write a program to add two Polynomials using arrays*/

#include <iostream>
using namespace std;
#define MAX 20

struct P
{
    int co;
    int ex;
};

class Poly
{
    struct P po[MAX];
    int n;

public:
    void ReadP(int n)
    {
        this->n = n;

        for (int i = 0; i < n; i++)
        {
            cout << endl
                 << "Enter the (co-efficient) & (exponent) : ";
            cin >> po[i].co >> po[i].ex;
        }
    }

    void DispP()
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (po[i].ex < po[j].ex)
                {
                    P temp = po[i];
                    po[i] = po[j];
                    po[j] = temp;
                }
            }
        }

        cout << "Polynomial : ";
        for (int i = 0; i < n; i++)
        {
            cout << po[i].co << "X^" << po[i].ex;

            if (i != n - 1)
            {
                cout << " + ";
            }
        }
        cout << endl;
    }

    Poly operator+(Poly z)
    {
        Poly temp;

        int i = 0, j = 0, k = 0;

        while (i < n && j < z.n)
        {
            if (po[i].ex > z.po[j].ex)
            {
                temp.po[k].co = po[i].co;
                temp.po[k].ex = po[i].ex;
                i++;
            }
            else if (z.po[j].ex > po[i].ex)
            {
                temp.po[k].co = z.po[j].co;
                temp.po[k].ex = z.po[j].ex;
                j++;
            }
            else
            {
                temp.po[k].co = po[i].co + z.po[j].co;
                temp.po[k].ex = po[i].ex;
                i++;
                j++;
            }
            k++;
        }

        while (i < n)
        {
            temp.po[k] = po[i];
            i++;
            k++;
        }

        while (j < z.n)
        {
            temp.po[k] = z.po[j];
            j++;
            k++;
        }

        temp.n = k;

        return temp;
    }
};

int main()
{
    Poly p1, p2;
    int n;

    cout << "Enter the number of terms in the 1st polynomial: ";
    cin >> n;

    cout << endl
         << endl
         << "Enter 1st polynomial: ";
    p1.ReadP(n);

    cout << endl
         << endl
         << "Enter the number of terms in the 2nd polynomial: ";
    cin >> n;

    cout << endl
         << endl
         << "Enter 2nd polynomial: ";
    p2.ReadP(n);

    cout << endl
         << endl
         << "1st ";
    p1.DispP();

    cout << endl
         << endl
         << "2nd ";
    p2.DispP();

    Poly Psum;
    Psum = p1 + p2;
    cout << endl
         << endl
         << "Sum of ";
    Psum.DispP();

    return 0;
}
