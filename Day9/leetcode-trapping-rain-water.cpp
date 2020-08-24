// https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    
    void print(vector<int>& v)
    {
        for (auto e : v)
            cout << e << " ";
        cout << endl;
    }
    
    int trap(vector<int>& height) {
        if (height.size() < 3)
            return 0;
        
        int n = height.size();
        
        vector<int> left(n);
        vector<int> right(n);
        
        left[0] = height[0];
        right[n - 1] = height[n - 1];
        
        for (int i = 1; i < n; i++)
            left[i] = (left[i - 1] > height[i]) ? left[i - 1] : height[i];
        
        for (int i = n - 2; i >= 0; i--)
            right[i] = (right[i + 1] > height[i]) ? right[i + 1] : height[i];
        
        int water_trap = 0;
        for (int i = 1; i < n - 1; i++)
            water_trap += min(left[i], right[i]) - height[i];
        
        // print(left);
        // print(right);
        
        return water_trap;
    }
};