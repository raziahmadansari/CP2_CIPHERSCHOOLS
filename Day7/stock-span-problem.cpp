#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> calculateSpan(vector<int>& v)
{
    vector<int> ans(v.size()); // for storing answer
    stack<int> st;
    ans[0] = 1; // for storing index
    st.push(0);

    for (int i = 1; i < v.size(); i++)
    {
        while (!st.empty() && v[st.top()] <= v[i])
            st.pop();
        ans[i] = (st.empty()) ? (i + 1) : i - st.top();
        st.push(i);
    }

    return ans;
}

int main()
{
    vector<int> v{100, 80, 60, 70, 60, 75, 85};
    
    for (auto e : calculateSpan(v))
        cout << e << " ";

    return 0;
}