// https://www.geeksforgeeks.org/minimum-number-of-jumps-to-reach-end-of-a-given-array/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int steps(vector<int>& v)
{
    int n = v.size();
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j + v[j] >= i)
                dp[i] = min(dp[i], dp[j] + 1);
        }
    }
    for (auto e : dp)
        cout << e << " ";
    cout << endl;
    return dp[n];
}

int main()
{
    vector<int> v{1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    // v = { 1, 3, 6, 1, 0, 9 };
    cout << steps(v);

    return 0;
}