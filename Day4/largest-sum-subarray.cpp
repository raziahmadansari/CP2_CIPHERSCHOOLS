// find largest sum subarray of a given array
// solve it in O(n), hint use Kaden's algorithm

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int max_sum(vector<int>& v) // O(n)
{
    int max_so_far = v[0];
    int curr_max = v[0];

    for (int i = 0; i < v.size(); i++)
    {
        curr_max = max(v[i], curr_max + v[i]);
        max_so_far = max(max_so_far, curr_max);
    }
    return max_so_far;
}

int largest_sum(vector<int>& v) // O(n^2)
{
    int sum = v[0];
    for (int i = 0; i < v.size(); i++)
    {
        int temp = v[i];
        for (int j = i + 1; j < v.size(); j++)
        {
            temp += v[j];
        }
        if (sum < temp)
            sum = temp;
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    cout << largest_sum(v) << endl;
    cout << max_sum(v);
   
    return 0;
}