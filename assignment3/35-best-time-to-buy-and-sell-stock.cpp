// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0)
            return 0;
        int n = prices.size();
        vector<int> left_min(n);
        left_min[0] = prices[0];
        
        vector<int> right_max(n);
        right_max[n - 1] = prices[n - 1];
        
        for (int i = 1; i < n; i++)
        {
            left_min[i] = min(left_min[i - 1], prices[i]);
        }
        for (int i = n - 2; i >= 0; i--)
        {
            right_max[i] = max(right_max[i + 1], prices[i]);
        }
        
        int max_profit = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            max_profit = max(max_profit, abs(left_min[i] - right_max[i]));
        }
        return max_profit;
    }
};