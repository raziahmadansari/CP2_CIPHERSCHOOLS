class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> indices;
        for (int i = 0; i < nums.size(); i++)
        {
            int number2find = target - nums[i];
            if (hash.find(number2find) != hash.end())
            {
                indices.push_back(hash[number2find]); // index of previous number
                indices.push_back(i); // index of current number
                return indices;
            }
            hash[nums[i]] = i;
        }
        return indices;
    }
};