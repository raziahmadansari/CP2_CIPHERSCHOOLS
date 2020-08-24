// https://www.geeksforgeeks.org/coin-change-dp-7/

#include <iostream>
#include <vector>

using namespace std;

// recursion
int change(vector<int>& v, int noc, int sum)    // noc -> number of coins
{
    if (sum == 0)
        return 1;
    if (sum < 0)
        return 0;
    if (noc <= 0 && sum > 0) // if no coin left and sum is greater than zero
        return 0;   // no solution
    return change(v, noc - 1, sum) + change(v, noc, sum - v[noc - 1]);
}

// DP
int changeDP(vector<int>& v, int sum)
{
    vector<vector<int> > dp(sum + 1, vector<int> (v.size(), 1));
    for (int i = 1; i <= sum; i++)  // i represents the current sum here
    {
        for (int j = 0; j < v.size(); j++)
        {
            int val1 = 0;
            int val2 = 0;
            if (i >= v[j])  // case of inclusion
                val1 = dp[i - v[j]][j];
            if (j >= 1)     // case of exclusion
                val2 = dp[i][j - 1];
            dp[i][j] = val1 + val2;
        }
    }
    
    for (auto row : dp)
    {
        for (auto e : row)
            cout << e << " ";
        cout << endl;
    }
    return dp[sum][v.size() - 1];
}

int main()
{
    vector<int> coins{ 1, 2, 3 };
    int sum = 4;

    cout << change(coins, coins.size(), sum) << endl << endl;
    
    int count = changeDP(coins, sum);
    cout << "\nnumber of ways = " << count << endl;

    return 0;
}