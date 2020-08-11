// print nth prime number
#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int num)
{
    bool flag = true;
    
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
            return !flag;
    }
    return flag;
}

int nthPrime(int n, int current = 1, int number = 2)
{
    if (isPrime(number))
    {
        if (current == n)
            return number;
        else
            return nthPrime(n, ++current, ++number);        
    }
    return nthPrime(n, current, ++number);
}

int main()
{
    int n;
    cin >> n;

    cout << nthPrime(n);

    return 0;
}