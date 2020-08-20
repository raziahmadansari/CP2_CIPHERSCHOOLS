// https://www.geeksforgeeks.org/number-subsequences-form-ai-bj-ck/


#include <iostream>
#include <string>

using namespace std;

int countSubsequence(string& str)
{
    int aCount = 0;
    int bCount = 0;
    int cCount = 0;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'a')
            aCount = (1 + 2 * aCount);
        else if (str[i] == 'b')
            bCount = (aCount + 2 * bCount);
        else if (str[i] == 'c')
            cCount = (bCount + 2 * cCount);
    }

    return cCount;
}

int main()
{
    string str = "abcabc";
    cout << countSubsequence(str);

    return 0;
}