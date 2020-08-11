#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int a = 0, b = 1, c = a + b, i = 2;

    cout << a << " " << b << " ";
    while (i < n)
    {
        cout << c << " ";
        a = b;
        b = c;
        c = a + b;
        i++;
    }

    return 0;
}