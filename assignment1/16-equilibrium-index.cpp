#include <iostream>
#include <vector>

using namespace std;

int equilibrium_index(vector<int>& v)
{
    int sum = 0;
    for (auto element : v)
        sum += element;
    
    int left_sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (left_sum == sum - left_sum - v[i])
            return i;
        left_sum += v[i];
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    
    cout << equilibrium_index(v);

    return 0;
}