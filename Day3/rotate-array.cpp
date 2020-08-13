// program to rotate the array by k times
// optimize it then push it on github
#include <iostream>

using namespace std;

void reverseArray(int arr[], int s, int e)
{
    int temp;
    for (int i = s, j = e - 1; i < e / 2; i++, j--)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void rotateOptimized(int arr[], int k, int size)
{
    reverseArray(arr, 0, size);
    reverseArray(arr, 0, k);
    reverseArray(arr, k+1, size);
}

/*void rotate(int arr[], int size)
{
    int temp = arr[size - 1];
    int i;
    for (i = size - 1; i > 0; i--)
        arr[i] = arr[i - 1];
    arr[i] = temp;
}*/

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    /*while (k > 0)     // this approach is like rotating array by 1 at a time
    {
        rotate(arr, size);
        k--;
    }*/

    rotateOptimized(arr, k, size);

    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    
    return 0;
}