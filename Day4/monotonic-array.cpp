#include <iostream>
#include <vector>

using namespace std;

bool checkIncreasing(vector<int>& v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i] > v[i + 1])
            return false;
    }
    return true;
}

bool checkDecreasing(vector<int>& v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i] < v[i + 1])
            return false;
    }
    return true;
}

bool isMonotonic(vector<int>& v)
{
    bool increasing = checkIncreasing(v);
    bool decreasing = checkDecreasing(v);

    return (increasing || decreasing);
}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    if (isMonotonic(v))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}