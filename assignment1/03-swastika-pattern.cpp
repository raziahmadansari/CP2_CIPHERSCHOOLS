#include <iostream>

using namespace std;

void printSwastik(int n)
{
    for (int row = 0; row < n; row++)
    {
        if (row == 0)
        {
            cout << "*";
            for (int f_row = 1; f_row < n; f_row++)
            {
                if (f_row < n / 2)
                    cout << " ";
                else
                    cout << "*";
            }
            cout << endl;
        }
        else if (row == n - 1)  // last row
        {
            for (int l_row = 0; l_row < n - 1; l_row++)
            {
                if (l_row < (n / 2 + 1))
                    cout << "*";
                else
                    cout << " ";
            }
            cout << "*" << endl;
        }
        else if (row == n / 2)   // mid row
        {
            for (int mid = 0; mid < n; mid++)
                cout << "*";
            cout << endl;
        }
        else if (row < n / 2)   // left side
        {
            cout << "*";
            for (int i = 1; i < n / 2; i++)
                cout << " ";
            cout << "*" << endl;
        }
        else    // right side
        {
            int i = 0;
            for (i = 0; i < n / 2; i++)
                cout << " ";
            cout << "*";
            for (++i; i < n - 1; i++)
                cout << " ";
            cout << "*" << endl;
        }
        
    }
}

int main()
{
    int n;
    cin >> n;

    printSwastik(n);

    return 0;
}