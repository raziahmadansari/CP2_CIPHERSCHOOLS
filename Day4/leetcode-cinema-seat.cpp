// https://leetcode.com/problems/cinema-seat-allocation/

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int> > seats;
        int result = 2 * n;
        
        for (auto element : reservedSeats)
            seats[element[0]].push_back(element[1]);
        
        for (auto row : seats)
        {
            bool left = false;
            bool right = false;
            bool mid = false;
            
            for (auto s : row.second)
            {
                if (s > 1 && s < 6)     left = true;
                if (s > 5 && s < 10)    right = true;
                if (s > 3 && s < 8)     mid = true;
            }
            
            if (left == true)   result--;
            if (right == true)  result--;
            
            if (left == true && right == true && mid == false)  result++;
        }
        return result;
    }
};