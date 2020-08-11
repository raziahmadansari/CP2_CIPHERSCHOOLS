#include <iostream>
#include <math.h>

using namespace std;

bool ch3kPrime(int n)
{
    // A prime number has exactly two distinct factor
    int count = 2;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            count++;
        if (count > 2)
            break;
    }
    if (count == 2)
        return true;
    else
        return false;
}

int main()
{
    int n;
    cin >> n;

    if (ch3kPrime(n))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}