// https://www.geeksforgeeks.org/longest-repeating-subsequence/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int longestRepeating(string& str)
{
    int n = str.size();
    vector<vector<int> > v(n + 1, vector<int> (n + 1, 0)); // declaring vector of size[n+1][n+1]
    // and initializing it to 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if ((str[i - 1] == str[j - 1]) && (i != j))
                v[i][j] = 1 + v[i - 1][j - 1];
            else
                v[i][j] = max(v[i - 1][j], v[i][j - 1]);
        }
    }

    for (auto row : v)
    {
        for (auto e : row)
            cout << e << " ";
        cout << endl;
    }

    return v[n][n];
}

int main()
{
    string str("aabb");

    int longestSequence = longestRepeating(str);

    cout << "\nLongest Repeating Subsequence = " << longestSequence;

    return 0;
}