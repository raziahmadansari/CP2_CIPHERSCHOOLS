#include <iostream>

using namespace std;

int countMazePath(int endrow, int endcol, int curr_row, int curr_col)
{
    if (curr_row == endrow && curr_col == endcol)
        return 1;
    if (curr_row > endrow || curr_col > endcol)
        return 0;

    return countMazePath(endrow, endcol, curr_row, curr_col + 1) + countMazePath(endrow, endcol, curr_row + 1, curr_col);
}

int main()
{
    cout << countMazePath(2, 2, 0, 0);

    return 0;
}