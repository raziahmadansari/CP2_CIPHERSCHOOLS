#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int toInt(char ch)
{
    if (ch == '1')
        return 1;
    return 0;
}

int toDecimal(string& binary)
{
    int len = binary.length();
    int decimal = 0;
    for (int i = 0; i < binary.length(); i++)
        decimal += toInt(binary[i]) * pow(2, --len);
    return decimal;
}

int main()
{
    string binary;
    cin >> binary;

    cout << toDecimal(binary);

    return 0;
}