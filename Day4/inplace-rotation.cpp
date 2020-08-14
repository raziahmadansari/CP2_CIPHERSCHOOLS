// in place rotation of a matrix in 90 degree clock wise
// https://www.interviewbit.com/problems/rotate-matrix/

#include <iostream>
#include <vector>

using namespace std;

void printMatrix(vector<vector<int> >& v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << v[i][j] << " ";
        cout << endl;
    }
}

void transpose(vector<vector<int> >& v)
{
    int len = v.size();

    for (int i = 0; i < len; i++)
        for (int j = i; j < len; j++)
            swap(v[i][j], v[j][i]);
}

void shift(vector<vector<int> >& v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        for (int left = 0, right = n - 1; left < right; left++, right--)
            swap(v[i][left], v[i][right]);
    }
}

void rotate90(vector<vector<int> >& v)
{
    transpose(v);   // find tranpose of matrix
    shift(v);       // swap each equidistant element in a row
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int> > v(n, vector<int> (n, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> v[i][j];

    rotate90(v);

    cout << "\nMatrix aafter 90 degree clock wise rotation:" << endl;
    printMatrix(v);

    return 0;
}