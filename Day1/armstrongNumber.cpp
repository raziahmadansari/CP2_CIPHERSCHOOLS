#include <iostream>
#include <math.h>

using namespace std;

int countDigit(int num)
{
    int noOfDigit = 0;
    while (num > 0)
    {
        noOfDigit++;
        num /= 10;
    }
    return noOfDigit;
}

bool checkArmstrong(int num)
{
    int power = countDigit(num);
    cout << "power = " << power << endl;
    int temp = num;
    int sum = 0; // to hold the sum of each digits
    int digit;
    while (num > 0)
    {
        digit = num % 10;
        sum += ceil(pow(digit, power)); // to overcome roundof issue
        num /= 10;
    }
    if (sum == temp)
        return true;
    else
        return false;
}

int main()
{
    int num;
    cin >> num;

    if (checkArmstrong(num))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}