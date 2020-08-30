// https://leetcode.com/problems/maximum-subarray/


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        
        int n = nums.size();
        vector<int> dp(n + 1);
        dp[0] = nums[0];
        int max_sum = dp[0];
        
        for (int i = 1; i < n; i++)
        {
            dp[i] = nums[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
            max_sum = max(max_sum, dp[i]);
        }
        
        return max_sum;
    }
};