#include <iostream>

using namespace std;

void printIncreasing(int n, int starting = 1)
{
    cout << starting << " ";
    if (starting < n)
        printIncreasing(n, ++starting);
}

int main()
{
    int n;
    cin >> n;
    printIncreasing(n);

    return 0;
}