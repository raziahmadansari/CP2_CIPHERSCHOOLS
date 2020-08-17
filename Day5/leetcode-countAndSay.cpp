#include <iostream>
#include <vector>
#include <string>

using namespace std;

string countAndSay(int n)
{
    if (n <= 0)
        return "";
    string str = "1";
    if (n == 1)
        return str;
    
    cout << str << endl;
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        string temp = "";
        count = 1;
        char ch = str[0];
        for (int j = 1; j < str.size(); j++)
        {
            if (ch == str[j])
                count++;
            else
            {
                temp += to_string(count) + ch;
                ch = str[j];
                count = 1;
            }
        }
        temp += to_string(count) + ch;
        str = temp;
        cout << temp << endl;
    }
    return str;
}

int main()
{
    int n;
    cin >> n;
    string ans = countAndSay(n);
    cout << "\nFinal answer = " << ans;
    return 0;
}