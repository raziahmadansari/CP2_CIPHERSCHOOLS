#include <iostream>

using namespace std;

int sumOfDigit(int n)
{
    int rem;
    int sum = 0;
    while (n > 0)
    {
        rem = n % 10;
        sum += rem;
        n /= 10;
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;

    cout << sumOfDigit(n);

    return 0;
}