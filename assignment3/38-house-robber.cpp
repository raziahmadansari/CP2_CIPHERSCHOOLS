// https://leetcode.com/problems/house-robber/


class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        
        int n = nums.size();
        vector<int> ans(n + 1);
        ans[0] = 0;
        ans[1] = nums[0];
        for (int i = 1; i < n; i++)
            ans[i + 1] = max(ans[i], ans[i - 1] + nums[i]);
        return ans[n];
    }
};