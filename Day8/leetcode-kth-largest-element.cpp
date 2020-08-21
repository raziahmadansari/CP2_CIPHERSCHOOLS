// https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        /*set<int> s;
        for (int i = 0; i < nums.size(); i++)
            s.insert(nums[i]);
        
        vector<int> v;
        for (auto itr = s.begin(); itr != s.end(); itr++)
        {
            v.push_back(*itr);
            cout << *itr << " ";
        }*/
        
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        
        return nums[k - 1];
    }
};