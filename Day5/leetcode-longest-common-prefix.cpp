class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if (strs.size() == 0)
            return "";
        
        if (strs.size() == 1)
            return strs[0];
        
        int minLength = strs[0].size();
        int index = 0;
        
        for (int i = 1; i < strs.size(); i++) // for finding minimum length
            if (minLength > strs[i].size())
            {
                minLength = strs[i].size();
                index = i;
            }
        
        string prefix = "";
        char ch;
        for (int i = 0; i < minLength; i++) // matching charecters
        {
            ch = strs[0][i];
            for (int j = 0; j < strs.size(); j++)
            {
                if (ch != strs[j][i])
                    return prefix;
            }
            prefix += ch;
        }
        return prefix;
    }
};