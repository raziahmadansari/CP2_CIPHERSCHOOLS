// https://leetcode.com/problems/unique-paths/


class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > dp(n, vector<int> (m, 1));
        
        for (int i = n - 2; i >= 0; --i)
            for (int j = m - 2; j >= 0; --j)
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
        
        return dp[0][0];
    }
};