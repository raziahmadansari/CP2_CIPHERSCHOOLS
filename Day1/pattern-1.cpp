#include <iostream>

using namespace std;

/*
 *N = 3
 *output : *
 *         * *
 *         * * *
*/

void printPattern(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            cout << "*" << " ";
        cout << endl;
    }
}
 
 int main()
 {
     int n;
     cin >> n;

     printPattern(n);

     return 0;
 }