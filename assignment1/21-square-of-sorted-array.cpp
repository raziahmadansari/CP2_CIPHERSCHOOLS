class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int x = 0;
        int y = A.size() - 1;
        vector<int> ans(A.size());
        for (int i = A.size() - 1; i >= 0; i--)
        {
            ans[i] = (fabs(A[x]) > fabs(A[y])) ? (A[x] * A[x++]) : (A[y] * A[y--]);
            /*if (fabs(*itr) > fabs(*itr2))
            {
                ans[i] = (*itr * *itr);
                itr++;
            }
            else {
                ans[i] = (*itr2 * *itr2);
                itr2--;
            }*/
        }
        
        return ans;
    }
};