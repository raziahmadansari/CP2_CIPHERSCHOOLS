#include <bits/stdc++.h>

using namespace std;

void add_to_vector(vector<int>& A, int x)
{
    A.push_back(x);
}

void sort_vector_asc(vector<int>& A)
{
    sort(A.begin(), A.end());
}

void reverse_vector(vector<int>& A)
{
    reverse(A.begin(), A.end());
}

int size_of_vector(vector<int>& A)
{
    return A.size();
}

void sort_vector_desc(vector<int>& A)
{
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
}

void print_vector(vector<int>& A)
{
    for (auto element : A)
        cout << element << " ";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> A;
        int q;
        cin >> q;
        while (q--)
        {
            char c;
            cin >> c;
            if (c == 'a')
            {
                int x;
                cin >> x;
                add_to_vector(A, x);
            }
            if (c == 'b')
                sort_vector_asc(A);
            if (c == 'c')
                reverse_vector(A);
            if (c == 'd')
                cout << size_of_vector(A) << " ";
            if (c == 'e')
                print_vector(A);
            if (c == 'f')
                sort_vector_desc(A);
        }
        cout << endl;
    }

    return 0;
}