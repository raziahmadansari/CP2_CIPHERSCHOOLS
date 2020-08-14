#include <iostream>

using namespace std;

void solid_rhombus(int n)
{
    /*
            *****
           *****
          *****
         *****
        *****
    */
    for (int i = 0; i < n; i++)
    {
        for (int s = 0; s < (n - i - 1); s++)
            cout << " ";
        for (int j = 0; j < n; j++)
            cout << "*";
        cout << endl;
    }
}

void hollow_rhombus(int n)
{
    /*
            *****
           *   *
          *   *
         *   *
        *****
    */
    for (int i = 0; i < n; i++)
    {
        for (int s = 0; s < (n - i - 1); s++)
            cout << " ";
        if (i == 0)
        {
            for (int top = 0; top < n; top++)
                cout << "*";
            cout << endl;
            continue;
        }
        if (i == n - 1)
        {
            for (int last = 0; last < n; last++)
                cout << "*";
            cout << endl;
            break;
        }
        for (int j = 0; j < n; j++)
        {
            if (j == 0 || j == (n - 1))
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    solid_rhombus(n);
    hollow_rhombus(n);

    return 0;
}