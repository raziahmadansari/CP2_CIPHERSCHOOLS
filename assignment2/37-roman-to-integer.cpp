// https://leetcode.com/problems/roman-to-integer/


class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> symbol;
        symbol['I'] = 1;
        symbol['V'] = 5;
        symbol['X'] = 10;
        symbol['L'] = 50;
        symbol['C'] = 100;
        symbol['D'] = 500;
        symbol['M'] = 1000;
        
        int num = 0;
        num += symbol[s[0]];
        
        for (int i = 1; i < s.size(); i++)
        {
            if (symbol[s[i - 1]] < symbol[s[i]])
                num += symbol[s[i]] - 2 * symbol[s[i - 1]];
            else
                num += symbol[s[i]];
        }
        
        return num;
    }
};