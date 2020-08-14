#include <iostream>
#include <vector>

using namespace std;

int pivot(vector<int>& v)
{
    int sum = 0;
    for (int i = 0; i < v.size(); i++)
        sum += v[i];

    int left_sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (left_sum == sum - left_sum - v[i])
            return i;   // return the current index

        left_sum += v[i];
    }
    return -1;  // return -1 if no pivot
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    
    cout << pivot(v);

    return 0;
}