/*Write a program to transpose of sparse matrix*/

#include <iostream>
using namespace std;
#define MAX 5
#define SMAX 12

class sparseMatrix
{
    int s[SMAX][3];

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
             << "Sparse Matrix is :-" << endl
             << endl;
        int r = s[0][0];
        int c = s[0][1];
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

    sparseMatrix TransposeM()
    {
        sparseMatrix temp;

        temp.s[0][0] = s[0][1];
        temp.s[0][1] = s[0][0];
        int k = temp.s[0][2] = s[0][2];

        for (int i = 1; i <= k; i++)
        {
            temp.s[i][0] = s[i][1];
            temp.s[i][1] = s[i][0];
            temp.s[i][2] = s[i][2];
        }

        temp.sortRow();

        return temp;
    }

    void sortRow()
    {
        int nz = s[0][2];
        for (int i = 1; i < nz; i++)
        {
            for (int j = 1; j < nz - i + 1; j++)
            {
                if (s[j][0] > s[j + 1][0] || (s[j][0] == s[j + 1][0] && s[j][1] > s[j + 1][1]))
                {
                    swap(s[j][0], s[j + 1][0]);
                    swap(s[j][1], s[j + 1][1]);
                    swap(s[j][2], s[j + 1][2]);
                }
            }
        }
    }
};

int main()
{

    sparseMatrix s, trans;
    s.ReadM();
    s.DisplayM();

    cout << endl
         << endl
         << "Transpose of the ";
    trans = s.TransposeM();
    trans.DisplayM();

    return 0;
}