// https://www.geeksforgeeks.org/find-largest-word-dictionary-deleting-characters-given-string/

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

bool isSubSequence(string word, string str)
{
    int m = word.length();
    int n = str.length();
    int j = 0;

    for (int i = 0; i < n && j < m; i++)
    {
        if (word[j] == str[i])
            j++;
    }

    return (j == m);
}

string largestWord(vector<string>& dict, string& str)
{
    pair<int, string> ans(make_pair(0, ""));

    for (string word : dict)
    {
        if (ans.first < word.length() && isSubSequence(word, str))
        {
            ans.first = word.length();
            ans.second = word;
        }
    }

    return ans.second;
}

int main()
{
    vector<string> dict{ "ale", "apple", "monkey", "plea" };
    string str("abpcplea");

    cout << largestWord(dict, str);

    return 0;
}