#include <iostream>
#include <vector>

using namespace std;

int minSwap(vector<int>& v, int num)
{
    int swaps = 0;
    for (int i = 0, j = v.size() - 1; i < j;)
    {
        if (v[i] >= num && v[j] <= num)
        {
            swap(v[i], v[j]);
            swaps++;
            i++;
            j--;
        }
        if (v[i] < num)
            i++;
        if (v[j] > num)
            j--;
    }
    return swaps;
}

int main()
{
    int k, n;
    cin >> k >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    
    cout << minSwap(v, k);

    return 0;
}