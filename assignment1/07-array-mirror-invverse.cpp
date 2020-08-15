#include <iostream>
#include <vector>

using namespace std;

bool isMirrorInverse(vector<int>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i != v[v[i]])
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n, 0);

    for (int i = 0; i < n; i++)
        cin >> v[i];
    
    if (isMirrorInverse(v))
        cout << "yes";
    else
        cout << "no";

    return 0;
}