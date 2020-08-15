class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > dp;
        if (numRows == 0)
            return dp;
        
        vector<int> temp = { 1 };
        dp.push_back(temp);
        if (numRows == 1)
            return dp;
        
        temp.clear();
        temp = { 1, 1 };
        dp.push_back(temp);
        if (numRows == 2)
            return dp;
        
        for (int i = 2; i < numRows; i++)
        {
            temp.clear();
            temp.push_back(1);
            for (int j = 0; j < dp[i - 1].size() - 1; j++)
                temp.push_back(dp[i - 1][j] + dp[i - 1][j + 1]);
            temp.push_back(1);
            dp.push_back(temp);
        }
        return dp;
    }
};