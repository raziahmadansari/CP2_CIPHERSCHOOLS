#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int* arr1 = new int[n];
    int* arr2 = new int[n];

    // input
    for (int i = 0; i < n; i++)
        cin >> arr1[i];

    // calculate cumulative sum
    arr2[0] = arr1[0];
    for (int i = 1; i < n; i++)
        arr2[i] = arr2[i - 1] + arr1[i];

    // output
    for (int i = 0; i < n; i++)
        cout << arr2[i] << " ";
    
    delete[] arr1;
    delete[] arr2;

    return 0;
}