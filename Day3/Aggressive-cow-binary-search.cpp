// Question "Spoj Aggressive Cow"
// Link - https://www.spoj.com/problems/AGGRCOW/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(vector<int>& pos, int cow, int gap)
{
    cout << "Gap = " << gap << endl;
    cow--;  // one cow always sit at first location
    for (int i = 0; i < pos.size(); i++)
    {
        for (int j = i + 1; j < pos.size(); j++)
        {
            if (pos[i] + gap <= pos[j])
            {
                cow--;
                i = j;
            }
        }
    }
    if (!cow)   // no cows left
        return true;
    return false;
}

int run()
{
    int n, c;
    cout << "Enter N and C :: ";
    cin >> n >> c;

    vector<int> position(n);    // store position of 'n' stall
    for (int i = 0; i < n; i++)
        cin >> position[i];

    sort(position.begin(), position.end());     // sort the stall in increasing order

    int low = 1;    // creating search space, set low to 1
    int high = position[n - 1];     // high will always be set to the largest element in the array
    int mid = low + (high - low) / 2;       // it works like gap
    int min_max_gap = 0;

    while (low <= high)     // binary search concept is used
    {
        if (check(position, c, mid))
        {
            min_max_gap = (min_max_gap < mid) ? mid : min_max_gap;  // store the largest minimum distance
            low = mid + 1;
            mid = low + (high - low) / 2;
        }
        else
        {
            high = mid - 1;
            mid = low + (high - low) / 2;
        }
    }

    return min_max_gap;
}

int main()
{
    int T;      // number of test cases
    cin >> T;

    while (T > 0)
    {
        cout << run();
        T--;
    }

    return 0;
}