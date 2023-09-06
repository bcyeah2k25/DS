/*Write a program to add 2 sparse matrix check all validations*/

#include <iostream>
using namespace std;
#define MAX 10

class sparseMatrix
{
    int s[MAX][3];

public:
    void ReadM()
    {
        int r, c, nz;

        while (true)
        {
            cout << "Enter the (row size) (column size) (number of non-zero numbers) : ";
            cin >> r >> c >> nz;

            if ((r < 1 || r > MAX) || (c < 1 || c > MAX) || (nz < 1 || nz >= ((r * c) / 2)))
            {
                cout << "\nInvalid values......Re-Enter!" << endl;
            }
            else
            {
                s[0][0] = r;
                s[0][1] = c;
                s[0][2] = nz;
                break;
            }
        }

        int k = 1;

        for (int i = 0; i < nz; i++)
        {
            int R, C, NZN;
            cout << "Enter the (row) (column) (non-zero number) : ";
            cin >> R >> C >> NZN;

            if ((R < 0 || R >= r) || (C < 0 || C >= c) || (NZN == 0))
            {
                cout << "\nInvalid values......Re-Enter!" << endl;
                i--;
            }
            else
            {
                s[k][0] = R;
                s[k][1] = C;
                s[k][2] = NZN;
                k++;
            }
        }
    }

    void DisplayM()
    {
        cout << endl
             << "Sparse Matrix is :-" << endl;
        int nz = s[0][2];

        for (int i = 0; i <= nz; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << s[i][j] << "\t";
            }
            cout << endl;
        }
    }

    sparseMatrix AddM(sparseMatrix &o)
    {

        if ((s[0][0] != o.s[0][0]) || (s[0][1] != o.s[0][1]))
        {
            cout << endl
                 << "Matrix addition not possible order of both matrix is not same!";
            exit(0);
        }

        sparseMatrix temp;
        int a = 1, b = 1, c = 1;

        temp.s[0][0] = s[0][0];
        temp.s[0][1] = s[0][1];

        while ((a <= s[0][2]) && b <= o.s[0][2])
        {

            if (s[a][0] == o.s[b][0])
            {

                if (s[a][1] == o.s[b][1])
                {

                    int sum = s[a][2] + o.s[b][2];

                    if (sum != 0)
                    {

                        temp.s[c][0] = s[a][0];
                        temp.s[c][1] = s[a][1];
                        temp.s[c][2] = sum;

                        a++;
                        b++;
                        c++;
                    }
                    else
                    {
                        a++;
                        b++;
                    }
                }
                else
                {

                    if (s[a][1] < o.s[b][1])
                    {

                        temp.s[c][0] = s[a][0];
                        temp.s[c][1] = s[a][1];
                        temp.s[c][2] = s[a][2];
                        a++;
                        c++;
                    }
                    else
                    {
                        temp.s[c][0] = o.s[b][0];
                        temp.s[c][1] = o.s[b][1];
                        temp.s[c][2] = o.s[b][2];
                        b++;
                        c++;
                    }
                }
            }
            else
            {

                if (s[a][0] < o.s[b][0])
                {

                    temp.s[c][0] = s[a][0];
                    temp.s[c][1] = s[a][1];
                    temp.s[c][2] = s[a][2];
                    a++;
                    c++;
                }
                else
                {

                    temp.s[c][0] = o.s[b][0];
                    temp.s[c][1] = o.s[b][1];
                    temp.s[c][2] = o.s[b][2];
                    b++;
                    c++;
                }
            }
        }

        while (a <= s[0][2])
        {

            temp.s[c][0] = s[a][0];
            temp.s[c][1] = s[a][1];
            temp.s[c][2] = s[a][2];
            a++;
            c++;
        }

        while (b <= o.s[0][2])
        {

            temp.s[c][0] = o.s[b][0];
            temp.s[c][1] = o.s[b][1];
            temp.s[c][2] = o.s[b][2];
            b++;
            c++;
        }

        temp.s[0][2] = c - 1;

        return temp;
    }
};

int main()
{
    sparseMatrix a, b, sum;

    cout << endl
         << endl
         << "Enter the details of sparse matrix 1 :-" << endl
         << endl;
    a.ReadM();
    cout << endl
         << endl
         << "Enter the details of sparse matrix 2 :- " << endl
         << endl;
    b.ReadM();

    cout << endl
         << endl
         << ".........1st.........." << endl;
    a.DisplayM();
    cout << endl
         << endl
         << ".........2nd.........." << endl;
    b.DisplayM();

    sum = a.AddM(b);

    cout << endl
         << endl
         << ".........Sum of both sparse matrix........." << endl;
    sum.DisplayM();

    return 0;
}
