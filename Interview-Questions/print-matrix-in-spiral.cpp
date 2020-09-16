/*
    INTPUT:-
    [[1, 2, 3, 4],
     [5, 6, 7, 8],
     [9, 10, 11, 12],
     [13, 14, 15, 16]]

    OUTPUT:-
    1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
*/

#include <bits/stdc++.h>

using namespace std;

void printSpiral(vector<vector<int> >& v) {
    int n = v.size();
    int m = v[0].size();

    int top = 0, bottom = n - 1, left = 0, right = m - 1;

    int direction = 0;
    while (top <= bottom && left <= right) {
        // left to right
        if (direction == 0) {
            for (int i = left; i <= right; i++)
                cout << v[top][i] << " ";
            top++;
        }

        // top to bottom
        else if (direction == 1) {
            for (int i = top; i <= bottom; i++)
                cout << v[i][right] << " ";
            right--;
        }

        // right to left
        else if (direction == 2) {
            for (int i = right; i >= left; i--)
                cout << v[bottom][i] << " ";
            bottom--;
        }

        // bottom to top
        else {
            for (int i = bottom; i >= top; i--)
                cout << v[i][left] << " ";
            left++;
        }

        direction = (direction + 1) % 4;
    }

    return;
}

int main()
{
    vector<vector<int> > v{{1, 2, 3, 4},
                           {5, 6, 7, 8},
                           {9, 10, 11, 12},
                           {13, 14, 15, 16}};
    
    printSpiral(v);

    return 0;
}