#include <iostream>

using namespace std;

void printDecreasing(int n, int ending = 1)
{
    cout << n << " ";
    if (n > ending)
        return printDecreasing(--n);
}

int main()
{
    int n;
    cin >> n;
    printDecreasing(n);

    return 0;
}