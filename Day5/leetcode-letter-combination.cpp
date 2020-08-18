// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> letterCombinations(string digits)
{
    vector<string> result;
    if(digits.empty())
        return vector<string>();
    
    static const vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    result.push_back("");   // add a seed for the initial case
    
    for(int i = 0 ; i < digits.size(); ++i)
    {
        int num = digits[i]-'0';
        if(num < 0 || num > 9)
            break;
        
        const string& candidate = v[num];

        // cout << "value of num, candidate = " << num << " " << candidate << endl;
            
        if(candidate.empty())
            continue;
            
        vector<string> tmp;

        // cout << "size of result = " << result.size() << endl;
        for(int j = 0 ; j < candidate.size() ; ++j)
            for(int k = 0 ; k < result.size() ; ++k)
            {
                // cout << "value of result[k], candidate[j] = " << result[k] << "-" << candidate[j] << endl;
                tmp.push_back(result[k] + candidate[j]);
            }
        result.swap(tmp);
    }
    return result;
}

int main()
{
    for (auto e : letterCombinations("2"))
        cout << e << " ";
    
    return 0;
}