#include <iostream>
#include <string>

using namespace std;

void subsequence(string str, string osf= "") // method 2nd
{
    if (str.size() == 0)
    {
        cout << "-> " << osf << endl;
        return;
    }
    char ch = str[0]; // store 1st character
    string ros = str.substr(1); // remove 1st character from str;
    subsequence(ros, osf + ch);
    subsequence(ros, osf);
}

void printSubsequence(string& str, int start = -1, string current = "") // method 1st
{
    if (start == str.size())
        return;
    cout << current << endl;
    for (int i = start + 1; i < str.size(); i++)
    {
        current += str[i];
        printSubsequence(str, i, current);
        current = current.erase(current.size() - 1); // backtracing
    }
    return;
}

int main()
{
    string str = "abc";
    //printSubsequence(str);
    subsequence(str);

    return 0;
}