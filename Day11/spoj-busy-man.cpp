// https://www.spoj.com/problems/BUSYMAN/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
    return a.first < b.first;
}

int maxTask(vector<pair<int, int> >& v)
{
    sort(v.begin(), v.end(), cmp);

    int final_max_task = 0;

    for (int i = 0; i < v.size(); i++)
    {
        int end_time = v[i].second;
        int max_task = 1;
        for (int j = i + 1; j < v.size(); j++)
        {
            if (end_time <= v[j].first)
            {
                max_task++;
                end_time = v[j].second;
            }
        }
        final_max_task = max(final_max_task, max_task);
    }
    return final_max_task;
}

void testcase()
{
    int n;
    cin >> n;
    vector<pair<int, int> > v;
    int s, e;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> e;
        v.push_back(make_pair(s, e));
    }

    cout << maxTask(v);
    return;
}

int main()
{
    int t;
    cin >> t;

    while (t)
    {
        testcase();
        t--;
    }

    return 0;
}