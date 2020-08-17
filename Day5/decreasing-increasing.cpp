// input 7
// output - 7 5 3 1 0 2 4 6

#include <iostream>

using namespace std;

void print(int n)
{
    if (n < 0)
        return;
    if (n % 2 != 0)
        cout << n << " ";
    
    print(n - 1); // recursive call

    if (n % 2 == 0)
        cout << n << " ";
}

int main()
{
    int n;
    cin >> n;
    print(n);

    return 0;
}