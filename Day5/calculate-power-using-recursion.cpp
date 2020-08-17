#include <iostream>

using namespace std;

int calculateApowerB(int a, int b)
{
    if (b == 0)
        return 1;
    return calculateApowerB(a, --b) * a;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << calculateApowerB(a, b);

    return 0;
}