#include <iostream>
#include <vector>

using namespace std;

void findLocation(vector<vector<int> > arr, int num, int size)
{
    // find row
    int row = -1;
    int i;
    for (i = 0; i < size - 1; i++)
    {
        if (arr[i][0] <= num && arr[i + 1][0] > num)
        {
            row = i;
            break;
        }
    }
    if (row == -1) // for last row
        row = i;
    int col = -1;
    for (i = 0; i < size; i++)
    {
        if (arr[row][i] == num)
        {
            col = i;
            break;
        }
    }
    cout << row << " " << col;
    return;
}

int main()
{
    vector<vector<int> > arr = {{1, 2, 3, 4},
                                {11, 12, 13, 14},
                                {21, 22, 23, 24},
                                {31, 32, 33, 34}};
    
    findLocation(arr, 32, arr.size());

    return 0;
}