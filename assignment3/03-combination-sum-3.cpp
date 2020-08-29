// https://leetcode.com/problems/combination-sum-iii/


class Solution {
public:
    void combination(vector<vector<int> >& result, vector<int> solution, int k, int sum)
    {
        if (solution.size() == k && sum == 0) // base case
        {
            result.push_back(solution);
            return;
        }
        if (solution.size() < k)
        {
            for (int i = solution.empty() ? 1 : solution.back() + 1; i <= 9; i++)
            {
                if (sum - i < 0)
                    break;
                solution.push_back(i);
                combination(result, solution, k, sum - i); // recursion
                solution.pop_back(); // backtracking
            }
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > result;
        vector<int> solution;
        
        combination(result, solution, k, n);
        
        return result;
    }
};