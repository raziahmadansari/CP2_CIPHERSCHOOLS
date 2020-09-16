/*
input : [1, 3, 4, 5, 6]
output: 2

input : [1, 1, 1, 1, 1]
output: 6
*/

#include <bits/stdc++.h>

using namespace std;

void find_minimum(vector<int>& v) {
    set<int> possibility;

    for (int i = 0; i < v.size(); i++) {
        int sum = 0;
        for (int j = i; j < v.size(); j++) {
            sum += v[j];
            possibility.insert(sum);
        }
    }
    
    for (auto e : possibility)
        cout << e << " ";
    
    set<int>::iterator itr = possibility.begin();

    int minimum = *itr++ + 1;
    for (; itr != possibility.end(); itr++) {
        if (*itr > minimum) {
            cout << "\n" << "Answer - " << minimum;
            break;
        }
        minimum += 1;
    }

    cout << "\n" << "Answer - " << minimum;

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // vector<int> v{1, 3, 4, 5, 6};

    vector<int> v{1, 1, 1, 1, 1};

    find_minimum(v);

    return 0;
}