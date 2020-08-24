// https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// RECURSION
int LCSubsequence(string& s1, string& s2, int i = 0, int j = 0)
{
    if (i >= s1.size() || j >= s2.size())   // end of string reached
        return 0;
    if (s1[i] == s2[j])
        return 1 + LCSubsequence(s1, s2, i + 1, j + 1);
    else
        return max(LCSubsequence(s1, s2, i + 1, j), LCSubsequence(s1, s2, i, j + 1));
    return 0;
}

// DP
int LCSdp(string& s1, string& s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<vector<int> > dp(n + 1, vector<int> (m + 1, 0)); // initialize all elements with 0

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;    // increase diagonal element by 1 and store it
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << endl;
    for (auto row : dp)
    {
        for (auto e : row)
            cout << e << " ";
        cout << endl;
    }
    
    return dp[n][m];
}

int main()
{
    string s1("ABCDE");
    string s2("ACDFG");

    cout << LCSubsequence(s1, s2) << endl;

    int result = LCSdp(s1, s2);
    cout << "Longest common substring = " << result;

    return 0;
}