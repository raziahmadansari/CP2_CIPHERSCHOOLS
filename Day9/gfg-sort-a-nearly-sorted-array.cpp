// https://www.geeksforgeeks.org/nearly-sorted-algorithm/

#include <iostream>
#include <queue>

using namespace std;

void sortKsorted(vector<int>& v, int k)
{
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 0; i <= k; i++) // push_back first k element to the heap
        pq.push(v[i]);
    
    for (int i = k + 1; i < v.size(); i++)
    {
        cout << pq.top() << " ";
        pq.pop();
        pq.push(v[i]);
    }

    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    return;
}

int main()
{
    vector<int> v{ 6, 5, 3, 2, 8, 10, 9 };
    int k = 3;

    sortKsorted(v, k);

    return 0;
}