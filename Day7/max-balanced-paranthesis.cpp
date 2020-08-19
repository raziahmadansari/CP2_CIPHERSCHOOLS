// max nested balanced paranthesis
// (((x))()) --> 3
// (()))( --> -1

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

bool isBalanced(string& str)
{
    stack<char> st;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
            st.push(str[i]);
        else if (str[i] == ')')
        {
            if (st.empty())
                return false;
            st.pop();
        }
    }

    return st.size() == 0;
}

int maxNested(string& str)
{
    if (!isBalanced(str))
        return -1;
    
    int max_nesting = 0;
    stack<char> st;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
            st.push(str[i]);
            
        else if (str[i] == ')')
            st.pop();
        
        max_nesting = (max_nesting > st.size()) ? max_nesting : st.size();
    }
    return max_nesting;
}

int main()
{
    string str = "(((x))())";
    str = "(()))(";
    
    cout << maxNested(str);

    return 0;
}