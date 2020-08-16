#include <iostream>
#include <vector>
#include <deque>
#include <climits>

using namespace std;

int findKMin(vector<int>& diff, int n, int k)
{
    deque<int> Qi(k);
    int i;

    for (i = 0; i < k; i++)
    {
        while (!Qi.empty() && diff[i] >= diff[Qi.back()])
            Qi.pop_back();
        Qi.push_back(i);
    }

    int minDiff = INT_MAX;
    for(; i < n; i++)
    {
        // the element at the front of the queue is the largest
        // element of previous window
        minDiff = min(minDiff, diff[Qi.front()]);

        // remove the elements which are out of this window
        while (!Qi.empty() && Qi.front() <= i - k)
            Qi.pop_front();
        
        // remove all elements smaller than the currently
        // being added element (remove useless element)
        while (!Qi.empty() && diff[i] >= diff[Qi.back()])
            Qi.pop_back();
        
        // add current element at the rear of Qi
        Qi.push_back(i);
    }

    // compare the maximum element of last window
    minDiff = min(minDiff, diff[Qi.front()]);
    return minDiff;
}

int minAdjacentDiff(vector<int>& v, int n, int k)
{
    // create difference array
    vector<int> diff(n - 1);
    for (int i = 0; i < n - 1; i++)
        diff[i] = v[i + 1] - v[i];
    
    // find minimum of all maximum of subarray sizes n - k - 1
    return findKMin(diff, n - 1, n - k - 1);
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    
    cout << minAdjacentDiff(v, n, k);

    return 0;
}