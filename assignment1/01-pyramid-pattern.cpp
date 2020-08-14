#include <iostream>

using namespace std;

void pattern1(int n)
{
    /*
        *
        * *
        * * *
        * * * *
        * * * * *
    */
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            cout << "* ";
        cout << endl;
    }
}

void pattern2(int n)
{
    /*
                *
              * *
            * * *
          * * * *
        * * * * *
    */
    for (int i = 0; i < n; i++)
    {
        // spaces
        for (int s = n - i - 1; s > 0; s--)
            cout << "  ";
        for (int j = 0; j <= i; j++)
            cout << "* ";
        cout << endl;
    }
}

void pattern3(int n)
{
    /*
            *
           * *
          * * *
         * * * *
        * * * * *
    */
    for (int i = 0; i < n; i++)
    {
        for (int s = 0; s < (n - i - 1); s++)
            cout << " ";
        for (int j = 0; j <= i; j++)
            cout << "* ";
        cout << endl;
    }
}

void pattern4(int n)
{
    /*
        1
        1 2
        1 2 3
        1 2 3 4
        1 2 3 4 5
    */
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            cout << (j + 1) << " ";
        cout << endl;
    }
}

void pattern5(int n)
{
    /*
        1
        2 3
        4 5 6
        7 8 9 10
        11 12 13 14 15
    */
    int track = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << track << " ";
            track++;
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    
    pattern1(n);
    pattern2(n);
    pattern3(n);
    pattern4(n);
    pattern5(n);

    return 0;
}