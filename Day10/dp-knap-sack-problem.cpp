// https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// RECURSION
int knapSackRecur(vector<pair<int, int> >& v, int W, int n)
{
    if (n == 0 || W == 0) // base case if no item present or weight becomes zero
        return 0;
    
    cout << "v[n - 1] - " << v[n - 1].first << " " << v[n - 1].second << endl;
    if (v[n - 1].second > W) // current element weight is greater than the capacity, remove it
        return knapSackRecur(v, W, n - 1);
    else
    {
        return max(v[n - 1].first + knapSackRecur(v, W - v[n - 1].second, n - 1), knapSackRecur(v, W, n - 1));
    }
    return -1;
}

// DP
int knapSackDp(vector<pair<int, int> >& v, int W)
{
    int n = v.size();

    vector<vector<int> > dp(n + 1, vector<int> (W + 1, 0)); // initialize with zero

    for (int i = 1; i <= n; i++) // i denotes the item
    {
        for (int j = 1; j <= W; j++) // j denotes the capacity
        {
            if (v[i - 1].second <= j) // if item weight is less than the capacity
                dp[i][j] = max(dp[i - 1][j - v[i - 1].second] + v[i - 1].first, dp[i - 1][j]);
        }
    }

    for (auto row : dp)
    {
        for (auto e : row)
            cout << e << " ";
        cout << endl;
    }

    return dp[n][W];
}

int main()
{
    vector<pair<int, int> > v{ {10, 1}, {50, 2}, {60, 3} };    // pair<value, weight>
    int W = 5;
    // cout << knapSackRecur(v, W, v.size()) << endl;

    int result = knapSackDp(v, W);
    cout << "Result = " << result << endl;

    return 0;
}