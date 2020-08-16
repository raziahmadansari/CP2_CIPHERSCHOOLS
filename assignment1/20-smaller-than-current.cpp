class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> a(101);
        vector<int> b(101);
        
        int n = nums.size();
        
        for (int i = 0; i < n; i++) // frequency
            a[nums[i]]++;
        
        for (int i = 1; i < 101; i++)   // fill a series of array with frequency
            b[i] = b[i - 1] + a[i - 1];
        
        vector<int> ans(n); // final array
        for (int i = 0; i < n; i++)
            ans[i] = b[nums[i]];
        return ans;
    }
};