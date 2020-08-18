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
    subsequence(ros, osf + to_string(int(ch)));
    subsequence(ros, osf);
}

int main()
{
    string str = "ab";
    //printSubsequence(str);
    subsequence(str);

    return 0;
}