#include <iostream>
#include <vector>

using namespace std;

int sumOfnumbers(vector<int>& v)
{
    vector<int>::iterator itr = v.begin();
    int sum = 0;
    for (; itr != v.end(); itr++)
        sum += *itr;
    return sum;
}

int main()
{
    int n;
    cin >> n;

    vector<int> v;
    int num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v.push_back(num);
    }

    cout << sumOfnumbers(v);

    return 0;
}