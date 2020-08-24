// https://www.geeksforgeeks.org/k-maximum-sum-combinations-two-arrays/


#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void maxKcombination(vector<int>& A, vector<int>& B, int k)
{
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int n = A.size();

    // pq<sum, (i, j)>
    priority_queue<pair<int, pair<int, int> > > pq;
    pq.push(make_pair(A[n - 1] + B[n - 1], make_pair(n - 1, n - 1)));

    set<pair<int, int> > unique_set;
    unique_set.insert(make_pair(n - 1, n - 1));

    for (int count = 0; count < k; count++)
    {
        pair<int, pair<int, int> > kthMax = pq.top();   pq.pop();

        cout << kthMax.first << " ";

        int i = kthMax.second.first;
        int j = kthMax.second.second;

        int sum = A[i - 1] + B[j];

        pair<int, int> temp1 = make_pair(i - 1, j);
        if (unique_set.find(temp1) == unique_set.end())
        {
            pq.push(make_pair(sum, temp1));
            unique_set.insert(temp1);
        }

        sum = A[i] + B[j - 1];
        temp1 = make_pair(i, j - 1);
        if (unique_set.find(temp1) == unique_set.end())
        {
            pq.push(make_pair(sum, temp1));
            unique_set.insert(temp1);
        }
    }
    return;
}

int main()
{
    vector<int> A{1, 4, 2, 3};
    vector<int> B{2, 5, 1, 6};
    int k = 4;
    
    maxKcombination(A, B, k);
    
    return 0;
}