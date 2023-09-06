/*Write program to convert ordinary matrix to sparse form representation*/

#include <iostream>
using namespace std;
#define MAX 5

class Matrix
{

    int M[MAX][MAX];
    int r, c;
    int nonZero = 0;

public:
    void ReadM()
    {

        while (true)
        {

            cout << "\nEnter the order of matrix : ";
            cin >> r >> c;

            if ((r < 1 || r > 10) || (c < 1 || c > 10))
            {

                cout << "\n\nRow and Column of the matrix should be from 1 to "<<MAX<<" !....Re-Try\n";
            }
            else
            {
                break;
            }
        }

        cout << "\n\nEnter the elements of the matrix :- " << endl;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> M[i][j];
                if (M[i][j] != 0)
                {
                    nonZero++;
                }
            }
        }
    }

    void DisplayM()
    {

        cout << endl
             << endl;
        cout << "Matrix is :-" << endl;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cout << M[i][j] << "\t";
            }
            cout << endl;
        }
    }

    void DisplaySparse()
    {

        int S[MAX][3], k = 1;
        if (nonZero < ((r * c) / 2))
        {

            S[0][0] = r;
            S[0][1] = c;
            S[0][2] = nonZero;

            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    if (M[i][j] != 0)
                    {
                        S[k][0] = i;
                        S[k][1] = j;
                        S[k][2] = M[i][j];
                        k++;
                    }
                }
            }

            cout << "\n\nSparse Representation :-" << endl
                 << endl;

            for (int i = 0; i <= nonZero; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    cout << S[i][j] << "\t";
                }
                cout << endl;
            }
        }
        else
        {

            cout << "\n\nThe given matrix cannot be represented in sparse form!\n";
        }
    }
};

int main()
{

    Matrix m;
    m.ReadM();
    m.DisplayM();
    m.DisplaySparse();
    return 0;
}