// https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>s;
        for(int i=0;i<nums.size();i++){
            s[nums[i]]++;
        }
        map<int,vector<int>>s1;
        for(auto x:s){
            s1[x.second].push_back(x.first);
        }
        vector<int>ans;
        std::map<int,vector<int>>::reverse_iterator rit;
        for (rit=s1.rbegin(); rit!=s1.rend() && k>0; ++rit){
            for(int i=0;i<rit->second.size()&&k>0;i++){
                ans.push_back(rit->second[i]);
                k--;
            }
        }
        return ans;
    }
};