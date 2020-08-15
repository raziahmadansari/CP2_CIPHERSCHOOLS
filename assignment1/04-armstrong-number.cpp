#include <iostream>
#include <math.h>

using namespace std;

int countDigit(int n)
{
    int digit = 0;
    while (n > 0)
    {
        n /= 10;
        digit++;
    }
    return digit;
}

bool isArmstrong(int n)
{
    int nod = countDigit(n); // number of digit
    int temp = n;
    int sum = 0;
    while (n > 0)
    {
        sum += ceil(pow(n % 10, nod));
        n /= 10;
    }
    if (temp == sum)
        return true;
    return false;
}

int main()
{
    int n;
    cin >> n;

    if (isArmstrong(n))
        cout << "yes";
    else
        cout << "no";
    
    return 0;
}