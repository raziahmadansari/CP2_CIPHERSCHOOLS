#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int longestCommonSubstring(string& s1, string& s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<vector<int> > dp(n + 1, vector<int> (m + 1, 0));

    int max_len = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                max_len = max(max_len, dp[i][j]);
            }
        }
    }
    return max_len;
}

int main()
{
    string s1("ABCXY");
    string s2("XYABC");
    // cin >> s1 >> s2;

    cout << longestCommonSubstring(s1, s2);

    return 0;
}