#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int add(vector<int>& v1, vector<int>& v2)
{
    int carry = 0;
    int ptr1 = v1.size() - 1;
    int ptr2 = v2.size() - 1;
    int sum = 0;
    
    vector<int> output;

    while (ptr1 >= 0 && ptr2 >= 0)
    {
        output.push_back((v1[ptr1] + v2[ptr2] + carry) % 10);
        carry = (v1[ptr1] + v2[ptr2] + carry) / 10;
        --ptr1;
        --ptr2;
    }

    while (ptr1 >= 0)
    {
        output.push_back((v1[ptr1] + carry) % 10);
        carry = (v1[ptr1] + carry) / 10;
        --ptr1;
    }

    while (ptr2 >= 0)
    {
        output.push_back((v1[ptr1] + carry) % 10);
        carry = (v2[ptr2] + carry) / 10;
        --ptr2;
    }

    reverse(output.begin(), output.end());

    int ptr3 = output.size();
    for (int i = 0; i < output.size(); i++)
        sum += output[i] * ceil(pow(10, --ptr3));

    return sum;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> v1(n);
    vector<int> v2(m);

    for (int i = 0; i < n; i++)
        cin >> v1[i];
    for (int i = 0; i < m; i++)
        cin >> v2[i];
    
    cout << add(v1, v2);

    return 0;
}