// HINT - XOR operation

#include <iostream>
#include <vector>

using namespace std;

int unique(vector<int>& v)
{
    int ans = 0;
    for (int i = 0; i < v.size(); i++)
        ans = ans ^ v[i];
    return ans;
}

int main()
{
    vector<int> v{ 1, 1, 2, 3, 2 };
    cout << unique(v);
    return 0;
}