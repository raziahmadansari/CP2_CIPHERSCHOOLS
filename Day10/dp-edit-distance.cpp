// https://www.geeksforgeeks.org/edit-distance-dp-5/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int minimum(int a, int b, int c)
{
    a = min(a, b);
    return min(a, c);
}

// RECURSION
int editDistanceRec(string& s1, string& s2, int n, int m)
{
    if (n < 1) // first string ends completely
        return m;
    if (m < 1)
        return n;
    if (s1[n - 1] == s2[m - 1]) // character matches
        return editDistanceRec(s1, s2, n - 1, m - 1);
    else
    {
        int insertion = editDistanceRec(s1, s2, n, m - 1);
        int deletion = editDistanceRec(s1, s2, n - 1, m);
        int replace = editDistanceRec(s1, s2, n - 1, m - 1);

        return minimum(insertion, deletion, replace) + 1; // +1 for operation to be counted
    }
    return 0;
}

int editDistanceDp(string& s1, string& s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<vector<int> > dp(n + 1, vector<int> (m + 1, 0)); // initialize the array with 0;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0)
                dp[i][j] = j; // base case, we need to delete all the available characters in s1
            else if (j == 0)
                dp[i][j] = i;
            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
            {
                int insertion = dp[i][j - 1]; // left
                int deletion = dp[i - 1][j]; // upper
                int replace = dp[i - 1][j - 1]; // diagonal

                dp[i][j] = min(insertion, min(deletion, replace)) + 1;
            }
        }
    }

    for (auto row : dp)
    {
        for (auto e : row)
            cout << e << " ";
        cout << endl;
    }

    return dp[n][m];
}

int main()
{
    string s1("CAT");
    string s2("CUT");

    cout << editDistanceRec(s1, s2, s1.size(), s2.size()) << endl;

    int result = editDistanceDp(s1, s2);
    cout << "Result = " << result;
    return 0;
}