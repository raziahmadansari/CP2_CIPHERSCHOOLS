#include <iostream>
#include <vector>

using namespace std;

int op_needed(vector<int> v, int n)
{
    int op = 0;
    if (n == 0) // greater - smaller - greater ...
    {
        for (int i = 0; i < v.size() - 1; i++)
        {
            if (i % 2 == 0)
            {
                if (v[i] <= v[i + 1])
                {
                    op++;
                    while (v[i + 1] >= v[i])
                        v[i + 1] -= 1;
                }
            }
            else
            {
                if (v[i] >= v[i + 1])
                {
                    op++;
                    while (v[i] >= v[i + 1])
                        v[i] -= 1;
                }
            }
        }
    }

    if (n == 1) // smaller - greater - smaller ...
    {
        for (int i = 0; i < v.size() - 1; i++)
        {
            if (i % 2 == 0)
            {
                if (v[i] >= v[i + 1])
                {
                    op++;
                    while (v[i] >= v[i + 1])
                        v[i] -= 1;
                }
            }
            else
            {
                if (v[i] <= v[i + 1])
                {
                    op++;
                    while (v[i + 1] >= v[i])
                        v[i + 1] -= 1;
                }
            }
        }
    }

    for (auto e : v)
        cout << e << " ";
    cout << endl;

    return op;
}

int operations(vector<int>& v)
{
    int a = op_needed(v, 0);
    int b = op_needed(v, 1);
    
    if (a <= b)
        return a;
    return b;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    
    cout << operations(v);

    return 0;
}