#include <iostream>
#include <string>
#include <deque>
#include <climits>
#include <vector>
#include <unordered_map>

using namespace std;

bool checkAllChars(string& s, string& t)
{
    unordered_map<char, int> hash_t;
    for (int i = 0; i < t.size(); i++) // frequency hash
    {
        if (hash_t.find(t[i]) == hash_t.end())
            hash_t[t[i]] = 1;
        else
            hash_t[t[i]] += 1;        
    }

    for (int i = 0; i < s.size(); i++) // decreasing frequency hash
    {
        // cout << "value of hash_t[s[i]] = " << hash_t[s[i]] << endl;
        if (hash_t.find(s[i]) != hash_t.end())
            hash_t[s[i]] -= 1;
    }

    for (int i = 0; i < t.size(); i++) // if character not balanced
        if (hash_t[t[i]] > 0)
            return false;
    return true;
}

bool check(deque<char>& dq, string& t)
{
    bool ans = false;
    vector<int> v(dq.size(), 0); // not visited
    for (int i = 0; i < t.size(); i++)
    {
        ans = false;
        for (int j = 0; j < dq.size(); j++)
        {
            // cout << "v[j] = " << v[j] << endl;
            if (t[i] == dq[j] && v[j] == 0)
            {
                // cout << "value matched = " << dq[j] << endl;
                ans = true;
                v[j] = 1;
                break;
            }
        }
        if (!ans)
            return ans;
    }
    return ans;
}

string minWindow(string& s, string& t) {
    if (s.size() < t.size())
        return "";
    
    if (!checkAllChars(s, t))
        return "";
    
    deque<char> dq;
    string ans = s; // the original string contains the target

    for (int i = 0; i < s.size(); i++)
    {
        dq.push_back(s[i]);
        for (auto e : dq)
            cout << e;
        cout << endl;
        if (!dq.empty() && dq.size() >= t.size() && check(dq, t)) // update the ans with smaller window
        {
            string temp = "";
            char ch = dq.front();
            dq.pop_front();
            while (check(dq, t)) // decrease the window size and check still condition satisfies or not
            {
                ch = dq.front();
                dq.pop_front();
            }
            temp += ch;
            for (int j = 0; j < dq.size(); j++)
                temp += dq[j];
            // dq.pop_front();
            if (temp.size() <= ans.size())
                ans = temp;
        }
        
        for (auto e : dq)
            cout << e;
        cout << endl;
        cout << ans << endl << endl;
    }
    return ans;
}

int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";

    // s = "this is a test string";
    // t = "tist";

    // s = "a";
    // t = "aa";

    // s = "a";
    // t = "b";

    // s = "babb";
    // t = "baba";

    // s = "a";
    // t = "a";

    cout << minWindow(s, t);

    // time limit exceeded

    return 0;
}

/*
// EFFICIENT SOLUTION

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() == 0 || t.size() == 0) return "";
        vector<int> remaining(128, 0);
        int required = t.size();
        for (int i = 0; i < required; i++) remaining[t[i]]++;
        // left is the start index of the min-length substring ever found
        int min = INT_MAX, start = 0, left = 0, i = 0;
        while(i <= s.size() && start < s.size()) {
            if(required) {
                if (i == s.size()) break;
                remaining[s[i]]--;
                if (remaining[s[i]] >= 0) required--;
                i++;
            } else {
                if (i - start < min) {
                    min = i -start;
                    left = start;
                }
                remaining[s[start]]++;
                if (remaining[s[start]] > 0) required++;
                start++;
            }
        }
        return min == INT_MAX? "" : s.substr(left, min);
    }
};


*/